/**
 * @file memory.c 
 * @brief .
 *
 * @author Richany Nguon
 * @date 12 08 2020
 *
 */

#include <stdint.h>
#include <stddef.h>

int is_contiguous(uint8_t * dst, size_t length){
    int i;
    int results= 1;
    uint8_t * ptr =  dst;
    // no need to hold original pointer
    // you can add to address and it wont
    // affect the original pointer
    for(i=0; i<length; i++){
        if(*dst != NULL){
            dst++;
        }else{
            results=0;
        }
    }
    dst = ptr;
    return results;
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
    int i;
    int contiguous = is_contiguous(dst, length);
    uint8_t * original_dst = dst;
    uint8_t * original_src = src;
    uint8_t * return_ptr = dst;
    if(contiguous==1){
        for(i=0; i<length; i++){
            *dst = *src;
            *src = NULL;
            src++;
            dst++;
        }
        dst = original_dst;
        src = original_src;
        return dst;
    }
    else{
       return_ptr = NULL;
       return return_ptr;
    }

};

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst,  size_t length){
    int i;
    uint8_t * original_dst = dst;
    uint8_t * original_src = src;
    for(i=0; i<length; i++){
        *dst = *src;
        *src = NULL;
        src++;
        dst++;
    }
    dst = original_dst;
    src = original_src;
    return dst;
};

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
    int i;
    uint8_t * original_src = src;
    for(i=0; i<length; i++){
        *src = value;
        src++;
    }
    src = original_src;
    return src;
};

uint8_t * my_memzero(uint8_t * src, size_t length){
    int i;
    uint8_t * original_src = src;
    for(i=0; i<length; i++){
        *src = 0;
        src++;
    }
    src = original_src;
    return src;  
};

uint8_t * my_reverse(uint8_t * src, size_t length){
    int i;
    uint8_t * original_src = src;
    uint8_t * end_pointer = src + length;

    for(i=0; i<length/2; i++){
        uint8_t temp = *src;
        *src = *end_pointer;
        *end_pointer = temp;
        end_pointer--;
        src++;
    }
    src = original_src;
    return src;  
};

int32_t * reserve_words(size_t length){
// This should take number of words to allocate in dynamic memory
// All operations need to be performed using pointer arithmetic, not array indexing
// Should return a pointer to memory if successful, or a Null Pointer if not successful 

    int i;
    uint8_t * src = &length;
    uint8_t * dst = src + length;
    uint8_t * original_src = src;
    for(i=0; i<length/2; i++){
        uint8_t temp = *src;
        *src = *dst;
        *dst = temp;
        dst--;
        src++;
    }
    src= original_src;
    return src;  
}

void free_words(int32_t * src){
// Should free a dynamic memory allocation by providing the pointer src to the function
// All operations need to be performed using pointer arithmetic, not array indexing
    int i;
    *src = NULL;
    return src;  
};