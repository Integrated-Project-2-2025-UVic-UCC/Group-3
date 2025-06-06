// Distance sensors
#include "VL53L0X.h"
VL53L0X TOF;
int TOF_OFFSET = 25; // Distance sensor offset

//LEDs
#define ledGpin 35 // Green LED pin
#define ledYpin 33 // Yellow LED pin
#define ledRpin 32 // Red LED pin

bool activateSerial = false; // Varaible controlled by BLE to activate and desativate PID loop

// Serial
float angleBT = 0;
float serialKp = 0.5; // Kp value controlled by BLE
float serialKi = 0; // Ki value controlled by BLE
float serialKd = 0; // Kd value controlled by BLE

// Motors
#include <ESP32Servo.h>
#define motorA 12  // Front-left motor PWM pin
#define motorB 26  // Front-right motor PWM pin
#define motorC 27  // Rear-right motor PWM pin
#define motorD 14  // Rear-left motor PWM pin
#define SERVO_PIN 13 // Servo pin
byte hoverPower = 0;
Servo FL;
Servo FR;
Servo RR;
Servo RL;
Servo tolva;
int motorPower[4] = {0, 0, 0, 0};

// PIDs
float lastError0 = 0;
float sumError0 = 0;
long lastTime0 = micros();

float lastError1 = 0;
float sumError1 = 0;
long lastTime1 = micros();

// MPU-Barometer
#include <MPU6050_light.h>
#include <Adafruit_BMP085.h>
#include "Wire.h"
Adafruit_BMP085 bmp;
MPU6050 mpu(Wire);
long lastT = micros();  // Variable initialization
double ypr[3];          // [yaw, pitch, roll]   yaw/pitch/roll container
double lastVel = 0;     // Variable initialization
double verticalVel = 0;
double lastMPUaltitude = 0;
double MPUaltitude = 0;  // In cm
double BMPaltitude = 0;  // In cm
double verticalAcc = 0;  // Vertical acceleracion in g without gravity component
double hOffset = 0;
int lecturas = 30;
double interval = 0;