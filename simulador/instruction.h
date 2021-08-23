//
// Created by lucas on 21/08/2021.
//

#ifndef OAC_INSTRUCTION_H
#define OAC_INSTRUCTION_H
#include <stdio.h>
#include <stdint.h>
#include "../memory/memory.h"

#define U_OPCODE1 0x37 //0110111
#define U_OPCODE2 0x17 //0010111
#define I_OPCODE1 0x3  //0000011
#define I_OPCODE2 0x13 //0010011
#define I_OPCODE3 0x73 //1110011
#define I_OPCODE4 0x67 //1100111
#define R_OPCODE 0x33  //0110011
#define S_OPCODE 0x23  //0100011
#define B_OPCODE 0x63  //1100011
#define J_OPCODE 0x6F  //1101111



void decode(uint32_t instruction);



#endif //OAC_INSTRUCTION_H
