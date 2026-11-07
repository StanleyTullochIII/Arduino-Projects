bool ledOn = false;         //Remembers if the LED is on (true) or off (false). starts off.
const int ledPin = 13;      //LED pin
const int buttonPin = 2;    //Button pin
void setup() {
  pinMode(ledPin, OUTPUT);      //Sets pin 13 as an output to send voltage to the LED
  pinMode(buttonPin, INPUT_PULLUP); //Sets pin 2 as an input that reads the button
}

void loop() {
  //If button is pressed, LED status flips (on or off)
  if(digitalRead(buttonPin) == LOW) {
    ledOn = !ledOn;
    digitalWrite(ledPin, ledOn); //Outputs ledOn through LED circuit

    //Code waits until button is released
    while(digitalRead(buttonPin) == LOW) {
    }
    delay(50); // debounce
  }
}
