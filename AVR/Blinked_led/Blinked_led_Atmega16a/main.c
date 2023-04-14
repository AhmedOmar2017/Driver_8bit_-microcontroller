/*
 * main.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Ahmed_Omar
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

