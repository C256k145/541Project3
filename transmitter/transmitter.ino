#include "PWM.h"
int led = 3;
int pw = 127; //Pulse Width
int32_t frequency = 90000;
bool success;
String serial_data = "";
int data_length = 0;
float delay_amt = 10;

void setup() 
{
  Serial.begin(9600);
  InitTimersSafe();
  bool success = SetPinFrequencySafe(led, 90000);
  if(success) 
  {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
  }
  pwmWrite(led, pw);
}

void loop() 
{
    serial_data = Serial.readString();
    data_length = serial_data.length();
    for(int j=0; j<data_length-1; j++)
    {
      send(serial_data[j]);
      Serial.println(serial_data[j]);
      SetPinFrequency(led, 90000);
      delay(10);
    }
}

void send(char character)
{
  for(int i=7; i>-1; i--)
  {
    if((character >> i) & 1)
    {
      SetPinFrequency(led, 93000);
      Serial.print(1);
    }
    else
    {
      SetPinFrequency(led, 87000);
      Serial.print(0);
    }
    delay(delay_amt);
  }
}
