//pin names
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int alarmDistance = 50; //anything closer than 30cm triggers the alarm

void setup() {
  pinMode(trigPin, OUTPUT); //pings the sensor
  pinMode(echoPin, INPUT);  //sets echo as an input gotten from trigPin
  pinMode(buzzerPin, OUTPUT); //uses echoPin as an input to buzz
  Serial.begin(9600); // starts serial monitor to see distances

}

void loop() {
  //make sure trig starts off for a clean pulse/read
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //holds trig on for 10 microseconds to take measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW); // releases measurement and fires ping

  long duration = pulseIn(echoPin, HIGH); // measures how long echo stays at high in microseconds.
  int distance = duration * 0.034/2; //converts to cm since sound travels at 0.034cm per microsecond and /2 accounts for the round trip
  Serial.println(distance); //prints the distance in cm

  // makes buzzer continuously go
      if (distance > 0 && distance <= 5) {
    digitalWrite(buzzerPin, HIGH);
  }
  // makes buzzer beep. the closer it is, the more it beeps
  else if (distance > 5 && distance < alarmDistance) {
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    delay(distance * 3);
  }
  // if distance doesnt fit in the other if statements, turns buzzer off
  else {
    digitalWrite(buzzerPin, LOW);
  }
  
  // replays every 100ms
  delay(100);
  
}
