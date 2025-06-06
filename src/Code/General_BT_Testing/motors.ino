void motorSetup() {
  Serial.begin(115200);
  FL.setPeriodHertz(50);
  FR.setPeriodHertz(50);
  RR.setPeriodHertz(50);
  RL.setPeriodHertz(50);
  FL.attach(motorA, 1000, 2000);
  FR.attach(motorB, 1000, 2000);
  RL.attach(motorD, 1000, 2000);
  RR.attach(motorC, 1000, 2000);
  tolva.attach(SERVO_PIN, 1000, 2000);
  FL.writeMicroseconds(1000);  // Inititates the ESCs to start value
  FR.writeMicroseconds(1000);
  RL.writeMicroseconds(1000);
  RR.writeMicroseconds(1000);
  
  
}


void motorStart(String motorSelect, int power) {  // Motor select --> A:Front-Left B:Front-Right C:Rear-Right D:Rear-Left   Power --> (0-100)
  power = constrain(power, 0, 100);
  int usMap;
  if (power != 0) usMap = map(power, 0, 100, 1200, 2000);
  else usMap = 1000;
  for (uint8_t i = 0; i < motorSelect.length(); i++) {
    if (motorSelect.charAt(i) == 'A') FL.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'B') FR.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'C') RR.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'D') RL.writeMicroseconds(usMap);
  }
}