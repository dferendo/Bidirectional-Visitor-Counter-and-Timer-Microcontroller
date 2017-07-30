/*!
 * \file      EEPROM.h
 * \brief     Implements data reading and writing from the EEPROM.
 */
#ifndef EEPROM_H
#define EEPROM_H

// Utility
#include <stdint.h>

/*! Frequency obtained by the datasheet. */
#define FREQ 375000
/*! Hexadecimal constant placed into the power-off
 *  register of the EEPROM to denote that the EEPROM
 *  is no longer powered off. */
#define EEPROM_OFF  0x0 	
/*!
 * Required to set bits that mark data as being saved and thus cleared.
 */
#define EEPROM_CLRSTAT1 26	
/*!
 * Required to set bits that mark data as being saved and thus cleared.
 */		
#define EEPROM_CLRSTAT2 28
/*! Used in order to effect particular offset for addressing. */
#define EEPROM_OFFSET 0x3F	
/*! 
 * Constant to be written into the EEPROM command register
 * to denote that the next command to be executed is an 8-bit write 
 */
#define EEPROM_WRITECMD 3 	 
/*!
 *  Constant to be written into the EEPROM command register
 *  to denote that the next command to be executed is an erase.
 */
#define EEPROM_ERASECMD 6
/*!
 *  Constant to be written into the EEPROM command register to
 *  denote that the next command to be executed is an 8-bit write.
 */		
#define EEPROM_READCMD 0 
														
/*! 
 *	\brief Sets power registers and several value registers for start up.
 */
void EEPROM_start(void);

/*! 
 *	\brief                  Writes 8-bits in a given page address. 
 *	\param page_offset 	Offset within the page to be written to.
 *	\param page_address     Which page in the EEPROM to write to.
 *	\param data 		Buffer from which data to be written to EEPROM is read
 */
void EEPROM_8Bit_Write(uint16_t page_offset, uint16_t page_address, void* data);

/*! 
 *	\brief                  Reads 8-bits in a certain page addres.
 *	\param page_offset      Offset within the page to be written to.
 *	\param page_address     Which page in the EEPROM to write to.
 *	\param data             Buffer to which data to be read from EEPROM is read.
 */
void EEPROM_8Bit_Read(uint16_t page_offset, uint16_t page_address, void* data);

#endif
