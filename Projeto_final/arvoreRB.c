#include "projetoFinal.h"
#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0




arvoreLLRB *cria_arvoreLLRB () {
arvoreLLRB *raizRB = (arvoreLLRB*) malloc(sizeof (arvoreLLRB));
    if (raizRB != NULL) {
        *raizRB = NULL;
    }
    return raizRB;
}

void liberar_arvoreLLRB (arvoreLLRB *raizRB){
     if (raizRB == NULL){
         return;
     }
     libera_NORB (*raizRB);
     free (raizRB);
}

 void libera_NORB(struct NORB *norb){
     if (norb == NULL){
         return;
         }
     libera_NORB (norb->esqrb);
     libera_NORB (norb->dirrb);
     free(norb);
     norb = NULL;
 }

int vazia_arvoreLLRB(arvoreLLRB *raizRB) {
    if(raizRB == NULL) {
    return 1;
    }
    if(*raizRB == NULL) {
    return 1;
    }
return 0;
}

int altura_arvoreLLRB(arvoreLLRB *raizRB){
    if(raizRB == NULL) {
        return 0;
    }
    if(*raizRB == NULL) {
        return 0;
    }
    int altRB_esq = altura_arvoreLLRB(&((*raizRB)->esqrb));
    int altRB_dir = altura_arvoreLLRB(&((*raizRB)->dirrb));
    if(altRB_esq > altRB_dir){
        return(altRB_esq + 1);
    }else{
        return(altRB_dir + 1);
}
}



int totalNO_arvoreLLRB(arvoreLLRB *raizRB) {
    if(raizRB == NULL) {
        return 0;
    }
    if(*raizRB == NULL) {
        return 0;
    }
    int altRB_esq = totalNO_arvoreLLRB(&((*raizRB)->esqrb));
    int altRB_dir = totalNO_arvoreLLRB(&((*raizRB)->dirrb));
    return (altRB_esq + altRB_dir + 1);
}


void preOrdem_arvoreLLRB(arvoreLLRB *raizRB){
    if(raizRB == NULL) {
        return;
}

if(*raizRB != NULL) {
    printf("%d\n", (*raizRB)->infoRB);
    preOrdem_arvoreLLRB(&((*raizRB)->esqrb));
    preOrdem_arvoreLLRB(&((*raizRB)->dirrb));
}
}

void emOrdem_arvoreLLRB(arvoreLLRB *raizRB) {
    if(raizRB == NULL) {
        return;
    }
    if(*raizRB != NULL) {
        emOrdem_arvoreLLRB(&((*raizRB) ->esqrb));
        printf("%d\n", (*raizRB)->infoRB) ;
        emOrdem_arvoreLLRB(&((*raizRB)->dirrb));
    }
}

void posOrdem_arvoreLLRB(arvoreLLRB *raizRB) {

    if(raizRB == NULL) {
        return;
    }

    if(*raizRB != NULL) {
        posOrdem_arvoreLLRB (&((*raizRB)->esqrb));
        posOrdem_arvoreLLRB(&((*raizRB)->dirrb));
        printf("%d\n", (*raizRB)->infoRB);
    }
}

int insere_arvoreLLRB(arvoreLLRB *raizRB, int valor){
    int resp;
    *raizRB = insereNORB(*raizRB, valor, &resp);
    if((*raizRB) != NULL){
        (*raizRB)->cor = BLACK;
    }
    return resp;
}




int remove_arvoreLLRB(arvoreLLRB *raizRB, int valor){
    if(consulta_arvoreLLRB(raizRB, valor)){
        struct NORB *H = *raizRB;
        *raizRB = removeNO(H, valor);
        if(*raizRB != NULL){
            (*raizRB)->cor = BLACK;
        }
        return 1;
    }else{
        return 0;
    }
}



int consulta_arvoreLLRB(arvoreLLRB *raizRB, int valor) {
    if (raizRB == NULL) {
        return 0;
    }

    struct NORB *atual = *raizRB;
    while(atual != NULL){
        if (valor == atual->infoRB) {
            return 1;
        }
        if (valor > atual->infoRB) {
        atual = atual->dirrb;
        }else{
        atual = atual->esqrb;
        }
    }
    return 0;
}

