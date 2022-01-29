#include "display.h"

// the setup routine runs once when you press reset:
void setup() {                
  setupDisplay();
}

// test counter
int counter = 76;

// the loop routine runs over and over again forever:
void loop() {
  writeNumber(counter);
}
