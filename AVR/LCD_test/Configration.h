/*
 * 4/2/2023
 * Auther: Ahmed Omar
 * Configration file used to configer which microcontroller you are used
 * 0 to disable
 * 1 to anable
    */


 #ifndef CONFIGRATION_H_
 #define CONFIGRATION_H_

 #include <stdint.h>
 /*========================================================== Define Microcontroller ==================================================*/
 #include <avr/io.h>
#include <util/delay.h>
 
 /*---------------------------------------------------------- AVR microcontroller -----------------------------------------------------*/
#define avr_atmega16A    1
#define avr_atmega32     0
#define avr_atmega328p   0
/*---------------------------------------------------------- End AVR microcontroller --------------------------------------------------*/



/*----------------------------------------------------------- PIC microcontroller -----------------------------------------------------*/
#define PIC_16F87XA      0
/*----------------------------------------------------------- PIC microcontroller -----------------------------------------------------*/


/*============================================================ End define Microcontroller==============================================*/





/*============================================================ Prephrials ============================================================= */
#define AnalogToDegital   0
/*============================================================ End Prephrials ========================================================= */



/*============================================================ Interfaceing =========================================================== */

/*-----------------------------------------------------------  LCD Display -------------------------------------------------------------*/
#define LCD_4X20         1

#define Mode             8                   // there are two mode (8, 4) depends on pins will connect.
#define Port_Data        BaseB               // choose the whole port to connect data port choose port(A, B, C, D,.....)
#define Command          BaseC               // choose the whole port to connect command port choose port(A, B, C, D,.....)
#define RS               0                   // choose pin to command port (0, 1, 2, 3, 4, 5, 6, 7)
#define E                1                   // choose pin to command port (0, 1, 2, 3, 4, 5, 6, 7)


/*-----------------------------------------------------------  End LCD Display ---------------------------------------------------------*/


/*============================================================ End Interfaceing ======================================================== */

#endif /* End configration*/  
