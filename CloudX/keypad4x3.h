/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   keypad4x3.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Website: http://www.makeelectronics.ng or http://www.bytehubembed.com
 * Description: This file contains the program to demonstrate the keypad. 

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



         char Roww1,Roww2,Roww3,Coll1,Coll2,Coll3,Coll4,stats;

void keypad4x3_Setting(char Row1,char Row2,char Row3,char Col1,char Col2,char Col3, char Col4, char statess)
{
    pinMode(Row1,OUTPUT); pinMode(Row2,OUTPUT); pinMode(Row3,OUTPUT); 
    pinMode(Col1,INPUT); pinMode(Col2,INPUT); pinMode(Col3,INPUT);  pinMode(Col4,INPUT);
    
   Roww1 = Row1; Roww2= Row2; Roww3 = Row3; Coll1=Col1; Coll2=Col2;  Coll3=Col3; Coll4=Col4;
   stats = statess;
    
   }
#define Row1 Roww1
#define Row2 Roww2
#define Row3 Roww3
#define Col1 Coll1
#define Col2 Coll2
#define Col3 Coll3
#define Col4 Coll4
#define states stats


Get_keypad4x3(){
            char kkey = 0;

                      if(states is HIGH){
            PinSelect(Row1 ,LOW);
            PinSelect(Row2 ,HIGH);
            PinSelect(Row3,HIGH);

            if(readPin(Col1)  is LOW){ delayMs(200);   kkey = '1';}
            if(readPin(Col2)  is LOW){ delayMs(200);  kkey = '4';}
            if(readPin(Col3)  is LOW){ delayMs(200);  kkey = '7';}
            if(readPin(Col4)  is LOW){ delayMs(200);  kkey = '*';}
            delayMs(1);

             PinSelect(Row1 ,HIGH);
            PinSelect(Row2 ,LOW);
            PinSelect(Row3,HIGH);

            if(readPin(Col1) is LOW){ delayMs(200);   kkey = '2';}
            if(readPin(Col2) is LOW){ delayMs(200);  kkey = '5';}
            if(readPin(Col3)  is LOW){ delayMs(200);  kkey = '8';}
            if(readPin(Col4)  is LOW){ delayMs(200);  kkey = '0';}
             delayMs(1);


             PinSelect(Row1 ,HIGH);
            PinSelect(Row2 ,HIGH);
            PinSelect(Row3,LOW);

            if(readPin(Col1) is LOW){ delayMs(200);   kkey = '3';}
            if(readPin(Col2) is LOW){ delayMs(200);  kkey = '6';}
            if(readPin(Col3) is LOW){ delayMs(200);  kkey = '9';}
            if(readPin(Col4) is LOW){ delayMs(200);  kkey = '#';}
             delayMs(1);
              PinSelect(Row1 ,HIGH);
            PinSelect(Row2 ,HIGH);
            PinSelect(Row3,HIGH);
            }

        if(states is LOW){
            PinSelect(Row1, HIGH);
            PinSelect(Row2, LOW);
            PinSelect(Row3 , LOW);
            
            if(readPin(Col1)  is HIGH){ delayMs(200);   kkey = '1';}
            if(readPin(Col2)  is HIGH){ delayMs(200);  kkey = '4';}
            if(readPin(Col3)  is HIGH){ delayMs(200);  kkey = '7';}
            if(readPin(Col4)  is HIGH){ delayMs(200);  kkey = '*';}
            delayMs(1);
             
            PinSelect(Row1 ,LOW);
            PinSelect(Row2 ,HIGH);
            PinSelect(Row3 , LOW);
            
            if(readPin(Col1) is HIGH){ delayMs(200);   kkey = '2';}
            if(readPin(Col2) is HIGH){ delayMs(200);  kkey = '5';}
            if(readPin(Col3)  is HIGH){ delayMs(200);  kkey = '8';}
            if(readPin(Col4)  is HIGH){ delayMs(200);  kkey = '0';}
             delayMs(1);
             
            PinSelect(Row1 , LOW);
            PinSelect(Row2 , LOW);
            PinSelect(Row3 , HIGH);
            
            if(readPin(Col1) is HIGH){delayMs(200);   kkey = '3';}
            if(readPin(Col2) is HIGH){ delayMs(200);  kkey = '6';}
            if(readPin(Col3) is HIGH){ delayMs(200);  kkey = '9';}
            if(readPin(Col4) is HIGH){ delayMs(200);  kkey = '#';}
             delayMs(1);
            PinSelect(Row1 , LOW);
            PinSelect(Row2 , LOW);
            PinSelect(Row3 , LOW);
            }
            if(kkey !=0) return kkey;
            else return  kkey;            
}