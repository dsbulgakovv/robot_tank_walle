/*
  keyestudio Mini Tank Robot V3
  lesson 11.1
  motor driver
  http://www.keyestudio.com
*/
#define ML_Ctrl 4  //Define the direction control pin of the left motor
#define ML_PWM 5   //Define the PWM control pin of the left motor
#define MR_Ctrl 2  //Define the direction control pin of the right motor
#define MR_PWM 6  //Define the PWM control pin of the right motor

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//Define the direction control pin of the left motor as output
  pinMode(ML_PWM, OUTPUT);//Define the PWM control pin of the left motor as output
  pinMode(MR_Ctrl, OUTPUT);//Define the direction control pin of the right motor as output
  pinMode(MR_PWM, OUTPUT);//Define the PWM control pin of the right motor as output
}
void loop()
{
  digitalWrite(ML_Ctrl, LOW); //The left motor direction control pin is in low level
  analogWrite(ML_PWM, 200); //The PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, LOW); //The right motor direction control pin is in low level
  analogWrite(MR_PWM, 200); //The PWM control speed of the right motor is 200
  //front
  delay(2000);//Delay in 2s
  digitalWrite(ML_Ctrl, HIGH); //The left motor direction control pin is in high level
  analogWrite(ML_PWM, 200); //The PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, HIGH); //The right motor direction control pin is in high level
  analogWrite(MR_PWM, 200); //The PWM control speed of the right motor is 200
  //back
  delay(2000);//Delay in 2s
  digitalWrite(ML_Ctrl, HIGH); //The left motor direction control pin is in high level
  analogWrite(ML_PWM, 200); //The PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, LOW); //The right motor direction control pin is in low level
  analogWrite(MR_PWM, 200); //The PWM control speed of the right motor is 200
  //left
  delay(2000);//Delay in 2s
  digitalWrite(ML_Ctrl, LOW); //The left motor direction control pin is in low level
  analogWrite(ML_PWM, 200); //The PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, HIGH); //The right motor direction control pin is in high level
  analogWrite(MR_PWM, 200); //The PWM control speed of the right motor is 200
  //right
  delay(2000);//Delay in 2s
  analogWrite(ML_PWM, 0); //The PWM control speed of the left motor is 0
  analogWrite(MR_PWM, 0); //The PWM control speed of the right motor is 0
  //stop
  delay(2000);//Delay in 2s
}
