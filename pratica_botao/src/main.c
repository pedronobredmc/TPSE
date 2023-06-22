/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "gpio.h"


/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define TIME				1000000
#define WDT_WSPR			0x48
#define WDT_WWPS			0x34
#define W_MASK				(1<< 0x4u)

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
void ledON(gpioMod  ,ucPinNumber );
void ledOFF(gpioMod ,ucPinNumber );
void disablewatchdog();
	
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main(void){
	unsigned int count=0;
	ucPinNumber port=21;
	ucPinNumber port2=6;
	pinDirection dir=OUTPUT;
	pinDirection dir2=INPUT;

	/*-----------------------------------------------------------------------------
	 *  disable Watchdog-reset
	 *-----------------------------------------------------------------------------*/
	disablewatchdog();

	/*-----------------------------------------------------------------------------
	 *  initialize UART modules
	 *-----------------------------------------------------------------------------*/
	uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);

	/*-----------------------------------------------------------------------------
	 *  initialize TIMER modules
	 *-----------------------------------------------------------------------------*/
    DMTimerSetUp();
	
	/*-----------------------------------------------------------------------------
	 *  initialize GPIO modules
	 *-----------------------------------------------------------------------------*/
	gpioInitModule(GPIO1);
	gpioInitModule(GPIO2);
	
	/*-----------------------------------------------------------------------------
	 *  configure multplex in the pin of mudule
	 *-----------------------------------------------------------------------------*/
	for(count=port; count<25; count++){
		gpioInitPin(GPIO1, count);
	}
	gpioInitPin(GPIO2, port2);
	

	/*-----------------------------------------------------------------------------
	 *  set pin direction 
	 *-----------------------------------------------------------------------------*/
	for(count=port; count<25; count++){
		gpioSetDirection(GPIO1, count, dir);	
	}
	gpioSetDirection(GPIO2, port2, dir2);

	/*-----------------------------------------------------------------------------
	 *  set pin in LOW level
	 *-----------------------------------------------------------------------------*/	
	for(count=port; count<25; count++){
		ledOFF(GPIO1, count);
	}	
  	
  	while(true){
		for(count=port; count<25; count++){
			ledON(GPIO1, count);
			Delay(1000);
		}
		for(count=port; count<25; count++){
			ledOFF(GPIO1, count);
			Delay(1000);
		}
		if((HWREG(SOC_GPIO_2_REGS+GPIO_DATAIN) & (1 << port2)) != 0){
			while((HWREG(SOC_GPIO_2_REGS+GPIO_DATAIN) & (1 << port2)) != 0){
				ledON(GPIO1, port);
				Delay(1000);
				ledOFF(GPIO1, port);
				Delay(1000);
				ledON(GPIO1, port+1);
				Delay(1000);
				ledOFF(GPIO1, port+1);
				Delay(1000);
				ledON(GPIO1, port+3);
				Delay(1000);
				ledOFF(GPIO1, port+3);
				
			}
		}
		
	}
	
	

	return(0);
} /* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledON
 *  Description:  
 * =====================================================================================
 */
void ledON(gpioMod mod, ucPinNumber pin){
	gpioSetPinValue(mod, pin, HIGH);	
}/* -----  end of function ledON  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledOFF
 *  Description:  
 * =====================================================================================
 */
void ledOFF(gpioMod mod,  ucPinNumber pin ){
	gpioSetPinValue(mod, pin, LOW);
}/* -----  end of function ledOFF  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Watchdog
 *  Description:  Disable Watchdog
 * =====================================================================================
 */
void disablewatchdog(){
	HWREG(SOC_WDT_1_REGS+WDT_WSPR) = 0xAAAA;
	while((HWREG(SOC_WDT_1_REGS+WDT_WWPS) & W_MASK) != 0x0){};
	HWREG(SOC_WDT_1_REGS+WDT_WSPR) = 0x5555;
	while ((HWREG(SOC_WDT_1_REGS+WDT_WWPS) & W_MASK) != 0x0){};
}



