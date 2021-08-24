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
    printf("type I\n");
    decode(0x00500893);
    execute();

    printf("type R\n");
    decode(0x000004b3);
    execute();

    printf("type J\n");
    decode(0xfedff06f);
    execute();

    printf("type B\n");
    decode(0x00d5dc63 );
    execute();
    return 0;
}
