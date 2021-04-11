#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int esquerda, int direita)
{
  int aux;
  aux = vetor[esquerda];
  vetor[esquerda] = vetor[direita];
  vetor[direita] = aux;
}


int particionar(int *vetor, int inicio, int fim)
{
  int pivo = vetor[inicio]; //primeiro elemento é o pivo
  int i = inicio + 1;       //índice i faz a varredura da esquerda para direita
  int j = fim;              //índice j faz a varredura da direita para esquerda
  while (i <= j)
  { //enquanto os índice não se ultrapassarem
    while (i <= j && vetor[i] <= pivo)
    { //enquanto vetor[i] não for maior que o pivô
      i++;
    }
    while (i <= j && vetor[j] > pivo)
    { //enquanto vetor[j] não for menor ou igual ao pivô
      j--;
    }
    if (i < j)
      troca(vetor, i, j); //se os índices não se ultrapassarem, troque os elementos
  }
  troca(vetor, inicio, j); //coloca o pivô na posição de ordenação
  return j;
}

void ordenarQuicksort(int *v, int esquerda, int direita)
{
  int divide;
  // if (direita > esquerda)
  // if (direita <= esquerda) return;
  // Se o vetor só possui um elemento o vetor já está ordenado, retorne.
  if (esquerda >= direita)
  {
    return;
  }
  divide = particionar(v, esquerda, direita); //para dividir o vetor
  ordenarQuicksort(v, esquerda, divide - 1);  //esquerda do divide, do começo até divide - 1
  ordenarQuicksort(v, divide + 1, direita);   //direita do pivo
}

void show(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++){
        printf("Numero --->  %d \n", vet[i]);
    }
}

int main()
{
  int size, i, *numbersVetor;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &size);

  numbersVetor = (int *)malloc(size * sizeof(int));

  for (i = 0; i < size; i++)
  {
    numbersVetor[i] = 1 + rand() % size;

  }

  ordenarQuicksort(numbersVetor, 0, size);

  printf("** Numero ordenados ** \n");
  show(numbersVetor, size);

  free(numbersVetor);
  system("pause");
  return 0;
}

//pior caso: O (n²)