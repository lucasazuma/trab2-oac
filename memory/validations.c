#include <stdio.h>
#include "validations.h"

#define SIZE_IN_BYTES MEM_SIZE * 4
int validates_byte_address(int32_t address){
    if(address >= 0 && address <= SIZE_IN_BYTES){
        return 1;
    }else{
        printf("endereço não valido\n\n");
        return 0;
    }
}

int validates_word_address(int32_t address){
    if(address >= 0 && address <= SIZE_IN_BYTES-4 && address%4 == 0){
        return 1;
    }else{
        printf("endereço não valido\n\n");
        return 0;
    }
}


