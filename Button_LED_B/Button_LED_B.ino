void setup() {
  pinMode(13, OUTPUT);      // pin 13 sends voltage to the LED circuit
  pinMode(2, INPUT_PULLUP);  // pin 2 reads the button: HIGH = not pressed , LOW = pressed
}

void loop() {
  if (digitalRead(2) == HIGH ) {     // if pin 2 reads button is high (not pressed), results in pin 13 voltage becoming high turning the LED on
    digitalWrite(13, HIGH);
} else {                            // if pin 2 reads button is low (pressed), pin 13's voltage will become low turning the LED off.   
    digitalWrite(13, LOW);
}

}
