int recv_pin = 2;
int signal = 0;
char value = 0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  delay(10);
  signal = digitalRead(recv_pin);
  value = value >> 1;
  bitWrite(value, 7, signal);
//  Serial.println(value);
  if(value == 'k') {
    retrieve();
  }
}

void retrieve() {
  for(int i = 0; i < 8; i++) {
    delay(10);
    signal = digitalRead(recv_pin);
    value = value >> 1;
    bitWrite(value, 7, signal);
  }
  Serial.print(value);
}
