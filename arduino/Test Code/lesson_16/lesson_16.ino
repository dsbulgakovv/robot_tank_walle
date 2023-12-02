/*
  keyestudio Mini Tank Robot V3
  lesson 16
  draw a circle for tank
  http://www.keyestudio.com
*/

//wire up the line tracking sensor
#define L_pin  11  //left
#define M_pin  7  //middle
#define R_pin  8  //right

#define ML_Ctrl 4  //define the direction control pin of thel left motor
#define ML_PWM 5   //define the PWM control pins of the left motor
#define MR_Ctrl 2  //define the direction control pin of thel right motor
#define MR_PWM 6   //define the PWM control pin of the right motor
int L_val, M_val, R_val;

void setup()
{
  Serial.begin(9600); //9600 set baud rate to 9600
  pinMode(L_pin, INPUT); //set pins of the line tracking sensor to INPUT
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}

void loop () {
  L_val = digitalRead(L_pin); //read the value of thel left sensor
  M_val = digitalRead(M_pin); //read the value of the middle one
  R_val = digitalRead(R_pin); //read the value of the right one
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //if no black lines are detected, go front
    Car_front();
  }
  else { // or else, go back and turn left
    Car_back();
    delay(700);
    Car_left();
    delay(800);
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
