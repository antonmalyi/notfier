#include "display.h"
#include "WiFiClient.h"

const int buzz = 0;
const String messages[] = {"BHU3!","TIMYR","EPIK","BOPOTA"};
void setup() {
  Serial.begin(115200);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
  if(!(displaySetup() && wifiSetup())){
    digitalWrite(buzz, HIGH);
    for(;;){}
  }
}
byte x=0;
void loop() {
  httpResp resp = wifiGetData();
  if(resp.status) {
    if(resp.result<sizeof(messages)){
      displayPrint(messages[resp.result]);
    }
    for(byte i = 0; i<5; i++) {
      digitalWrite(buzz, HIGH);
      delay(1000);
      digitalWrite(buzz, LOW);
      delay(2000);
    }
    delay(30000);
    displayPrint("");
  }
  else {
    delay(19000);
    displayPrint(".", x * 10);
    delay(1000);
    displayPrint("");
    x+=1;
    if(x>10){
      x=0;
    }
  }
}
