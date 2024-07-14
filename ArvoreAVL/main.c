#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
    int x;
    arvAVL *raiz;

    raiz = cria_arvAVL();

    // Destruir a árvore
    liberar_arvAVL(raiz);

    // Vazia
    if(vazia_arvAVL(raiz)){
        printf("A arvore esta vazia.");
    }else{
        printf("A arvore possui elementos");
    }
    printf("\n");

    //Altura
    x = altura_arvAVL(raiz);
    printf("Altura da arvore: %d", x);

    // Numero total de Nos
    x = totalNO_arvAVL(raiz);
    printf("Total de nos na arvore: %d", x);

    //Pre Ordem
    preOrdem_arvAVL(raiz);

    // Em Ordem
    emOrdem_arvAVL(raiz);

    // pos Ordem
    posOrdem_arvAVL(raiz);

    // Inserção na árvore de busca
    raiz = cria_arvAVL();
    x = insere_arvAVL(raiz, 150);
    x = insere_arvAVL(raiz, 110);
    x = insere_arvAVL(raiz, 100);
    x = insere_arvAVL(raiz, 130);
    x = insere_arvAVL(raiz, 120);
    x = insere_arvAVL(raiz, 140);
    x = insere_arvAVL(raiz, 160);

    // Remove
    x = remove_arvAVL(raiz, 100);

    // Consulta
    printf("\nBusca na Arvore Binaria:\n");
    if(consulta_arvAVL(raiz, 140)){
        printf("\nConsulta realizada com sucesso!");
    }else{
        prinft("\nElemento nao encontrado...");
    }

    return 0;
}
