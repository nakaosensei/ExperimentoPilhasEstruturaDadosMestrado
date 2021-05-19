#include "pilha_encadeada.h"


/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct _pilha{
	No *topo;
	int qtdeElementos;
};



/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool pilha_ehValida(Pilha* p){
    return (p != NULL? true: false);    
}

No* criar_no(TipoElemento elemento, No* proximoNo){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = proximoNo;
    return no;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/


Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtdeElementos = 0;
    return p;
}


void pilha_destruir(Pilha* p){
    if(!pilha_ehValida(p)) return;

    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    
    free(p);
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(!pilha_ehValida(p)) return false;
    
    No* novo = criar_no(elemento, NULL);
    novo->prox = p->topo;
    p->topo = novo;
    p->qtdeElementos++;
    return true;


}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;

    No* noRemovido = p->topo;
    p->topo = p->topo->prox;
    noRemovido->prox = NULL;
    p->qtdeElementos--;
    *saida = noRemovido->dado;
    free(noRemovido);

    return true;

}

bool pilha_topo(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;
    
    *saida = p->topo->dado;
    return true;

}

bool pilha_vazia(Pilha* p){
    return (p->qtdeElementos == 0? true: false);
}

void pilha_imprimir(Pilha* p){
    if(!pilha_ehValida(p)) return;
    
    printf("Encadeada");
    printf("[");
    No* aux = p->topo;
    while(aux != NULL){
        printf("%d", aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

int pilha_tamanho(Pilha* p){
    return p->qtdeElementos;
}
