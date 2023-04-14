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





/*===================================== Prephrials functions ======================================*/

/*------------------------------------- Analog to Digital ------------------------------------------*/

void SelectADC (uint8_t Base, uint8_t value);
/*------------------------------------- End Analog to Digital --------------------------------------*/

/*===================================== End Prephrials functions ==================================*/


/*===================================== End Interface functions ==================================*/


/*------------------------------------- LCD Dispaly functions ----------------------------------------*/
#if LCD_4X20  == 1
#endif  /* End LCD */



#endif /*End HAL.H file*/