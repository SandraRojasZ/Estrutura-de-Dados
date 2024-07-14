#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projetofim.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Inicia a contagem de tempo

    int linha;
    char **dados = lerArquivo("massaDados.csv", &linha);

    int *codigos = (int *)malloc(linha * sizeof(int));
    DADOS *dadosOrdenados = (DADOS *)malloc(linha * sizeof(DADOS));

    for (int i = 0; i < linha; i++) {
        sscanf(dados[i], "%d,%[^,],%d,%[^,],%[^,],%lf",
               &dadosOrdenados[i].codigo, dadosOrdenados[i].nome,
               &dadosOrdenados[i].idade, dadosOrdenados[i].empresa,
               dadosOrdenados[i].departamento, &dadosOrdenados[i].salario);

        codigos[i] = dadosOrdenados[i].codigo;
    }

    countingSort(codigos, linha);

// Construção da árvore AVL
    Node *root = NULL;

    for (int i = 0; i < linha; i++) {
        root = insert(root, dadosOrdenados[i]);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Árvore AVL construída em %.2f segundos.\n", cpu_time_used);


    // Salvar dados ordenados em "massaDadosOrd.csv"
    FILE *saida = fopen("massaDados.csv", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saída");
        exit(1);
    }

    salvarArvoreEmOrdem(root, saida);
    printf("Dados ordenados salvos em \"massaDados.csv\".\n");
    fclose(saida);


    // Libera memória
    liberarVetor(dados, linha);
    free(codigos);
    free(dadosOrdenados);

    return 0;
}
