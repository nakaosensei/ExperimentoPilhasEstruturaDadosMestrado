#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libraries/pilha_contigua.h"
// #include "libraries/pilha_encadeada.h"
// #include "inputs/01_8.h"
// #include "inputs/02_16.h"
// #include "inputs/03_32.h"
// #include "inputs/04_64.h"
// #include "inputs/05_128.h"
// #include "inputs/f2_100k.h"
// #include "inputs/f2_200k.h"
// #include "inputs/f2_400k.h"
// #include "inputs/f2_800k.h"
#include "inputs/f2_1_6M.h"
// #include "inputs/f2_01M.h"
// #include "inputs/f2_02M.h"
// #include "inputs/f2_04M.h"
// #include "inputs/f2_08M.h"
// #include "inputs/f2_16M.h"
#define CLOCKTYPE CLOCK_MONOTONIC

int verifica_expressao(){
    Pilha* p = pilha_criar();
    int tam = strlen(expressao);
    TipoElemento saida;
    for (int i = 0; i < tam; i++){
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
            pilha_empilhar(p, expressao[i]);
        }
        if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}'){
            if(pilha_desempilhar(p, &saida)){
                if(expressao[i] == ')' && saida != '('){
                    pilha_destruir(p);
                    return 0;
                }
                if(expressao[i] == ']' && saida != '['){
                    pilha_destruir(p);
                    return 0;
                }
                if(expressao[i] == '}' && saida != '{'){
                    pilha_destruir(p);
                    return 0;
                }
            }
            else{
                pilha_destruir(p);
                return 0;
            }
        }
    }
    if(pilha_vazia(p)){
        pilha_destruir(p);
        return 1;
    }
    else{
        pilha_destruir(p);
        return 0;
    }
}


void print_result(char * number_test){
    /* time */    
    struct timespec tsi, tsf;
    double elaps_s = 0.0;
    long elaps_ns = 0;    
    clock_gettime(CLOCKTYPE, &tsi);
    verifica_expressao();
    clock_gettime(CLOCKTYPE, &tsf);
    elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);
    elaps_ns = tsf.tv_nsec - tsi.tv_nsec;
    printf("***** Arquivo de %s expressões *****\n", number_test);
    printf("Tempo : %lf s\n", (elaps_s + ((double)elaps_ns) / 1.0e9));
}

int main(){
    print_result("8");    
    return 0;
}