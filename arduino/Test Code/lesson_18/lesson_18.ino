/*
  keyestudio Mini Tank Robot V3
  lesson 18
  Fire extinguishing tank
  http://www.keyestudio.com
*/

int flame_L = A2; //define as the anlog port of the left flame sensor as A2
int flame_R = A1; //define as the anlog port of the right flame sensor as A1
//wire up the line tracking sensor
#define L_pin  11  //left
#define M_pin  7  //middle
#define R_pin  8  //right
//the pin of 130 motor
int INA = 12;
int INB = 13;
#define ML_Ctrl 4  //define the direction control pin of thel left motor
#define ML_PWM 5   //define the PWM control pin of the left motor
#define MR_Ctrl 2  //define the direction control pin of thel right motor
#define MR_PWM 6   //define the PWM control pin of the right motor
int L_val, M_val, R_val, flame_valL, flame_valR;

void setup()
{
  Serial.begin(9600);
  //set pins of the line tracking sensor to INPUT
  pinMode(L_pin, INPUT);
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  //define the buzzer as INPUT
  pinMode(flame_L, INPUT);
  pinMode(flame_R, INPUT);
  // define the motor as INPUT
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
  pinMode(INA, OUTPUT);//set INA to OUTPUT
  pinMode(INB, OUTPUT);//set INB to OUTPUT
}

void loop () {
  //read the analog value of the flame sensor
  flame_valL = analogRead(flame_L);
  flame_valR = analogRead(flame_R);
  Serial.print(flame_valL);
  Serial.print("  ");
  Serial.print(flame_valR);
  Serial.println("  ");
//  delay(500);
  if (flame_valL <= 700 || flame_valR <= 700) {
    Car_Stop();
    fan_begin();
  } else {
    fan_stop();
    L_val = digitalRead(L_pin); //read the value of thel left sensor 
    M_val = digitalRead(M_pin); //read the value of the middle one
    R_val = digitalRead(R_pin); //read the value of the right one
    
    if (M_val == 1) { //the middle one detects the black line
      if (L_val == 1 && R_val == 0) { //if only the left one detects the black line, turn left
        Car_left();
      }
      else if (L_val == 0 && R_val == 1) { //if only the right one detects black lines, turn right
        Car_right();
      }
      else { //or else, go front
        Car_front();
      }
    }
    else { //the middle one doesn't detect the black line
      if (L_val == 1 && R_val == 0) { //if only the left one detects the black line, turn left
        Car_left();
      }
      else if (L_val == 0 && R_val == 1) { //or else if only the right one detects the black line, turn right
        Car_right();
      }
      else { //or else, stop
        Car_Stop();
      }
    }
  }

}


void fan_stop() {
  //stop rotating
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
}

void fan_begin() {
  //enable the fan
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
}

void Car_front()
{
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 150);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 150);
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
  analogWrite(ML_PWM, 100);
}
void Car_right()
{
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 100);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 200);
}
void Car_Stop()
{
  digitalWrite(MR_Ctrl, HIGH);
  analogWrite(MR_PWM, 200);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 200);
  
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
}
