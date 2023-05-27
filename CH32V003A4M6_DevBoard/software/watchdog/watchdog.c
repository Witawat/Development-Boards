// ===================================================================================
// Project:   Independent Watchdog Demo for CH32V003
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
// Blink an LED using independent watchdog resets.
//
// References:
// -----------
// - CNLohr ch32v003fun: https://github.com/cnlohr/ch32v003fun
// - WCH Nanjing Qinheng Microelectronics: http://wch.cn


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include <system.h>                 // system functions
#include <gpio.h>                   // GPIO functions

#define PIN_LED   PC0               // define LED pin

// ===================================================================================
// Main Function
// ===================================================================================
int main(void) {
  // Setup
  PIN_output(PIN_LED);              // set LED pin as output
  IWDG_start(200);                  // start watchdog with 200ms timer
  DLY_ms(100);                      // wait 100ms
  PIN_toggle(PIN_LED);              // toggle LED on/off
  
  // Loop
  while(1);                         // wait for watchdog reset
}
