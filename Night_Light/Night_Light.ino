const int sensorPin = A0; //Turns voltage into a number that can be read
const int ledPin = 13; //LED circuit comes from digital pin 13
const int onThreshold = 120; //anything below this level of brightness will turn the LED on
const int offThreshold = 150; //anything above this level of brightness will turn the LED off

void setup() {
  Serial.begin(9600); //Starts communication with the computer at 9600 bits per second.
  pinMode(ledPin, OUTPUT); // Sets pin 13 as an output
}

void loop() {
  int lightLevel = analogRead(sensorPin); //variable that reads and holds sensorPin as a number from 0-1023.
  Serial.println(lightLevel); //prints the light level so it can be seen how much light is hitting the photoresistor.

  if (lightLevel < onThreshold) { 
    digitalWrite(ledPin, HIGH); //sends out high voltage meaning that it is dark and turns LED on
  } else if (lightLevel > offThreshold){
    digitalWrite(ledPin, LOW); //sends out low/0 voltage meaning that it is not dark and turns LED off
  }
  //if lightLevel value is inbetween onThreshold and offThreshold, the LED will simply stay put and not change.

  delay(200); //takes 5 readings a second so its readable.

}
