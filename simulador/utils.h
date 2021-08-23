//
// Created by lucas on 21/08/2021.
//

#ifndef OAC_UTILS_H
#define OAC_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include "instruction.h"

#define OPCODE_MASK 0x7F
#define RS2_MASK 0x1F00000
#define RS1_MASK 0xF8000
#define FUNCT3_MASK 0x7000
#define RD_MASK 0xF80
#define FUNCT7_MASK 0xFE000000
#define IMM_12_S_LOW 0xFE000000
#define IMM_12_S_TOP 0x00000F80

int32_t get_opcode(int32_t instruction) {
    return instruction & OPCODE_MASK;
}

int32_t get_rs2(int32_t instruction) {
    int32_t extracted = instruction & RS2_MASK;
    return extracted >> 20;
}

int32_t get_rs1(uint32_t instruction) {
    int32_t extracted = instruction & RS1_MASK;
    return extracted >> 15;
}

int32_t get_funct3(int32_t instruction) {
    int32_t extracted = instruction & FUNCT3_MASK;
    return extracted >> 12;
}

int32_t get_funct7(int32_t instruction) {
    int32_t extracted = instruction & FUNCT7_MASK;
    return extracted >> 25;
}

int32_t get_rd(int32_t instruction) {
    int32_t extracted = instruction & RD_MASK;
    return extracted >> 7;
}

int32_t get_imm12_i(int32_t instruction){
    return instruction >> 20;
}

int32_t get_imm12_s(int32_t instruction){
    int32_t extracted_top = instruction & IMM_12_S_TOP;
    int32_t extracted_low = instruction & IMM_12_S_LOW;
    int32_t top = extracted_top >> 25;
    int32_t low = extracted_low >> 7;
    int32_t imm =  top|low;
    return imm;
}

//int32_t get_imm12_s(int32_t instruction){
//    int32_t extracted_top = instruction & IMM_12_S_TOP;
//    int32_t extracted_low = instruction & IMM_12_S_LOW;
//}


#endif //OAC_UTILS_H
