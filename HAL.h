/*
 * 3/4/2023
 * Auther: Ahmed omar
 * File: include lower function 
*/

#ifndef HAL_H_
#define HAL_H_

#include "Mcal.h"

/*=====================================GPIO functions===========================================*/

void PinDir(uint8_t  Base, uint8_t pin, uint8_t state);
void PinWrite(uint8_t  Base, uint8_t pin, uint8_t stat);
void PinTaggle(uint8_t  Base, uint8_t pin);
uint8_t PinRead(uint8_t Base, uint8_t pin);

/*==================================End GPIO Function============================================*/
#endif /*end HAL.H file*/