#include <stdlib.h>
#include <iostream>
using namespace std;

void bubble_sort(int *vet, int size, int aux){

    for (int i = 0; i < size; i++) {
        vet[i] = 1 + rand() % size;
    }

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

int main() {

    int *vet1, aux1, size1;
    cout << "Informe um valor para dimensionar o vetor: " << endl;
    cin >> size1;

    vet1 = (int *) malloc(size1 * sizeof (int));

    bubble_sort(vet1, size1, aux1);

    for (int i = 0; i < size1; ++i) {
        cout << " | " << vet1[i] << " | " << endl;
    }

    free(vet1);

    system("pause");
    return 0;
}

//melhor caso: O(n) *
//pior caso: O(n*2) *