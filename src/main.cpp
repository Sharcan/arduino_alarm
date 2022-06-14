/* Exemple d’esquisse pour contrôler un moteur pas à pas 28BYJ-48 avec carte pilote ULN2003 et Arduino UNO. Plus d’infos: https://www.makerguides.com */
// Inclut la bibliothèque Arduino Stepper.h:
#include <IRremote.hpp>
#include <Stepper.h>
#include <Arduino.h>
#define DECODE_NEC

const int RIGHT_COMMAND = 9;
const int LEFT_COMMAND = 7;
// Définit le nombre de pas par rotation:
const int stepsPerRevolution = 4000;

int ir = 2;

// Câblage:
// Broche 8 à IN1 sur le pilote ULN2003
// Broche 9 à IN2 sur le pilote ULN2003
// Broche 10 à IN3 sur le pilote ULN2003
// Broche 11 à IN4 sur le pilote ULN2003
// Créez un objet stepper appelé ‘myStepper’, notez l’ordre des broches:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void  setup()  {
  IrReceiver.begin(ir, ENABLE_LED_FEEDBACK);
  myStepper.setSpeed(5);
  Serial.begin(9600);
}

void getCommand() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command);

    if (IrReceiver.decodedIRData.command == RIGHT_COMMAND) {
      myStepper.step(50);
    } else if (IrReceiver.decodedIRData.command == LEFT_COMMAND) {
      myStepper.step(-50);
    }

    IrReceiver.resume();
  }
}

void loop()  {
  getCommand();
}