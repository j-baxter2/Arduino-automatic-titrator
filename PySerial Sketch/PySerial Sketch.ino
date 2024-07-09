// Define channel for analogue output
int channeloutPWM = 10;  // digital output 10

// Declare variable for pulse width (to set the duty factor)
int pulseWidth = 128; // (pulse width in range 0-255 for duty factor from 0 to 100%)

// Initialisation routine
void setup() {
  // Set the PWM cycle frequency for pins D9 & D10 to 3921.16 Hz
  TCCR1B = TCCR1B & B11111000 | B00000010;  // comment this out to set the PWM cycle frequency to 490.2 Hz

  // Set initial values of outputs
  analogWrite(channeloutPWM,pulseWidth);  // set initial pulse width

  // Wait for serial port to connect
  Serial.begin(9600); 
  while (!Serial) {
    ; 
  }
}

// Now run continuously
void loop() {
  // If we get some input on the Serial Monitor...
  if (Serial.available() > 0) {
    // read the text that has been entered
    String Vgin = Serial.readStringUntil('\n');
    
    // If it is an integer...
    if (pulseWidth != Vgin.toInt()) {
      
      // ... set the gate PWM to the specified value
      pulseWidth = Vgin.toInt();

      // If the pulse width is too big...
      if (pulseWidth > 255) {

        // ...set it to the upper limit
        pulseWidth = 255;
      }

      // Write the pulse width to the output channel
      analogWrite(channeloutPWM, pulseWidth);
    }
  }
  
  delay(10);
  
}
