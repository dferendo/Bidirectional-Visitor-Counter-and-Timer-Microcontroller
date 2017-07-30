#include "EEPROM.h"

// Board Interfacing
#include "LPC407x_8x_177x_8x.h"

void EEPROM_start(void){
    uint32_t val, cclk;
		// Turning power off register off
    LPC_EEPROM->PWRDWN = EEPROM_OFF;
	
    cclk = SystemCoreClock;
    val = (cclk/FREQ)-1;
    LPC_EEPROM->CLKDIV = val;

    /* Setting wait state */
    val  = ((((cclk / 1000000) * 15) / 1000) + 1);
    val |= (((((cclk / 1000000) * 55) / 1000) + 1) << 8);
    val |= (((((cclk / 1000000) * 35) / 1000) + 1) << 16);
    LPC_EEPROM->WSTATE = val;
}

void EEPROM_8Bit_Write(uint16_t page_offset, uint16_t page_address, void* data){
	//send data to page register
	uint8_t *tmp8 = (uint8_t *)data;
	
	LPC_EEPROM->INT_CLR_STATUS = ((1 << EEPROM_CLRSTAT1)|(1 << EEPROM_CLRSTAT2));
	LPC_EEPROM->ADDR = (page_offset&EEPROM_OFFSET);
	LPC_EEPROM->CMD = EEPROM_WRITECMD;
	LPC_EEPROM->WDATA = *tmp8;
	
	//write data in page register to EEPROM	
  LPC_EEPROM->INT_CLR_STATUS = (1 << EEPROM_CLRSTAT1);
	LPC_EEPROM->INT_CLR_STATUS = (0x1 << EEPROM_CLRSTAT2);
	LPC_EEPROM->ADDR = ((page_address&EEPROM_OFFSET)<<6);
	
  //erase and program page command
	LPC_EEPROM->CMD = EEPROM_ERASECMD; 
  while(!((LPC_EEPROM->INT_STATUS >> EEPROM_CLRSTAT2)&0x01));
  LPC_EEPROM->INT_CLR_STATUS = (1 << EEPROM_CLRSTAT2);
}

void EEPROM_8Bit_Read(uint16_t page_offset, uint16_t page_address, void* data){
	uint8_t *tmp8 = (uint8_t *)data;
	
	LPC_EEPROM->INT_CLR_STATUS = ((1 << EEPROM_CLRSTAT1)|(1 << EEPROM_CLRSTAT2));
  LPC_EEPROM->ADDR = ((page_address&EEPROM_OFFSET)<<6)|(page_offset&EEPROM_OFFSET);
	LPC_EEPROM->CMD = EEPROM_READCMD|(1<<3);
	
  *tmp8 = (uint8_t)(LPC_EEPROM -> RDATA); 
	
  LPC_EEPROM->INT_CLR_STATUS = (1 << EEPROM_CLRSTAT1);
}
