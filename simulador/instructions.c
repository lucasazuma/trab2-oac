//
// Created by lucas on 22/08/2021.
//
#include <stdio.h>
#include "instruction.h"
#include "utils.h"

#define I_OPCODE1 0x3  //0000011
#define I_OPCODE2 0x13 //0010011
#define I_OPCODE3 0x73 //1110011
#define I_OPCODE4 0x67 //1100111
#define R_OPCODE 0x33  //0110011
#define S_OPCODE 0x23  //0100011
#define B_OPCODE 0x63  //1100011
#define J_OPCODE 0x6F  //1101111
#define U_OPCODE1 0x37 //0110111
#define U_OPCODE2 0x17 //0010111

uint32_t pc;                        // contador de programa
uint32_t ri;                            // registrador de intrucao
uint32_t sp;                            // stack pointer
uint32_t gp;                            // global pointer
int32_t breg[32];

enum REGISTERS {
    ZERO = 0, RA = 1, SP = 2, GP = 3,
    TP = 4, T0 = 5, T1 = 6, T2 = 7,
    S0 = 8, S1 = 9, A0 = 10, A1 = 11,
    A2 = 12, A3 = 13, A4 = 14, A5 = 15,
    A6 = 16, A7 = 17, S2 = 18, S3 = 19,
    S4 = 20, S5 = 21, S6 = 22, S7 = 23,
    S8 = 24, S9 = 25, S10 = 26, S11 = 27,
    T3 = 28, T4 = 29, T5 = 30, T6 = 31
};

enum FUNCT3 {
    BEQ3 = 0, BNE3 = 01, BLT3 = 04, BGE3 = 05, BLTU3 = 0x06, BGEU3 = 07,
    LB3 = 0, LH3 = 01, LW3 = 02, LBU3 = 04, LHU3 = 05,
    SB3 = 0, SH3 = 01, SW3 = 02,
    ADDSUB3 = 0, SLL3 = 01, SLT3 = 02, SLTU3 = 03,
    XOR3 = 04, SR3 = 05, OR3 = 06, AND3 = 07,
    ADDI3 = 0, ORI3 = 06, SLTI3 = 02, XORI3 = 04, ANDI3 = 07,
    SLTIU3 = 03, SLLI3 = 01, SRI3 = 05
} funct3_types;

enum FUNCT7 {
    ADD7 = 0, SUB7 = 0x20, SRA7 = 0x20, SRL7 = 0, SRLI7 = 0x00, SRAI7 = 0x20
} funct7_types;


uint32_t opcode; //código da operação
uint32_t rs1; //índice do primeiro registrador fonte
uint32_t rs2; //índice do segundo registrador fonte
uint32_t rd; //índice do registrador destino, que recebe o resultado da operação
uint32_t shamt; //quantidade de deslocamento em instruções shift e rotate
uint32_t funct3; //código auxiliar de 3 bits para determinar a instrução a ser executada
uint32_t funct7; //código auxiliar de 7 bits para determinar a instrução a ser executada
int32_t imm12_i; //constante de 12 bits, valor imediato em instruções tipo I
int32_t imm12_s; //constante de 12 bits, valor imediato em instruções tipo S
int32_t imm13; //constante de 13 bits, valor imediato em instruções tipo SB, bit 0 é sempre 0
int32_t imm20_u; //constante de 20 bits mais significativos, 31 a 12
int32_t imm21; //constante de 21 bits para saltos relativos, bit 0 é sempre 0



void decode(uint32_t instruction){
    opcode = get_opcode(instruction);
    rs1 = get_rs1(instruction);
    rs2 = get_rs2(instruction);
    funct3 = get_funct3(instruction);
    funct7 = get_funct7(instruction);
    rd = get_rd(instruction);
}

