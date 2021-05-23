#include "fila_prioridade.h"
#include <string.h>

#define TAM_INICIAL 5


/**************************************
* DADOS
**************************************/
typedef struct no{
    TipoElemento dado;
    struct no* prox;
}No;


struct _filaPrioridade{
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
bool fila_ehValida(FilaPrioridade* f){
    return (f != NULL? true : false);
}

No* novoNo(TipoElemento elemento){
    No* no = (No*)malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    return no;
}

No* procuraNoPrioridade(FilaPrioridade* f, TipoElemento elemento){
    No* aux = f->inicio;
    while(aux->prox != NULL && elemento < aux->prox->dado) aux = aux->prox;

    return aux;

}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

FilaPrioridade* filaP_criar(){
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
    return f;
}

void filaP_destruir(FilaPrioridade** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    FilaPrioridade* f = *enderecoFila;
    No* aux;
    while(f->inicio != NULL){
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    free(f);
    *enderecoFila = NULL;
}

bool filaP_inserir(FilaPrioridade* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;
   
    No* novo = novoNo(elemento);

    
    if(f->inicio == NULL){ // Insere no início. É o primeiro nó da lista.
        f->inicio = f->fim = novo;
    }else if(elemento >= f->inicio->dado){ // Insere no início. Tem maior prioridade que o primeiro.
        novo->prox = f->inicio;
        f->inicio = novo;
    }else if(elemento <= f->fim->dado){ // Insere no fim. Tem menor prioridade de toda fila.
        f->fim->prox = novo;
        f->fim = novo;
    }else{ // Devolve o no que antecede a posicao correta
        No* noPosEsq = procuraNoPrioridade(f, elemento);
        novo->prox = noPosEsq->prox;
        noPosEsq->prox = novo;
   }

   f->qtde++;
   return true;
}

bool filaP_remover(FilaPrioridade* f, TipoElemento* saida){
    if(!fila_ehValida(f)) return false;
    if(filaP_vazia(f)) return false;

    *saida = f->inicio->dado;
    No* aux = f->inicio;
    f->inicio = f->inicio->prox;
    if(f->inicio == NULL) f->fim = NULL;

    f->qtde--;
    free(aux);
    return true;
}

bool filaP_primeiro(FilaPrioridade* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(filaP_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;;
}

bool filaP_vazia(FilaPrioridade* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int filaP_tamanho(FilaPrioridade* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtde;
}

FilaPrioridade* filaP_clone(FilaPrioridade* f){
    if(!fila_ehValida(f)) return NULL;

    FilaPrioridade* clone = filaP_criar();
    No* aux = f->inicio;
    while(aux != NULL){
        filaP_inserir(clone, aux->dado);
        aux = aux->prox;
    }
    return clone;
}

bool filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, long int tamVetor){
    if(!fila_ehValida(f)) return false;

    long int i;
    for(i=0; i < tamVetor ; i++){
        filaP_inserir(f, vetor[i]);
    }
    return true;
}


bool filaP_removerTodos(FilaPrioridade* f){
    if(!fila_ehValida(f)) return false;
    TipoElemento e;
    while (!filaP_vazia(f)){
        filaP_remover(f, &e);
    }
    return true;
}

bool filaP_toString(FilaPrioridade* f, char* str){
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    No* aux = f->inicio;
    
    while(aux != NULL){    
        sprintf(elemento,"%ld", aux->dado);
        strcat(str, elemento);
        if (aux->prox != NULL) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}

