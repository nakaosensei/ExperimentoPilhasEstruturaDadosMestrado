#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libraries/pilha_contigua.h"
// #include "libraries/pilha_encadeada.h"
#include "inputs/100k.h"
#include "inputs/200k.h"
#include "inputs/400k.h"
#include "inputs/800k.h"
#include "inputs/1_6M.h"

#define CLOCKTYPE CLOCK_MONOTONIC

int verifica_expressao(char * exp){
    Pilha* p = pilha_criar();
    int tam = strlen(exp);
    TipoElemento saida;
    for (int i = 0; i < tam; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            pilha_empilhar(p, exp[i]);
        }
        if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(pilha_desempilhar(p, &saida)){
                if(exp[i] == ')' && saida != '('){
                    pilha_destruir(p);
                    return 0;
                }
                if(exp[i] == ']' && saida != '['){
                    pilha_destruir(p);
                    return 0;
                }
                if(exp[i] == '}' && saida != '{'){
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


void print_result(char * number_test, char * exp){
    /* time */
    struct timespec tsi, tsf;
    clock_gettime(CLOCKTYPE, &tsi);
    verifica_expressao(exp);
    clock_gettime(CLOCKTYPE, &tsf);
    printf("***** Arquivo de %s expressões *****\n", number_test);
    double elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);
    long elaps_ns = tsf.tv_nsec - tsi.tv_nsec;
    printf("Tempo : %lf s\n", (elaps_s + ((double)elaps_ns) / 1.0e9));
}

int main(){
    print_result("100k", expressao);
    print_result("200k", expressao2);
    print_result("400k", expressao4);
    print_result("800k", expressao8);
    print_result("1,6M", expressao16);
    return 0;
}