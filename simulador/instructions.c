//
// Created by lucas on 22/08/2021.
//
#include <stdio.h>
#include "instruction.h"
#include "../memory/memory.h"
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
#define DATA_SEGMENT_START 0x2000

uint32_t pc;                        // contador de programa
uint32_t ri;                            // registrador de intrucao
uint32_t sp;                            // stack pointer
uint32_t gp;                            // global pointer
int32_t breg[32] = {};
int stop = 0;

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
};

enum FUNCT7 {
    ADD7 = 0, SUB7 = 0x20, SRA7 = 0x20, SRL7 = 0, SRLI7 = 0x00, SRAI7 = 0x20
};


uint32_t opcode; //código da operação
uint32_t rs1; //índice do primeiro registrador fonte
uint32_t rs2; //índice do segundo registrador fonte
uint32_t rd; //índice do registrador destino, que recebe o resultado da operação
uint32_t shamt; //quantidade de deslocamento em instruções shift e rotate
uint32_t funct3; //código auxiliar de 3 bits para determinar a instrução a ser executada
uint32_t funct7; //código auxiliar de 7 bits para determinar a instrução a ser executada
int32_t imm12_i = 0x0; //constante de 12 bits, valor imediato em instruções tipo I
int32_t imm12_s = 0x0; //constante de 12 bits, valor imediato em instruções tipo S
int32_t imm13 = 0x0; //constante de 13 bits, valor imediato em instruções tipo SB, bit 0 é sempre 0
int32_t imm20_u = 0x0; //constante de 20 bits mais significativos, 31 a 12
int32_t imm21 = 0x0; //constante de 21 bits para saltos relativos, bit 0 é sempre 0


void fetch() {
    ri = lw(pc, 0);
    pc = pc + 4;
}

void step() {
    fetch();
    decode();
    execute();
}

void decode() {
    opcode = get_opcode(ri);
    rs1 = get_rs1(ri);
    rs2 = get_rs2(ri);
    funct3 = get_funct3(ri);
    funct7 = get_funct7(ri);
    rd = get_rd(ri);
    imm12_i = get_imm12_i(ri);
    imm12_s = get_imm12_s(ri);
    imm20_u = get_imm21_u(ri);
    imm13 = get_imm12_b(ri);
    shamt = get_shamt(ri);
    printf("ri -  %x", ri);
}

void run() {
    pc = 0; ri = 0;
    stop = 0;
    sp = 0x3ffc;
    gp = 0x1800;
    while (pc < DATA_SEGMENT_START && !stop) {
        step();
    }
}

void execute() {
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
    switch (funct7) {
        case SUB7:
            switch (funct3) {
                case ADDSUB3:
                    breg[rd] = breg[rs1] - breg[rs2];
                    break;
            }
            break;
        case ADD7:
            switch (funct3) {
                case ADDSUB3:
                    breg[rd] = breg[rs1] - breg[rs2];
                    break;
                case SLT3:
                    breg[rd] = breg[rs1] << breg[rs2];
                    break;
                case OR3:
                    breg[rd] = breg[rs1] | breg[rs2];
                    break;
                case AND3:
                    breg[rd] = breg[rs1] & breg[rs2];
                    break;
                case XOR3:
                    breg[rd] = breg[rs1] ^ breg[rs2];
                    break;
                case SLTU3:
                    breg[rd] = ((uint32_t)breg[rs1] < (uint32_t)breg[rs2]);break;
                    break;
            }
            break;
    }
}

void execute_I_1() {
    switch (funct3) {
        case LB3:
            breg[rd] = lb(breg[rs1], imm12_i);
            break;
        case LBU3:
            breg[rd] = lbu(breg[rs1], imm12_i);
            break;
        case LW3:
            breg[rd] = lw(breg[rs1], imm12_i);
            break;
    }
}

void execute_I_2() {
    switch (funct3) {
        case ADDI3:
            breg[rd] = breg[rs1] + imm12_i;
            break;
        case ANDI3:
            breg[rd] = breg[rs1] & imm12_i;
            break;
        case SLLI3:
            break;
        case ORI3:
            breg[rd] = breg[rs1] | imm12_i;
            break;
        case 3:
            switch (funct7) {
                case SRAI7:
                    breg[rd] = breg[rs1] >> shamt;
                    break;
                case SRLI7:
                    breg[rd] = (uint32_t) breg[rs1] >> shamt;
                    break;
            }
            break;
    }
}

void execute_I_3() {
    switch (breg[A7]) {
        case 1:
            printf("%d", get_memory()[breg[A0]]);
            break;
        case 4:
            printf("%s", get_memory()[breg[A0]]);
            break;
        case 10:
            stop = 1;
            break;

    }
}

void execute_I_4() {
    breg[rd] = pc;
    pc = breg[rs1] + imm12_i;
    breg[ZERO] = 0;
}

void execute_B() {
    switch (funct3) {
        case BEQ3:
            if (breg[rs1] == breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
        case BNE3:
            if (breg[rs1] != breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
        case BGE3:
            if (breg[rs1] >= breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
        case BGEU3:
            if ((uint32_t) breg[rs1] >= (uint32_t) breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
        case BLT3:
            if (breg[rs1] < breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
        case BLTU3:
            if ((uint32_t) breg[rs1] < (uint32_t) breg[rs2]) {
                pc += imm13 - 4;
            }
            break;
    }
}

void execute_U_1() {
    breg[rd] = imm20_u;
}

void execute_U_2() {
    breg[rd] = pc + imm20_u;
}

void execute_S() {
    switch (funct3) {
        case SB3:
            sb(breg[rs1], imm12_s, (int8_t)breg[rs2]);
            break;
        case SW3:
            sw(breg[rs1], imm12_s, breg[rs2]);
            break;
    }
}

void execute_J() {
    breg[rd] = pc;
    pc += imm21 - 4;
    breg[ZERO] = 0;
}




