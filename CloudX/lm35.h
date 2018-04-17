/* 
 * File:   lm35.h
 * Author: Ogboye Godwin
 *
 * Created on April 9, 2018, 1:39 PM
 */

/*
 *  EXAMPLE CODE WITH LM016 LCD DISPLAY
 #include <CloudX/CloudX.h>
#include <CloudX/Lcd.h>
#include <CloudX/Adc.h>
#include <CloudX/lm35.h>
#include <stdlib.h>
#include <CloudX/floatTostr.h>


char *txt;
setup(){
lcdSetting(2, 3,4,5,6,7);
    loop(){ 
        txt = floatTostr(readTemperature(0));
        txt[5]='\0';
        lcdCmd(lcd_clear);
        lcdWriteText(1,1,"i.o Temperature");
        lcdWriteText(2,1,"temp:");
        lcdWriteTextCP(txt);
        lcdWriteTextCP("C");  
    }
}
 
 */

int Lm35data;
long Temparature;

readTemperature(int Apin){
        analogSetting();
        Lm35data=analogRead(Apin);
        Temparature = 0.487 * Lm35data;
        return Temparature;
}