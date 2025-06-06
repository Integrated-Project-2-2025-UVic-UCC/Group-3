float PID0(float measure, float objective, float kp, float ki, float kd) {
  float error = measure - objective;
  // Proportional
  float k = error * kp;
  // Integral
  sumError0 += error;
  if (error > -5 and error < 5) sumError0 = 0;
  float i = sumError0 * ki;
  // Derivative
  float actualTime = micros();
  float d = (error - lastError0) / (actualTime - lastTime0) * kd;
  lastTime0 = actualTime;
  lastError0 = error;
  float values = k + i + d;
  values = constrain(values, -100, 100);
  return values;
}

float PID1(float measure, float objective, float kp, float ki, float kd) {
  float error = measure - objective;
  // Proportional
  float k = error * kp;
  // Integral
  sumError1 += error;
  if (error > -5 and error < 5) sumError1 = 0;
  float i = sumError1 * ki;
  // Derivative
  float actualTime = micros();
  float d = (error - lastError1) / (actualTime - lastTime1) * kd;
  lastTime1 = actualTime;
  lastError1 = error;
  float values = k + i + d;
  values = constrain(values, -100, 100);
  return values;
}

int RollStabilize(int angle) { // Returns the Roll motor power requiered after the stabilization calculations
  return int(PID1(getYangle(), angle, serialKp, serialKi, serialKd));
}

int PitchStabilize(int angle) { // Returns the Pitch motor power requiered after the stabilization calculations
  return int(PID0(getXangle(), angle, serialKp, serialKi, serialKd));
}

void motorUpdate(int yawPower, int pitchPower, int rollPower) { // Given each power needed for each axis, updates every motor power
  motorPower[0] = yawPower - pitchPower - rollPower + hoverPower;
  motorPower[1] = (-1)*yawPower - pitchPower + rollPower + hoverPower;
  motorPower[2] = yawPower + pitchPower + rollPower + hoverPower;
  motorPower[3] = (-1)*yawPower + pitchPower - rollPower + hoverPower;
  motorStart("A", motorPower[0]);
  motorStart("B", motorPower[1]);
  motorStart("C", motorPower[2]);
  motorStart("D", motorPower[3]);
}
