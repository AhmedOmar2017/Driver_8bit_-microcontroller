

#include "HAL.h"
/*==========================GPIO Functions========================================*/

void PinDir(uint8_t Base, uint8_t pin, uint8_t state){
    if(state == output){
        #if PIC_16F87XA == 1
        set_bit( AdrPORT(DirPort(Base, 0x80)), pin); 
        #else
        set_bit( AdrPORT(DirPort(Base, 0x01)), pin);
        #endif 
    }else{
         #if PIC_16F87XA == 1
        reset_bit( AdrPORT(DirPort(Base, 0x80)), pin); 
        #else
        reset_bit( AdrPORT(DirPort(Base, 0x01)), pin);
        #endif 
    }
}

void PinWrite(uint8_t  Base, uint8_t pin, uint8_t stat){
    
    if(stat == high){
        #if PIC_16F87XA == 1
        set_bit( AdrPORT(Base), pin); 
        #else
        set_bit( AdrPORT(DirPort(Base, 0x02)), pin);
        #endif 
    }else{
        #if PIC_16F87XA == 1
        reset_bit( AdrPORT(Base), pin); 
        #else
        reset_bit( AdrPORT(DirPort(Base, 0x02)), pin);
        #endif 
    }
    
}

uint8_t PinRead(uint8_t Base, uint8_t pin){

   return (AdrPORT(Base) & (1<<pin));
}

void PinTaggle(uint8_t  Base, uint8_t pin){
	   #if PIC_16F87XA == 1
			Toggle_bit(AdrPORT(Base), pin);
       #else
			Toggle_bit(AdrPORT(DirPort(Base, 0x02)), pin);
       #endif
}
/*=============================End GPIO Function=====================================*/