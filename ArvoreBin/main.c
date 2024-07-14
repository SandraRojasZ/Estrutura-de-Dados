#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"


int main() {
    No* raiz = NULL;

    // Inserindo elementos na �rvore

    raiz = insere(raiz, 150);
    insere(raiz, 110);
    insere(raiz, 100);
    insere(raiz, 130);
    insere(raiz, 120);
    insere(raiz, 140);
    insere(raiz, 160);

    // Imprimindo informa��es da �rvore
    printf("A arvore possui elementos.\n");
    printf("Altura da arvore: %d\n", altura(raiz));
    // Calculando e imprimindo o total de n�s na �rvore
    int totalNos = contNos(raiz);
    printf("Total de nos na arvore: %d\n", totalNos);

    printf("\n");
    // Imprimindo elementos em pr�-ordem
    printf("Visitando em pre-Ordem:\n");
    preOrdem(raiz);

    printf("\n");
    // Imprimindo elementos em ordem
    printf("Visitando em-Ordem:\n");
    emOrdem(raiz);

    printf("\n");
    // Imprimindo elementos em p�s-ordem
    printf("Visitando em pos-Ordem:\n");
    posOrdem(raiz);

    printf("\n");
    // Removendo um elemento e imprimindo elementos em p�s-ordem
    raiz = removeNo(raiz, 100);
    printf("Visitando em pos-Ordem depois de remocao:\n");
    posOrdem(raiz);

    printf("\n");
    // Buscando um elemento na �rvore
    No* result = buscar(raiz, 130);
    if (result != NULL) {
        printf("Busca na Arvore Binaria:\nConsulta realizada com sucesso!\n");
    } else {
        printf("Busca na Arvore Binaria:\nElemento nao encontrado.\n");
    }

    printf("Hello world!\n");

    return 0;
}
