#include <ESP32Servo.h>
#define motorA 12  // Front-left motor PWM pin
#define motorB 13  // Front-right motor PWM pin
#define motorC 14  // Rear-right motor PWM pin
#define motorD 15  // Rear-left motor PWM pin
Servo FL;
Servo FR;
Servo RR;
Servo RL;

void motorSetup() {
  FL.setPeriodHertz(50);
  FR.setPeriodHertz(50);
  RR.setPeriodHertz(50);
  RL.setPeriodHertz(50);
  FL.attach(motorA, 1000, 2000);
  FR.attach(motorB, 1000, 2000);
  RR.attach(motorC, 1000, 2000);
  RL.attach(motorD, 1000, 2000);
  FL.writeMicroseconds(1000);  // Inititates the ESCs to min value
  FR.writeMicroseconds(1000);
  RR.writeMicroseconds(1000);
  RL.writeMicroseconds(1000);
}


void motorStart(String motorSelect, byte power) {  // Motor select --> A:Front-Left B:Front-Right C:Rear-Right D:Rear-Left   Power --> (0-100)
  int usMap = map(power, 0, 100, 1000, 2000);
  for (uint8_t i = 0; i < motorSelect.length(); i++) {
    if (motorSelect.charAt(i) == 'A') FL.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'B') FR.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'C') RR.writeMicroseconds(usMap);
    else if (motorSelect.charAt(i) == 'D') RL.writeMicroseconds(usMap);
  }
}