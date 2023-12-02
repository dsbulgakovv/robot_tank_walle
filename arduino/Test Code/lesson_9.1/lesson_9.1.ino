/*
  keyestudio Mini Tank Robot V3
  lesson 9.1
  IRremote
  http://www.keyestudio.com
*/
#include <IRremote.h>     //IRremote library statement
int RECV_PIN = 3;        //define the pin of IR receiver as 3
IRrecv irrecv(RECV_PIN);
decode_results results;   //decoding results are saved in the result
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();    //enable the IR receiver
}
void loop() {
  if (irrecv.decode(&results))//decode successfully, and receive a group of IR signals
  {
    Serial.println(results.value, HEX);//outptut and receive code in 16 hexadecimal
    irrecv.resume(); //receive next value
  }
  delay(100);
}
