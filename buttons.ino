#include "buttons.h"

/*
 * Logic is flipped
 * LOW is pressed
 * HIGH is NOT pressed
 */

const int counterButtonPin = A0;
const int resetButtonPin = A1;

int currentCounterButtonState;
int lastCounterButtonState = 1;

int currentResetButtonState;
int lastResetButtonState = 1;

void setupButtons() {
  pinMode(counterButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void readButtons() {
  currentCounterButtonState = digitalRead(counterButtonPin);
  currentResetButtonState = digitalRead(resetButtonPin);
}

void checkButtons() {
  if (currentCounterButtonState == LOW && lastCounterButtonState == HIGH)
  {
    counter++;
    
    lastCounterButtonState = LOW;
  }

  if (currentCounterButtonState == HIGH && lastCounterButtonState == LOW)
  {
    lastCounterButtonState = HIGH;
  }

  if (currentResetButtonState == LOW && lastResetButtonState == HIGH)
  {
    counter = 0;

    lastResetButtonState = LOW;
  }

  if (currentResetButtonState == HIGH && lastResetButtonState == LOW)
  {
    lastResetButtonState = HIGH;
  }
}
