#include "projetoFinal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numFuncionarios 14999
#include <time.h>

void recebeDesordenado(){
    // Inicio da marcação do tempo
    clock_t start = clock();

    No *raiz = NULL;
    char arquivo[] = "massaDados.csv";
    DADOS *func = ler(arquivo, 0);

    inserirElementosNaArvore(&raiz, func, numFuncionarios);

    // Fim de marcação do tempo
    clock_t end = clock();
    double tempo_gasto = (double)(end - start) / CLOCKS_PER_SEC;
    // Imprimi a mensagem da marcação do tempo
    printf("O tempo de insercao dos dados desordenados na Arvore AVL eh em: %f segundos\n\n", tempo_gasto);
}

void recebeOrdenado(){
    // Inicio da marcação do tempo
    clock_t start = clock();

    No *raiz = NULL;
    char arquivo[] = "massaDados.csv";
    DADOS *func = ler(arquivo, 1);

    inserirElementosNaArvore(&raiz, func, numFuncionarios);

    // Fim de marcação do tempo
    clock_t end = clock();
    double tempo_gasto = (double)(end - start) / CLOCKS_PER_SEC;
    // Imprimir a mensagem após a construção da árvore
    printf("O tempo de ordenamento e a insersao na Arvore AVL eh em: %f segundos\n\n", tempo_gasto);
}

void recebeDesordenadoRB(){
    // Inicio da marcação do tempo
    clock_t start = clock();

    Norb *raiz = NULL;
    char arquivo[] = "massaDados.csv";
    DADOS *func = ler(arquivo, 0);

    inserirElementosNaArvore(&raiz, func, numFuncionarios);

    // Fim de marcação do tempo
    clock_t end = clock();
    double tempo_gasto = (double)(end - start) / CLOCKS_PER_SEC;
    // Imprimi a mensagem da marcação do tempo
    printf("O tempo de insercao dos dados desordenados na Arvore RB eh em: %f segundos\n\n", tempo_gasto);
}

void recebeOrdenadoRB(){
    // Inicio da marcação do tempo
    clock_t start = clock();

    Norb *raiz = NULL;
    char arquivo[] = "massaDados.csv";
    DADOS *func = ler(arquivo, 1);

    inserirElementosNaArvore(&raiz, func, numFuncionarios);

    // Fim de marcação do tempo
    clock_t end = clock();
    double tempo_gasto = (double)(end - start) / CLOCKS_PER_SEC;
    // Imprimir a mensagem após a construção da árvore
    printf("O tempo de ordenamento e a insersao na Arvore RB eh em: %f segundos\n\n", tempo_gasto);
}


void she11Sort(DADOS *V, int N) {
    int i, j, h;
    DADOS aux;

    h = 1;
    while (h < N / 3)
        h = 3 * h + 1;

    while (h > 0) {
        for (i = h; i < N; i++) {
            aux = V[i];
            j = i;

            while (j >= h && aux.codigo < V[j - h].codigo) {
                V[j] = V[j - h];
                j = j - h;
            }
            V[j] = aux;
        }

        h = (h - 1) / 3;
    }
}

// Teste CountingSort

/*

void countingSort(DADOS *V, int N) {
  int MAX = N;
  int i, j, k;

  DADOS *baldes = (DADOS *)malloc((MAX + 1) * sizeof(DADOS));

  // Inicializa os baldes com zeros
  for (i = 0; i < MAX + 1; i++) {
    baldes[i].codigo = 0;
  }

  // Conta as ocorr�ncias de cada valor no array
  for (i = 0; i < N; i++) {
    baldes[V[i].codigo].codigo++;
  }

  i = 0; // �ndice para percorrer o array original
  // Preenche o array ordenado com os valores ordenados
  for (j = 0; j < MAX; j++) {
    for (k = baldes[j].codigo; k > 0; k--) {
      V[i++].codigo = j;
    }
  }
}
*/

/*FUNCOES ARQUIVO*/

DADOS *ler(char *f, int ordena) {
    FILE *file = fopen(f, "rt");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    DADOS *funcionarios = malloc(numFuncionarios * sizeof(DADOS));

    if (funcionarios == NULL) {
        printf("Erro de alocação de memória");
        fclose(file);
        // Adicionei para teste
        return 0;
    }

    int i = 0;
    char linha[150];
    int primeiraLinha = 1;

    while (fgets(linha, sizeof(linha), file)) {
        if (primeiraLinha) {
            primeiraLinha = 0;
            continue;  // Pula a primeira linha
        }

        funcionarios[i].codigo = atoi(strtok(linha, ";"));
        strcpy(funcionarios[i].nome, strtok(NULL, ";"));
        funcionarios[i].idade = atoi(strtok(NULL, ";"));
        strcpy(funcionarios[i].empresa, strtok(NULL, ";"));
        strcpy(funcionarios[i].departamento, strtok(NULL, ";"));
        funcionarios[i].salario = atof(strtok(NULL, "\n"));

        i++;
    }

    fclose(file);

    if(ordena == 1){
        she11Sort(funcionarios, numFuncionarios);
        //countingSort(funcionarios, numFuncionarios);
    }


   // Salva os dados no arquivo informado em csv
    FILE *file_ordenado = fopen("massaDados_ordenado.csv", "wt");
    if (file_ordenado == NULL) {
        perror("Erro ao criar o arquivo ordenado");
        free(funcionarios);  // Libera a memória alocada
        return;
    }

    for (int j = 0; j < numFuncionarios; j++) {
        fprintf(file_ordenado, "%d;%s;%d;%s;%s;%f\n", funcionarios[j].codigo, funcionarios[j].nome,
                funcionarios[j].idade, funcionarios[j].empresa, funcionarios[j].departamento,
                funcionarios[j].salario);
    }

    fclose(file_ordenado);

    return funcionarios;
}
