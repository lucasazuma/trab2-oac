//
// Created by lucas on 07/08/2021.
//

#ifndef OAC_MEMORY_H
#define OAC_MEMORY_H
#include <stdint.h>
#define MEM_SIZE 4096

int32_t* get_memory();

void reset_memory();

int32_t lw(uint32_t address, int32_t kte);

int32_t lb(uint32_t address, int32_t kte);

int32_t lbu(uint32_t address, int32_t kte);

void sb(uint32_t address, int32_t kte, int8_t dado);

void sw(uint32_t address, int32_t kte, int32_t dado);


#endif //OAC_MEMORY_H
