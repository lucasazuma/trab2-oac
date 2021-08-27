#include <stdio.h>
#include <stdlib.h>
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


int main(){
    reset_memory();
    load_mem("bin_text.bin", 0);
    load_mem("bin_data.bin", 0x2000);
    run();

    return 0;
}
