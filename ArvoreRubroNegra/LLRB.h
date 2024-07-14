//Arquivo arvoreLLRB.h
typedef struct NO *arvoreLLRB;
//Arquivo arvoreLLRB.c


#define RED 1
#define BLACK 0

// fun��es auxiliares
int cor(struct NO *H);

// Inverte a cor de um n� Pai e de seus filhos
void trocaCor(struct NO *H);
//Rota��o a esquerda
struct NO *rotacionaEsquerda(struct NO *A);

//Rota��o a direita
struct NO *rotacionaDireita(struct NO *A);

//Mover um n� vermelho
struct NO *move2EsqRED(struct NO *H);

struct No *move2DirRED(struct NO *H);

//Balancear
struct NO *balancear(struct NO *H);

//Insere
int insere_arvoreLLRB(arvoreLLRB *raiz, int valor);

struct NO *insereNO(struct NO *H, int valor, int *resp);

//Remove
int remove_arvoreLLRB(arvoreLLRB *raiz, int valor;

struct NO *removeNO(struct NO *H, int valor);

struct NO *removeMenor(struct NO *H);

struct NO *procuraMenor(struct NO *atual);

