//
// Created by lucas on 22/08/2021.
//
#include <stdio.h>
#include "instruction.h"
#include "utils.h"

uint32_t opcode; //código da operação
uint32_t rs1; //índice do primeiro registrador fonte
uint32_t rs2; //índice do segundo registrador fonte
uint32_t rd; //índice do registrador destino, que recebe o resultado da operação
uint32_t shamt; //quantidade de deslocamento em instruções shift e rotate
uint32_t funct3; //código auxiliar de 3 bits para determinar a instrução a ser executada
uint32_t funct7; //código auxiliar de 7 bits para determinar a instrução a ser executada
uint32_t imm12_i; //constante de 12 bits, valor imediato em instruções tipo I
uint32_t imm12_s; //constante de 12 bits, valor imediato em instruções tipo S
uint32_t imm13; //constante de 13 bits, valor imediato em instruções tipo SB, bit 0 é sempre 0
uint32_t imm20_u; //constante de 20 bits mais significativos, 31 a 12
uint32_t imm21; //constante de 21 bits para saltos relativos, bit 0 é sempre 0


void decode(uint32_t instruction) {
    opcode = get_opcode(instruction);
    printf("OPCODE MOTHERFUCKER => %x\n\n", opcode);
    switch (opcode) {
        case R_OPCODE:
            rs1 = get_rs1(instruction);
            rs2 = get_rs2(instruction);
            funct3 = get_funct3(instruction);
            funct7 = get_funct7(instruction);
            rd = get_rd(instruction);
            printf("rs1 => %x\n", rs1);
            printf("rs2 => %x\n", rs2);
            printf("funct3 => %x\n", funct3);
            printf("funct7 => %x\n", funct7);
            printf("rd => %x\n", rd);
            printf("R OPCODE\n\n");
            break;
        case I_OPCODE1:
            printf("I_1 OPCODE\n\n");
            break;
        case I_OPCODE2:
            printf("I_2 OPCODE\n\n");
            imm12_i = get_imm12_i(instruction);
            rs1 = get_rs1(instruction);
            funct3 = get_funct3(instruction);
            funct7 = get_funct7(instruction);
            rd = get_rd(instruction);
            printf("imm12_i => %x\n", imm12_i);
            printf("rs1 => %x\n", rs1);
            printf("funct3 => %x\n", funct3);
            printf("funct7 => %x\n", funct7);
            printf("rd => %x\n", rd);
            break;
        case I_OPCODE3:
            printf("I_3 OPCODE\n\n");
            break;
        case I_OPCODE4:
            printf("I_4 OPCODE\n\n");
            break;
        case U_OPCODE1:
            printf("U_1 OPCODE\n\n");
            break;
        case U_OPCODE2:
            printf("U_2 OPCODE\n\n");
            break;
        case S_OPCODE:
            printf("S OPCODE\n\n");
            break;
        case B_OPCODE:
            printf("B OPCODE\n\n");
            break;
        case J_OPCODE:
            printf("J OPCODE\n\n");
            break;
        default:
            printf("WHAT THE FUCK IS THIS INSTRUCTION :(\n");
            break;
    }
}



