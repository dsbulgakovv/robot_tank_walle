/*
  keyestudio Mini Tank Robot V3
  lesson 1.1
  Blink
  http://www.keyestudio.com
*/
int LED = 9;  //Define the pin of LED to connect with digital port 9
void setup()
{
  pinMode(LED, OUTPUT); //Initialize the LED pin to output mode
}
void loop() //Form an infinite loop
{
  digitalWrite(LED, HIGH); //Output high level and turn on the LED 
  delay(1000);  //Wait for 1s
  digitalWrite(LED, LOW);  //Output low level and turn on LED
  delay(1000);  //Wait for 1s
}
