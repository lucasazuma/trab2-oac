//
// Created by lucas on 21/08/2021.
//

#ifndef OAC_UTILS_H
#define OAC_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include "instruction.h"


int32_t get_opcode(int32_t instruction);

int32_t get_rs2(int32_t instruction);

int32_t get_rs1(uint32_t instruction);

int32_t get_funct3(int32_t instruction);

int32_t get_funct7(int32_t instruction);

int32_t get_rd(int32_t instruction);

int32_t get_imm12_i(int32_t instruction);

int32_t get_imm12_s(int32_t instruction);

int32_t get_imm12_b(int32_t instruction);

int32_t get_imm21_j(int32_t instruction);

int32_t get_imm21_u(int32_t instruction);


#endif //OAC_UTILS_H
