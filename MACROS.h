/* 
 * MACRO.H
 *
 * 
 * Created: 3/29/2023
 * Auther: Ahmed Omar
 * *********************
 * */

#ifndef MACROS_H_
#define MACROS_H_

#include <stdint.h>
#include "Configration.h"


#define AdrPORT(addr) (*( volatile uint8_t *)(addr))

#if PIC_16F87XA == 1
    #define DirPort(port, Offset)  (port|Offset)
#else
    #define DirPort(port, Offset)  (port+Offset)
#endif /* end PIC*/


#define set_bit(reg, bit)    (reg |= 1<<bit)
#define reset_bit(reg, bit)  (reg &= ~(1<<bit)) 
#define Toggle_bit(reg, bit)  (reg^= 1<<bit)   

#endif /* MACROS_H_ */
    