#include <bits/stdc++.h>//biblioteca abstrata
#ifndef LISTA_H_
#define LISTA_H_
using namespace std;

// Estrutura para o no Lista
struct listaNo {
    int valor;
    listaNo* dir;
    listaNo* esq;
};

class Lista {
private:
 
    listaNo* inicio;
    listaNo* fim;

public:
    // exibe os elementos em Lista
    void exibe()
    {
        // se a lista não estiver vazia
        if (!vazia()) {
            listaNo* temp = inicio;
            while (temp != NULL) {
                cout << temp->valor << " ";
                temp = temp->dir;
            }
            cout << endl;
            return;
        }
        cout << "Etrutura vazia!" << endl;
    }
    
    // Contador de nó, decidi priorizar espaço!
    int contNo()
    {
        // Caso a lista não estiver vazia
        if (!vazia()) {
            listaNo* temp = inicio;
            int tam = 0;
            while (temp != NULL) {
                tam++;
                temp = temp->dir;
            }
            return tam;
        }
        return 0;
    }

protected:
    // construtor, pode ser considerado sobrecarga
    Lista()
    {
        inicio = fim = NULL;
    }
 
    // verificação booleana para lista vazia
    bool vazia()
    {
        if (inicio == NULL)
            return true;
        return false;
    }
 
    // insere inicio
    void insereInicio(int item)
    {
        // alocando nó do tipo listaNo
        listaNo* temp = new listaNo[sizeof(listaNo)];
        temp->valor = item;
 
        // se o valor é o meu primeiro elemento
        if (inicio == NULL) {
            inicio = fim = temp;
            temp->dir = temp->esq = NULL;
        }
        else {
            inicio->esq = temp;
            temp->dir = inicio;
            temp->esq = NULL;
            inicio = temp;
        }
    }
 
    // inserindo a última posição da Lista
    void insereFim(int item)
    {
        // alocando nó do tipo listaNo
        listaNo* temp = new listaNo[sizeof(listaNo)];
        temp->valor = item;
 
        // se o valor é o meu primeiro elemento
        if (inicio == NULL) {
            inicio = fim = temp;
            temp->dir = temp->esq = NULL;
        }
        else {
            fim->dir = temp;
            temp->dir = NULL;
            temp->esq = fim;
            fim = temp;
        }
    }
 
   // remove o elemento na primeira posição
    void removeInicio()
    {
        // se a lista não estiver vazia
        if (!vazia()) {
            listaNo* temp = inicio;
            inicio = inicio->dir;
            inicio->esq = NULL;
            free(temp);
            return;
        }
        cout << "Etrutura vazia!" << endl;
    }
 
    // remove o elemento na última posição
    void removeFim()
    {
        // se a lista não estiver vazia
        if (!vazia()) {
            listaNo* temp = fim;
            fim = fim->esq;
            fim->dir = NULL;
            free(temp);
            return;
        }
        cout << "Etrutura vazia!" << endl;
    }
 

};

#endif 