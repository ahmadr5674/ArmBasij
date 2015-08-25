#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"
#include <string.h>

int main(void)
{
	initUSART();
	char myString[50];
  printString("RESEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEET\r\n");
	while (1)
	{
  	printString("AT\r\n");
		readString(myString,50);
		printString("\r\n");
	  printString(myString);
	  printString("hi");
		printString("\r\n");
	}

  return 0;
}
