
#ifndef OAC_INSTRUCTION_H
#define OAC_INSTRUCTION_H

#include <stdio.h>
#include <stdint.h>
#include "utils.h"

void decode();

void execute();

int32_t get_imm();

void execute_R();

void execute_I_1();

void execute_I_2();

void execute_I_3();

void execute_I_4();

void execute_B();

void execute_U_1();

void execute_U_2();

void execute_S();

void execute_J();

void fetch ();

void run();



#endif //OAC_INSTRUCTION_H
