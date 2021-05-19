#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libraries/fila.h"
// #include "libraries/fila_prioridade.h"

#include "inputs/teste1-100.h"
// #include "inputs/teste1-1000.h"
// #include "inputs/teste1-10000.h"
// #include "inputs/teste1-100000.h"
// #include "inputs/teste1-1000000.h"
// #include "inputs/teste1-10000000.h"
// #include "inputs/teste1-100000000.h"

#define CLOCKTYPE CLOCK_MONOTONIC

void print_result(){
    /* time */    
    struct timespec tsi, tsf;
    double elaps_s = 0.0;
    long elaps_ns = 0;    
    clock_gettime(CLOCKTYPE, &tsi);
    // verifica_expressao();
    clock_gettime(CLOCKTYPE, &tsf);
    elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);
    elaps_ns = tsf.tv_nsec - tsi.tv_nsec;
    printf("***** Resultados *****\n");
    printf("Tempo : %lf s\n", (elaps_s + ((double)elaps_ns) / 1.0e9));
}

int main(){
    print_result();    
    return 0;
}