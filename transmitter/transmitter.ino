int out_pin = 3;
void setup() 
{
  Serial.begin(9600);
  pinMode(out_pin, OUTPUT);
}

void loop() 
{
  if(Serial.available() > 0) 
  {
    delay(10);
    char serial_data = Serial.read();
    send('k');
    send(serial_data);
  }
}

void send(char character)
{
  for(int i=0; i<8; i++)
  {
    delay(1);
    if((character >> i) & 1)
    {
      digitalWrite(out_pin, HIGH);
    }
    else
    {
      digitalWrite(out_pin, LOW);
    }
  }
}
