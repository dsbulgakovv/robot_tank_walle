/*
  keyestudio Mini Tank Robot V3
  lesson 9.2
  IRremote
  http://www.keyestudio.com
*/
#include <IRremote.h>     //IRremote library statement
int RECV_PIN = 3;        //define the pin of the IR receiver as 3
int LED = 9;
bool flag = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;   //
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);// set pins of LED as OUTPUT
  irrecv.enableIRIn();    //enable the receiver
}
void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0xFF02FD & flag == 0) //if OK key is pressed
    {
      digitalWrite(LED, HIGH); //LED is off
      flag = 1;
    }
    else if (results.value == 0xFF02FD & flag == 1) //press again
    {
      digitalWrite(LED, LOW); //LED is off
      flag = 0;
    }
    irrecv.resume(); // receive next value
  }
}
