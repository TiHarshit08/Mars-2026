int btn = 2; //position of button
int led = 13; //position of led

volatile bool hitFlag = false;
volatile unsigned long timeEnd = 0;

unsigned long timeStart = 0; 
unsigned long waitDelay = 0;
bool lightOn = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP); 

  Serial.begin(9600);
  randomSeed(analogRead(A0)); // need this so random is actually random
  
  // hook up the interrupt tripwire
  attachInterrupt(digitalPinToInterrupt(btn), catchPress, FALLING);
  
  resetGame();
}

void resetGame() {
  digitalWrite(led, LOW);
  lightOn = false;
  hitFlag = false; 
  
  waitDelay = random(2000, 6000); 
  timeStart = millis(); 
  Serial.println("Get Ready...");
}

// ISR triggered when button goes LOW
void catchPress() {
  // only care if the light is actually on and we haven't hit it yet
  if (lightOn && !hitFlag) { 
    timeEnd = millis();    
    hitFlag = true;   
  }
}

void loop() {
  // wait for the random delay to pop the LED
  if (!lightOn) {
    if (millis() - timeStart >= waitDelay) {
      digitalWrite(led, HIGH); 
      lightOn = true;             
      timeStart = millis(); // reset timer for the reaction speed
    }
  }
  // if LED is on and interrupt caught a press, calculate score
  else if (hitFlag) {
    unsigned long score = timeEnd - timeStart;
    
    Serial.print("Reaction: ");
    Serial.print(score);
    Serial.println(" ms");

    delay(2000); 
    Serial.println("---");
    resetGame();
  }
}
