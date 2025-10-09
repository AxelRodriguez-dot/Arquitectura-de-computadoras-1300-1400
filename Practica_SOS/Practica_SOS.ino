int ledPin = LED_BUILTIN;
int dotDuration = 400;
int dashDuration = dotDuration * 3; 
int letterGap = dotDuration * 5; 
int wordGap = dotDuration * 6;

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

}
