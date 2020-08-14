/**
 * @file data.c 
 * @brief .
 *
 * @author Richany Nguon
 * @date 12 08 2020
 *
 */

#include <stdint.h>

char base_symbols[16] = "0123456789ABCDEF";

unsigned char place_values_of_integer(int32_t data)
{
    int32_t copy = data;
    unsigned char counter =0;
    while(data > 0)
    {
        counter++;
        copy/=10;
    }

}

unsigned int pow(unsigned int x, unsigned int y){
    unsigned int accumulator= x;
    unsigned char i=1;
    while(i<y)
    {
        if(i != 1)
        {
            accumulator*=x;
            i++;
        }
        
    }
    return accumulator;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    // data is signed integer representing the incoming data 32 bit
    // ptr is the pointer to the array that will hold the transformed data
    // base is the desired base for the ASCII number to be converted to

    // need to find how long data is 
    unsigned char length = place_values_of_integer(data);
    unsigned char i = 0;
    unsigned int 
    while(i<length)
    {
    // for each element in data modulate with desired base to the power of place value
    // diveded by desired base pow place value
        unsigned int i_casted = (unsigned int) i;
        unsigned int converted = data % pow(base,i_casted) / pow(base,i_casted);
        *(ptr+i) = 
    }
    // return length of converted data which I assume will be the same?
    return length;

    
};

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    // take data from ptr
    // split them up by digits split them up respectively cannot exceed 127 
    // convert to signed interger
    // return results
};
