#include <stdio.h>
#include <time.h>
#include <string.h>
// #include "libraries/fila.h"
#include "libraries/fila_prioridade.h"

// #include "inputs/aleatorio-100.h"
// #define SIZE 100
// #include "inputs/aleatorio-1000.h"
// #define SIZE 1000
// #include "inputs/aleatorio-10000.h"
// #define SIZE 10000
// #include "inputs/aleatorio-100000.h"
// #define SIZE 100000
// #include "inputs/aleatorio-1000000.h"
// #define SIZE 1000000
#include "inputs/aleatorio-10000000.h"
#define SIZE 10000000


#define CLOCKTYPE CLOCK_MONOTONIC

void teste_tempo(){
    /* time */    
    struct timespec tsi, tsf;
    double elaps_s = 0.0;
    long elaps_ns = 0;
    double elaps_s2 = 0.0;
    long elaps_ns2 = 0;        
    int i = 0; 
    FilaPrioridade * f = filaP_criar();
    for (i = 0; i < 1; i++){
        clock_gettime(CLOCKTYPE, &tsi);
        filaP_inserirTodos(f, vetor, SIZE);
        clock_gettime(CLOCKTYPE, &tsf);
        elaps_s += difftime(tsf.tv_sec, tsi.tv_sec);
        elaps_ns += tsf.tv_nsec - tsi.tv_nsec;
        
        clock_gettime(CLOCKTYPE, &tsi);
        filaP_removerTodos(f);
        clock_gettime(CLOCKTYPE, &tsf);
        elaps_s2 += difftime(tsf.tv_sec, tsi.tv_sec);
        elaps_ns2 += tsf.tv_nsec - tsi.tv_nsec;
    }
    elaps_s /= (double)i; 
    elaps_ns /= (long)i;
    elaps_s2 /= (double)i; 
    elaps_ns2 /= (long)i;
    printf("***** Resultados *****\n");
    printf("Tempo add: %lf s\n", (elaps_s + ((double)elaps_ns) / 1.0e9));
    printf("Tempo rm: %lf s\n", (elaps_s2 + ((double)elaps_ns2) / 1.0e9));

    filaP_destruir(&f);
}



void teste_memoria(){
    FilaPrioridade * f = filaP_criar();
    filaP_inserirTodos(f, vetor, SIZE);
    filaP_removerTodos(f);
    filaP_destruir(&f);
}

int main(){
    teste_tempo();
    // teste_memoria();
    return 0;
}