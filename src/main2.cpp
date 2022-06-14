// #include <Arduino.h>

// const int trigPin = 3;
// const int echoPin = 2;
// const int led = 5;
// // defines variables
// long duration;
// int distance;

// // Functions
// void turnOnLight() {
//   Serial.print("hahahahahah: ");
//   digitalWrite(led, HIGH);
// }

// void turnOfLight() {
//   Serial.print("hohohoh: ");
//   digitalWrite(led, LOW);
// }

// void setup() {
//   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
//   pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//   pinMode(led, OUTPUT);
//   Serial.begin(9600); // Starts the serial communication
// }

// void loop() {
//   // Clears the trigPin
//   digitalWrite(trigPin, LOW);
//   delay(2000);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(trigPin, HIGH);
//   //delay(1000);
//   digitalWrite(trigPin, LOW);
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(echoPin, HIGH);
//   // Calculating the distance
//   distance = duration * 0.034 / 2;
//   // Prints the distance on the Serial Monitor
//   Serial.print("Distance: ");
//   Serial.println(distance);

//   if (distance < 100) {
//     turnOnLight();
//   } else {
//     turnOfLight();
//   }
  
// }