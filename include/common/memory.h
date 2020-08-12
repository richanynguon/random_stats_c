/**
 * @file  memory.h
 * @brief  Basic memory movement options
 *
 * Users are able to use move, copy, set, zero, reverse, and free word functions
 *
 * @author Richany Nguon
 * @date 05 08 2020
 *
 */

#include <stdint.h>
#include <stddef.h>

#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Moves memory block from source to destination
 *
 * Moves memory from source to destination pointer, throws an error if there
 * is an overlap of source and destination without data corruption
 * 
 * @param src 2 byte pointer that points to a source
 * @param dst 2 byte pointer that points to an intended destination
 * @param length the size of the memory block
 * @return  A pointer to the destination
 */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies memory block from the source to the destination
 *
 * Copies memory from source to destination pointer, returns NULL
 * if overlap occurs, copy can happen but will corrupt data
 *
 * @param src 2 byte pointer that points to a source
 * @param dst 2 byte pointer that points to an intended destination
 * @param length the size of the memory block
 * @return A pointer to the destination
 */

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst,  size_t length);

/**
 * @brief Sets a range of bytes
 *
 * Sets a range of bytes starting from the source pointer for length of the segment
 *
 * @param src 2 byte pointer that points to the source
 * @param length the size of the memory block
 * @param value the intended value to be set in the given range
 * @return A pointer to the source
 */

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zero out all of memory in a given range.
 *
 * Sets a range of bytes to zeros
 *
 * @param src 2 byte pointer that points to the source
 * @param length the size of the memory block
 * @return A pointer to the source
 */

uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all bytes in a given range
 *
 * Reverse the order of all bytes in a given range
 *
 * @param src 2 byte pointer that points to the source
 * @param length the size of the memory block
 * @return A pointer to the source
 */

uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocate given words in dynamic memory
 *
 * Take number of words to allocate in dynamic memory
 *
 * @param length Amount of bytes needed to be allocated
 * @return A pointer to memory if successful and NULL if not
 */

int32_t * reserve_words(size_t length);

/**
 * @brief Free a dynamic memory allocation
 *
 * Free a dynamic memory allocation by providing the pointer src to the function
 *
 * @param src A pointer to the source of a specific function
 * @return void
 */

void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
