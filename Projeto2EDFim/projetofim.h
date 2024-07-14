#ifndef PROJETO_H
#define PROJETO_H
#include <stdio.h>

typedef struct dados {
    int codigo;
    char nome[30];
    int idade;
    char empresa[25];
    char departamento[40];
    double salario;
} DADOS;

typedef struct Node {
    DADOS data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

char **lerArquivo(const char *nomeArquivo, int *linha);
void liberarVetor(char **vetor, int tamanho);
void countingSort(int *V, int N);

Node *insert(Node *node, DADOS data);
int max(int a, int b);
int height(Node *node);
Node *newNode(DADOS data);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *node);

void salvarArvoreEmOrdem(Node *root, FILE *saida);

#endif
