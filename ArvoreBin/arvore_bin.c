#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"



// Fun��o para criar um novo n�
No* novoNo(int info) {
    No* no = (No*)malloc(sizeof(No));
    no->info = info;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// Fun��o para inserir um novo elemento na �rvore
No* insere(No* raiz, int info) {
    if (raiz == NULL) {
        return novoNo(info);
    }
    if (info < raiz->info) {
        raiz->esq = insere(raiz->esq, info);
    } else if (info > raiz->info) {
        raiz->dir = insere(raiz->dir, info);
    }
    return raiz;
}

// Fun��o para encontrar a altura da �rvore
int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int esqaltura = altura(raiz->esq);
    int diraltura = altura(raiz->dir);
    return 1 + (esqaltura > diraltura ? esqaltura : diraltura);
}

// Fun��o para imprimir os elementos em pr�-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Fun��o para imprimir os elementos em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d\n", raiz->info);
        emOrdem(raiz->dir);
    }
}

// Fun��o para imprimir os elementos em p�s-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

// Fun��o para encontrar o n� com valor m�nimo na �rvore
No* encontrarMin(No* raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

// Fun��o para remover um elemento da �rvore
No* removeNo(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }
    if (chave < raiz->info) {
        raiz->esq = removeNo(raiz->esq, chave);
    } else if (chave > raiz->info) {
        raiz->dir = removeNo(raiz->dir, chave);
    } else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        No* temp = encontrarMin(raiz->dir);
        raiz->info = temp->info;
        raiz->dir = removeNo(raiz->dir, temp->info);
    }
    return raiz;
}

// Fun��o para buscar um elemento na �rvore
No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->info == chave) {
        return raiz;
    }
    if (chave < raiz->info) {
        return buscar(raiz->esq, chave);
    }
    return buscar(raiz->dir, chave);
}
// Fun��o para calcular o total de n�s na �rvore
int contNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contNos(raiz->esq) + contNos(raiz->dir);
}

