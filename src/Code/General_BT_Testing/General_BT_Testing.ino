#include "definitions.h"
unsigned long timeBT = millis(); // Variable to send BT data at a given rate
unsigned long timeloop = millis(); // Variable to calculate the iteration time
void setup() {
  // put your setup code here, to run once:
  pinMode(ledGpin, OUTPUT);
  pinMode(ledYpin, OUTPUT);
  pinMode(ledRpin, OUTPUT);
  digitalWrite(ledGpin, 0);
  digitalWrite(ledYpin, 0);
  digitalWrite(ledRpin, 1); // LED Initialization
  motorSetup(); // Motor setup
  setupTOF(); // Distance sensors setup
  setupBLE(); // Bluetooth Low Energy setup
  setupMPU(); // Gyroscope/Accelerometer setup
  delay(2000);
  Serial.println("DRONE INITIATED");
  digitalWrite(ledGpin, 0);
  digitalWrite(ledYpin, 1);
  digitalWrite(ledRpin, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  timeloop = millis(); // Resets the loop time
  int distToGround = getDistance(); // Reads the distance sensor
  Serial.println(distToGround);
  updateMPU(); // Updates sensor values (Angles and accelerations)
  calcularKalman(); // Calculates height
  if (activateSerial) {
    motorUpdate(0, PitchStabilize(0), RollStabilize(0)); // If activated via BT, starts the stabilization loop (Yaw is set to 0 so it doesn't have control)
  }
  if (timeBT < millis()) { // Prints some info every 500 ms
    enviarBLE("X:" + String(getXangle()) + " A:" + String(motorPower[0]) + " B:" + String(motorPower[1]) + " C:" + String(motorPower[2]) + " D:" + String(motorPower[3]) + " Ts:" + String(millis() - timeloop));
    timeBT = millis() + 500;
  }
}
