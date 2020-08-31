void motorStop()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}

void turnLeft()
{
  analogWrite(LM1, 150);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}

void calculatePID()
{
  P = error;
  I = I + error;
  D = error - previousError;
  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;
}

void motorPIDcontrol()
{

  int leftMotorSpeed = 100 - iniMotorPower - PIDvalue;
  int rightMotorSpeed = 100 + iniMotorPower * adj - PIDvalue;

  // The motor speed should not exceed the max PWM value
  constrain(leftMotorSpeed, 0, 255);
  constrain(rightMotorSpeed, 0, 255);

  analogWrite(LM1, leftMotorSpeed);
  analogWrite(LM2, 0);
  analogWrite(RM1, rightMotorSpeed);
  analogWrite(RM2, 0);

  //Serial.print (PIDvalue);
  //Serial.print (" ==> Left, Right:  ");
  //Serial.print (leftMotorSpeed);
  //Serial.print ("   ");
  //Serial.println (rightMotorSpeed);
}
