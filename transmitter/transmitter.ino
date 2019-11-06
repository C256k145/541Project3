int out_pin = 8;
void setup() {
  Serial.begin(19200);
  pinMode(out_pin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    char serial_data = Serial.read();
    switch(serial_data) {
      case 'd':
        digitalWrite(out_pin, HIGH);
        Serial.println("high");
        break;
      case 'a':
        digitalWrite(out_pin, LOW);
        Serial.println("low");
        break;
    }
  }
}
