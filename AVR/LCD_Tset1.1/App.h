#ifndef _APP_H_
#define _APP_H_

#include "HAL.h"

/*============================================ GPIO Initialization =================================================*/

void GPIO_INIT();

/*============================================ End GPIO Initialization =============================================*/



/*============================================ LCD Initialization =================================================*/

void LCD_INIT();
void LCD_Print(uint8_t * str);
/*============================================ End LCD Initialization =============================================*/



#endif /* END App.h file*/