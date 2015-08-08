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
#include <string.h>

int main(void) {
char i=0;
  char buffer[50];
  char serialCharacter;

  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();						
  printString("Hello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  while (1) {

    //serialCharacter = receiveByte();
    //transmitByte(serialCharacter);
    i=0;
	serialCharacter='[';
    while (serialCharacter!=';')

	{
		serialCharacter = receiveByte();
		transmitByte(serialCharacter);
		buffer[i]=serialCharacter;
		i++;
	}
		buffer[i+1]=0;
		if(strcmp(buffer,"hello"))
	{
		printString("Hi :)\n");
		break;
	}

		else if (strcmp(buffer , "fohsh"))
		{
			printString("khodeT\n");
			break;
		}

			else 
				{
					printString("nemiad!!\n");
					break;
				}

    //transmitByte(serialCharacter);
    //LED_PORT = serialCharacter;
                           /* display ascii/numeric value of character */

  }                                                  /* End event loop */
  return (0);
}
