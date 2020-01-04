#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 13;          //  The digital pin that the signal pin of the sensor is connected to
IRrecv receiver(RECV_PIN);  //  Create a new receiver object that would decode signals to key codes
decode_results results;     //  A varuable that would be used by receiver to put the key code into

void setup() {
  Serial.begin(9600);       //  Setup serial port to send key codes to computer
  receiver.enableIRIn();    //  Enable receiver so that it would start processing infrared signals
}

void loop() {
  if(receiver.decode(&results)) {             //  Decode the button code and put it in "results" variable
    Serial.println(results.value, HEX);       //  Print the code as a hexadecimal value
    receiver.resume();                        //  Continue listening for new signals
  }
}
