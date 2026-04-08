//  Arrays to hold the data for all 3 LEDs in lists
const int ledPin[] = {13, 12, 11};   
const long intervals[] = {500, 1000, 1500}; 
int ledStates[] = {LOW, LOW, LOW};          
unsigned long previousMillis[] = {0, 0, 0}; 

const int numLeds = 3; 

void setup() {
  //  Loop through the array to set all pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  //  Loop through the logic for each LED, one by one
  for (int i = 0; i < numLeds; i++) {
    
    // Check if enough time has passed for this specific LED (LED 'i')
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      
      // Save the current time
      previousMillis[i] = currentMillis; 

      // Toggle the state
      if (ledStates[i] == LOW) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      }
      
      // Apply the new state to the correct pin
      digitalWrite(ledPin[i], ledStates[i]); 
    }
  }
}
