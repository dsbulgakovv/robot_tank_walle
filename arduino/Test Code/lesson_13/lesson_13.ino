/*
  keyestudio Mini Tank Robot V3
  lesson 13
  light follow tank
  http://www.keyestudio.com
*/
#define light_L_Pin A2   //define the pin of the left photoresistor as A0 
#define light_R_Pin A1   //define the pin of the right photoresistor as A1
#define ML_Ctrl 4  //define the control pin of the left motor as 4
#define ML_PWM 5   //define as the PWM control pin of the left motor 
#define MR_Ctrl 2  //define the control pin of the right motor as 2
#define MR_PWM 6   //define the PWM control pin of the right motor as 6
int left_light;
int right_light;
void setup() {
  Serial.begin(9600);
  pinMode(light_L_Pin, INPUT);
  pinMode(light_R_Pin, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}
void loop() {
  left_light = analogRead(light_L_Pin);
  right_light = analogRead(light_R_Pin);
  Serial.print("left_light_value = ");
  Serial.println(left_light);
  Serial.print("right_light_value = ");
  Serial.println(right_light);
  if (left_light > 650 && right_light > 650) //the range value detected by photoresistor, go front
  {
    Car_front();
  }
  else if (left_light > 650 && right_light <= 650)  //the range value detected by photoresistor, turn left
  {
    Car_left();
  }
  else if (left_light <= 650 && right_light > 650) //the range value detected by photoresistor, turn right
  {
    Car_right();
  }
  else  //or else，stop
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
