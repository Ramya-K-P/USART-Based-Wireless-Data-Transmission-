#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);
const int trigPin = 9;
const int echoPin = 8;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  BTSerial.print("Distance: ");
  BTSerial.print(distance);
  BTSerial.println(" cm");

  delay(1000);
}
