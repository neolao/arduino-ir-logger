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
  if (receiver.decode(&results)) {
    Serial.print("Type: ");
    switch (results.decode_type) {
      case NEC:
        Serial.print("NEC");
        break;
      case SONY:
        Serial.print("SONY");
        break;
      case RC5:
        Serial.print("RC5");
        break;
      case RC6:
        Serial.print("RC6");
        break;
      default:
        Serial.print("Unknown");
    }
    Serial.print(", Value: ");
    Serial.print(results.value, HEX);
    Serial.print(", Bits: ");
    Serial.print(results.bits);
    Serial.println();
    receiver.resume();
  }
}
