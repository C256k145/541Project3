int recv_pin = 0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  int signal = analogRead(recv_pin);
  Serial.println(signal);
}
