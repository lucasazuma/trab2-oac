//
// Created by lucas on 22/08/2021.
//
#include <stdio.h>
#include "instruction.h"
#include "utils.h"


void add(uint32_t rd_index, uint32_t rs1_index, uint32_t rs2_index){
    uint32_t rs1 = lw(rs1_index, 0);
    uint32_t rs2 = lw(rs2_index, 0);
    int decimal_rs1 = hex_to_decimal(rs1);
    int decimal_rs2 = hex_to_decimal(rs2);
    int decimal_rd = decimal_rs1 + decimal_rs2;
    sw(rd_index, 0, decimal_to_hex(decimal_rd));
}


