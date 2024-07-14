#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    int x;
    ArvBin *raiz;

    raiz = cria_arvBin();

    // Destruir a árvore
    liberar_arvBin(raiz);

    // Vazia
    if(vazia_arvBin(raiz)){
        printf("A arvore esta vazia.");
    }else{
        printf("A arvore possui elementos");
    }
    printf("\n");

    //Altura
    x = altura_arvBin(raiz);
    printf("Altura da arvore: %d", x);

    // Numero total de Nos
    x = totalNO_arvBin(raiz);
    printf("Total de nos na arvore: %d", x);

    //Pre Ordem
    preOrdem_arvBin(raiz);

    // Em Ordem
    emOrdem_arvBin(raiz);

    // pos Ordem
    posOrdem_arvBin(raiz);

    // Inserção na árvore de busca
    raiz = cria_arvBin();
    x = insere_arvBin(raiz, 150);
    x = insere_arvBin(raiz, 110);
    x = insere_arvBin(raiz, 100);
    x = insere_arvBin(raiz, 130);
    x = insere_arvBin(raiz, 120);
    x = insere_arvBin(raiz, 140);
    x = insere_arvBin(raiz, 160);

    // Remove
    x = remove_arvBin(raiz, 100);

    // Consulta
    printf("\nBusca na Arvore Binaria:\n");
    if(consulta_arvBin(raiz, 140)){
        printf("\nConsulta realizada com sucesso!");
    }else{
        prinft("\nElemento nao encontrado...");
    }

    return 0;
}
