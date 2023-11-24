#include "DigiKeyboard.h"
/*
    **Minimal version** (compile and use this if you do not want the "fancy" features of the other one)

    Paddle to USB - Morse Interface for Internet-based CW practice 
    See vail.woozle.org, hamradio.solutions/vband/
    
    Pin connections for Digispark ATTiny85 with microUSB

    P0 = (INPUT) paddle left lever, dah  - pushbutton (connected to a 10 KOhm resistor to GND when OFF, and to 5V when ON)
    P1 = (INPUT) paddle right lever, dit - pushbutton (connected to a 10 KOhm resistor to GND when OFF, and to 5V when ON)

    Michele Giugliano, 24th November 2023

  */

//----------------------------------------------------------------------------------------------------------
//inputs (entirely depend on the actual wiring of the prototype I built)
const int DIT = 0;            // pin 0 - paddle right level contact (dit)
const int DAH = 1;            // pin 1 - paddle left lever contact (dah)

//setup (emulated) keyboard key-press characters (default for vail.woozle.org)
int DIT_key;                  // Contains the hex code of the key to be used for a dit..
int DAH_key;                  // Contains the hex code of the key to be used for a dah..

//----------------------------------------------------------------------------------------------------------

void setup() {
    // Paddle contacts inputs
    pinMode(DIT, INPUT);  // DIT to INPUT
    pinMode(DAH, INPUT);  // DAH to INPUT
    
    // For: vail.woozle.org
    //DAH_key = 0x1D; // z
    //DIT_key = 0x1B; // x

    // For: hamradio.solutions/vband/
    DAH_key = 0x30; // ]
    DIT_key = 0x2F; // [
} // setup()



void loop() {
  paddle();
} // loop()



void paddle() {
  // Paddles lever can be "at rest"... so none pressed: -----------------------------------------
   if (digitalRead(DAH) == LOW && digitalRead(DIT) == LOW) {
          DigiKeyboard.sendKeyPress(0); 
   }
  //---------------------------------------------------------------------------------------------
  // The DAH lever (only) is pressed:
   if (digitalRead(DAH) == HIGH && digitalRead(DIT) == LOW) {
          DigiKeyboard.sendKeyPress(DAH_key); 
   }
  //---------------------------------------------------------------------------------------------
  // The DIT lever (only) is pressed:
   if (digitalRead(DAH) == LOW && digitalRead(DIT) == HIGH) {
          DigiKeyboard.sendKeyPress(DIT_key); 
   }
  //---------------------------------------------------------------------------------------------
  // Both DIT and DAH levers are pressed:
   if (digitalRead(DAH) == HIGH && digitalRead(DIT) == HIGH) {
          DigiKeyboard.sendKeyPress(DIT_key, DAH_key);     // Tested fine with a Bencher paddle!
   }
  //---------------------------------------------------------------------------------------------
} // paddle()
