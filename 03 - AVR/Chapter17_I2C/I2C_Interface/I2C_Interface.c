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

int main(void) {
//  char serialCharacter;
	char devAddr[20], addr[20], data[20], report[200];

	char mode, enter; //mode = write(w) / read(r)
	int number1;
	int number2;
	int i;
  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();
  printString("I2C Interface!\r\n");                          /* to test */

  // ------ Event loop ------ //
  while (1) {
	
	
 //   serialCharacter = receiveByte();
 //   transmitByte(serialCharacter);
//    LED_PORT = serialCharacter;

	//write/read	
	do{	
		printString("write(w)/read(r)\r\n");
		transmitByte('>');
		mode = receiveByte();
		transmitByte(mode);
		do{
			enter = receiveByte();
			transmitByte(enter);
		}while(enter !='\r');
		transmitByte('\n');
	}while(mode!='r' && mode!='w');
		
	//EnterDeviceAddress
	switch(mode){
		case 'w':
			printString("mode set as Write\r\n");
			break;
		case 'r':
			printString("mode set as Read\r\n");
			break;
		default:
			printString("goFuckYourSelf\r\n");
	}

	//Device Addr.
		printString("Enter Device Address:\r\n");
		transmitByte('>');
		i= -1;
		do{
			i++;
			devAddr[i]=receiveByte();	
	    	transmitByte(devAddr[i]);
		
		}while(devAddr[i] != '\r');
		transmitByte('\n');
		
	//Addr.
		printString("Enter Address:\r\n");
		transmitByte('>');
		i= -1;
		do{
			i++;
			addr[i]=receiveByte();	
	    	transmitByte(addr[i]);
		
		}while(addr[i] != '\r');
		transmitByte('\n');
		printString(addr);

	//Data.
		printString("Enter Data:\r\n");
		transmitByte('>');
		i= -1;
		do{
			i++;
			data[i]=receiveByte();	
	    	transmitByte(data[i]);
		
		}while(data[i] != '\r');
		transmitByte('\n');

	//Report
		sprintf(report,"mode = %c \r\ndevice address = %s \r\naddress = %s \r\ndata = %s \r\n",mode, devAddr, addr, data);
		printString(report);
		
	
	
  }                                                  /* End event loop */
  return (0);
}
