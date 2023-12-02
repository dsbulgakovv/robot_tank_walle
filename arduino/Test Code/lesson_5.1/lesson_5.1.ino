/*
  keyestudio Mini Tank Robot V3
  lesson 5.1
  flame sensor
  http://www.keyestudio.com
*/
int flame = A1; //Define the flame pin as analog pin A1

int val = 0; //Define digital variables
void setup() {
  pinMode(flame, INPUT); //Define the buzzer as an input source
  Serial.begin(9600);    //Set the baud rate to 9600
}
void loop() {
  val = analogRead(flame); //Read the analog value of the flame sensor
  Serial.println(val);//Output analog value and print it
  delay(100); //Delay in 100ms
}
