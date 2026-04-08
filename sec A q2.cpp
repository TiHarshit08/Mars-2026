int pot = A0;  //potentiometer middle pin
int blinkLed = 13;

// PWM pins for RGB
int rPin = 11;
int gPin = 10;
int bPin = 9;

unsigned long lastTime = 0;
bool ledOn = false;

void setup() {
  pinMode(blinkLed, OUTPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  int val = analogRead(pot); 

  //Blinking Speed
  long delayTime = map(val, 0, 1023, 50, 1000);

  if (millis() - lastTime >= delayTime) {
    lastTime = millis();
    ledOn = !ledOn; // Flips true to false, or false to true automatically
    digitalWrite(blinkLed, ledOn);
  }

  //RGB Fading
  int r = 0, g = 0, b = 0;

  //Split the 1023 range into thirds for smooth color blending
  if (val < 341) {
    r = 255 - map(val, 0, 341, 0, 255);
    g = map(val, 0, 341, 0, 255);
  } else if (val < 682) {
    g = 255 - map(val, 341, 682, 0, 255);
    b = map(val, 341, 682, 0, 255);
  } else {
    b = 255 - map(val, 682, 1023, 0, 255);
    r = map(val, 682, 1023, 0, 255);
  }

  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
}
