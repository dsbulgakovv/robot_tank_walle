/*
  keyestudio Mini Tank Robot V3
  lesson 15
  Ultrasonic avoid tank
  http://www.keyestudio.com
*/
#define servoPin 10  //the pin of the servo
int a, a1, a2;
#define ML_Ctrl 4  //define the direction control pin of the left motor as 4
#define ML_PWM 5   //define the PWM control pin of the lfet motor as 5
#define MR_Ctrl 2  //define the direction control pin of the right motor as 9
#define MR_PWM 6   //define the PWM control pin of the right motor as 6
#define Trig 12
#define Echo 13
float distance;

void setup() {
  Serial.begin(9600);
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
  a = checkdistance();  //assign the front distance to variable a

  if (a < 20) {//when the front distance is less than 20cm
    Car_Stop();  //robot stops
    delay(500); //delay in 500ms
    procedure(180);  //the platform of the ultrasonic sensor rotates to left
    delay(500); //delay in 500ms
    a1 = checkdistance();  // assign the left distance value detected by ultrasonic sensor to the variable a
    delay(100); //
    procedure(0); //the platform of the ultrasonic sensor rotates to right
    delay(500); //delay in 500ms
    a2 = checkdistance(); //assign the right distance value detected by ultrasonic sensor to the variable a2
    delay(100); //
    
    procedure(90);  //back to 90°
    delay(500);
    if (a1 > a2) { //if the left distance is larger than the right one
      Car_left();  //robot turns left
      delay(700);  //turn left for 700ms
    } else {
      Car_right(); //robot turns right
      delay(700);
    }
  } 
  else { //if the detected front distance ≥20cm, the robot will go forward
    Car_front(); //go front
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
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 200);
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

//a function to contol the ultrasonic sensor
float checkdistance() {
  float distance;
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  distance = pulseIn(Echo, HIGH) / 58.20;  // 2*29.1=58.2
  delay(10);
  return distance;
}
