#include <Servo.h>

Servo servo;

const int trigPin = 6;
const int echoPin = 5;
const int trigPin1 = 12;
const int echoPin1 = 11;
const int buzzerPin = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  servo.attach(3);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  digitalWrite(trigPin, LOW);
  int duration, distance, distance1, duration1;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance <= 10 && distance >= 0) {
    servo.write(160);
    delay(10);
  } else {
    servo.write(50);
  }
  delay(60);
  Serial.println(distance);

  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin1, HIGH);
  delay(1);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;
  if (distance1 <= 10 && distance >= 10) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("buzzer in"); // Send the buzzer message to the serial port
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(50);
  }
  Serial.print("distance1: ");
  Serial.println(distance1);

  delay(1000);
}
