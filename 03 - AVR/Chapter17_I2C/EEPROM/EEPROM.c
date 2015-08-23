                /* Reads LM75 Thermometer and Prints Value over Serial */

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include <string.h>
#include "pinDefines.h"
#include "USART.h"
#include "i2c.h"

// -------- Defines -------- //

#define EEPROM_ADDRESS_W               0b10100000
#define EEPROM_ADDRESS_R               0b10100001
// -------- Functions --------- //
#define EEPROM_ADDRESS_DATA_H          0b00100001
#define EEPROM_ADDRESS_DATA_L          0b00100000
#define EEPROM_DATA                    'h'
#define maxLength 100
int main(void) {

	char buffer[maxLength],tempcondition = 'n';
	uint8_t address , data , address2;
  // -------- Inits --------- //
  initUSART();
  printString("\r\n====  EEPROM STARTED  ====\r\n");
  initI2C();
  
  int Read_Data;

  while (1)
  {
    //Write To EEPROM
	tempcondition = 'n';
    i2cStart();
	readString(buffer,maxLength);
	printString("\r\n");
	while(tempcondition != 'y'){
		if(!strcmp(buffer,"write")){
			printString("Enter Address: \r\n");
			address = getNumber();
			printString("\r\n Enter Data: \r\n");
			data = getNumber();
			printString("\r\n Enter Address: \r\n");
			address2 = getNumber();
			printString("\r\n Enter Data: \r\n");
			tempcondition = 'y';
		}
		else
			printString("chert nagu. \r\n");
	 }                                                  /* End event loop */
	i2cSend(EEPROM_ADDRESS_W);
	i2cSend(address);
	i2cSend(data);
	i2cSend(address2);
	i2cStop();
 }
  return (0);                            /* This line is never reached */
}
