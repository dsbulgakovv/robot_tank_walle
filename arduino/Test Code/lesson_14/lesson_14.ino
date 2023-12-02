/*
  keyestudio Mini Tank Robot V3
  lesson 14
  Ultrasonic follow tank
  http://www.keyestudio.com
*/
#define servoPin 10  //the pin of the servo

#define ML_Ctrl 4  //define define the control pin of the left motor as 4
#define ML_PWM 5   //define the PWM control pin of the left motor as 5
#define MR_Ctrl 2  //define the control pin of the right motor as 2
#define MR_PWM 6   //define the PWM control pin of the right motor as 6
#define Trig 12
#define Echo 13
float distance;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
  procedure(90); //set the angle of the servo to 90°
  delay(500); //delay in 500ms
}
void loop() {
  distance = checkdistance();  //distance assign the distance detected by an ultrasonic sensor
  if (distance >= 20 && distance <= 60) //the range to go front
  {
    Car_front();
  }
  else if (distance > 10 && distance < 20)  //the range to stop
  {
    Car_Stop();
  }
  else if (distance <= 10)  //the range to go back
  {
    Car_back();
  }
  else  //or else, stop
  {
    Car_Stop();
  }
}
void Car_front()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 200);
}
void Car_back()
{
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,200);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,200);
}
void Car_left()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 200);
}
void Car_right()
{
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 200);
}
void Car_Stop()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
}

//a function to control servos
void procedure(byte myangle) {
  int pulsewidth;
  for (int i = 0; i < 5; i++) {
    pulsewidth = myangle * 11 + 500;  //calculate the value of pulse width
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulsewidth);   //the time that high level maintains is pulse width
    digitalWrite(servoPin, LOW);
    delay((20 - pulsewidth / 1000));  //The cycle is 20ms
  }
}
//a function to control the ultrasonic sensor
float checkdistance() {
  static float distance;
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  distance = pulseIn(Echo, HIGH) / 58.20;  //2*29.1=58.2
  delay(10);
  return distance;
}
