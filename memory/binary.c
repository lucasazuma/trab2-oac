
#include <stdio.h>
#include "validations.h"
#include "binary.h"
#define STANDARD 0xFF

int32_t extraction_mask(uint8_t byte_index) {
    return STANDARD << (byte_index * 8);
}

int32_t int_from_byte(int32_t memory_data, int32_t mask) {
    return mask & memory_data;
}


