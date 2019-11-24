#include <PWM.h>
int out_pin = 3;
char serial_data;
int32_t high_freq = 93000;
int32_t low_freq = 87000;

void send(int bit) {
  if(bit == 1) {
    SetPinFrequency(out_pin, high_freq);
  }
  else {
    SetPinFrequency(out_pin, low_freq);
  }
}

void setup()  {
  Serial.begin(9600);
  pinMode(out_pin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    serial_data = Serial.read();
    for(int i = 0; i < 8; i++) {
      int bit_to_send = serial_data && 1;
      send(bit_to_send);
      serial_data >> 1;
    }
  }
}
