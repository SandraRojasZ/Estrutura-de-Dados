// Arvore Binaria.h


typedef struct No *ArvBin;

ArvBin *cria_arvBin();

// Destruir a árvore
void liberar_arvBin(ArvBin *raiz);

// Vazia
int vazia_arvBin(ArvBin *raiz);

// Altura
int altura_arvBin(ArvBin *raiz);

// Numero total de Nos
int totalNO_arvBin(ArvBin *raiz);

//Pre Ordem
void preOrdem_arvBin(ArvBin *raiz);

// Em Ordem
void emOrdem_arvBin(ArvBin *raiz);

// pos Ordem
void posOrdem_arvBin(ArvBin *raiz);

// Inserção na árvore de busca
int insere_arvBin(ArvBin *raiz, int valor);

// Remove
int remove_arvBin(ArvBin *raiz, int valor);

// Consulta
int consulta_arvBin(ArvBin *raiz, int valor);


