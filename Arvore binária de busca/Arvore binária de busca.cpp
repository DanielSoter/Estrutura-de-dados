#include <stdlib.h>
#include<stdio.h>
#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no *esq, *dir;
};
struct no *novoNo(int item){
    struct no *temp = (struct no *)malloc(sizeof(struct no));
    temp->valor = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

void preOrdem(no *temp) {
    if (temp != NULL) {
        cout << " " << temp->valor;
        preOrdem(temp->esq);
        preOrdem(temp->dir);
    }
}

void emOrdem(no *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}


void posOrdem(struct no *temp) {
    if (temp != NULL) {
        posOrdem(temp->esq);
        posOrdem(temp->dir);
        cout << " " << temp->valor;
    }
}

struct no* inserir(struct no* no, int chave){
    if (no == NULL) return novoNo(chave);
    if (chave < no->valor)
        no->esq = inserir(no->esq, chave);
    else
        no->dir = inserir(no->dir, chave);
    return no;
}
struct no * valorMinimoNo(struct no* node){
    struct no* current = node;
    while (current && current->esq != NULL)
        current = current->esq;
    return current;
}
struct no* excluirNo(struct no* raiz, int chave){
    if (raiz == NULL) return raiz;
    if (chave < raiz->valor)
        raiz->esq = excluirNo(raiz->esq, chave);
    else if (chave > raiz->valor)
        raiz->dir = excluirNo(raiz->dir, chave);
    else{
        if (raiz->esq == NULL){
            struct no *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL){
            struct no *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        struct no* temp = valorMinimoNo(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = excluirNo(raiz->dir, temp->valor);
    }
    return raiz;
}
int main(){
    struct no *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    cout << "Em ordem: " ;
    emOrdem(raiz);
    cout << endl;
    cout << "Pos ordem: ";
    posOrdem(raiz);
    cout << endl;
    cout << "Pre ordem: ";
    preOrdem(raiz);
    cout << endl;
    cout << "Deletando valor 20: ";
    raiz = excluirNo(raiz, 20);
    cout << endl;
    cout << "Valor 20 deletado com sucesso: " << endl;
    emOrdem(raiz);

    system("pause");
    return 0;
}