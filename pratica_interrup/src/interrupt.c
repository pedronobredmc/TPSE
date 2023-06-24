#include "interrupt.h"
/*Configura a máscara de interrupção*/
static int blink_mode;
void gpioIsrconfig(gpioIntNum num){
    int val_temp = num / 32;
    int val_temp2;
    if(val_temp==0){
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR0) |= (1<<num);
    }else if(val_temp==1){
        val_temp2 = 32-num;
        if(val_temp2<0){
            val_temp2 = (-1*val_temp2);
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR1) |= (1<<val_temp2);
    }else if(val_temp==2){
        val_temp2 = 64-num;
        if(val_temp2<0){
            val_temp2 = (-1*val_temp2);
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<val_temp2);

    }else if(val_temp==3){
        val_temp2 = 96-num;
        if(val_temp2<0){
            val_temp2 = (-1*val_temp2);
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<val_temp2);
    }
    /*
    0--31 INTC_MIR_CLEAR0
    32--63 INTC_MIR_CLEAR1
    64--95 INTC_MIR_CLEAR2
    96--127 INTC_MIR_CLEAR3
    */
   setBlinkMode(0);
     
}

void ISR_Handler(){
    unsigned int irq_number = HWREG(SOC_AINTC_REGS+INTC_SIR_IRQ) & 0x7f;
    switch (irq_number){
        case GPIO1A:
            gpioIsrHandler_1A();
    break;
        case GPIO1B:
            gpioIsrHandler_1B();
    break;
        case GPIO3A:
            gpioIsrHandler_3A();
    break;
        case GPIO3B:
            gpioIsrHandler_3B();
    break;
        case GPIO2A:
            gpioIsrHandler_2A();
    break;
        case GPIO2B:
            gpioIsrHandler_2B();
    break;
        case GPIO0A:
            gpioIsrHandler_0A();
    break;
        case GPIO0B:
            gpioIsrHandler_0B();
    break;
    }
    
	HWREG(SOC_AINTC_REGS+INTC_CONTROL) = 0x1;
}

/*Configura interrupção num certo pino*/
void pinGPIOinterrupt(gpioMod mod, ucPinNumber pin){
    switch (mod){
        case GPIO0:
            
            HWREG(SOC_GPIO_0_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pin);
            HWREG(SOC_GPIO_0_REGS+GPIO_RISINGDETECT) |= (1<<pin);
        break;
        
        case GPIO1:
            
            HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pin);
            HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) |= (1<<pin);
        break;
        
        case GPIO2:
            
            HWREG(SOC_GPIO_2_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pin);
            HWREG(SOC_GPIO_2_REGS+GPIO_RISINGDETECT) |= (1<<pin);
        break;

        case GPIO3:
            
            HWREG(SOC_GPIO_3_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pin);
            HWREG(SOC_GPIO_3_REGS+GPIO_RISINGDETECT) |= (1<<pin);
        break;
    }
}

void gpioIsrHandler_1A(void){
    /* Clear the status of the interrupt flags */
    HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_0) |= (1<<28);

    setBlinkMode(1);
    
}
void gpioIsrHandler_0A(void){

}
void gpioIsrHandler_0B(void){

}
void gpioIsrHandler_1B(void){

}
void gpioIsrHandler_2A(void){

}
void gpioIsrHandler_2B(void){

}
void gpioIsrHandler_3A(void){

}
void gpioIsrHandler_3B(void){

}


int getBlinkMode(){
    return blink_mode;
}

void setBlinkMode(int mode) {
    blink_mode = mode;
}