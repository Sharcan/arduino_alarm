// /* Exemple d’esquisse pour contrôler un moteur pas à pas 28BYJ-48 avec carte pilote ULN2003 et Arduino UNO. Plus d’infos: https://www.makerguides.com */
// // Inclut la bibliothèque Arduino Stepper.h:
// #include <Stepper.h>
// #include <Arduino.h>

// // Joystick commands
// #define MIN_VAL 0
// #define MAX_VAL 1023

// // Définit le nombre de pas par rotation:
// const int stepsPerRevolution = 4000;

// // Câblage:
// // Broche 8 à IN1 sur le pilote ULN2003
// // Broche 9 à IN2 sur le pilote ULN2003
// // Broche 10 à IN3 sur le pilote ULN2003
// // Broche 11 à IN4 sur le pilote ULN2003
// // Créez un objet stepper appelé ‘myStepper’, notez l’ordre des broches:
// Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

// // Joystick parameters
// const int xAxis = A0;
// const int yAxis = A1;
// const int joyBtn  = 2;
// const int joyOffset  = 0;

// void  setup()  {
//   Serial.begin(9600);

//   // Réglez la vitesse sur 5 tr / min:
//   myStepper.setSpeed(5);

//   // Init joystick
//   pinMode(xAxis, INPUT);
//   pinMode(yAxis, INPUT);
// }

// float joyRawToPhys(int raw) {
//   // Joystick conversion rule
//   float phys = map(raw, MIN_VAL, MAX_VAL, -100 + joyOffset, 100 + joyOffset) - joyOffset; 

//   return phys;
// }

// void readJoystick() {
//   // Get joystick values (base 526 -3.00)
//   int xVal = joyRawToPhys(analogRead(xAxis));
//   int yVal = joyRawToPhys(analogRead(yAxis));

//   // Set to motor
//   if(xVal >= 10 || xVal <= -10) {
//     myStepper.step(xVal);
//   } else {
//     myStepper.step(0);
//   }

//   // Print
//   Serial.print(F("X")); Serial.print(F(" : ")); Serial.println(xVal);
//   Serial.print(F("Y")), Serial.print(F(" : ")); Serial.println(yVal);
//   if (!digitalRead(joyBtn)) {
//     Serial.println(F("Joy Button pressed"));
//   }
// }

// void loop()  {
//   readJoystick();
//   delay(50);

//   // Étape d’une révolution dans une direction:
//   // Serial.println( "Dans le sens d'une aiguille d'une montre");
//   // myStepper.step( stepsPerRevolution );

//   // // Étape d’une révolution dans l’autre sens:
//   // Serial.println("Sens inverse");
//   // myStepper.step(-stepsPerRevolution); 
// }