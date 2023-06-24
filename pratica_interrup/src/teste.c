#include "interrupt.h"

void gpioIsrconfig(gpioIntNum num){
    int val_temp = num & 31;
    int val_temp2;
    if(val_temp==0){
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR0) |= (1<<num);
    }else if(val_temp==1){
        val_temp2 = 32-num;
        if(val_temp2<0){
            val_temp2 = -val_temp2;
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR1) |= (1<<val_temp2);
    }else if(val_temp==2){
        val_temp2 = 64-num;
        if(val_temp2<0){
            val_temp2 = -val_temp2;
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<val_temp2);

    }else if(val_temp==3){
        val_temp2 = 96-num;
        if(val_temp2<0){
            val_temp2 = -val_temp2;
        }
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<val_temp2);
    }
    /*
    0--31 INTC_MIR_CLEAR0
    32--63 INTC_MIR_CLEAR1
    64--95 INTC_MIR_CLEAR3
    96--127 INTC_MIR_CLEAR4
    */
     
}
/*switch(mod){
        case GPIO0:
        if(num==GPIO0A){
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<0);
        }else{
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<1);
        }
    break;
        case GPIO1:
        if(num==GPIO1A){
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<2);
        }else{
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<3);
        }
    break;
        case GPIO2:
        if(num==GPIO2A){
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<0);
        }else{
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<1);
        }
    break;
        case GPIO3:
        if(num==GPIO3A){
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<29);
        }else{
            HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<30);
        }
    break;
    } */