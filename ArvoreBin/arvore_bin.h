//arvoreBin.h

// Definição da estrutura de um nó da árvore
typedef struct No{
    int info;
    struct No* esq;
    struct No* dir;
} No;

// Função para criar um novo nó
No* novoNo(int info);

// Função para inserir um novo elemento na árvore
No* insere(No* raiz, int info);

// Função para encontrar a altura da árvore
int altura(No* raiz);

// Função para imprimir os elementos em pré-ordem
void preOrdem(No* raiz);

// Função para imprimir os elementos em ordem
void emOrdem(No* raiz);

// Função para imprimir os elementos em pós-ordem
void posOrdem(No* raiz);

// Função para encontrar o nó com valor mínimo na árvore
No* encontrarMin(No* raiz);

// Função para remover um elemento da árvore
No* removeNo(No* raiz, int chave);

// Função para buscar um elemento na árvore
No* buscar(No* raiz, int chave);

// Função para calcular o total de nós na árvore
int contNos(No* raiz);

