int input_pin = A5; //Analogread should be fast enough here
float input_val;
char output;
bool flag = false;

float center_freq_val;
float high_freq_val;
float low_freq_val;
float delay_amt = 10;

void setup() {
  Serial.begin(9600);
  pinMode(input_pin, INPUT);
}

void loop() {
  if(flag == false) {
    center_freq_val = calibrate(); //calibrates
    high_freq_val = 1.05*center_freq_val;
    low_freq_val = 0.95*center_freq_val;
    flag = true;
  }
  float test_val = measure();
  if(test_val > high_freq_val || test_val < low_freq_val) {
    retrieve();
  }
  output = NULL;
}

float measure() {
  float return_val = 0;
  for(int i = 0; i < 10; i++) {
    return_val += analogRead(input_pin);
  }
  return(return_val/10.0);
}

void retrieve() {
  for(int i = 7; i >= 0; i--) {
    float test = measure();
    int bit_to_write = determineBit(test);
    bitWrite(output, i, bit_to_write);
    delay(delay_amt);
  }
  Serial.print(output);
}

int determineBit(float val) {
  if(val > high_freq_val) {
    return(1);
  }
  else if(val < low_freq_val) {
    return(0);
  }
  return(NULL);
}

float calibrate() {
  float val = 0.0;
  for(int i = 0; i < 10; i++) {
    val += measure();
  }
  return(val/10.0);
}
