/*
    * 2/4/2023
    * Auther: Ahmed Omar
    * It include all addresses for microcontroller
    * 
*/


#ifndef MCAL_H_
#define MCAL_H_

#include "MACROS.h"

typedef enum{
    low, high
}status;

/*============================================================================================================*/

/*Configration for PIC _microcontroller*/
#if PIC_16F87XA == 1

typedef enum {
    output,
    input
}Data_dir;

/* Adresses of ports*/

#define BaseA       0x05
#define BaseB       0x06
#define BaseC       0x07
#define baseD       0x08
#define BaseE       0x09


// #define BaseA       AdrPORT(0x05)
// #define BaseB       AdrPORT(0x06)
// #define BaseC       AdrPORT(0x07)
// #define baseD       AdrPORT(0x08)
// #define BaseE       AdrPORT(0x09)


/* Diraction of Port*/
// #define DirPortA      DirPort(PORTA, 0x80)     
// #define DirPortB      DirPort(PORTB, 0x80)  
// #define DirPortC      DirPort(PORTC, 0x80)  
// #define DirPortD      DirPort(PORTD, 0x80)
// #define DirPortE      DirPort(PORTE, 0x80)   



#endif /* end  PIC_16F87XA */

/*==============================================================================================================*/

/*Configration for Avr_atmega16A _microcontroller*/
#if avr_atmega16A == 1

typedef enum {
    input, output
}Data_dir;

/* Adresses of ports*/

#define BaseA        0x39
#define BaseB        0x36
#define BaseC        0x33
#define BaseD        0x30


// #define BaseA       AdrPORT(0x39)
// #define BaseB       AdrPORT(0x36)
// #define BaseC       AdrPORT(0x33)
// #define BaseD       AdrPORT(0x30)



/* Diraction of Port*/
// #define DirPortA      DirPort(PINA, 0x01)     
// #define DirPortB      DirPort(PINB, 0x01)  
// #define DirPortC      DirPort(PINC, 0x01)  
// #define DirPortD      DirPort(PIND, 0x01)



/* Adresses ports */
// #define PortA      DirPort(PINA, 0x02)
// #define PortA      DirPort(PINB, 0x02)
// #define PortA      DirPort(PINC, 0x02)
// #define PortA      DirPort(PIND, 0x02)

#endif /* END  AVR */

#endif /* END MCAL FILE*/