/*
    * 2/4/2023
    * Auther: Ahmed Omar
    * It include all addresses for microcontroller
    * 
*/


#ifndef MCAL_H_
#define MCAL_H_

#include "MACROS.h"
#if PIC_16F87XA == 1
    #include <xc.h>
#endif



typedef enum{
    low, high
}status;


typedef enum {
    output,
    input
}Data_dir;

/*======================================================== PIC ================================================*/

/*------------------------------------------------------- PIC_16F87XA ----------------------------------------*/

#if PIC_16F87XA == 1

/* Adresses of ports*/

#define BaseA       0x05
#define BaseB       0x06
#define BaseC       0x07
#define BaseD       0x08
#define BaseE       0x09

/* END Adresses of ports*/

/* Ananlog to degital */

#define EnADC0       0x1F
#define EnADC1       0x9F

/* End Ananlog to degital */

#endif /* end  PIC_16F87XA */

/*================================================== End PIC ====================================================*/


/*====================================================== AVR ====================================================*/

/*------------------------------------------------- AVR_atmega16A -----------------------------------------------*/
#if avr_atmega16A == 1


/* Adresses of ports*/

#define BaseA        0x39
#define BaseB        0x36
#define BaseC        0x33
#define BaseD        0x30

/* End Adresses of ports*/


#endif /* END  AVR_atmega16A */


#endif /* END MCAL FILE*/