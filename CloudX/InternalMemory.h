/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   InternalMemory.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Website: http://www.makeelectronics.ng or http://www.bytehubembed.com
 * Description: This file contains the program to demonstrate the Internal Memory Storge. 

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



readMemory(unsigned char RIM){
    EEADR = RIM;
    EECON1bits.EEPGD =0;
    EECON1bits.RD =1;
    return EEDATA ;
}

writeMemory(unsigned char WIMADDR, unsigned char WIMDATA){
    while(EECON1bits.WR==1);
    EEADR = WIMADDR;
    EEDATA = WIMDATA;
    EECON1bits.EEPGD =0;
    EECON1bits.WREN =1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR =1;
    EECON1bits.WREN =0;
}