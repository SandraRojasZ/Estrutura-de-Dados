#include <stdio.h>
#include <stdlib.h>
#include "LLRB.h"

#define RED 1
#define BLACK 0

int main(){
    arvoreLLRB *raiz = NULL;

    int x;

    //Insere
    x = insere_arvoreLLRB(raiz, 150);
    x = insere_arvoreLLRB(raiz, 110);
    x = insere_arvoreLLRB(raiz, 100);
    x = insere_arvoreLLRB(raiz, 130);
    x = insere_arvoreLLRB(raiz, 120);
    x = insere_arvoreLLRB(raiz, 140);
    x = insere_arvoreLLRB(raiz, 160);

    //Remove
    remove_arvoreLLRB(raiz,100);

    return 0;

}
