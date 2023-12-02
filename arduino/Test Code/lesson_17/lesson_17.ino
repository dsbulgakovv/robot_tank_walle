/*
  keyestudio Mini Tank Robot V3
  lesson 17
  Line track tank
  http://www.keyestudio.com
*/

//wire up the line tracking sensor
#define L_pin  11  //left
#define M_pin  7  //middle
#define R_pin  8  //right

#define ML_Ctrl 4  //define the direction control pins of thel left motor
#define ML_PWM 5   //define the PWM control pins of thel left motor
#define MR_Ctrl 2  //efine the direction control pin of the right sensor
#define MR_PWM 6   //define the PWM control pins of thel right motor
int L_val, M_val, R_val;
int speeds = 150;
void setup()
{
  Serial.begin(9600); //set baud rate to 9600
  pinMode(L_pin, INPUT); //set the pins of the line tracking sensor to INPUT
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
}

void loop () {
  L_val = digitalRead(L_pin); //read the value of the left one
  M_val = digitalRead(M_pin); //read the value of the middle one
  R_val = digitalRead(R_pin); //read the value of the right one
  if (M_val == 1) { //the middle one detects the black line
    if (L_val == 1 && R_val == 0) { //if only the left one detects the black line, turn left
      Car_left();
    }
    else if (L_val == 0 && R_val == 1) { //if only the right one detects black lines, turn right
      Car_right();
    }
    else { //or else go front
      Car_front();
    }
  }
  else { //the middle one doesn't detect black lines
    if (L_val == 1 && R_val == 0) { //if only the left one detects the black line, turn left
      Car_left();
    }
    else if (L_val == 0 && R_val == 1) { //or else if only the right one detects the black line, turn right
      Car_right();
    }
    else { //or else stop
      Car_Stop();
    }
  }
}

//go front
void Car_front()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 150);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 150);
}
//go back
void Car_back()
{
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 150);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 150);
}
//turn left
void Car_left()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 250);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 100);
}
//turn right
void Car_right()
{
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 100);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 250);
}
//stop
void Car_Stop()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
}
