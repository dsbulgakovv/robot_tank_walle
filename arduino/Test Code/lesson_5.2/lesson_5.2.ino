/*
  keyestudio Mini Tank Robot V3
  lesson 5.2
  flame sensor
  http://www.keyestudio.com
*/
int flame = A1; //Define the flame pin as analog pin A1
int LED = 9;    //Define the LED as digital port 3
int val = 0;    //Define digital variables
void setup() {
  pinMode(flame, INPUT);    //Define the buzzer as an input source
  pinMode(LED, OUTPUT);     //Set LED to output mode
  Serial.begin(9600);    //Set the baud rate to 9600
}
void loop() {
  val = analogRead(flame); //Read the analog value of the flame sensor
  Serial.println(val);//Output analog value and print it
  if (val < 300) {  //When analog value is less than 300, LED is on
    digitalWrite(LED, HIGH);  //LED is on
  } else {
    digitalWrite(LED, LOW); //LED is off
  }
  delay(50); //Delay in 50ms
}
