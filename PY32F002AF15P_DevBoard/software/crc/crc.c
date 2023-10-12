// ===================================================================================
// Project:   Example for PY32F0xx
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
// Send a message through UART with a newline at the end, and the CRC of the message 
// will be sent back. We're checking if the PY32F002A has a hidden CRC module.
//
// Compilation Instructions:
// -------------------------
// - Make sure GCC toolchain (gcc-arm-none-eabi) and Python3 with PySerial is
//   installed. If necessary, a driver for the USB-to-serial converter used must
//   be installed.
// - Connect the USB-to-serial converter to the MCU board.
// - Run 'make flash'.


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include "system.h"                 // for system functions
#include "uart.h"                   // for UART

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  // Setup
  UART_init();                      // init UART, 8N1, BAUD: 115200, PA2/PA3
  CRC_enable();                     // enable CRC module

  // Loop
  while(1) {
    char c = UART_read();           // read character from UART
    if(c != '\n') CRC_write(c);     // not newline -> add to CRC calculation
    else {                          // newline ->
      UART_printW(CRC_read());      //   read CRC calculation and send it via UART
      UART_newline();               //   print newline
      CRC_reset();                  //   reset CRC calculation
    }
  }
}
