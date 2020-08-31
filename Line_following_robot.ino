
int mode = 0;

# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2

const int lineFollowSensor0 = 8;
const int lineFollowSensor1 = 7;
const int lineFollowSensor2 = 6;
const int lineFollowSensor3 = 5;
const int lineFollowSensor4 = 4;

const int LM1 = A0;
const int LM2 = A1;
const int RM1 = A2;
const int RM2 = A3;

int LFSensor[5] = {0, 0, 0, 0, 0};

float Kp = 0;
float Ki = 0;
float Kd = 0;

float error = 0, P = 0, I = 0, D = 0, PIDvalue = 0;
float previousError = 0;

const int iniMotorPower = 50;
const int adj = 1;


void setup()
{
  Serial.begin(9600);

  // line follow sensors
  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);

  //Output Motor
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

}
void loop()
{
  readLFSsensors();
  switch (mode)
  {
    case STOPPED:
      motorStop();
      previousError = error;
      break;

    case NO_LINE:
      motorStop();
      turnLeft();
      previousError = error;
      break;

    case FOLLOWING_LINE:
      calculatePID();
      motorPIDcontrol();
      break;
  }
}
