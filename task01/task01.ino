#define ledPin1 11
#define ledPin2 10
#define ledPin3 9
#define ledPin4 6
#define ledPin5 5
#define ledPin6 3
 
// For each
// 450ms / 75ms / 5ms / 750mcs / 75mcs

#define cnt 5 
long leds[cnt][4];
 
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
 
  leds[0][0] = ledPin1;
  leds[1][0] = ledPin2; 
  leds[2][0] = ledPin3;
  leds[3][0] = ledPin4;
  leds[4][0] = ledPin5;
 
  for(int i = 0; i<cnt; ++i){
    leds[i][1] = LOW;
    leds[i][2] = 0;
  }
  
  leds[0][3] = 450 * 1000;
  leds[1][3] = 75 * 1000; 
  leds[2][3] = 5 * 1000;
  leds[3][3] = 750 * 1000;
  leds[4][3] = 75 * 1000;
}
 
void loop() {
  long current = micros();
  for(int i = 0; i < cnt; ++i){
      if(current - leds[i][2] > leds[i][3]){
      if(leds[i][1] == HIGH){
        leds[i][1] = LOW;
      } else{
        leds[i][1] = HIGH;
      }
      leds[i][2] = current;
    }
    digitalWrite(leds[i][0], leds[i][1]);
  }
}
