int input_pin = A3; //Analogread should be fast enough here
float input_val;
char output;

/*These values specify the range of analog values we should expect to see from the input pin,
everything in between this values is treated as null*/
float high_freq_val; //If analogread() returns higher than this value, we read a '1'
float low_freq_val; //If analogread() returns low than this value, we read a '0'

void setup() {
  Serial.begin(9600);
  pinMode(input_pin, INPUT);
}

void loop() {
  input_val = analogRead(input_pin);
  if(input_val > high_freq_val || input_val < low_freq_val) {
    retrieve(input_val); 
  }
}

void retrieve(float start_val) {
  if(start_val > high_freq_val) {
    bitWrite(output, 0, 1);
  }
  else {
    bitWrite(output, 0, 0);
  }
  for(int i = 1; i < 8; i ++) {
    input_val = analogRead(input_pin);
    if(input_val > high_freq_val) {
      bitWrite(output, i, 1);
    }
    else {
      bitWrite(output, 0, 0);
    }
  }
  Serial.println(output);
}
