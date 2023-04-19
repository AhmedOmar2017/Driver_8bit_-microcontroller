/*
 * File:   main.c
 * Author: Ahmed_Omar
 *
 * Created on April 17, 2023, 5:34 PM
 */



#include "App.h"



void main(void) {
   GPIO_INIT();
   LCD_INIT();
   LCD_Print("Ahmed Omar");
   
   
 
PinDir(BaseD, 0, output);
PinDir(BaseD, 1, input);
while(1){
    if(PinRead(BaseD, 1)){
        PinWrite(BaseD, 0, high);
         __delay_ms(500);
    }else{
        PinWrite(BaseD, 0, low);
    } 
}
    return;
}
