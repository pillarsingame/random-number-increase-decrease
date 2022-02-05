#include "display.h"

// Segment arrangement
/*
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
*/

// Digit arrangement
/*
 1 2 3 4
*/

int segmentA = 2;
int segmentB = 3;
int segmentC = 4;
int segmentD = 5;
int segmentE = 6;
int segmentF = 7;
int segmentG = 8;
int displayDigit1 = 9;
int displayDigit2 = 10;
int displayDigit3 = 11;
int displayDigit4 = 12;

void setupDisplay() {
    // Initialize the digital segments as outputs.
    pinMode(segmentA, OUTPUT);
    pinMode(segmentB, OUTPUT);
    pinMode(segmentC, OUTPUT);
    pinMode(segmentD, OUTPUT);
    pinMode(segmentE, OUTPUT);
    pinMode(segmentF, OUTPUT);
    pinMode(segmentG, OUTPUT);
    pinMode(displayDigit1, OUTPUT);
    pinMode(displayDigit2, OUTPUT);
    pinMode(displayDigit3, OUTPUT);
    pinMode(displayDigit4, OUTPUT);
}

void writeDigit(short digit, short displayDigit) {
    // Logic is flipped
    // LOW results in the digit being written to
    switch (displayDigit) {
        case 1:
        {
            digitalWrite(displayDigit1, LOW);
            digitalWrite(displayDigit2, HIGH);
            digitalWrite(displayDigit3, HIGH);
            digitalWrite(displayDigit4, HIGH);
            break;
        }
        case 2:
        {
            digitalWrite(displayDigit1, HIGH);
            digitalWrite(displayDigit2, LOW);
            digitalWrite(displayDigit3, HIGH);
            digitalWrite(displayDigit4, HIGH);
            break;
        }
        case 3:
        {
            digitalWrite(displayDigit1, HIGH);
            digitalWrite(displayDigit2, HIGH);
            digitalWrite(displayDigit3, LOW);
            digitalWrite(displayDigit4, HIGH);
            break;
        }
        case 4:
        {
            digitalWrite(displayDigit1, HIGH);
            digitalWrite(displayDigit2, HIGH);
            digitalWrite(displayDigit3, HIGH);
            digitalWrite(displayDigit4, LOW);
            break;
        }
    }

    // Logic is normal
    // HIGH results in the segment being lit
    switch (digit) {
        case 0:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, HIGH);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, LOW);

            break;
        }
        case 1:
        {
            digitalWrite(segmentA, LOW);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, LOW);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, LOW);
            digitalWrite(segmentG, LOW);

            break;
        }
        case 2:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, LOW);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, HIGH);
            digitalWrite(segmentF, LOW);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 3:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, LOW);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 4:
        {
            digitalWrite(segmentA, LOW);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, LOW);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 5:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, LOW);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 6:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, LOW);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, HIGH);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 7:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, LOW);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, LOW);
            digitalWrite(segmentG, LOW);

            break;
        }
        case 8:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, HIGH);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, HIGH);

            break;
        }
        case 9:
        {
            digitalWrite(segmentA, HIGH);
            digitalWrite(segmentB, HIGH);
            digitalWrite(segmentC, HIGH);
            digitalWrite(segmentD, HIGH);
            digitalWrite(segmentE, LOW);
            digitalWrite(segmentF, HIGH);
            digitalWrite(segmentG, HIGH);

            break;
        }
    }

    // delay so the numbers are readable (at >=1ms)
    // but not too much as it will cause flickering (at >=5ms)
    // 4ms seem to be the sweet spot
    delay(4);
}

void writeNumber(short number) {
    short digit[4];

    for (short i = 3; i >= 0; i--) {
        digit[i] = number % 10;

        number /= 10;
    }

    for (short i = 0; i < 4; i++) {
        writeDigit(digit[i], i + 1);
    }
}
