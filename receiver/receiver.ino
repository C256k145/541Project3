#include <FreqCount.h>

void setup() {
  Serial.begin(9600);
  FreqCount.begin(1000);
}

void loop() {
  if (FreqCount.available()) {
    unsigned long count = FreqCount.read();
    Serial.println(count);
  }
}

//void retrieve() {
//  for(int i = 0; i < 8; i++) {
//    delay(10);
//    signal = digitalRead(recv_pin);
//    value = value >> 1;
//    bitWrite(value, 7, signal);
//  }
//  Serial.print(value);
//}
