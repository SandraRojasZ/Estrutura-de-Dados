#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void submenu(void (*algoritmo_escolhido)(int[], int)) {
  int qtd;
  struct timeval Tempo_antes, Tempo_depois;
  double deltaT;
  double media = 0;

  while (1) {
    printf("-------- SUB-MENU --------\n\n");
    printf("Digite a quantidade de elementos a serem ordenados:\n");
    printf("Lista de Opções Disponíveis:\n");
    printf("1000\n");
    printf("5000\n");
    printf("10000\n");
    printf("20000\n");
    printf("50000\n");
    printf("100000\n");
    printf("Para encerrar o programa, digite 0\n");
    printf("Se quiser retornar ao menu anterior, digite 1\n");

    scanf("%d", &qtd);
    //int *vetor;
    int *vetor = NULL;

    switch (qtd) {

    case 0:
    exit(1);

    case 1:
      return;

    case 1000:
      for(int k = 1; k < 11;k++){

      vetor = geraVetorAleatorio(qtd);
     // Tempo do vetor aleatorio
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);

      deltaT = (Tempo_depois.tv_sec * 1000 + Tempo_depois.tv_usec / 1000.0) -
               (Tempo_antes.tv_sec * 1000 + Tempo_antes.tv_usec / 1000.0);
      printf("Tempo para execucao dos comandos: %f milissegundos\n", deltaT);
         media = media + deltaT;
          //liberando a memória
       free(vetor);
    }

      media = media / 10;
      printf("\nA media de execucao e: %f\n\n",media);

      //rodar só uma vez, não precisa media
      //gettimeoffday
      //algoritmo_escplhido(vetor_Ordenado, qtd)
      //gettimeofday
      //vetorC = geraVetorCrescente(qtd);
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      //algoritmo_escolhido(vetorC, qtd);
      gettimeofday(&Tempo_depois, NULL);

      deltaT = (Tempo_depois.tv_sec * 1000 + Tempo_depois.tv_usec / 1000.0) -
               (Tempo_antes.tv_sec * 1000 + Tempo_antes.tv_usec / 1000.0);

      printf("Tempo para execucao dos comandos (Crescente): %f milissegundos\n\n", deltaT);
      free(geraVetorCrescente);


      //gettimeoffday
      //algoritmo_escplhido(vetor_Invertido, qtd)
      //gettimeofday
      //vetorD = geraVetorDecrescente(qtd);
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      //algoritmo_escolhido(vetorD, qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec * 1000 + Tempo_depois.tv_usec / 1000.0) -
               (Tempo_antes.tv_sec * 1000 + Tempo_antes.tv_usec / 1000.0);

      printf("Tempo para execucao dos comandos (Decrescente):: %f milissegundos\n\n", deltaT);
      free(geraVetorDecrescente);

      break;

    case 5000:
      // geraVetorAleatorio(qtd);
      for(int k = 1; k < 11;k++){
      vetor = geraVetorAleatorio(qtd);

      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);

      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos: %f sequndos\n", deltaT);
         media = media + deltaT;

       //liberando a memória
      free(vetor);
      }

      media = media / 10;
      printf("\nA media de execucao e: %f\n",media);

      //rodar só uma vez, não precisa media
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos (Crescente): %f segundos\n\n", deltaT);
      free(geraVetorCrescente);

      //Vetor Invertido
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      gettimeofday(&Tempo_depois, NULL);
      printf("\n");
      printf("Tempo para execucao dos comandos (Decrescente): %f segundos\n\n", deltaT);
      free(geraVetorDecrescente);

      break;

    case 10000:
      for(int k = 1; k < 11;k++){
      vetor = geraVetorAleatorio(qtd);
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos: %f sequndos\n", deltaT);
         media = media + deltaT;
       //liberando a memória
      free(vetor);
        }

      media = media / 10;
      printf("\nA media de execucao e: %f\n",media);

       //rodar só uma vez, não precisa media
       //Vetor Ordenado
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos (Crescente): %f segundos\n\n", deltaT);
      free(geraVetorCrescente);

      //Vetor invertido
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("\n");
      printf("Tempo para execucao dos comandos (Decrescente): %f segundos\n\n", deltaT);
      free(geraVetorDecrescente);

      break;

    case 20000:
      for(int k = 1; k < 11;k++){
      vetor = geraVetorAleatorio(qtd);
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos: %f sequndos\n", deltaT);
         media = media + deltaT;

       //liberando a memória
      free(vetor);
      }

      media = media / 10;
      printf("\nA media de execucao e: %f\n",media);

       //Vetor Ordenado
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos (Crescente): %f segundos\n\n", deltaT);
      free(geraVetorCrescente);

      //Vetor invertido
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      printf("\n");
      printf("Tempo para execucao dos comandos (Decrescente): %f segundos\n\n", deltaT);
      free(geraVetorDecrescente);
      break;

    case 50000:
      for(int k = 1; k < 11;k++){
      vetor = geraVetorAleatorio(qtd);

      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos: %f sequndos\n", deltaT);
         media = media + deltaT;
     //liberando a memória
      free(vetor);
      }

      media = media / 10;
      printf("\nA media de execucao e: %f\n",media);

       //rodar só uma vez, não precisa media
       //Vetor Ordenado
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos (Crescente): %f segundos\n\n", deltaT);
      free(geraVetorCrescente);

      //Vetor invertido
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      printf("\n");
      printf("Tempo para execucao dos comandos (Decrescente): %f segundos\n\n", deltaT);
      free(geraVetorDecrescente);

      break;

    case 100000:
      for(int k = 1; k < 11;k++){
      vetor = geraVetorAleatorio(qtd);

      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(vetor, qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos: %f sequndos\n", deltaT);
         media = media + deltaT;
      //liberando a memória
      free(vetor);
      }

      media = media / 10;
      printf("\nA media de execucao e: %f\n",media);


      //rodar só uma vez, não precisa media
       //Vetor Ordenado
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorCrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
               (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
      printf("Tempo para execucao dos comandos (Crescente): %f segundos\n\n", deltaT);
      free(geraVetorCrescente);

      //Vetor invertido
      gettimeofday(&Tempo_antes, NULL);
      algoritmo_escolhido(geraVetorDecrescente(qtd), qtd);
      gettimeofday(&Tempo_depois, NULL);
      printf("\n");
      printf("Tempo para execucao dos comandos (Decrescente): %f segundos\n\n", deltaT);
      free(geraVetorDecrescente);

      break;

    default:
      printf("Opcao nao existente. Digite uma das opções da lista!\n");
      break;
    }

    //Nova adição de tempo
    struct timeval Tempo_antes, Tempo_depois;
    double deltaT;

  }
}


