#include<Servo.h>
// #include <Firebase_ESP_Client.h>
// #include "addons/TokenHelper.h"
// #include "addons/RTDBHelper.h"
// #include <ESP8266WiFi.h>

Servo servo;
int const trigPin = 6;
int const echoPin = 5;
int const trigPin1 = 12;
int const echoPin1 = 11;
int const buzzerPin = 7;
// #define FIREBASE_HOST "xxxxxxxxxxxxxxxxxxxxxxx"
// #define API_KEY "xxxxxxxxxxxxxxxxxxxxxxxxxx"
// #define WIFI_SSID "xxxxxxxxxxxxx"
// #define WIFI_PASSWORD "xxxxxxxxxxx"
// #define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxx"

// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// unsigned long sendDataPrevMillis = 0;
// int ldrData = 0;
// bool signupOK = false;


void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(buzzerPin, OUTPUT); 
servo.attach(3);
// Serial.begin(9600);
// WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
// Serial.print("Connecting to Wi-Fi");
// while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(1000);
//   }
//   Serial.println();
//   Serial.println("Connected to Wi-Fi");
//   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;
//   if(Firebase.signUp(&config, &auth, "", "")){
//   Serial.println("signup successful");
//   signupOK = true;
//   }
//   else{
//     Serial.println("signup failed");
//   }

// config.token_status_callback = tokenStatusCallback;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);  
}
void loop()
{ 
  Serial.begin(9600);
  digitalWrite(trigPin, LOW); 
  int duration, distance, distance1, duration1;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
  if (distance <= 15 && distance >= 0) {
  servo.write(170);
  delay(10);
  } 
  else {
	
	  servo.write(100);
  }
  // Waiting 60 ms won't hurt any one
  delay(60);
  Serial.println(distance);

  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin1, HIGH); 
  delay(1);
  digitalWrite(trigPin1, LOW);
  // Measure the pulse input in echo pin
  duration1 = pulseIn(echoPin1, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance1 = (duration1/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
  if (distance1 <= 3 && distance1 >= 0 && distance>15) {
  	digitalWrite(buzzerPin, HIGH);
    Serial.println("buzzer in");
      delay(100);
      digitalWrite(buzzerPin, LOW);
      delay(50);
  } 
  Serial.print("distance1: ");
  Serial.println(distance1);
  // if(Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 5000  || sendDataPrevMillis == 0)){
  //   // sendDataPrevMillis = millis();
  //   // Firebase.set("Peelamedu", distance1);
  //   // if(Firebase.RTDB.setInt(&fbdo, "Peelamedu", distance1)){
  //   //   Serial.println("successfully added to the database");
  //   // }
  //   // else{
  //   //   Serial.println("failed to add to database");
  //   // }
  // }

    delay(60);
  }
