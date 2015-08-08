#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"
#include <string.h>



void main ()
{
	char buffer[50] ;
	int  val;
	char SerialCharacter, i ;
	i=0;
	SerialCharacter="]";
	while (1)
	{
		i=0;
		SerialCharacter="]";
		while (Serialcharacter!=";")
		{
			SerialCharacter=receiveByte();
			transmitByte(SerialCharacter);
			buffer[i]=SerialCharacter;
			i++;
		}
		buffer[i+1]=0;
		val=atoi(buffer);

	}
}
