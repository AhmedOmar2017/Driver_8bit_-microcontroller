#include "App.h"

void GPIO_INIT(){
#if PIC_16F87XA == 1    
    #if AnalogToDegital == 0
    SelectADC (EnADC1, 0x06);
    #endif
#endif    
}



void LCD_INIT(){
    #if LCD_4X20 == 1
        PortDir(Port_Data, output);         // Define the port as output to connect Data pins
        PinDir(Command, RS, output);         // Define the port as output to connect Data pins
        PinDir(Command, E, output);         // Define the port as output to connect Data pins
        PortWrite(Port_Data, 0x00);
        PinWrite(Command, E, low);          // reset pin E

        #if Mode == 8
            #if PIC_16F87XA == 1
            __delay_us(2000);
            #else
            _delay_us(2000);
            #endif 
            LCD_Command(0x38);          // Init command
        #elif Mode == 4
           #if PIC_16F87XA == 1
            __delay_us(2000);
            #else
            _delay_us(2000);
           #endif
           
            LCD_Command(0x33);           // Init command
            LCD_Command(0x32);           // Init command
            LCD_Command(0x28);           // Init command

        #else
            #error Value of mode must be 4 or 8 only    
        #endif
        LCD_Command(0x0E);           // Init command
        LCD_Command(0x01);           // Init command
         #if PIC_16F87XA == 1
            __delay_us(2000);
         #else
            _delay_us(2000);
         #endif      
        LCD_Command(0x06);           // Init command
    #endif
}

void LCD_Print(uint8_t * str){
    uint8_t i = 0;
    while(str[i] != '\0'){
        LCD_Data(str[i]);
        i++;
    }
}