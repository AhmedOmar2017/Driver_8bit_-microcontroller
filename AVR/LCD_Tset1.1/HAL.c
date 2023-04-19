

#include "HAL.h"
/*==========================GPIO Functions========================================*/

void PinDir(uint8_t Base, uint8_t pin, uint8_t state){
    if(state == output){
        #if PIC_16F87XA == 1
        reset_bit(AdrPORT(OffsetAdr(Base, 0x80)), pin); 
        #else
        set_bit(AdrPORT(OffsetAdr(Base, 0x01)), pin);
        #endif 
    }else{
         #if PIC_16F87XA == 1
        set_bit(AdrPORT(OffsetAdr(Base, 0x80)), pin); 
        #else
        reset_bit(AdrPORT(OffsetAdr(Base, 0x01)), pin);
        #endif 
    }
}/*     End Pin diraction function      */

void PortDir(uint8_t Base, uint8_t state){
     if(state == output){
        #if PIC_16F87XA == 1
        AdrPORT(OffsetAdr(Base, 0x80)) = 0x00; 
        #else
        AdrPORT(OffsetAdr(Base, 0x01)) = 0xFF;
        #endif 
    }else{
         #if PIC_16F87XA == 1
        AdrPORT(OffsetAdr(Base, 0x80)) = 0xFF; 
        #else
        AdrPORT(OffsetAdr(Base, 0x01)) = 0x00;
        #endif 
    }
}/*     End Port diraction function      */

void PortWrite(uint8_t  Base, uint8_t value){
    
        #if PIC_16F87XA == 1
        AdrPORT(Base) = value; 
        #else
        AdrPORT(OffsetAdr(Base, 0x02)) = value;
        #endif 
    
}/*     End Pin write function      */

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
    

/*===================================== App functions ==============================================*/

#if LCD_4X20 == 1

/*------------------------------------LCD Command function -------------------------------------------*/
void LCD_Command(uint8_t value){
    #if Mode == 8
        PortWrite(Port_Data, value);
    #elif Mode == 4
        PortWrite(Port_Data, (value & 0xf0)); //  ?????????? oring
        PinWrite(Command, RS, low);
        PinWrite(Command, E, high);
         #if PIC_16F87XA == 1
            __delay_us(1);
         #else
            _delay_us(1);   
         #endif   
        PinWrite(Command, E, low);
         #if PIC_16F87XA == 1
            __delay_us(100);
         #else
            _delay_us(100);   
         #endif   
        PortWrite(Port_Data, (value << 4));
        
     #else
            #error Value of mode must be 4 or 8 only    
     #endif  
    PinWrite(Command, RS, low);
    PinWrite(Command, E, high);
     #if PIC_16F87XA == 1
          __delay_us(1);
    #else
          _delay_us(1);   
    #endif   
    PinWrite(Command, E, low);
    #if PIC_16F87XA == 1
          __delay_us(100);
    #else
          _delay_us(100);   
    #endif   
} /* End LCD Command function */



/*------------------------------------LCD Data function -------------------------------------------*/

volatile void LCD_Data(uint8_t value){
        PinWrite(Command, RS, high);
    #if Mode == 8
        PortWrite(Port_Data, value);
    #elif Mode == 4
        PortWrite(Port_Data, (value & 0xf0));
        PinWrite(Command, RS   , high);
        PinWrite(Command, E, high);
        #if PIC_16F87XA == 1
          __delay_us(1);
        #else
          _delay_us(1);   
        #endif   
        PinWrite(Command, E, low);
        #if PIC_16F87XA == 1
          __delay_us(100);
        #else
          _delay_us(100);   
        #endif   
        PortWrite(Port_Data, (value << 4));
    #else
        #error  Value of mode must be 4 or 8 only
    #endif
    PinWrite(Command, E, high);
     #if PIC_16F87XA == 1
        __delay_us(1);
    #else
        _delay_us(1);   
    #endif   
    PinWrite(Command, E, low);
    #if PIC_16F87XA == 1
        __delay_us(100);
    #else
        _delay_us(100);     
    #endif   
}/* End LCD Data function  */

#endif




/*===================================== App functions ==============================================*/