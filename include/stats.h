/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Simple Statistic Tool
 * @brief Statistics tool to print basic information from a data set
 *
 * Users are able to find a minimum, maximum, mean, and median of a numeric array.
 *
 * @author Richany Nguon
 * @date 05 08 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints data values
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return Void value, prints out array values
 */

void print_array (unsigned char *data, int size);


/**
 * @brief Returns median Value of dataset
 *
 *  Given an array of data and a length, returns the median value - the middle value
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return unsigned char representing the median value of the data array
 */

char calc_median(unsigned char *data, int size);

/**
 * @brief Returns mean of dataset
 * 
 * Given an array of data and a length, returns the mean - average value
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return double datatype representing mean value of the data array
 */

double calc_mean(unsigned char *data, int size);


/**
 * @brief Returns maxmimum of dataset
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return unsigned char representing maximum value of data array
 */

char calc_max(unsigned char *data, int size);


/**
 * @brief Returns minimum of dataset
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return unsigned char representing maximum value of data array
 */

unsigned char calc_min(unsigned char *data, int size);


/**
 * @brief Find a proper place for an element to be placed in a sorted array
 *
 * Find a proper place for an element to be placed in a sorted array
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param low An int datatype that references the index of an array where the array's start range is
 * @param high An unsigned char pointer to a index of an array where the array's end range is
 * @param element An unsigned char pointer to a value of an array that will
 *
 * @return char returns a element location where element should be inserted
 */

char binary_search(unsigned char *data, unsigned char *element, signed char *high, unsigned char low);


/**
 * @brief Manipulates a array from smallest to largest. 
 *
 * Manipulates a array from smallest to largest using Binary Insertion Sort. 
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * 
 * @return Void, data array values sorted from smallest to largest
 */

void sort_data(unsigned char *data, int size);


/**
 * @brief A unsigned char pointer to an array filled with minimum, maximum, mean and median
 *
 * A function that returns a unsigned char pointer to an array with the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param data An unsigned char pointer to an array of unsigned char data types
 * @param size Int datatype representing the amount of int elements in data array
 *
 * @return A unsigned char pointer to an array, prints out minimum, maximum, mean, and median. In this case an unsigned float or int.
 */

unsigned char * print_statistics (unsigned char *data, int size);



#endif /* __STATS_H__ */
