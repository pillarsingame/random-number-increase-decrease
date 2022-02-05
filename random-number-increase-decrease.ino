#include "display.h"
#include "buttons.h"

// the setup routine runs once when you press reset:
void setup() {                
  setupDisplay();
  setupButtons();

  randomSeed(analogRead(A7));
}

int counter = static_cast<int>(random(-999, 10000));

// the loop routine runs over and over again forever:
void loop() {
  writeNumber(counter);

  readButtons();
  checkButtons();
}
