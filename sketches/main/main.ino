#include "display.h"
#include "vibrator.h"
#include "classifier.h"

#define SERIAL_PORT 115200

Display* screen;
Vibrator* vibrator;
Classifier* classifier;

void setup() {
  Serial.begin(SERIAL_PORT);
  screen = new Display();
  vibrator = new Vibrator();
  classifier = new Classifier();
}

void loop() {
  screen->loop();
  vibrator->loop();
  classifier->loop();

  if (classifier->isBabyCrying()) {
    screen->transitionToBabyCrying();
  }

  if (classifier->isSiren()) {
    screen->transitionToSiren();
  }

  if (classifier->isPhone()) {
    screen->transitionToPhone();
  }

  if (!classifier->isUnknown()) {
    vibrator->transitionToVibrate();
  }
}
