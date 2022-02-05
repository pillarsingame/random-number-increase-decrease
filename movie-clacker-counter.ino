#include "display.h"
#include "buttons.h"

// the setup routine runs once when you press reset:
void setup() {                
  setupDisplay();
  setupButtons();
}

int counter = 0;

// the loop routine runs over and over again forever:
void loop() {
  writeNumber(counter);

  readButtons();
  checkButtons();
}
