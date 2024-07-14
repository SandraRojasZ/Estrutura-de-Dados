#include "projetofim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **lerArquivo(const char *nomeArquivo, int *linha) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    int numLinhas = 15000;

    char **dados = (char **)malloc(numLinhas * sizeof(char *));

    for (int i = 0; i < numLinhas; i++) {
        dados[i] = (char *)malloc(15000 * sizeof(char));
        fgets(dados[i], 15000, arquivo);
    }

    *linha = numLinhas;

    fclose(arquivo);
    return dados;
}

void liberarVetor(char **vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(vetor[i]);
    }
    free(vetor);
}

void countingSort(int *V, int N) {
    int MAX = N;
    int i, j, k;

    int *baldes = (int *)malloc((MAX + 1) * sizeof(int));

    for (i = 0; i < MAX + 1; i++) {
        baldes[i] = 0;
    }

    for (i = 0; i < N; i++) {
        baldes[V[i]]++;
    }

    i = 0;
    for (j = 0; j < MAX + 1; j++) {
        for (k = 0; k < baldes[j]; k++) {
            V[i++] = j;
        }
    }
}

Node *insert(Node *node, DADOS data) {
    if (node == NULL)
        return newNode(data);

    if (data.codigo < node->data.codigo)
        node->left = insert(node->left, data);
    else if (data.codigo > node->data.codigo)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data.codigo < node->left->data.codigo)
        return rightRotate(node);

    if (balance < -1 && data.codigo > node->right->data.codigo)
        return leftRotate(node);

    if (balance > 1 && data.codigo > node->left->data.codigo) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data.codigo < node->right->data.codigo) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

Node *newNode(DADOS data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Salvará o arquivo Ordenado em AVL
void salvarArvoreEmOrdem(Node *root, FILE *saida) {
    if (root != NULL) {
        salvarArvoreEmOrdem(root->left, saida);

        fprintf(saida, "%d,%s,%d,%s,%s,%.2lf\n",
                root->data.codigo, root->data.nome, root->data.idade,
                root->data.empresa, root->data.departamento, root->data.salario);

        salvarArvoreEmOrdem(root->right, saida);
    }
}
