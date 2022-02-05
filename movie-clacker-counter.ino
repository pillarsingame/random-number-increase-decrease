#include "display.h"

const int buttonPin = 13;

int buttonState = 0;

// the setup routine runs once when you press reset:
void setup() {                
  setupDisplay();
}

// test counter
int counter = 0;

// the loop routine runs over and over again forever:
void loop() {
  writeNumber(counter);

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    counter++;

    delay(200);
  }
}
