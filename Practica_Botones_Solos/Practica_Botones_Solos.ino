int ledPin = LED_BUILTIN;

int dotDuration = 400;
int dashDuration = dotDuration * 3;
int brillo = 0;

int buttonSOS = 9;
int buttonBlink = 8;
int buttonPulse = 10;

void delaySafe(int t) {
  delay(t);
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delaySafe(dotDuration);
  digitalWrite(ledPin, LOW);
  delaySafe(dotDuration);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delaySafe(dashDuration);
  digitalWrite(ledPin, LOW);
  delaySafe(dotDuration);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonSOS, INPUT_PULLUP);
  pinMode(buttonBlink, INPUT_PULLUP);
  pinMode(buttonPulse, INPUT_PULLUP);
}

void loop() {

  // --- SOS ---
  if (digitalRead(buttonSOS) == LOW) {
    for (int i = 0; i < 3; i++) dot();
    for (int i = 0; i < 3; i++) dash();
    for (int i = 0; i < 3; i++) dot();
  }

  // --- BLINK ---
  if (digitalRead(buttonBlink) == LOW) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(ledPin, HIGH);
      delaySafe(200);
      digitalWrite(ledPin, LOW);
      delaySafe(200);
    }
  }

  // --- PULSE ---
  if (digitalRead(buttonPulse) == LOW) {
    for (int rep = 0; rep < 8; rep++) {

      for (brillo = 0; brillo <= 255; brillo++) {
        analogWrite(ledPin, brillo);
        delaySafe(5);
      }

      for (brillo = 255; brillo >= 0; brillo--) {
        analogWrite(ledPin, brillo);
        delaySafe(5);
      }

    }
  }
}
