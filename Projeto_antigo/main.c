#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/*
Main
*/

int main() {
  int algoritmo;
  int qtd;

  printf(
      "Programa para avaliacao de desempenho de algoritmos de ordenacao!\n\n");

  while (1) {
    printf("--------MENU--------\n\n");
    printf("Qual algoritmo deseja testar?\n");
    printf("1 - BubbleSort\n");
    printf("2 - InsertionSort\n");
    printf("3 - SelectionSort\n");
    printf("4 - ShellSort\n");
    printf("5 - MergeSort\n");
    printf("6 - QuickSort\n");
    printf("7 - HeapSort\n");
    printf("8 - RadixSort(LSD)\n");
    printf("9 - CountigSort\n");
    printf("10 - TimSort\n");

    printf("Para encerrar o programa, digite 0\n");

    scanf("%d", &algoritmo);

    switch (algoritmo) {

    case 0:
      return 0;

    // bubblesort
    case 1:
      algoritmo = Ordena_bubbleSort;
      submenu(algoritmo);
      break;

    // InsertionSort
    case 2:
      algoritmo = Ordena_insertionSort;
      submenu(algoritmo);
      break;

    // SelectionSort
    case 3:
      algoritmo = Ordena_selectionSort;
      submenu(algoritmo);
      break;

    // ShellSort
    case 4:
      algoritmo = she11Sort;
      submenu(algoritmo);
      break;

    // MergeSort
    case 5:
      algoritmo = mergeSort;
      submenu(algoritmo);
      break;

    // QuickSort
    case 6:
      algoritmo = quicksort;
      submenu(algoritmo);
      break;

    // HeapSort
    case 7:
      algoritmo = Ordena_heapSort;
      submenu(algoritmo);
      break;

    // RadixSort
    case 8:
      algoritmo = RadixSort_lsd;
      submenu(algoritmo);
      break;

    // CountingSort
    case 9:
      algoritmo = countingSort;
      submenu(algoritmo);
      break;

    // TimSort
    case 10:
      algoritmo = timSort;
      submenu(algoritmo);
      break;

    default:
      printf("Opcao nao existente. Digite uma op�ao valida!\n");
      break;
    }
  }

  return 0;
}
