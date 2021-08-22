#include <stdio.h>
#include <stdint.h>

/*
 * exemplo de instrução R Logico aritimeticas => add t0, s0 s1
 * to = rd
 * s0 = rs1
 * s1 = rs2
 * opcode 0x33
 * */
typedef struct
{
    uint8_t funct7;  /*opcode auxliar 7bits*/
    uint8_t rs2;     /*registrador de origem 5bits*/
    uint8_t rs1;     /*registrador de origem 5bits*/
    uint8_t funct3;  /*opcode auxiliar 3bits*/
    uint8_t rd;     /*registrador de destino 5bits*/
    uint8_t opcode; /*identifica a instrução 7bits*/

} Instruction_R;

/*
 * exemplo de instrução I operações com dados imediatos pequenos => add t0, s0 s1
 * to = rd
 * s0 = rs1
 * s1 = rs2
 * opcode 0x33
 * */
typedef struct
{
    uint16_t imm;  /*dado imediato 12bits*/
    uint8_t rs1;     /*registrador de origem 5bits*/
    uint8_t funct3;  /*opcode auxiliar 3bits*/
    uint8_t rd;     /*registrador de destino 5bits*/
    uint8_t opcode; /*identifica a instrução 7bits*/

} Instruction_I;

/*
 * exemplo de instrução S intruções store => sw s0, 16(s1)
 * to = rd
 * s0 = rs1
 * s1 = rs2
 * opcode 0x33
 * */
typedef struct
{
    uint16_t imm1;  /*dado imediato 7bits*/
    uint8_t rs1;     /*registrador de base para calculo do endereço (s1) 5bits*/
    uint8_t rs2;     /*registrador com dado a ser escrito (s0)*/
    uint8_t funct3;  /*opcode auxiliar 3bits*/
    uint16_t imm2;  /*dado imediato 7bits*/
    uint8_t opcode; /*identifica a instrução 7bits*/

} Instruction_I;