//fun��es auxiliares
int cor(struct NORB *H){
    if(H == NULL){
        return BLACK;
    }else{
        return H->cor;
    }
}

void trocaCor(struct NORB *H){
    H->cor = !H->cor;
    if(H->esqrb != NULL){
        H->esqrb->cor = !H->esqrb->cor;
    }
    if(H->dirrb != NULL){
        H->dirrb->cor = !H->dirrb->cor;
    }
}

struct NORB *rotacionaEsquerda(struct NORB *A){
    struct NORB *B = A->dirrb;
    A->dirrb = B->esqrb;
    B->esqrb = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
};

struct NORB *rotacionaDireita(struct NORB *A){
    struct NORB *B = A->esqrb;
    A->esqrb = B->dirrb;
    B->dirrb = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
};

struct NORB *move2EsqRED(struct NORB *H){
    trocaCor(H);
    if(cor(H->dirrb->esqrb) == RED){
        H->dirrb = rotacionaDireita(H->dirrb);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
};

struct NORB *move2DirRED(struct NORB *H){
    trocaCor(H);
    if(cor(H->esqrb->esqrb) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
};

struct NORB *balancear(struct NORB *H){
    if(cor(H->dirrb) == RED){
        H = rotacionaEsquerda(H);
    }
    if(H->esqrb != NULL && cor(H->dirrb) == RED && cor(H->esqrb->esqrb) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esqrb) == RED && cor(H->dirrb) == RED){
        trocaCor(H);
    }
    return H;
};

struct NORB *insereNORB(struct NORB *H, int valor, int *resp){
    if(H == NULL){
        struct NORB *novo;
        novo = (struct NORB*) malloc(sizeof(struct NORB));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }
        novo->infoRB = valor;
        novo->cor = RED;
        novo->dirrb = NULL;
        novo->esqrb = NULL;
        *resp = 1;
        return novo;
    }
    if(valor == H->infoRB){
        *resp = 0;
    }else{
        if(valor < H->infoRB){
            H->esqrb = insereNORB(H->esqrb, valor, resp);
        }else{
            H->dirrb = insereNORB(H->dirrb, valor, resp);
        }
    }
    if(cor(H->dirrb) == RED && cor(H->esqrb) == BLACK){
        H = rotacionaEsquerda(H);
    }
    if(cor(H->esqrb) == RED && cor(H->esqrb->esqrb) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esqrb) == RED && cor(H->dirrb) == RED){
        trocaCor(H);
    }
    return H;
};

struct NORB *removeNO(struct NORB *H, int valor){
    if(valor < H->infoRB){
        if(cor(H->esqrb) == BLACK && cor(H->esqrb->esqrb) == BLACK){
            H = move2EsqRED(H);
        }
        H->esqrb = removeNO(H->esqrb, valor);
    }else{
        if(cor(H->esqrb) == RED){
            H = rotacionaDireita(H);
        }
        if(valor == H->infoRB && (H->dirrb == NULL)){
            free(H);
            return NULL;
        }
        if(cor(H->dirrb) == BLACK && cor(H->dirrb->esqrb) == BLACK){
            H = move2DirRED(H);
        }
        if(valor == H->infoRB){
            struct NORB *x  = procuramenorRB(H->dirrb);
            H->infoRB = x->infoRB;
            H->dirrb = removeMenorRB(H->dirrb);
        }else{
            H->dirrb = removeNO(H->dirrb, valor);
        }
    }
    return balancear(H);
};

struct NORB *procuramenorRB(struct NORB *atual){
    struct NORB *no1 = atual;
    struct NORB *no2  = atual->esqrb;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esqrb;
    }
    return no1;
};

struct NORB *removeMenorRB(struct NORB *H){
    if(H->esqrb == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esqrb) == BLACK && cor(H->esqrb->esqrb) == BLACK){
        H = move2EsqRED(H);
    }
    H->esqrb = removeMenorRB(H->esqrb);
    return balancear(H);
};