void execute() {
    printf("OPCODE MOTHERFUCKER => %x\n\n", opcode);
    switch (opcode) {
        case R_OPCODE:
            execute_R();
            break;
        case I_OPCODE1:
            execute_I_1();
            break;
        case I_OPCODE2:
            execute_I_2();
            break;
        case I_OPCODE3:
            execute_I_3();
            break;
        case I_OPCODE4:
            execute_I_4();
            break;
        case U_OPCODE1:
            execute_U_1();
            break;
        case U_OPCODE2:
            execute_U_2();
            break;
        case S_OPCODE:
            execute_S();
            break;
        case B_OPCODE:
            execute_B();
            break;
        case J_OPCODE:
            execute_J();
            break;
        default:
            printf("WHAT THE FUCK IS THIS INSTRUCTION :(\n");
            break;
    }
}

int32_t get_imm() {
    switch (opcode) {
        case I_OPCODE1:
            return get_imm12_i(ri);
            break;
        case I_OPCODE2:
            return get_imm12_i(ri);
            break;
        case I_OPCODE3:
            return get_imm12_i(ri);
            break;
        case I_OPCODE4:
            return get_imm12_i(ri);
            break;
        case S_OPCODE:
            return get_imm12_s(ri);
            break;
        case B_OPCODE:
            return get_imm12_b(ri);
            break;
        case J_OPCODE:
            return get_imm21_j(ri);
            break;
        case U_OPCODE1:
            return get_imm21_u(ri);
            break;
        case U_OPCODE2:
            return get_imm21_u(ri);
            break;
    }
}

void execute_R() {
    switch (funct7_types) {
        case ADD7:
            switch (funct3_types) {
                case ADDSUB3:
                    printf("add\n\n");
                    break;
            }
            break;
        case SUB7:
            switch (funct3_types) {
                case ADDSUB3:
                    printf("add\n\n");
                    break;
                case SLT3:
                    printf("slt\n\n");
                    break;
                case OR3:
                    printf("or\n\n");
                    break;
                case AND3:
                    printf("and");
                    break;
            }
            break;

    }
}

void execute_I_1() {
    switch (funct3_types) {
        case LB3:
            printf("lb\n\n");
            break;
        case LBU3:
            printf("lbu\n\n");
            break;
        case LW3:
            printf("lw\n\n");
            break;
    }
}

void execute_I_2() {
    switch (funct3_types) {
        case ADDI3:
            printf("ADDI\n\n");
            break;
        case ANDI3:
            printf("ADDI\n\n");
            break;
        case SLLI3:
            printf("slli\n\n");
            break;
        case ORI3:
            printf("ori\n\n");
            break;
        case 3:
            switch (funct7) {
                case SRAI7:
                    printf("srai\n\n");
                    break;
                case SRLI7:
                    printf("srli\n\n");
                    break;
            }
            break;
    }
}

void execute_I_3() {
    switch (breg[A7]) {
        case 1:
            printf("a7,1\n\n");
            break;
        case 4:
            printf("a7,4");
            break;
        case 10:
            return;

    }
}

void execute_I_4() {
//    breg[rd] = pc+ 4;
//    pc = (rs1 + imm12_i) & ~ 1;
    printf("jalr\n\n");
}

void execute_B() {
    switch (funct3_types) {
        case BEQ3:
            printf("beq\n\n");
            break;
        case BNE3:
            printf("bne\n\n");
            break;
        case BGE3:
            printf("bge\n\n");
            break;
        case BGEU3:
            printf("bgeu\n\n");
            break;
        case BLT3:
            printf("blt\n\n");
            break;
        case BLTU3:
            printf("bltu\n\n");
            break;
    }
}

void execute_U_1(){
    printf("lui\n\n");
}

void execute_U_2(){
    printf("auipc\n\n");
}

void execute_S(){
    switch(funct3_types){
        case SB3:
            printf("sb\n\n");
            break;
        case SW3:
            printf("sw\n\n");
            break;
    }
}

void execute_J(){
    printf("jal\n\n");
}




