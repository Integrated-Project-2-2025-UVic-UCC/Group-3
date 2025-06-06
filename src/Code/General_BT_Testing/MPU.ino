void setupMPU() { // Initates the Gyroscope/Accelerometer module
  byte status = mpu.begin();
  Serial.print("Calibrating MPU");
  while (status != 0) Serial.println("ERROR");  // stop everything if could not connect to MPU6050
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  mpu.calcOffsets();
  Serial.print(".");
  Serial.println("DONE");
  Serial.print("Calibrating BMP...");
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1)
      ;
  }
  delay(500);
  float sumlecturas = 0;
  for (int i = 0; i < lecturas; i++) { // Calculates initial offset of the barometer
    sumlecturas += bmp.readAltitude() - hOffset;
  }
  hOffset = sumlecturas / lecturas;
}

void updateMPU() {  // Updates MPU data (has to run as fast as possible)
  int measures = 1;
  float sumlecturas = 0;
  for (int i = 0; i < measures; i++) {
    sumlecturas += bmp.readAltitude() - hOffset;
  }
  BMPaltitude = 100 * sumlecturas / measures;
  //BMPaltitude = (bmp.readAltitude() - hOffset) * 100;
  mpu.update();
  long t = micros();
  interval = (t - lastT);
  ypr[0] = mpu.getAngleZ();
  ypr[1] = mpu.getAngleY();
  ypr[2] = mpu.getAngleX();
  double accX = mpu.getAccX();
  double accY = mpu.getAccY();
  double accZ = mpu.getAccZ();
  // Angle transportation to calculate vertical acceleration
  verticalAcc = ((-1) * accX * sin(ypr[1] * DEG_TO_RAD) + accY * sin(ypr[2] * DEG_TO_RAD) * cos(ypr[1] * DEG_TO_RAD) + accZ * cos(ypr[2] * DEG_TO_RAD) * cos(ypr[1] * DEG_TO_RAD) - 1);
  verticalVel = lastVel + interval * verticalAcc * 9.81 / 10000;  // Integrates acceleration to get velocity in cm/s
  MPUaltitude = lastMPUaltitude + lastVel * interval / 1000000 + 0.5 * interval * interval * (verticalAcc)*9.81 / 10000000000;
  lastT = t;
  lastVel = verticalVel;
}

float getZangle() {
  return ypr[0];
}

float getYangle() {
  return ypr[1];
}

float getXangle() {
  return ypr[2];
}

float getVerticalVelocity() {
  return lastVel;
}

float getVerticalAcceleration() {
  return verticalAcc;
}

float getMPUaltitude() {
  return lastMPUaltitude;
}

void calcularKalman() {
  double y = BMPaltitude - MPUaltitude;
  double K = 0.3; // Confidency constant for Barometer over MPU
  lastMPUaltitude = MPUaltitude + K * y;
}
