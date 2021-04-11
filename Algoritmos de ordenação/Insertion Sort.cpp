#include <iostream>
#include <stdlib.h>
using namespace std;

void insertion_sort(int *vet, int aux, int size){

    for (int i = 0; i < size; ++i) {
        vet[i] = 1 + rand() % size;
    }
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
int main() {
    int *vet, aux, size;
    cout << "Informe um valor para dimensionar o vetor: " << endl;
    cin >> size;

    vet =(int *) malloc(size * sizeof (int));

    insertion_sort(vet, aux, size);

    for (int i = 0; i < size; ++i) {
        cout << " | " << vet[i] << " | " << endl;
    }

    free(vet);

    system("pause");
    return 0;
}

//melhor caso: O(n)
//pior caso: o(n*2)

