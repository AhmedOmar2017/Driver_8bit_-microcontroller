

#include "HAL.h"
/*==========================GPIO Functions========================================*/

void PinDir(uint8_t Base, uint8_t pin, uint8_t state){
    if(state == output){
        #if PIC_16F87XA == 1
        reset_bit( AdrPORT(OffsetAdr(Base, 0x80)), pin); 
        #else
        set_bit( AdrPORT(OffsetAdr(Base, 0x01)), pin);
        #endif 
    }else{
         #if PIC_16F87XA == 1
        set_bit( AdrPORT(OffsetAdr(Base, 0x80)), pin); 
        #else
        reset_bit( AdrPORT(OffsetAdr(Base, 0x01)), pin);
        #endif 
    }
}/*     End Pin diraction function      */

void PinWrite(uint8_t  Base, uint8_t pin, uint8_t stat){
    
    if(stat == high){
        #if PIC_16F87XA == 1
        set_bit(AdrPORT(Base), pin); 
        #else
        set_bit(AdrPORT(OffsetAdr(Base, 0x02)), pin);
        #endif 
    }else{
        #if PIC_16F87XA == 1
        reset_bit(AdrPORT(Base), pin); 
        #else
        reset_bit( AdrPORT(OffsetAdr(Base, 0x02)), pin);
        #endif 
    }
    
}/*     End Pin write function      */

uint8_t PinRead(uint8_t Base, uint8_t pin){
if (AdrPORT(Base) & (1<<pin)) return 1;
else return 0;
}/*     End Pin Read function      */

void PinTaggle(uint8_t  Base, uint8_t pin){
	   #if PIC_16F87XA == 1
			Toggle_bit(AdrPORT(Base), pin);
       #else
			Toggle_bit(AdrPORT(OffsetAdr(Base, 0x02)), pin);
       #endif
}/*     End Pin taggle function      */

/*=============================End GPIO Function=====================================*/

/*===================================== Prephrials functions ======================================*/

/*------------------------------------- Analog to Digital ------------------------------------------*/


void SelectADC (uint8_t Base, uint8_t value){
    AdrPORT(Base) |= value;
}

/*------------------------------------- End Analog to Digital --------------------------------------*/
    
/*===================================== End Prephrials functions ==================================*/    
    