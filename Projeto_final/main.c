#include <stdio.h>
#include <stdlib.h>
#include "projetoFinal.h"
#define numFuncionarios 14999

int main() {

  int opcao;

  printf("Programa para medi�ao de desempenho AVL x RubroNegra\n\n");

  while (1) {
    printf("--------MENU--------\n\n");
    printf("Digite o numero para a acao desejada\n");
    printf("1 - Insercao AVL desordenada.\n");
    printf("2 - Insercao AVL ordenada.\n");
    printf("3 - Insercao RubroNegra desordenada.\n");
    printf("4 - Insercao RubroNegra ordenada.\n");
    printf("Para encerrar o programa, digite 0\n\n");
    printf("Sua escolha:");
    scanf("%d", &opcao);

    switch (opcao) {
      case 0:
        return 0;

      // Inser��o AVL desordenada
      case 1:
          recebeDesordenado();

        break;
      case 2:
        recebeOrdenado();

        break;

      // Inser��o RubroNegro desordenada
      case 3:
          recebeDesordenadoRB();
        // Implemente aqui
        break;

      // Inser��o RubroNegro ordenada
      case 4:
          recebeOrdenadoRB();
        // Implemente aqui


        break;

      default:
        printf("Opcao nao existente. Digite uma op�ao valida!\n");
        break;
    }
  }

  return 0;
}

