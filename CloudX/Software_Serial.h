/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   Software_Serial.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Date:   13-02-18
 * Time:   01:05PM
 * Office:  MBED Studio Lab
 * Website: http://www.makeelectronics.ng or http://www.bytehubembed.com
 * Description: This file contains the program to demonstrate the Software Serial. 

This code has been developed and tested on CloudX microcontroller boards.  
We strongly believe that the library works on any of development boards for respective controllers. 
Check this link http://www.makeelectronics.ng for awesome tutorials on CloudX,ARM,Robotics,RTOS,IOT.
ByteHub Embedded invests substantial time and effort developing open source HW and SW tools,
to support consider buying the CloudX microcontroller boards.
 
The ByteHub Embedded libraries and examples are licensed under the terms of the new-bsd license
(two-clause bsd license). See also: http://www.opensource.org/licenses/bsd-license.php

BYTEHUB EMEBEDED DISCLAIMS ANY KIND OF HARDWARE FAILURE RESULTING OUT OF USAGE OF LIBRARIES, DIRECTLY OR
INDIRECTLY. FILES MAY BE SUBJECT TO CHANGE WITHOUT PRIOR NOTICE. THE REVISION HISTORY CONTAINS THE 
INFORMATION RELATED TO UPDATES.
 

Permission to use, copy, modify, and distribute this software and its documentation for any purpose
and without fee is hereby granted, provided that this copyright notices appear in all copies 
and that both those copyright notices and this permission notice appear in supporting documentation.
**************************************************************************************************/

/******************** Software serial Library ******************************************
				    						       *		 
*************** PLEASE NOTE THAT THE SOFTWARE SERIAL LIBRARY MUST BE INCLUDED***********			               *
************************** Software serial Initialisation ******************************    
										       *
This library initialises the software serial library and accepts parameters            *
such as the desired baudrates, desire Transmit  and Receive pin.     		       *
										       *	
void Software_serialInit(unsigned long Baudrate, char TX, char RX);		       *
										       *
* supported Baudrates ---- 1200							       *
                      ---- 2400							       *
		      ---- 4800							       *
		      ---- 9600							       *
                      ---- 19200						       *
										       *
* TX pin: can be any of the digital pins					       *
										       *
* RX pin:  can be any of the digital pins					       *
						 				       *
****************************************************************************************      

***************************** Software Serial Write Text  ******************************
										       *
This library allows users to write text to serial communication			       *
										       *
void Software_SerialWriteText(unsigned char *Text) 				       *
										       *
* Pointer Text holds entire string to be transmitted 				       *
  										       *
**************************************************************************************** 
										       *
***************************** Software Serial Write  ***********************************
										       *
This library allows users to write a single character to serial communication	       *
										       *
void Software_SerialWrite(unsigned char chr)                                           *
                                                                                       *
* chr holds entire a character to be transmitted                                       *
                                                                                       *
**************************************************************************************** 
                                                                                       *
*****************************   Software Serial Read   *********************************
                                                                                       *                                         
This library allows users to read and return incoming character text through serial    * 
communication                                                                          *
                                                                                       *
void Software_SerialRead()                                                             * 
                                                                                       *
* This library returns received characters from serial                                 *
                                                                                       *
**************************************************************************************** 
                                                                                       *
****************************************************************************************
Example:									       *
   									               *
										       *
#include <CloudX\CloudX.h>							       *
#include <CloudX/Software_Serial.h>						       *
										       *
										       *
										       *
										       *
             char txt[]= "\rWelcome to cloudx software uart";                          *
setup()										       *
{										       *
    unsigned char ch = 0;      // Variable to store Rx character		       *
    Software_serialInit(19200, 1, 2);   //Baudrate, TX, RX -- Intialize Soft UART      *
   										       *
   Software_SerialWriteText(txt);						       *
   Software_SerialWriteText("\rMy Programming skills improving");                      *
   Software_SerialWriteText("\rGenerating software Serial for Cloudx");                *
   Software_SerialWriteText("\rInterfacing it to different serial chips");             *
   Software_SerialWriteText("\rCommunication protocols uses several baudrates");       *
   Software_SerialWriteText(" such as 1200 -- 2400 -- 9600 -- 19200");                 *
loop()										       *
    {										       *
        ch= Software_SerialRead();   // Receive a character from UART		       *
        Software_SerialWrite(ch);     // Echo back that character		       *
    }										       *
}										       *
										       *
										       *				
***************************************************************************************/

unsigned long bauudd;
char txxx, rxxx;



long Software1_serial(unsigned long bauud, char txx, char rxx)     //  Initialize UART pins to proper values
{
    bauudd= bauud;
    pinMode(rxx, INPUT);
    pinMode(txx, OUTPUT);
    txxx = txx;
    rxxx = rxx;
}


//#define   Baudrate
#define UART_TX  txxx
#define UART_RX  rxxx

#define OneBitDelay_1200           (1000000/1200)      // microseconds
#define OneBitDelay_2400           (1000000/2400)-8      // microseconds
#define OneBitDelay_4800           (1000000/4800)-16      // microseconds
#define OneBitDelay_9600           (1000000/9600)-32   // microseconds
#define OneBitDelay_19200          (1000000/19200)-32     // microseconds


