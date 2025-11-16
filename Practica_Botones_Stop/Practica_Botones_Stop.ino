int ledPin = LED_BUILTIN;
int dotDuration = 400;
int dashDuration = dotDuration * 3; 
int letterGap = dotDuration * 5;
int brillo = 0;

int buttonSOS = 9;
int buttonBlink = 8;
int buttonPulse = 10;
int buttonStop = 11;

bool stopPressed = false;

void smartDelay(int t) {
  for (int i = 0; i < t; i++) {
    if (digitalRead(buttonStop) == LOW) {
      stopPressed = true;
      digitalWrite(ledPin, LOW);
      return;
    }
    delay(1);
  }
}


void dot() {
  digitalWrite(ledPin, HIGH);
  smartDelay(dotDuration);
  digitalWrite(ledPin, LOW);
  smartDelay(dotDuration);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  smartDelay(dashDuration);
  digitalWrite(ledPin, LOW);
  smartDelay(dotDuration);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonSOS, INPUT_PULLUP);
  pinMode(buttonBlink, INPUT_PULLUP);
  pinMode(buttonPulse, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(buttonStop) == LOW) {
    stopPressed = true;
    digitalWrite(ledPin, LOW);
    return;
  }
  stopPressed = false;

  if (digitalRead(buttonSOS) == LOW) {
    for (int i = 0; i < 3 && !stopPressed; i++) dot();
    for (int i = 0; i < 3 && !stopPressed; i++) dash();
    for (int i = 0; i < 3 && !stopPressed; i++) dot();
  }

  if (digitalRead(buttonBlink) == LOW) {
    for (int i = 0; i < 8 && !stopPressed; i++) {
      digitalWrite(ledPin, HIGH);
      smartDelay(200);
      digitalWrite(ledPin, LOW);
      smartDelay(200);
    }
  }

  if (digitalRead(buttonPulse) == LOW) {
    for (int rep = 0; rep < 8 && !stopPressed; rep++) {

      for (brillo = 0; brillo <= 255 && !stopPressed; brillo++) {
        analogWrite(ledPin, brillo);
        smartDelay(5);
      }

      for (brillo = 255; brillo >= 0 && !stopPressed; brillo--) {
        analogWrite(ledPin, brillo);
        smartDelay(5);
      }

    }
  }
}
