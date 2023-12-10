typedef struct{
  int codigo;
  char nome[30];
  int idade;
  char empresa[25];
  char departamento[40];
  double salario;
}DADOS;

typedef struct no{
    DADOS func;
    struct no *esquerdo, *direito;
    int altura;
}No;

typedef struct NORB{
    int infoRB;
    struct NORB *esqrb;
    struct NORB *dirrb;
    int cor;
}Norb;

// algoritmo de ordenação escolhido
void she11Sort(DADOS *V, int N);

DADOS *ler(char *f, int ordena);

void liberarVetor(char **vetor, int tamanho);

void recebeDesordenado();

void recebeOrdenado();

// Teste do algoritmo de ordenção CountingSort
//void countingSort(DADOS *V, int N);

/*ARVORE AVL*/

No* novoNo(DADOS *x);

int maior(int x, int y);

int alt_no(No *no);

int fatorDeBalanceamento_NO(No *no);

No* rotacaoL(No *r);

No* rotacaoR(No *r);

No* rotacaoLR(No *r);

No* rotacaoRL(No *r);

No* balancearr(No *raiz);

No* inserir(No *raiz, DADOS *x);

void inserirElementosNaArvore(No **raiz, DADOS vetor[], int tamanho);

void imprimirArvore(No *raiz);

/*ARVORE RUBRONEGRA*/
typedef struct NORB *arvoreLLRB;

arvoreLLRB *cria_arvoreLLRB();

void liberar_arvoreLLRB (arvoreLLRB *raiz); ;


typedef struct NO *ArvAVL;

int vazia_arvoreLLRB (arvoreLLRB *raiz);

int altura_arvoreLLRB (arvoreLLRB *raiz);

int totalNO_arvoreLLRB(arvoreLLRB *raiz);

void preOrdem_arvoreLLRB(arvoreLLRB *raiz);

void emOrdem_arvoreLLRB(arvoreLLRB *raiz);

void posOrdem_arvoreLLRB(arvoreLLRB *raiz);

int insere_arvoreLLRB(arvoreLLRB *raiz, int valor);

int remove_arvoreLLRB(arvoreLLRB *raiz, int valor);

int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor);

struct NORB *insereNORB(struct NORB *H, int valor, int *resp);

struct NORB *removeNO(struct NORB *H, int valor);

struct NORB *removeMenorRB(struct NORB *H);

struct NORB *procuramenorRB(struct NORB *atual);
