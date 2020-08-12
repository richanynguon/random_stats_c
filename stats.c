/**
 * @file Simple Statistic Tool
 * @brief Statistics tool to print basic information from a data set size of 40 elements
 *
 * Users are able to find a minimum, maximum, mean, and median of a numeric array.
 *
 * @author Richany Nguon
 * @date 05 08 2020
 *
 */

#include "stats.h"
#define SIZE (40)


char calc_median(unsigned char *data, int size){};

double calc_mean(unsigned char *data, int size){};

char calc_max(unsigned char *data, int size){};

unsigned char calc_min(unsigned char *data, int size){};

char binary_search(unsigned char *data, unsigned char *element, signed char *high, unsigned char low){};

void sort_data(unsigned char *data, int size){};

char * calc_statistics (unsigned char *data, int size){};


char * main(){
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    return calc_statistics(test, SIZE);
};