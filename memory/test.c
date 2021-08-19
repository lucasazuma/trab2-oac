//
// Created by lucas on 08/08/2021.
//

#include <stdio.h>
#include "test.h"
#include "memory.h"

void required_tests_set_memory() {
    sb(0, 0, 0x04);
    sb(0, 1, 0x03);
    sb(0, 2, 0x02);
    sb(0, 3, 0x01);
    sb(4, 0, 0xFF);
    sb(4, 1, 0xFE);
    sb(4, 2, 0xFD);
    sb(4, 3, 0xFC);
    sw(12, 0, 0xFF);
    sw(16, 0, 0xFFFF);
    sw(20, 0, 0xFFFFFFFF);
    sw(24, 0, 0x80000000);

    printf("======================\n");
    printf("|| TESTES de sb     ||\n");
    printf("======================\n\n");
    printf("sb(0, 0, 0x04);\n");
    printf("sb(0, 1, 0x03);\n");
    printf("sb(0, 2, 0x02);\n");
    printf("sb(0, 3, 0x01);\n");
    printf("sb(4, 0, 0xFF);\n");
    printf("sb(4, 1, 0xFE);\n");
    printf("sb(4, 2, 0xFD);\n");
    printf("sb(4, 3, 0xFC);\n\n");


    printf("======================\n");
    printf("|| TESTES de sw     ||\n");
    printf("======================\n\n");
    printf("sw(12, 0, 0xFF);\n");
    printf("sw(16, 0, 0xFFFF);\n");
    printf("sw(20, 0, 0xFFFFFFFF);\n");
    printf("sw(24, 0, 0x80000000);\n\n");
}

void required_tests_show_memory() {
    printf("=======================\n");
    printf("||Mostrando a memória||\n");
    printf("=======================\n\n");
    printf("mem[0] = %X\n", get_memory()[0]);
    printf("mem[1] = %X\n", get_memory()[1]);
    printf("mem[2] = %X\n", get_memory()[2]);
    printf("mem[3] = %X\n", get_memory()[3]);
    printf("mem[4] = %X\n", get_memory()[4]);
    printf("mem[5] = %X\n", get_memory()[5]);
    printf("mem[6] = %X\n\n", get_memory()[6]);
    printf("--- showing lb ---\n");
    printf("lb(4,0) = %X\n", lb(4, 0));
    printf("lb(4,1) = %X\n", lb(4, 1));
    printf("lb(4,2) = %X\n", lb(4, 2));
    printf("lb(4,3) = %X\n\n", lb(4, 3));
    printf("--- lbu ---\n")        ;
    printf("lbu(4,0) = %X\n", lbu(4,0));
    printf("lbu(4,1) = %X\n", lbu(4,1));
    printf("lbu(4,2) = %X\n", lbu(4,2));
    printf("lbu(4,3) = %X\n\n", lbu(4,3));
    printf("--- lw ---\n");
    printf("lw(12,0) = %X\n",lw(12,0));
    printf("lw(16,0) = %X\n",lw(16, 0));
    printf("lw(20,0) = %X\n",lw(20,0));
}

void extra_tests(){
    printf("CASO: sb(4000000, 0, 0);\n");
    sb(4000000, 0, 0);

    printf("CASO: sb(-2, 0, 0);\n");
    sb(-2, 0, 0);

    printf("CASO: lb(4000000, 0, 0);\n");
    lb(4000000, 0);

    printf("CASO: lb(-2, 0, 0);\n");
    lb(-2, 0);

    printf("CASO: lbu(4000000, 0, 0);\n");
    lbu(4000000, 0);

    printf("CASO: lbu(-2, 0, 0);\n");
    lbu(-2, 0);

    printf("CASO: sw(4000000, 0, 0);\n");
    sw(4000000, 0, 0);

    printf("CASO: sw(-2, 0, 0);\n");
    sw(-2, 0, 0);

    printf("CASO: sw(5, 0, 0);\n");
    sw(5, 0, 0);

    printf("CASO: lw(4000000, 0, 0);\n");
    lw(4000000, 0);

    printf("CASO: lw(-2, 0, 0);\n");
    lw(-2, 0);

    printf("CASO: sw(5, 0, 0);\n");
    lw(5, 0);
}


void run_required_tests() {
    required_tests_set_memory();
    required_tests_show_memory();
}
