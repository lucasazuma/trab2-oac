#include <stdio.h>
#include "memory/test.h"
#include "simulador/instruction.h"

/*
 * Nome: Lucas Azuma Pelicioni Ishiruji
 * Matricula: 180061623
 * Disciplina: Organização e Arquitetura de Computadores
 * Turma: C
 * Trabalho 1, acesso à memória RISC-V
 * Resumo: simular o acesso a memória RISC-V
 * Sistema Operacional: Linux
 * IDE: Clion
 * compilador: gcc
 * para compilar e rodar:
 *  -compilar:  make compile
 *  -rodar: make run
 */


int main() {
//    reset_memory();
//    printf("======================\n");
//    printf("|| testes principais||\n");
//    printf("======================\n\n");
//    run_required_tests();
//
//    printf("======================\n");
//    printf("|| testes extras||\n");
//    printf("======================\n\n");
//    extra_tests();
    printf("type I\n");
    decode(0x00500893);

    printf("type R\n");
    decode(0x00e00533);
    return 0;
}
