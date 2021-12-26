////////////////////////////////////// ////////
// Project: Internet to serial port Control  //
// Author:  M.Saeed Yasin                    //
// Date:    14/11/2010                       //
///////////////////////////////////////////////

#include <reg52.h>
#include "serial.h"
#include "LCD4bit.h"
void main()
{	
	cct_init();                                     //Make all ports zero
   	lcdinit();                                      //Initilize LCD
	SerialInitialize();	
	EA = 1;
	ES = 1;
	writeString("Hello World");
	UWriteString("Taher");
	while(1) 
	{

	}
} 	  
