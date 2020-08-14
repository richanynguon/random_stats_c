/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * Users are able to convert integer to ASCII and from ASCII to integer
 *
 * @author Richany Nguon
 * @date 05 08 2020
 *
 */

#include <stdint.h>

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts integer to ASCII
 *
 *  Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 *  All operations need to be performed using pointer arithmetic, not array indexing
 *  The number you wish to convert is passed in as a signed 32-bit integer.
 *  You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
 *  Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 *  The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 *  You must place a null terminator at the end of the converted c-string
 *  Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
 *  This function needs to handle signed data.
 *  You may not use any string functions or libraries
 *
 * @param data a value as a signed 32-bit integer
 * @param ptr A pointer where the information will be assigned to
 * @param base desired base value for conversion
 * @return  The length of the converted data 
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ASCII to integer
 *
 * Support bases 2 to 16, handles signed data.
 *
 * @param ptr A pointer to a character string to convert
 * @param digits number of digits in your character set
 * @param base desired base value for conversion
 * @return Converted 32-bit signed integer
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */