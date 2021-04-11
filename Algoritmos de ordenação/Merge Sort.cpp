#include <stdlib.h>
#include <iostream>

using namespace std;
void merge(int vet[], int start, int m, int end)
{
    int i, j, k;
    int n1 = m - start + 1;
    int n2 = end - m;

    // Vetores temporarios
    int vetTemp1[n1], vetTemp2[n2];

    // Copiando os dados para os vetores temporarios vetTemp1[] and vetTemp2[]
    for (i = 0; i < n1; i++)
        vetTemp1[i] = vet[start + i];
    for (j = 0; j < n2; j++)
        vetTemp2[j] = vet[m + 1 + j];

    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = start; //indice inicial de subarray mesclado

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

    //Copie os elementos restantes de vetTemp1[], se houver algum
    while (i < n1)
    {
        vet[k] = vetTemp1[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de vetTemp2[], se houver algum
    while (j < n2)
    {
        vet[k] = vetTemp2[j];
        j++;
        k++;
    }
}



void mergeSort(int vet[], int start, int end)
{
    if (start < end)
    {
        int m = start + (end - start) / 2;

        // Ordena de forma recursiva, primeiro esquerda, depois direita
        mergeSort(vet, start, m);
        mergeSort(vet, m + 1, end);

        merge(vet, start, m, end);
    }
}

void imprime(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << " | " << vet[i] << " | " << endl;
    }
}


int main()
{
    int size, i, *vet1;

    cout << "Informe o tamanho do vetor: " << endl;
    cin >> size;

    vet1 = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        vet1[i] = 1 + rand() % size;
    }


    mergeSort(vet1, 0, size - 1);

    imprime(vet1, size);

    free(vet1);

    system("pause");
    return 0;
}

//pior e melhor caso: Linearitmica O(n log2 n)
//o código acima executa operações logarítmicas n vezes.