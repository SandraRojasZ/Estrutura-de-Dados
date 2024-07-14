
// Projeto h
// submenu pra escolha da quantidade de elementos
void submenu(void (*algoritmo_escolhido)(int[], int));

// fun��o pra gerar vetor aleat�rio
int *geraVetorAleatorio(int qtd);

// fun��o pra embaralhar os elementos do vetor
void embaralha(int *vetor, int MAX, int MIN);

//Ordenado - Crescente
int *geraVetorCrescente(int qtd);

//Ordenado - Inverso
int *geraVetorDecrescente(int qtd);

// fun��o para o bubbleSort
void Ordena_bubbleSort(int *v, int n);

// fun��o para o insertSort
void Ordena_insertionSort(int *v, int n);

// fun��o para o selectionSort
void Ordena_selectionSort(int *v, int n);

// fun��o para o shellSort
void she11Sort(int *V, int N);

// fun��es para o mergeSort
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio,
           int fim); //????? existe alguma fun��o do merge??

// fun��es para o quicksort
void quicksort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int finali);

// fun��es para o heapSort
void Ordena_heapSort(int *v, int n);
void criaHeap(int *v, int i, int f);

// fun��o para o radixSort
void RadixSort_lsd(int arr[], int arr1[], int len);

// fun��o para o countingSort
void countingSort(int *V, int N);

// fun��es para o timSort
void insertion_timSort(int arr[], int left,
                       int right); // Fun��o para fazer a inser��o para o tim
void merge_timSort(int arr[], int l, int m,
                   int r);      // Fun��o para fazer a mesclagem para o tim
void timSort(int arr[], int n); // Fun��o principal do TimSort

int calculatempo(void (*algoritmo_escolhido)(int vetor[], int qtd));
