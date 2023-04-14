#include "App.h"

void GPIO_INIT(){
#if PIC_16F87XA == 1    
    #if AnalogToDegital == 0
    SelectADC (EnADC1, 0x06);
    #endif
#endif    
}