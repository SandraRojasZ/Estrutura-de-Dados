//arvoreBin.h

// Defini��o da estrutura de um n� da �rvore
typedef struct No{
    int info;
    struct No* esq;
    struct No* dir;
} No;

// Fun��o para criar um novo n�
No* novoNo(int info);

// Fun��o para inserir um novo elemento na �rvore
No* insere(No* raiz, int info);

// Fun��o para encontrar a altura da �rvore
int altura(No* raiz);

// Fun��o para imprimir os elementos em pr�-ordem
void preOrdem(No* raiz);

// Fun��o para imprimir os elementos em ordem
void emOrdem(No* raiz);

// Fun��o para imprimir os elementos em p�s-ordem
void posOrdem(No* raiz);

// Fun��o para encontrar o n� com valor m�nimo na �rvore
No* encontrarMin(No* raiz);

// Fun��o para remover um elemento da �rvore
No* removeNo(No* raiz, int chave);

// Fun��o para buscar um elemento na �rvore
No* buscar(No* raiz, int chave);

// Fun��o para calcular o total de n�s na �rvore
int contNos(No* raiz);

