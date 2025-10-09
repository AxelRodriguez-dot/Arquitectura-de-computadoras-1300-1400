int ledPin = LED_BUILTIN;
int dotDuration = 400;
int dashDuration = dotDuration * 3; 
int letterGap = dotDuration * 5; 
int wordGap = dotDuration * 6;
int brillo=0;


void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW); 
  delay(dotDuration); 
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void setup() {
  
  pinMode(ledPin, OUTPUT);
}

void loop() {

  dot();
  dot();
  dot();

  delay(letterGap);

  dash();
  dash();
  dash();

  delay(letterGap);

  dot();
  dot();
  dot();
  
  delay(wordGap);
  for (int i=0;i<8;i++){
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(100);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(100);  }
  
  dot();
  dot();
  dot();

  delay(letterGap);

  dash();
  dash();
  dash();

  delay(letterGap);

  dot();
  dot();
  dot();
  delay(wordGap);
for (int i=0;i<8;i++){
 for (brillo=0;brillo<=255;brillo++){
  analogWrite(LED_BUILTIN,brillo);
delay(10);
}
for (brillo=255;brillo>=0;brillo--){
analogWrite(LED_BUILTIN,brillo);
delay(10);
}
 } 
}