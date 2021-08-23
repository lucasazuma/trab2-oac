//
// Created by lucas on 23/08/2021.
//
#include <stdio.h>
#include <stdint.h>

#define OPCODE_MASK 0x7F
#define RS2_MASK 0x1F00000
#define RS1_MASK 0xF8000
#define FUNCT3_MASK 0x7000
#define RD_MASK 0xF80
#define FUNCT7_MASK 0xFE000000
#define IMM_12_S_LOW 0xFE000000
#define IMM_12_S_TOP 0x00000F80
#define IMM_12_B_TOP_SIG_MASK 0x80000000
#define IMM_12_B_LOW_SIG_MASK 0x00000080
#define IMM_12_B_TOP_REST_MASK 0x7E000000
#define IMM_12_B_LOW_REST_MASK 0xF00
#define IMM_12_J_TOP_REST_MASK 0x000FF000
#define IMM_12_ELEVENTH_BIT_MASK 0x00100000
#define IMM_12_J_LOW_REST_MASK 0x7FE00000
#define IMM_12_U_MASK 0xFFFFF000

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

int32_t get_imm12_i(int32_t instruction) {
    return instruction >> 20;
}

int32_t get_imm12_s(int32_t instruction) {
    int32_t extracted_top = instruction & IMM_12_S_TOP;
    int32_t extracted_low = instruction & IMM_12_S_LOW;
    int32_t top = extracted_top >> 25;
    int32_t low = extracted_low >> 7;
    int32_t imm = top | low;
    return imm;
}

int32_t get_imm12_b(int32_t instruction) {
    int32_t top_sig = (instruction & IMM_12_B_TOP_SIG_MASK) >> 19;
    int32_t low_sig = (instruction & IMM_12_B_LOW_SIG_MASK) << 4;
    int32_t top_rest = (instruction & IMM_12_B_TOP_REST_MASK) >> 20;
    int32_t low_rest = (instruction & IMM_12_B_LOW_REST_MASK) >> 7;
    int32_t imm = top_sig | low_sig | top_rest | low_rest;
    return imm;
}

int32_t get_imm21_j(int32_t instruction) {
    int32_t top_sig = (instruction & IMM_12_B_TOP_SIG_MASK) >> 19;
    int32_t top_rest = (instruction & IMM_12_J_TOP_REST_MASK);
    int32_t low_sig = (instruction & IMM_12_ELEVENTH_BIT_MASK) >> 9;
    int32_t low_rest = (instruction & IMM_12_J_LOW_REST_MASK) >> 20;
    int32_t imm = top_sig | top_rest | low_sig | low_rest;
    return imm;
}

int32_t get_imm21_u(int32_t instruction) {
    return instruction & IMM_12_U_MASK;
}
