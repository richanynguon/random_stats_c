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
 *  Support bases 2 to 16, handles signed data.
 * ** null terminator at the end of the converted c-string
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