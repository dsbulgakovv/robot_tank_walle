/*
  keyestudio Mini Tank Robot V3
  lesson 6.1
  130 motor
  http://www.keyestudio.com
*/
int INA = 12;
int INB = 13;
void setup() {
  pinMode(INA, OUTPUT);//Set digital port INA as output
  pinMode(INB, OUTPUT);//Set digital port INA as output
}
void loop() {
  //Set the fan to rotate anticlockwise for 3s
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
  delay(3000);
  //Set the fan to stop for 1s
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(1000);
  //Set the fan to rotate clockwise for 3s
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
  delay(3000);
}
//*****************************************
