void setupTOF() { // Initiates distance sensors
  Wire.begin();
  Wire.setClock(400000);
  TOF.setTimeout(500);
  if (!TOF.init()){
    while (1) {
      Serial.println("Failed to detect and initialize TOF!");
      delay(500);
    }
  }
  TOF.startContinuous(50);
}

unsigned int getDistance(){ // Returns distance reading in mm
  int lectura = TOF.readRangeContinuousMillimeters() - TOF_OFFSET;
  if (lectura < 0) lectura = 0;
  return lectura;
}