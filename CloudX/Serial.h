/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   serial.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Website: http://www.makeelectronics.ng or http://www.bytehubembed.com
 * Description: This file contains the program to demonstrate the serial. 

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


#define   OK 0


void serialBegin(unsigned long baudd){
    SPBRG = (_XTAL_FREQ - (baudd*16)) / (baudd*16);
    TXSTA = 0x24;
    RCSTA = 0x90;
   
}

void serialWrite(unsigned char SerTx)
{
    TXSTAbits.TXEN =1;
    TXREG = SerTx;
    delayMs(5);
}

void serialWriteText(unsigned char *Sertxxt){
    unsigned char pnttter=0;
    while(Sertxxt[pnttter] != 0)
        serialWrite(Sertxxt[pnttter++]);
}

unsigned char serialRead(){
     RCSTAbits.CREN =1;
     PIR1bits.RCIF=0;
    return RCREG;
}


unsigned char serialAvailable(){
    RCSTAbits.CREN =1;
    return PIR1bits.RCIF;
}