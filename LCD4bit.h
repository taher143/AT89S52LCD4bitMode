// ***********************************************************
// Project:   LCD 4bit
// Author:    M.Saeed Yasin
// Module description:  Operate LCD in 4bit mode
// ***********************************************************

#include<reg52.h>


//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void writeString(unsigned char *);
void ReturnHome(void);

//*******************
//Pin description
/*
P2.4 to P2.7 is data bus
P1.0 is RS
P1.1 is E
*/
//********************

// Defines Pins
sbit RS = P2^0;
sbit E  = P2^1;

void cct_init(void)
{
P0 = 0x00;   //not used 
//P1 = 0x00;   //not used 
P2 = 0x00;   //used as data port
//P3 = 0x00;   //used for generating E and RS
}

void delay(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(char t)
{
   RS = 1;             // This is data

   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
   P0 |= (t&0xF0);     // Write Upper nibble of data

   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);

   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
   P0 |= ((t<<4)&0xF0);// Write Lower nibble of data

   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}


void writecmd(int z)
{
   RS = 0;             // This is command

   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
   P0 |= (z&0xF0);     // Write Upper nibble of data

   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);

   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
   P0 |= ((z<<4)&0xF0);// Write Lower nibble of data

   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}
void writeString(unsigned char *s)
{
	while(*s)
	writedata(*s++);

}
void lcdinit(void)
{
  ///////////// Reset process from datasheet /////////
     delay(15000);

	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P0 |= (0x30&0xF0);    // Write 0x3
	
	 E  = 1;               // => E = 1
	 delay(150);
	 E  = 0;               // => E = 0
	 delay(150);

     delay(4500);

	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P0 |= (0x30&0xF0);    // Write 0x3
	
	 E  = 1;               // => E = 1
	 delay(150);
	 E  = 0;               // => E = 0
	 delay(150);

     delay(300);

	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P0 |= (0x30&0xF0);    // Write 0x3
	
	 E  = 1;               // => E = 1
	 delay(150);
	 E  = 0;               // => E = 0
	 delay(150);

     delay(650);

	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P0 |= (0x20&0xF0);    // Write 0x2
	
	 E  = 1;               // => E = 1
	 delay(150);
	 E  = 0;               // => E = 0
	 delay(150);

	 delay(650);

  /////////////////////////////////////////////////////
   writecmd(0x28);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment
}

void ReturnHome(void)     //Return to 0 location
{
  writecmd(0x02);
    delay(1500);
}