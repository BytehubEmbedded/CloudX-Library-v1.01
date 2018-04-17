/* 
 * File:   randomNumberGenerator.h
 * Author: Ogboye Godwin
 *
 * Created on February 28, 2018, 2:43 PM
 */


#include <stdlib.h>
int minimum,maximum,Divisor;
randNumLimit(int min, int max){
    minimum=min;
    maximum=max;
}
int randNumGen(){
//#define	RAND_MAX	32767		/* max value returned by rand() */
    int generated;
    Divisor=32767/(maximum);
    generated = rand()/Divisor + minimum;
    return generated;
}