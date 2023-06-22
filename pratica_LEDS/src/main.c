#include	"hw_types.h"
#include	"soc_AM335x.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/

#define TIME													1000000	//"Tempo", para o delay
#define TOGGLE          										(0x01u)

#define CM_PER_GPIO1											0xAC	//Manual, tabela na pag 1017
#define CM_PER_GPIO2											0xB0	//Manual, tabela na pag 1017

#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE   				(0x2u)
#define CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE   				(0x2u)

#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK   			(0x00040000u)
#define CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK   			(0x00040000u)

#define CM_conf_gpmc_ben1      	 								0x0878	//Manual, tabela na pag 1220
#define CM_conf_gpmc_a5         								0x0854	//Manual, tabela na pag 1220
#define CM_conf_gpmc_a6         								0x0818	//Manual, tabela na pag 1220
#define CM_conf_gpmc_a7         								0x081C	//Manual, tabela na pag 1220
#define CM_conf_gpmc_a8         								0x0820	//Manual, tabela na pag 1220
#define CM_conf_gpmc_ad12         								0x0830	//Manual, tabela na pag 1220
#define CM_conf_gpmc_ad11										0x0820	//Manual, tabela na pag 1220




#define GPIO_OE                 								0x134
#define GPIO_CLEARDATAOUT       								0x190
#define GPIO_SETDATAOUT         								0x194


unsigned int flagBlink0;
unsigned int flagBlink1;
unsigned int flagBlink2;
unsigned int flagBlink3;
unsigned int flagBlink4;
unsigned int flagBlink5;

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void delay();
static void ledInit();
static void ledInit2();
static void ledToggle0();
static void ledToggle1();
static void ledToggle2();
static void ledToggle3();
static void ledToggleled2_1();
static void ledToggleled2_2();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int _main(void){
	flagBlink0=0;	//init flag
	flagBlink1=0;	//init flag
	flagBlink2=0;	//init flag
	flagBlink3=0;	//init flag
	flagBlink4=0;	//init flag
	flagBlink5=0;	//init flag

  	
	/* Configure the green LED control pin. */
  	ledInit();
	ledInit2();
  
  	while (1){
    	ledToggle0();
		delay();
		ledToggle0();
		delay();
		ledToggle1();
		delay();
		ledToggle1();
		delay();
		ledToggle2();
		delay();
		ledToggle2();
		delay();
		ledToggle3();
		delay();
		ledToggle3();
		delay();
		ledToggleled2_1();
		delay();
		ledToggleled2_1();
		delay();
		ledToggleled2_2();
		delay();
		ledToggleled2_2();
	}

	return(0);
} /* ----------  end of function main  ---------- */


/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
static void delay(){
	volatile unsigned int ra;
	for(ra = 0; ra < TIME; ra ++);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledInit
 *  Description:  
 * =====================================================================================
 */
void ledInit(){
	
	unsigned int val_temp; 	
	/*-----------------------------------------------------------------------------
	 *  configure clock GPIO in clock module
	 *-----------------------------------------------------------------------------*/
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO1) |= CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK | CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;
	
	/*-----------------------------------------------------------------------------
	 * configure mux pin in control module
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a5) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a6) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a7) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a8) |= 7;
 	
 
	/*-----------------------------------------------------------------------------
	 *  set pin direction 
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<21);
	val_temp &= ~(1<<22);
	val_temp &= ~(1<<23);
	val_temp &= ~(1<<24);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;
	
}/* -----  end of function ledInit  ----- */

void ledInit2(){
	
	unsigned int val_temp; 	
	/*-----------------------------------------------------------------------------
	 *  configure clock GPIO in clock module
	 *-----------------------------------------------------------------------------*/
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO2) |= CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK | CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE;
	
	/*-----------------------------------------------------------------------------
	 * configure mux pin in control module
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ben1) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ad12) |= 7;
 	
 
	/*-----------------------------------------------------------------------------
	 *  set pin direction 
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
	val_temp &= ~(1<<6);
	val_temp &= ~(1<<7);
	HWREG(SOC_GPIO_2_REGS+GPIO_OE) = val_temp;
	
}/* -----  end of function ledInit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledToggle
 *  Description:  
 * =====================================================================================
 */
void ledToggle0(){
		
		flagBlink0 ^= TOGGLE;

		if(flagBlink0){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<21;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<21;
		}
}/* -----  end of function ledToggle  ----- */
void ledToggle1(){
		
		flagBlink1 ^= TOGGLE;

		if(flagBlink1){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<22;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<22;
		}
}/* -----  end of function ledToggle  ----- */
void ledToggle2(){
		
		flagBlink2 ^= TOGGLE;

		if(flagBlink2){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<23;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<23;
		}
}/* -----  end of function ledToggle  ----- */
void ledToggle3(){
		
		flagBlink3 ^= TOGGLE;

		if(flagBlink3){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<24;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<24;
		}
}/* -----  end of function ledToggle  ----- */
void ledToggleled2_1(){
		
		flagBlink5 ^= TOGGLE;

		if(flagBlink5){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<6;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<6;
		}
}/* -----  end of function ledToggle  ----- */
void ledToggleled2_2(){
		
		flagBlink4 ^= TOGGLE;

		if(flagBlink4){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<7;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<7;
		}
}/* -----  end of function ledToggle  ----- */










