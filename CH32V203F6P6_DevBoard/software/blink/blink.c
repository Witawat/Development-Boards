// ===================================================================================
// Project:   Blink Demo for CH32V203
// Version:   v1.0
// Year:      2023
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Blink built-in LED using delay.
//
// References:
// -----------
// - CNLohr ch32v003fun: https://github.com/cnlohr/ch32v003fun
// - WCH Nanjing Qinheng Microelectronics: http://wch.cn


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include <system.h>         // system functions
#include <gpio.h>           // GPIO functions

#define PIN_LED   PB1       // define LED pin

// ===================================================================================
// Main Function
// ===================================================================================
int main(void) {
  // Setup
  PIN_output(PIN_LED);      // set LED pin as output
  
  // Loop
  while(1) {
    PIN_toggle(PIN_LED);    // toggle LED on/off
    DLY_ms(100);            // wait 100ms
  }
}
