#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libraries/fila.h"
// #include "libraries/fila_prioridade.h"

// #include "inputs/teste1-100.h"
// #define SIZE 100
// #include "inputs/teste1-1000.h"
// #define SIZE 1000
// #include "inputs/teste1-10000.h"
// #define SIZE 10000
// #include "inputs/teste1-100000.h"
// #define SIZE 100000
// #include "inputs/teste1-1000000.h"
// #define SIZE 1000000
// #include "inputs/teste1-10000000.h"
// #define SIZE 10000000


#define CLOCKTYPE CLOCK_MONOTONIC

void teste_tempo(){
    /* time */    
    struct timespec tsi, tsf;
    double elaps_s = 0.0;
    long elaps_ns = 0;
    int i = 0; 
    for (i = 0; i < 50; i++){
        clock_gettime(CLOCKTYPE, &tsi);
        Fila * f = fila_criar();
        fila_inserirTodos(f, vetor, SIZE);
        fila_removerTodos(f);
        fila_destruir(&f);
        clock_gettime(CLOCKTYPE, &tsf);
        elaps_s += difftime(tsf.tv_sec, tsi.tv_sec);
        elaps_ns += tsf.tv_nsec - tsi.tv_nsec;        
    }
    elaps_s /= (double)i; 
    elaps_ns /= (long)i;
    printf("***** Resultados *****\n");
    printf("Tempo : %lf s\n", (elaps_s + ((double)elaps_ns) / 1.0e9));
}



void teste_memoria(){
    Fila * f = fila_criar();
    fila_inserirTodos(f, vetor, SIZE);
    fila_removerTodos(f);
    fila_destruir(&f);
}

int main(){
    teste_tempo();
    // teste_memoria();
    return 0;
}