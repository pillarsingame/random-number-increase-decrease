#include "buttons.h"

/*
 * Logic is flipped
 * LOW is pressed
 * HIGH is NOT pressed
 */

const int increaseCounterButtonPin = A0;
const int decreaseCounterButtonPin = A1;

const int resetButtonPin = A2;

int currentIncreaseCounterButtonState;
int lastIncreaseCounterButtonState = 1;

int currentDecreaseCounterButtonState;
int lastDecreaseCounterButtonState = 1;

int currentResetButtonState;
int lastResetButtonState = 1;

void setupButtons() {
  pinMode(increaseCounterButtonPin, INPUT_PULLUP);
  pinMode(decreaseCounterButtonPin, INPUT_PULLUP);
  
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void readButtons() {
  currentIncreaseCounterButtonState = digitalRead(increaseCounterButtonPin);
  currentDecreaseCounterButtonState = digitalRead(decreaseCounterButtonPin);
  
  currentResetButtonState = digitalRead(resetButtonPin);
}

void checkButtons() {
  if (currentIncreaseCounterButtonState == LOW && lastIncreaseCounterButtonState == HIGH)
  {
    counter++;
    
    lastIncreaseCounterButtonState = LOW;
  }
  if (currentIncreaseCounterButtonState == HIGH && lastIncreaseCounterButtonState == LOW)
  {
    lastIncreaseCounterButtonState = HIGH;
  }

  if (currentDecreaseCounterButtonState == LOW && lastDecreaseCounterButtonState == HIGH)
  {
    counter--;
    
    lastDecreaseCounterButtonState = LOW;
  }
  if (currentDecreaseCounterButtonState == HIGH && lastDecreaseCounterButtonState == LOW)
  {
    lastDecreaseCounterButtonState = HIGH;
  }

  if (currentResetButtonState == LOW && lastResetButtonState == HIGH)
  {
    counter = static_cast<int>(random(0, 10000));

    lastResetButtonState = LOW;
  }
  if (currentResetButtonState == HIGH && lastResetButtonState == LOW)
  {
    lastResetButtonState = HIGH;
  }
}
