#include <stdlib.h>
#include <iostream>
using namespace std;

void selectionSort(int *vet, int size, int aux){

    for (int i = 0; i < size; i++) //Inicializando meu aaray com valores random()
    {
        vet[i] = 1 + rand() % size; // atribuimos o valor 1 a funçã rand() para inicializarmos acima de 0 e % size para limitar através da variável size e não do RAND_MAX
    }

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (vet[j] < vet[i]){ // Caso o valor da posição seguinte seja menor do que a posição anterior
                aux = vet[i]; //atribua o valor da primeira posição a minha variável auxiliar
                vet[i] = vet[j]; // efetue a troca do menor valor encontrado na posição seguindo com o valor da anterior
                vet[j] = aux; // afim de não perder o maior valor atribuimos o mesmo salvo anteriormente na posição perdida
            }
        }
    }

}

int main()
{
    int *vet, aux, size;

    cout << "Informe um valor para dimensionar o vetor: " << endl;
    cin >> size;
    vet = (int *) malloc(size * sizeof (int));

    selectionSort(vet, size, aux); //Chamando função

    for (int i = 0; i < size; i++) { // Imprimindo
        cout << " | " << vet[i] << " | " << endl;
    }

    system("pause");
    return 0;
}

//pior e melhor caso: o(n*2)
