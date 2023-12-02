/*
  keyestudio Mini Tank Robot V3
  lesson 4.2
  Line Track sensor
  http://www.keyestudio.com
*/
//LED pin
#define LED 9
//The wiring of line tracking sensors
#define L_pin  11  //for the sensor in the left
#define M_pin  7  //for the sensor in the middle
#define R_pin  8  //for the sensor in the right

void setup(){
  Serial.begin(9600);    //Set the baud rate to 9600
  pinMode(LED, OUTPUT);  //Set LED to output mode
  pinMode(L_pin, INPUT); //Set all pins of the line tracking sensors to input mode
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
}

void loop (){
  int L_val = digitalRead(L_pin); //Read the value of the left sensor
  int M_val = digitalRead(M_pin); //Read the value of the middle sensor
  int R_val = digitalRead(R_pin); //Read the value of the right sensor
  Serial.print(L_val);
  Serial.print("  ");
  Serial.print(M_val);
  Serial.print("  ");
  Serial.print(R_val);
  Serial.println("  ");
  delay(100); //Delay in 100ms
  if (L_val == 0 || M_val == 0 || R_val == 0) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