int calculatempo(void (*algoritmo_escolhido)(int[], int));


// corrigir geraVetorAleatorio porque está retornando um vetor com varios 0
int *geraVetorAleatorio(int qtd) {
  int MAX = qtd + 1;
  int MIN = 1;

  srand((unsigned)time(NULL));
  int j = 0;
  int *numeros = (int *)malloc((MAX - MIN) * sizeof(int));
  if (!numeros) {
    printf("Erro de alocacao!!");
    exit(1);
  }
  // qera vetor com todos os numeros do intervalo escolhido
  for (int i = 0; i < MAX - MIN; i++) {
    numeros[i] = i + MIN;
  }
  embaralha(numeros, MAX, MIN); // vetor "numeros" ja embaralhado

  return numeros;
}

//void embaralha(int *vetor, int MAX, int MIN) {
void embaralha(int *vetor, int MAX, int MIN) {
  for (int i = MAX - MIN - 1; i > 0; i--) {
    int j = rand() % (i + 1); // gera indice aleatório dentro da
    int tmp = vetor[j];       // qtd de elementos pega o elemento
    vetor[j] = vetor[i];      // no indice gerado e troca pelo
    vetor[i] = tmp;           // elemento na posiçao i
  }
}


// Função para gerar um vetor ordenado de forma crescente
int *geraVetorCrescente(int qtd) {
  int *vetor = (int *)malloc(qtd * sizeof(int));
  if (!vetor) {
    printf("Erro de alocacao!!");
    exit(1);
  }
  for (int i = 0; i < qtd; i++) {
    vetor[i] = rand() % qtd;
  }

  return vetor;
}

// Função para gerar um vetor ordenado de forma decrescente
int *geraVetorDecrescente(int qtd) {
  int *vetor = (int *)malloc(qtd * sizeof(int));
  if (!vetor) {
    printf("Erro de alocacao!!");
    exit(1);
  }
  //agora é invertido
  for (int i = qtd; i >= 0; i--) {
    vetor[i] = rand() % qtd;
  }

  return vetor;
}

void Ordena_bubbleSort(int *v, int n) {
  printf("\n");
  printf("Método escolhido: BubbleSort!\n");
  printf("Ordenando %d elementos!\n", n);
  int i, continua, aux, fim = n;
  do {
    continua = 0;
    for (i = 0; i < fim - 1; i++) {
      if (v[i] > v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        continua = i;
      }
    }
    fim--;
  } while (continua != 0);

}

void Ordena_insertionSort(int *v, int n) {
  printf("\n");
  printf("Método escolhido: InsertionSort!\n");
  printf("Ordenando %d elementos!\n", n);
  int i, j, aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    for (j = i; (j > 0) && (aux < v[j - 1]); j--) {
      v[j] = v[j - 1];
    }
    v[j] = aux;
  }
}

