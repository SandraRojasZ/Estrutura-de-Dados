// Arvore Binaria.h


typedef struct No *arvAVL;

arvAVL *cria_arvAVL();

// Destruir a �rvore
void liberar_arvAVL(arvAVL *raiz);

// Vazia
int vazia_arvAVL(arvAVL *raiz);

// Altura
int altura_arvAVL(arvAVL *raiz);

// Numero total de Nos
int totalNO_arvAVL(arvAVL *raiz);

//Pre Ordem
void preOrdem_arvAVL(arvAVL *raiz);

// Em Ordem
void emOrdem_arvAVL(arvAVL *raiz);

// pos Ordem
void posOrdem_arvAVL(arvAVL *raiz);

// Inser��o na �rvore de busca
int insere_arvAVL(arvAVL *raiz, int valor);

// Remove
int remove_arvAVL(arvAVL *raiz, int valor);

// Consulta
int consulta_arvAVL(arvAVL *raiz, int valor);



