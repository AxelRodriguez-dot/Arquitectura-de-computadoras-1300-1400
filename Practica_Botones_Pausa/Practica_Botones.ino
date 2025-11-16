int ledPin = LED_BUILTIN; 

int dotDuration = 400;
int dashDuration = dotDuration * 3;
int letterGap = dotDuration * 5;

int brillo = 0;

int buttonSOS = 8;
int buttonBlink = 9;
int buttonPulse = 10;
int buttonStop = 11;
int buttonPause = 12;

int currentMode = 0;
bool paused = false;
int pausedMode = 0;

int sosStep = 0;
int blinkStep = 0;

int pulseStep = 0;
int pulseDir = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonSOS, INPUT_PULLUP);
  pinMode(buttonBlink, INPUT_PULLUP);
  pinMode(buttonPulse, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
  pinMode(buttonPause, INPUT_PULLUP);
}

void checkButtons() {

  if (digitalRead(buttonStop) == LOW) {
    currentMode = 0;
    paused = false;
    sosStep = 0;
    blinkStep = 0;
    pulseStep = 0;
    pulseDir = 1;
    digitalWrite(ledPin, LOW);
  }

  if (digitalRead(buttonPause) == LOW) {
    if (!paused) {
      paused = true;
      pausedMode = currentMode;
    } else {
      paused = false;
      currentMode = pausedMode;
    }
    delay(250);
  }

  if (digitalRead(buttonSOS) == LOW) {
    if (currentMode == 1) {
      sosStep = 0;
    } else {
      currentMode = 1;
      sosStep = 0;
      blinkStep = 0;
      pulseStep = 0;
      pulseDir = 1;
    }
    delay(200);
  }

  if (digitalRead(buttonBlink) == LOW) {
    if (currentMode == 2) {
      blinkStep = 0;
    } else {
      currentMode = 2;
      sosStep = 0;
      blinkStep = 0;
      pulseStep = 0;
      pulseDir = 1;
    }
    delay(200);
  }

  if (digitalRead(buttonPulse) == LOW) {
    if (currentMode == 3) {
      pulseStep = 0;
      pulseDir = 1;
    } else {
      currentMode = 3;
      sosStep = 0;
      blinkStep = 0;
      pulseStep = 0;
      pulseDir = 1;
    }
    delay(200);
  }
}

void safeDelay(int t) {
  for (int i = 0; i < t; i += 10) {
    checkButtons();

    if (paused && currentMode == pausedMode) return;
    if (currentMode == 0) return;

    delay(10);
  }
}

void loop() {

  checkButtons();
  if (currentMode == 0) return;
  if (paused && currentMode == pausedMode) return;

  switch(currentMode) {

    case 1:
      switch(sosStep) {
        case 0: digitalWrite(ledPin, HIGH); safeDelay(dotDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 1: digitalWrite(ledPin, HIGH); safeDelay(dotDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 2: digitalWrite(ledPin, HIGH); safeDelay(dotDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 3: safeDelay(letterGap); sosStep++; break;
        case 4: digitalWrite(ledPin, HIGH); safeDelay(dashDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 5: digitalWrite(ledPin, HIGH); safeDelay(dashDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 6: digitalWrite(ledPin, HIGH); safeDelay(dashDuration); digitalWrite(ledPin, LOW); safeDelay(dotDuration); sosStep++; break;
        case 7: safeDelay(letterGap); sosStep = 0; break;
      }
      break;

    case 2:
      if (blinkStep % 2 == 0) digitalWrite(ledPin, HIGH);
      else digitalWrite(ledPin, LOW);
      safeDelay(300);
      blinkStep++;
      break;

    case 3: 
      analogWrite(ledPin, pulseStep);

      pulseStep += pulseDir;

      if (pulseStep >= 255) pulseDir = -1;
      if (pulseStep <= 0) pulseDir = 1;

      safeDelay(10);
      break;
  }
}
