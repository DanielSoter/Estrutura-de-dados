#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

//Selection
// 256 =  1 KB (0 segundos)
// 262.144 =  1 MB (141 segundos)
// 13.107.200 = 50 MB (Inviável)

//Insertion
// 256 =  1 KB (0 segundos)
// 262.144 =  1 MB (150 segundos)
// 13.107.200 = 50 MB (Inviável)

//Bubble
// 256 =  1 KB (0 segundos)
// 262.144 =  1 MB (328 segundos)
// 13.107.200 = 50 MB (Inviável)

//Quick
// 256 =  1 KB (0 segundos)
// 262.144 =  1 MB (0 segundos)
// 13.107.200 = 50 MB (10 segundos) 0,1 processador 1 teste
// 13.107.200 = 50 MB (09 segundos) 0,0 processador 2 teste

//Merge
// 256 =  1 KB (0 segundos)
// 262.144 =  1 MB (0 segundos)
// 393.216 = 1,5 MB (1 segundo) 0,0 processador 
// 13.107.200 = 50 MB (07 segundos) 1,7 processador
// 268.435.456 = 1GB ( segundos)

void preencheVetor(int *vet, int size){
    for (int i = 0; i < size; ++i) {
        vet[i] = 1 + rand() % size;
    }
}

void insertionSort(int *vet, int size, int aux){

    for (int i = 0; i < size-1; i++) {
        bool troca  = false;
        for (int j = i+1; j > 0; j--) {
            if (vet[j] < vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
                troca = true;
            }
            if(troca == false){
                break;
            }
        }
    }
}

void selectionSort(int *vet, int size, int aux){

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (vet[j] < vet[i]){ 
                aux = vet[i]; 
                vet[i] = vet[j]; 
                vet[j] = aux; 
            }
        }
    }
}

void bubbleSort(int *vet, int size, int aux){

    for (int i = 0; i < size; i++) {
        bool troca = false;
        for (int j = 0; j < size-1; j++) {
            if (vet[j] > vet[j+1]){
                aux = vet[j];             
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                troca = true;
            }
        }
        if(troca == false){
            break;
        }
    }

}

void troca(int *vet, int esq, int dir)
{
  int aux;
  aux = vet[esq];
  vet[esq] = vet[dir];
  vet[dir] = aux;
}

int particionar(int *vet, int inicio, int fim)
{
  int pivo = vet[inicio]; 
  int i = inicio + 1;       
  int j = fim;              
  while (i <= j)
  { 
    while (i <= j && vet[i] <= pivo)
    { 
      i++;
    }
    while (i <= j && vet[j] > pivo)
    { 
      j--;
    }
    if (i < j)
      troca(vet, i, j); 
  }
  troca(vet, inicio, j);
  return j;
}

void ordenarQuicksort(int *v, int esquerda, int direita)
{
  int divide;
 
  if (esquerda >= direita)
  {
    return;
  }
  divide = particionar(v, esquerda, direita); 
  ordenarQuicksort(v, esquerda, divide - 1);  
  ordenarQuicksort(v, divide + 1, direita);   
}

    
/* intercala os vetores v[esq..meio] e v[meio+1..dir] */
void mergeSort_intercala(int *v, int esq, int meio, int dir) {
    int i, j, k;
    int a_tam = meio-esq+1;
    int b_tam = dir-meio;
    int *a = (int*) malloc(sizeof(int) * a_tam);
    int *b = (int*) malloc(sizeof(int) * b_tam);
    for (i = 0; i < a_tam; i++) a[i] = v[i+esq];
    for (i = 0; i < b_tam; i++) b[i] = v[i+meio+1];

    for (i = 0, j = 0, k = esq; k <= dir; k++) {
    if (i == a_tam) v[k] = b[j++];
    else if (j == b_tam) v[k] = a[i++];
    else if (a[i] < b[j]) v[k] = a[i++];
    else v[k] = b[j++];
    }
    free(a); free(b);
}

/* ordena o vetor v[esq..dir] */
    void mergeSort_ordena(int *v, int esq, int dir) {
    if (esq == dir)
    return;

    int meio = (esq + dir) / 2;
    mergeSort_ordena(v, esq, meio);
    mergeSort_ordena(v, meio+1, dir);
    mergeSort_intercala(v, esq, meio, dir);
    return;
}

/* ordena o vetor v[0..n-1] */
void mergeSort(int *v, int n) {
    mergeSort_ordena(v, 0, n-1);

    }

//Algoritmos desenvolvidos para testes, não é recomentado executar todos os algoritmos sort de uma vez.

int main() {

    int *vet, aux, size;

    cout << "Informe um valor para dimensionar o vetor: " << endl;
    cin >> size;

    vet = (int *) malloc(size * sizeof (int)); 

    /*preencheVetor(vet, size);
    time_t start_i = time(NULL);
    insertionSort(vet, size, aux);
    time_t diff_i = time(NULL) - start_i;
    free(vet);

    preencheVetor(vet, size);
    time_t start_s = time(NULL);
    selectionSort(vet, size, aux);
    time_t diff_s = time(NULL) - start_s;
    free(vet);

    preencheVetor(vet, size);
    time_t start_b = time(NULL);
    bubbleSort(vet, size, aux);
    time_t diff_b = time(NULL) - start_b;
    free(vet);

    preencheVetor(vet, size);
    time_t start_q = time(NULL);
    ordenarQuicksort(vet, 0, size);
    time_t diff_q = time(NULL) - start_q;
    free(vet);*/

    preencheVetor(vet, size);
    time_t start_m = time(NULL);
    mergeSort(vet, size - 1);
    time_t diff_m = time(NULL) - start_m;
    free(vet);

    /*cout << "Tempo em segundos algoritmo de ordenacao Insertion: " << diff_i << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Selection: " << diff_s << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Bubble: " << diff_b << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Quick: " << diff_q << endl;*/
    cout << "Tempo em segundos algoritmo de ordenacao Merge: " << diff_m << endl;

    system("pause");
    return 0;

}
