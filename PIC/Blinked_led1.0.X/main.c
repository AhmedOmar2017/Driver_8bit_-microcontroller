/*
 * File:   main.c
 * Author: Ahmed_Omar
 *
 * Created on April 14, 2023, 11:53 PM
 */
#include "App.h"

void main(void) {
    GPIO_INIT();
    PinDir(BaseA, 1, input);
    PinDir(BaseB, 1, output);
    
    while(1){
        if(PinRead(BaseA, 1)){
            PinWrite(BaseB, 1, low);
        }else{
            PinWrite(BaseB, 1, high);
        }
    } 
    return;
}
