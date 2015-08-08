/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  //char serialCharacter;
  int a = 0;
  int b = 5;
  int c = 0;
  int i = 0;
  char str[50];
  

  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();

  while (1) {
  printString("\r\nHello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  for (i = 0 ; ; i++)
  {
  	str[i] = receiveByte();
  	transmitByte(str[i]);
  	if (str[i] == '\r')
  		break;
  }
  str[i] = 0;
  a = strtol(str , NULL , 10);
 
  for (i = 0 ;  ; i++)
  {
  	str[i] = receiveByte();
  	transmitByte(str[i]);
  	if (str[i] == '\r')
  		break;
  }
  str[i] = 0;
  b = strtol(str , NULL , 10);

  c = a+b;
  sprintf(str, "%d\r\n", c);
  printString(str);
	/*	
    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    LED_PORT = serialCharacter;*/

  }                                                 
  return (0);
}
