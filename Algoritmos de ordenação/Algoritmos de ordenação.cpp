#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;



//Selection
// 256 =  1 MB (0 segundos)
// 262.144 =  1 GB (141 segundos)
// 13.107.200 = 50 GB (Inviável)

//Insertion
// 256 =  1 MB (0 segundos)
// 262.144 =  1 GB (150 segundos)
// 13.107.200 = 50 GB (Inviável)

//Bubble
// 256 =  1 MB (0 segundos)
// 262.144 =  1 GB (328 segundos)
// 13.107.200 = 50 GB (Inviável)

//Quick
// 256 =  1 MB (0 segundos)
// 262.144 =  1 GB (0 segundos)
// 13.107.200 = 50 GB (10 segundos) 0,1 processador 1 teste
// 13.107.200 = 50 GB (09 segundos) 0,0 processador 2 teste

//Merge
// 256 =  1 MB (0 segundos)
// 262.144 =  1 GB (0 segundos)
// 393.216 = 1,5 GB (1 segundo) 0,0 processador 

// 524.288 = 2 GB (trava) 0,4 processador 
// 1.310.720 =  5 GB (Trava) 0,5 processador 
// 2.621.440 =  10 GB (Trava) 0,7 processador  
// 13.107.200 = 50 GB (Trava) 1,7 processador 
// OBS: No debug ele simplesmente sai sem ordenar nos casos em que o algoritmo travou


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

void merge(int *vet, int start, int m, int end)
{
    int i, j, k;
    int n1 = m - start + 1;
    int n2 = end - m;

    int vetTemp1[n1], vetTemp2[n2];

    for (i = 0; i < n1; i++)
        vetTemp1[i] = vet[start + i];
    for (j = 0; j < n2; j++)
        vetTemp2[j] = vet[m + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (vetTemp1[i] <= vetTemp2[j])
        {
            vet[k] = vetTemp1[i];
            i++;
        }
        else
        {
            vet[k] = vetTemp2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vet[k] = vetTemp1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet[k] = vetTemp2[j];
        j++;
        k++;
    }
}

void mergeSort(int *vet, int start, int end)
{
    if (start < end)
    {
        int m = start + (end - start) / 2;

        mergeSort(vet, start, m);
        mergeSort(vet, m + 1, end);
        merge(vet, start, m, end);
    }
}

int main() {

    int *vet, *vet1, *vet2, *vet3, *vet4, aux, size;

    cout << "Informe um valor para dimensionar o vetor: " << endl;
    cin >> size;

    vet = (int *) malloc(size * sizeof (int)); 
    vet1 = (int *) malloc(size * sizeof (int));
    vet2 = (int *) malloc(size * sizeof (int));
    vet3 = (int *) malloc(size * sizeof (int));
    vet4 = (int *) malloc(size * sizeof (int));
    preencheVetor(vet, size);
    preencheVetor(vet1, size);
    preencheVetor(vet2, size);
    preencheVetor(vet3, size);
    preencheVetor(vet4, size);

    time_t start_i = time(NULL);
    insertionSort(vet, size, aux);
    time_t diff_i = time(NULL) - start_i;
    free(vet);

    time_t start_s = time(NULL);
    selectionSort(vet1, size, aux);
    time_t diff_s = time(NULL) - start_s;
    free(vet1);

    time_t start_b = time(NULL);
    bubbleSort(vet2, size, aux);
    time_t diff_b = time(NULL) - start_b;
    free(vet2);

    time_t start_q = time(NULL);
    ordenarQuicksort(vet3, 0, size);
    time_t diff_q = time(NULL) - start_q;
    free(vet3);


    time_t start_m = time(NULL);
    mergeSort(vet4, 0, size - 1);
    time_t diff_m = time(NULL) - start_m;
    free(vet4);

    

    cout << "Tempo em segundos algoritmo de ordenacao Insertion: " << diff_i << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Selection: " << diff_s << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Bubble: " << diff_b << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Quick: " << diff_q << endl;
    cout << "Tempo em segundos algoritmo de ordenacao Merge: " << diff_m << endl;

    
    system("pause");
    return 0;

}
