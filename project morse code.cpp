int outPin = 8; // both LED and Buzzer
int dotLen = 200; // Base time unit in ms

void setup() {
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Transmitter Ready. Enter text:");
}

// Function to handle the actual flashing/beeping of the string
void playMorse(String seq) {
  for (int i = 0; i < seq.length(); i++) {
    digitalWrite(outPin, HIGH);
    
    // Check if it is a dot or a dash
    if (seq[i] == '.') {
      delay(dotLen);
    } else {
      delay(dotLen * 3); 
    }
    
    digitalWrite(outPin, LOW);
    delay(dotLen); // Standard gap between symbols of the same letter
  }
  delay(dotLen * 2); // Gap between different letters
}

void loop() {
  if (Serial.available() > 0) {
    String msg = Serial.readString();
    msg.toUpperCase(); // Force uppercase to match our cases
    
    Serial.print("Sending: ");
    Serial.println(msg);

    // Loop through every character the user typed
    for (int i = 0; i < msg.length(); i++) {
      char c = msg[i];
      
      // switch case for alphabets
      switch (c) {
        case 'A': playMorse(".-"); break;
        case 'B': playMorse("-..."); break;
        case 'C': playMorse("-.-."); break;
        case 'D': playMorse("-.."); break;
        case 'E': playMorse("."); break;
        case 'F': playMorse("..-."); break;
        case 'G': playMorse("--."); break;
        case 'H': playMorse("...."); break;
        case 'I': playMorse(".."); break;
        case 'J': playMorse(".---"); break;
        case 'K': playMorse("-.-"); break;
        case 'L': playMorse(".-.."); break;
        case 'M': playMorse("--"); break;
        case 'N': playMorse("-."); break;
        case 'O': playMorse("---"); break;
        case 'P': playMorse(".--."); break;
        case 'Q': playMorse("--.-"); break;
        case 'R': playMorse(".-."); break;
        case 'S': playMorse("..."); break;
        case 'T': playMorse("-"); break;
        case 'U': playMorse("..-"); break;
        case 'V': playMorse("...-"); break;
        case 'W': playMorse(".--"); break;
        case 'X': playMorse("-..-"); break;
        case 'Y': playMorse("-.--"); break;
        case 'Z': playMorse("--.."); break;
        
        // Handle spaces between words
        case ' ': delay(dotLen * 6); break; 
      }
    }
    Serial.println("Transmission Complete.");
  }
}
