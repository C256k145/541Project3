int recv_pin = 8;
void setup() {
 Serial.begin(9600);
}

void loop() {
  delay(100);
  int signal = digitalRead(recv_pin);
  Serial.println(signal);
}
