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
#include "platform.h"
#include "stats.h"
#define SIZE (40)


unsigned char calc_median(unsigned char *data, int size){
    unsigned char median_num = *(data+(size/2));
    return median_num;
};

unsigned char calc_mean(unsigned char *data, int size){
    int accumluator = 0;
    int i;
    unsigned char mean;
    for(i = 0; i < size; ++i){
        accumluator += (int)*(data+i);
    };
    mean = accumluator/size;
    return mean;
};

unsigned char calc_max(unsigned char *data, int size){
    unsigned char max_num = *(data+(size-1));
    return max_num;
};

unsigned char calc_min(unsigned char *data, int size){
    return *data;
};

unsigned char binary_search(unsigned char *data, unsigned char *element, signed char *high, unsigned char low){
    if(*high <= low) 
      return (*element > *(data+low)) ? (low+1) : low;
  
    unsigned char mid = (low+*high)/2;
    unsigned char one = (unsigned char)1;
    unsigned char plus_one= mid+one;
    signed char minus = mid-one ;
    signed char * minus_one = &minus;

    unsigned char mid_element = *(data+mid);
    if(*element ==  mid_element){ 
        return plus_one;      
    } else if(*element > mid_element){
        return binary_search(data, element, high, plus_one );
    } else if(*high != (unsigned char)0){
        return binary_search(data, element, minus_one, low);
    }else {
    return (signed char)-1;
    }
};

void sort_data(unsigned char *data, int size){
    int i;
    unsigned char selected, location;
    signed char end_range;

    signed char *end_range_ptr;
    unsigned char *selected_ptr;

    end_range_ptr = &end_range; 
    selected_ptr = &selected;

    for(i = 1; i < size; ++i){
        *end_range_ptr= i - 1;
        *selected_ptr = *(data+i);
        unsigned char start_range = 0;
        location = binary_search(data, selected_ptr, end_range_ptr, start_range);
        
        while(*end_range_ptr >= location){
            *(data+*end_range_ptr+1) = *(data+*end_range_ptr);
            (*end_range_ptr)--;
        }
        *(data+*end_range_ptr+1) = *selected_ptr;
    }
};

unsigned char * calc_statistics (unsigned char *data, int size){
    unsigned char stats[4];
    unsigned char max = calc_max(data,size);
    unsigned char min = calc_min(data,size);
    unsigned char mean = calc_mean(data,size);
    unsigned char median = calc_median(data,size);

    stats[0] = max;
    stats[1] = min;
    stats[2] = mean;
    stats[3] = median;

    unsigned char * stats_ptr;
    stats_ptr=stats;

    return stats_ptr;
};


void print_statistics(){
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
    int i;
    unsigned char x;
    unsigned char * stats_ptr = calc_statistics(test, SIZE);
    for(i = 0; i < 4; ++i){
      PRINTF("%c", *(stats_ptr+i));
    };
    x = *stats_ptr;
    x++;
    
};

void print_array (unsigned char *data, int size){
    int i;
    for(i = 0; i < size; ++i){
        // unsigned char current = *(data+i);
        // PRINTF("%c",  current);
    };
    PRINTF("%s","\n");
};

#ifdef DEBUG
print_statistics()
#endif