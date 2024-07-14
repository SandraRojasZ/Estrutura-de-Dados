#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"



// Função para criar um novo nó
No* novoNo(int info) {
    No* no = (No*)malloc(sizeof(No));
    no->info = info;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// Função para inserir um novo elemento na árvore
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

// Função para encontrar a altura da árvore
int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int esqaltura = altura(raiz->esq);
    int diraltura = altura(raiz->dir);
    return 1 + (esqaltura > diraltura ? esqaltura : diraltura);
}

// Função para imprimir os elementos em pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Função para imprimir os elementos em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d\n", raiz->info);
        emOrdem(raiz->dir);
    }
}

// Função para imprimir os elementos em pós-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

// Função para encontrar o nó com valor mínimo na árvore
No* encontrarMin(No* raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

// Função para remover um elemento da árvore
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

// Função para buscar um elemento na árvore
No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->info == chave) {
        return raiz;
    }
    if (chave < raiz->info) {
        return buscar(raiz->esq, chave);
    }
    return buscar(raiz->dir, chave);
}
// Função para calcular o total de nós na árvore
int contNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contNos(raiz->esq) + contNos(raiz->dir);
}