#define DataBitCount          8                    // no parity, no flow control


unsigned char Software_SerialRead(void)
{
    unsigned char i,DataValue = 0;

    //wait for start bit
    while(readPin(UART_RX)==1);
    if(bauudd == 1200){
    delayus(OneBitDelay_1200);
    delayus(OneBitDelay_1200/2);   // Take sample value in the mid of bit duration
    }
    else  if(bauudd == 2400){
    delayus(OneBitDelay_2400);
    delayus(OneBitDelay_2400/2);   // Take sample value in the mid of bit duration
    }
    else  if(bauudd == 4800){
    delayus(OneBitDelay_4800);
    delayus(OneBitDelay_4800/2);   // Take sample value in the mid of bit duration
    }
    else  if(bauudd == 9600){
    delayus(OneBitDelay_9600);
    delayus(OneBitDelay_9600/2);   // Take sample value in the mid of bit duration
    }
    else  if(bauudd == 19200){
    delayus(OneBitDelay_19200);
    delayus(OneBitDelay_19200/2);   // Take sample value in the mid of bit duration
    }

    for (i = 0; i < DataBitCount; i++ )
    {
        if (readPin(UART_RX) == 1 )   //if received bit is high
        {
            DataValue += (1<<i);
        }
        if(bauudd == 1200) delayus(OneBitDelay_1200);
        else if(bauudd == 2400) delayus(OneBitDelay_2400);
        else if(bauudd == 4800) delayus(OneBitDelay_4800);
        else if(bauudd == 9600) delayus(OneBitDelay_9600);
        else if(bauudd == 19200) delayus(OneBitDelay_19200);
    }

    // Check for stop bit
    if ( readPin(UART_RX) == 1 )       //Stop bit should be high
    {
        //delayus(OneBitDelay/2);
         if(bauudd == 1200) delayus(OneBitDelay_1200/2);
       else  if(bauudd == 2400) delayus(OneBitDelay_2400/2);
       else  if(bauudd == 4800) delayus(OneBitDelay_4800/2);
       else  if(bauudd == 9600) delayus(OneBitDelay_9600/2);
       else  if(bauudd == 19200) delayus(OneBitDelay_19200/2);
        return DataValue;
    }
    else                      //some error occurred !
    {
       if(bauudd == 1200) delayus(OneBitDelay_1200/2);
        if(bauudd == 2400) delayus(OneBitDelay_2400/2);
        if(bauudd == 4800) delayus(OneBitDelay_4800/2);
        if(bauudd == 9600) delayus(OneBitDelay_9600/2);
        if(bauudd == 19200) delayus(OneBitDelay_19200/2);
        return 0x000;
    }
}




void Software_SerialWrite(const char DataValue)
{
    /* Basic Logic

       TX pin is usually high. A high to low bit is the starting bit and
       a low to high bit is the ending bit. No parity bit. No flow control.
       BitCount is the number of bits to transmit. Data is transmitted LSB first.

    */
                 char i=0;
    // Send Start Bit
    PinSelect(UART_TX ,LOW);
     if(bauudd == 1200)      delayus(OneBitDelay_1200);
     else  if(bauudd == 2400) delayus(OneBitDelay_2400);
     else   if(bauudd == 4800) delayus(OneBitDelay_4800);
     else   if(bauudd == 9600) delayus(OneBitDelay_9600);
     else  if(bauudd == 19200) delayus(OneBitDelay_19200);

    for (i = 0; i < DataBitCount; i++ )
    {
        //Set Data pin according to the DataValue
        if( ((DataValue>>i)&0x1) == 0x1 )   //if Bit is high
        {
            PinSelect(UART_TX, 1);
        }
        else      //if Bit is low
        {
            PinSelect(UART_TX , 0);
        }

        if(bauudd == 1200) delayus(OneBitDelay_1200);
        else    if(bauudd is 2400) delayus(OneBitDelay_2400);
        else  if(bauudd is 4800) delayus(OneBitDelay_4800);
        else  if(bauudd is 9600) delayus(OneBitDelay_9600);
        else  if(bauudd is 19200) delayus(OneBitDelay_19200);
    }

    //Send Stop Bit
    PinSelect(UART_TX, HIGH);
     if(bauudd == 1200)        delayus(OneBitDelay_1200);
     else   if(bauudd == 2400) delayus(OneBitDelay_2400);
     else   if(bauudd == 4800) delayus(OneBitDelay_4800);
     else   if(bauudd == 9600) delayus(OneBitDelay_9600);
     else  if(bauudd == 19200) delayus(OneBitDelay_19200);
}

Software_SerialWriteText(unsigned char *txtt){
                      char cntter=0;
                      while(txtt[cntter] != '\0'){
                              Software_SerialWrite(txtt[cntter++]);
                              delayms(1);
                      }

                 }

Software_serialInit(unsigned long bassd,  char ppin1, unsigned char ppin2){
   // const char *softbar = "****************** CloudX Software Serial Test ****************************";
    Software1_serial(bassd,ppin1,ppin2);
    PinSelect(UART_TX ,HIGH);
  //  Software_SerialWriteText(softbar);
}
