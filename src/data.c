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

unsigned int pow(int x, int y){
    unsigned int accumulator= 0;
    unsigned char i=0;
    for(){}
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    // data is signed integer representing the incoming data 32 bit
    // ptr is the pointer to the array that will hold the transformed data
    // base is the desired base for the ASCII number to be converted to

    // need to find how long data is 
    unsigned char length = place_values_of_integer(data);
    // for each element in data modulate with desired base to the power of place value
    unsigned char i = 0;
    while(i<length)
    {
       data % pow(base,i) / base**i;
    }
    // diveded by desired base pow place value
    // with return value access base_symbols with that number
    // copy return into a string? and set pointer to the string?
    // return length of converted data which I assume will be the same?
    // data % base ** i / base**i 


    
};

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    // take data from ptr
    // split them up by digits split them up respectively cannot exceed 127 
    // convert to signed interger
    // return results
};
