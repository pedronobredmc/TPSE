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
	ucPinNumber port2=6;
	pinDirection dir=OUTPUT;

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
	gpioInitModule(GPIO2);
	
	/*-----------------------------------------------------------------------------
	 *  configure multplex in the pin of mudule
	 *-----------------------------------------------------------------------------*/
	gpioInitPin(GPIO2, port2);
	

	/*-----------------------------------------------------------------------------
	 *  set pin direction 
	 *-----------------------------------------------------------------------------*/
	gpioSetDirection(GPIO2, port2, dir);	
  	
  	while(true){
		ledON(GPIO2, port2);
		Delay(10);
		ledOFF(GPIO2, port2);
		Delay(10);
	
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



