/*
  keyestudio Mini Tank Robot V3
  lesson 6.2
  130 motor
  http://www.keyestudio.com
*/
int INA = 12;
int INB = 13;
int flame = A2; //Define the flame pin as analog pin A2
int val = 0;    //Define digital variables
void setup() {
  pinMode(INA, OUTPUT);//Set digital port INA as output
  pinMode(INB, OUTPUT);//Set digital port INA as output
  pinMode(flame, INPUT); //Define the buzzer as an input source
}

void loop() {
  val = analogRead(flame); //Read the analog value of the flame sensor
  if (val <= 700) {  //When analog value is less than 700, LED is on
    //Turn on the fan when flame is detected
    digitalWrite(INA, LOW);
    digitalWrite(INB, HIGH);
  } else {
    //Otherwise it stops operating
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
  }
}
