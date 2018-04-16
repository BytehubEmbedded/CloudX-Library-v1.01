/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   Ultrasonic.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Website: http://www.makeelectronics.ng or http://www.bytehubembed.com
 * Description: This file contains the program to demonstrate the Ultrasonic sensor. 

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
		
	
 char triggg,echooo;	
void ultrasonic_Init(unsigned char trigg, unsigned char echoo){
                        	T1CON = 0x10;
                            pinMode(trigg,OUTPUT);
							pinMode(echoo,INPUT);
							triggg = trigg; echooo = echoo;
							
}

#define trig triggg
#define echo echooo

float readDistance(){
	     
             TMR1H = 0;
             TMR1L = 0;
             PinSelect(trig,HIGH);
             delayUs(10);
             PinSelect(trig,LOW);
 
             while(!readPin(echo));
             T1CONbits.TMR1ON = 1;
             while(readPin(echo));
             T1CONbits.TMR1ON = 0;
            
            return ((TMR1L | (TMR1H<<8))/58.82 - 10);
         }