void Ordena_selectionSort(int *v, int n) {
  printf("\n");
  printf("Método escolhido: SelectionSort!\n");
  printf("Ordenando %d elementos!\n", n);
  int i, j, menor, troca;
  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    if (i != menor) {
      troca = v[i];
      v[i] = v[menor];
      v[menor] = troca;
    }
  }
}

void she11Sort(int *V, int N) {
  printf("\n");
  printf("Método escolhido: ShellSort!\n");
  printf("Ordenando %d elementos!\n", N);
  int i, j, h, aux;

  // Define o valor inicial de 'h' usando a sequência de Knuth
  h = 1;
  while (h < N / 3)
    h = 3 * h + 1;

  // Loop externo que diminui o valor de 'h' gradualmente
  while (h > 0) {
    // Loop interno que faz a inserção por comparação
    for (i = h; i < N; i++) {
      aux = V[i];
      j = i;

      // Realiza as trocas necessárias para inserção
      while (j >= h && aux < V[j - h]) {
        V[j] = V[j - h];
        j = j - h;
      }
      V[j] = aux;
    }

    // Atualiza o valor de 'h' de acordo com a sequência de Knuth
    h = (h - 1) / 3;
  }
}

void mergeSort(int *V, int inicio, int fim) {
  printf("\n");
  printf("Método escolhido: MergeSort!\n");

  // Declaração da variável meio
  int meio;

  if (inicio < fim) {
    // Atribuição de valor na variável meio
    // floor é uma função da biblioteca "math.h",
    // Ela devolve a parte inteira de um número
    meio = floor((inicio + fim) / 2);

    // Divide a parte esquerda de um array para um sub-array
    mergeSort(V, inicio, meio);

    // Divide a parte direita de um array para um sub-array
    mergeSort(V, meio + 1, fim);

    // Mescla os dois sub-arrays ordenando eles
    merge(V, inicio, meio, fim);
  }
}

void merge(int *V, int inicio, int meio, int fim) {
  // Declaração das variaveis
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;

  // Coleta do tamanho total desses sub-arrays
  tamanho = fim - inicio + 1;
  // Inicio do primeiro sub-array
  p1 = inicio;

  // Inicio do segundo sub-array
  p2 = meio + 1;

  // Alocação de memória
  temp = (int *)malloc(tamanho * sizeof(int));

  // Verifacação se a alocação foi bem sucedida
  if (temp != NULL) {
    // Loop que roda os sub-arrays inteiros
    for (i = 0; i < tamanho; i++) {
      // Verifica se já algum dos sub-arrays já chegou no fim
      if (!fim1 && !fim2) {
        // Caso o valor correspondente do primeiro sub-array for menor insira em
        // temp
        if (V[p1] < V[p2])
          temp[i] = V[p1++];
        // Caso contrario insira o valor correspondente do segundo sub-array
        else
          temp[i] = V[p2++];
        // Caso o primeiro sub-array tenha chegado ao fim, atribua 1
        if (p1 > meio)
          fim1 = 1;
        // Caso o segundo sub-array tenha chegado ao fim, atribua 1
        if (p2 > fim)
          fim2 = 1;
      } else {
        // Se o segundo sub-array tenha acabado vai executar
        if (!fim1)
          temp[i] = V[p1++];
        // Executa se o primeiro sub-array ter acabado
        else
          temp[i] = V[p2++];
      }
    }
    // Passa os valores do array temp para o array principal
    for (j = 0, k = inicio; j < tamanho; j++, k++)
      V[k] = temp[j];
  }
  free(temp);
}

void quicksort(int *v, int inicio, int fim) {
  printf("\n");
  printf("Método escolhido: QuickSort!\n");

  int pivo;
  if (fim > inicio) {
    pivo = particiona(v, inicio, fim);
    quicksort(v, inicio, pivo - 1);
    quicksort(v, pivo + 1, fim);
  }
}

int particiona(int *v, int inicio, int finali) {
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = finali;
  pivo = v[inicio]; // Defini o pivo primeiro elemento
  while (esq < dir) {
    while (esq <= finali && v[esq] <= pivo) // avança posição esquerda
      esq++;
    while (dir >= 0 && v[dir] > pivo) // avança posição direita
      dir--;
    if (esq < dir) {   //
      aux = v[esq];    // Trocar esq e dir
      v[esq] = v[dir]; //
      v[dir] = aux;    //
    }
  }
  v[inicio] = v[dir];
  v[dir] = pivo;
  return dir;
}

