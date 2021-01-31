#include "DigiKeyboard.h"
/*
    Paddle to USB - Morse Interface for Internet-based CW practice 
    See vail.woozle.org, hamradio.solutions/vband/, and morsecode.me
    
    Pin connections for Digispark ATTiny85 with microUSB

    P0 = (INPUT) paddle left lever, dah  - pushbutton (connected to a 10 KOhm resistor to GND when OFF, and to 5V when ON)
    P1 = (INPUT) paddle right lever, dit - pushbutton (connected to a 10 KOhm resistor to GND when OFF, and to 5V when ON)
    P2 = (INPUT) dipswicth               -            (connected to a 10 KOhm resistor to GND when OFF, and to 5V when ON)

    Michele Giugliano, 30th January 2021

    From http://digistump.com/wiki/digispark/tutorials/basics I have unfortunately discovered that:
    - P3 and P4 are (also) used for USB communication and programming, so they can't be used as originally planned,
    since USB is still needed for communication (and episodic programming).
    - Connecting a pull-down resistor to P5 did not allow the board to react to the programming stage. I thus gave up
    with this pin as well.
  */

//----------------------------------------------------------------------------------------------------------
//inputs (entirely depend on the actual wiring of the prototype I built)
const int DIT = 0;            // pin 0 - paddle right level contact (dit)
const int DAH = 1;            // pin 1 - paddle left lever contact (dah)
const int S   = 2;            // pin 2 - dip switch

//setup (emulated) keyboard key-press characters (default for vail.woozle.org)
int DIT_key;                  // Contains the hex code of the key to be used for a dit..
int DAH_key;                  // Contains the hex code of the key to be used for a dah..

//setup for selecting the operating modes at run-time
int operation_mode = 0;       // Current operation mode (i.e. 0, 1, 2)
bool previous_DIT_state;      // Previous state for the DIT lever (useful for counting time elapsed)
bool previous_DAH_state;      // Previous state for the DAH lever (useful for counting time elapsed)
unsigned long StartTime_DIT;  // Start time for a counter, since the first press of DIT lever...
unsigned long StartTime_DAH;  // Start time for a counter, since the first press of DAH lever...
unsigned long CurrentTime;    // Stop/current time for the counters.
const unsigned long LongInterval = 5000; // Amount of millsecond to wait until "switching modes"...
//----------------------------------------------------------------------------------------------------------

void setup() {
    // Paddle contacts inputs
    pinMode(DIT, INPUT);  // DIT to INPUT
    pinMode(DAH, INPUT);  // DAH to INPUT

    // Dip-switch input
    pinMode(S,   INPUT);  // S   to INPUT

    previous_DIT_state = LOW;  // Init for DIT (past) state
    previous_DAH_state = LOW;  // Init for DAH (past) state
    
    // For: vail.woozle.org
    DAH_key = 0x1D; // z
    DIT_key = 0x1B; // x

    // For: hamradio.solutions/vband/
    //DAH_key = 0x30; // ]
    //DIT_key = 0x2F; // [
} // setup()



void loop() {
  paddle();
} // loop()


void change_operation_mode() {
  // every time this function is called
  // operation_mode is incremented, but the
  // remainder of division makes it like: 0 --> 1 --> 2 --> 0 --> 1 --> ...
  operation_mode = (operation_mode + 1) % 3;

  // after the operation_mode is changed, the 
  // corresponding settings are applied...
  switch (operation_mode) {
    
   case 0: // vail.woozle.org
    DAH_key = 0x1D; // z
    DIT_key = 0x1B; // x
    break;
    
   case 1: // hamradio.solutions/vband/
    DAH_key = 0x30; // ]
    DIT_key = 0x2F; // [    
    break;
    
   case 2: // morsecode.me
    DAH_key = 0x37; // .
    DIT_key = 0x37; // .
    break;
    
   default:
    DAH_key = 0x1D; // z
    DIT_key = 0x1B; // x
    break;
 }
} // change_operation_mode()

void long_press_DIT() {
 change_operation_mode();
} // long_press_DIT()


void long_press_DAH() {
 change_operation_mode();
} // long_press_DAH()


void paddle() {
  // Paddles lever can be "at rest"... so none pressed: -----------------------------------------
   if (digitalRead(DAH) == LOW && digitalRead(DIT) == LOW) {
          DigiKeyboard.sendKeyPress(0); 

          if (previous_DIT_state == HIGH)
            previous_DIT_state = LOW;
          if (previous_DAH_state == HIGH)
            previous_DAH_state = LOW;
   }
  //---------------------------------------------------------------------------------------------
  // The DAH lever (only) is pressed:
   if (digitalRead(DAH) == HIGH && digitalRead(DIT) == LOW) {
          DigiKeyboard.sendKeyPress(DAH_key); 
          if (previous_DAH_state == LOW)
            {
            previous_DAH_state = HIGH;
            StartTime_DAH = millis();  // Take current time at first lever press...
            }

            CurrentTime = millis();
            if (CurrentTime > StartTime_DAH + LongInterval) {
              // DO SOMETHING WHEN THIS MODE IS ENTERED
              long_press_DAH();
              StartTime_DAH = millis();
            }
   }
  //---------------------------------------------------------------------------------------------
  // The DIT lever (only) is pressed:
   if (digitalRead(DAH) == LOW && digitalRead(DIT) == HIGH) {
          DigiKeyboard.sendKeyPress(DIT_key); 
          if (previous_DIT_state == LOW)
            {
            previous_DIT_state = HIGH;
            StartTime_DIT = millis();  // Take current time at first lever press...
            }

            CurrentTime = millis();
            if (CurrentTime > StartTime_DIT + LongInterval) {
              // DO SOMETHING WHEN THIS MODE IS ENTERED
              long_press_DIT();
              StartTime_DIT = millis();
            }
   }
  //---------------------------------------------------------------------------------------------
  // Both DIT and DAH levers are pressed:
   if (digitalRead(DAH) == HIGH && digitalRead(DIT) == HIGH) {
          DigiKeyboard.sendKeyPress(DIT_key, DAH_key);     // Tested fine with a Bencher paddle!
   }
  //---------------------------------------------------------------------------------------------
} // paddle()

