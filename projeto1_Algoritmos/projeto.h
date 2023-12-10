
// submenu pra escolha da quantidade de elementos
void submenu(void (*algoritmo_escolhido)(int[], int));

// função pra gerar vetor aleatório
int *geraVetorAleatorio(int qtd);

// função para gerar vetor crescente
int *geraVetorCrescente(int qtd);

// função para gerar vetor descrescente
int *geraVetorDecrescente(int qtd);

// função pra embaralhar os elementos do vetor
void embaralha(int *vetor, int MAX, int MIN);

// Função para executar o algoritmo escolhido 10 vezes e realizar a média de
// tempo de execução também realiza a medição de tempo de vetor crescente e decrescente
void calculatempo(void (*algoritmo_escolhido)(int[], int), int qtd);

// função para o bubbleSort
void Ordena_bubbleSort(int *v, int n);

// função para o insertSort
void Ordena_insertionSort(int *v, int n);

// função para o selectionSort
void Ordena_selectionSort(int *v, int n);

// função para o shellSort
void she11Sort(int *V, int N);

// funções para o mergeSort
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);

// funções para o quicksort
void quicksort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int finali);

// funções para o heapSort
void Ordena_heapSort(int *v, int n);
void criaHeap(int *v, int i, int f);

// função para o radixSort
void RadixSort_lsd(int arr[], int arr1[], int len);

// função para o countingSort
void countingSort(int *V, int N);

// funções para o timSort
void insertion_timSort(int arr[], int left, int right); // Função para fazer a inserção para o tim
void merge_timSort(int arr[], int l, int m, int r);      // Função para fazer a mesclagem para o tim
void timSort(int arr[], int n); // Função principal do TimSort