void Ordena_heapSort(int *v, int n) {
  printf("\n");
  printf("Método escolhido: HeapSort!\n");
  printf("Ordenando %d elementos!\n", n);
  int i, aux;
  for (i = (n - 1) / 2; i >= 0; i--) {
    criaHeap(v, i, n - 1);
  }
  for (i = n - 1; i >= 1; i--) {
    aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    criaHeap(v, 0, i - 1);
  }
}

void criaHeap(int *v, int i, int f) {
  int aux = v[i];
  int j = i * 2 + 1;
  while (j <= f) {
    if (j < f) {
      if (v[j] < v[j + 1]) {
        j = j + 1;
      }
    }
    if (aux < v[j]) {
      v[i] = v[j];
      i = j;
      j = 2 * i + 1;
    } else {
      j = f + 1;
    }
  }
  v[i] = aux;
}

void RadixSort_lsd(int arr[], int arr1[], int len) {
  printf("\n");
  printf("Método escolhido: RadixSort!\n");

  // Variveis de controle
  int i = 0; // locomove dentro do vetor
  int j = 0; // locomove dentro do vetor
  int k = 0; // número de casa decimais
  int t = 0; // indice do menor elemento

  int min = 0; // Armazena o menor valor encontrado
  int tmp = 0; // Armazena um valor temporario para realizar uma troca

  for (i = 0; i < len; i++) // Percorre o vetor
    arr1[i] = arr[i];       // Amazenan todos os elementos de arr em arr1

  for (k = 0; k < 3; k++) { // Varre o vetor k vezes, sendo k o número de casas
                            // decimais presentes no vetor
    for (i = 0; i < len; i++) { // Percorre o vetor
      min = arr[i] % 10;        // min recebe o resto de arr[i] / 10
      t = i;
      for (j = i + 1; j < len; j++) { // Percorre o vetor a partir do ponto i+1
        if (min > (arr[j] % 10)) {    // Se min for maior q o atual resto da
                                      // divisão do vetor por 10
          min = arr[j] % 10; // min recebe o resto a partir do valor atual
          t = j;             // t recebe j
        }
      }

      tmp = arr1[t];
      arr1[t] = arr1[i];
      arr1[i] = tmp;
      // Realiza a troca entre os indices i e t
      tmp = arr[t];
      arr[t] = arr[i];
      arr[i] = tmp;
    }
    for (j = 0; j < len; j++)
      arr[j] = arr[j] / 10; // Percorre o arr1 subdividindo ele
  }
}

void countingSort(int *V, int N) {
  int MAX = N + 1;
  int i, j, k;
  int baldes[MAX];
  // sim, ta dando erro nesse MAX, dps tem que corrigir isso

  // Inicializa os baldes com zeros
  for (i = 0; i < MAX; i++) {
    baldes[i] = 0;
  }

  // Conta as ocorrências de cada valor no array
  for (i = 0; i < N; i++) {
    baldes[V[i]]++;
  }

  i = 0; // Índice para percorrer o array original
  // Preenche o array ordenado com os valores ordenados
  for (j = 0; j < MAX; j++) {
    for (k = baldes[j]; k > 0; k--) {
      V[i++] = j;
    }
  }
}

// Função para fazer a inserção pro tim
const int RUN = 64;
int minimo(int a, int b){

    if(a < b){
        return a;
    }
    else{
        return b;
    }
}
void timInsertion(int a[], int inicio, int fim){

    int i, j, temp;

    for (i = inicio + 1; i <= fim; i++) {

        temp = a[i];
        j = i - 1;

        while(j >= 0 && temp <= a[j]){

            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
    }
}
void timMerge(int a[], int inicio, int meio, int fim){

    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int vetorEsquerdo[n1], vetorDireito[n2];

    for (int i = 0; i < n1; i++) vetorEsquerdo[i] = a[inicio + i];
    for (int j = 0; j < n2; j++) vetorDireito[j] = a[meio +1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2){

        if(vetorEsquerdo[i] <= vetorDireito[j]){

            a[k] = vetorEsquerdo[i];
            i++;
        }
        else{

            a[k] = vetorDireito[j];
            j++;
        }
        k++;
    }
    while(i < n1){

        a[k] = vetorEsquerdo[i];
        i++;
        k++;
    }
    while(j < n2){

        a[k] = vetorDireito[j];
        j++;
        k++;
    }
}
void timSort(int a[], int n){
    printf("Método escolhido: TimSort!\n");

    for(int i = 0; i < n; i+=RUN) timInsertion(a, i, minimo((i + RUN -1), (n -1)));

    for(int size = RUN; size < n; size = 2*size){

        for(int inicio = 0; inicio < n; inicio += 2*size){

            int meio = inicio + size - 1;
            int fim = minimo((inicio + 2 * size - 1),(n-1));

            if(meio < fim) timMerge(a, inicio, meio, fim);
        }
    }
}
