#include <stdlib.h>
#include<stdio.h>
#include <iostream>

using namespace std;

struct No{
    int item;
    struct No *esq, *dir;
};

struct No *novoNo(int item){
    struct No *temp = (struct No *)malloc(sizeof(struct No));
    temp->item = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

void preOrdem(No *temp) {
    if (temp != NULL) {
        cout << " " << temp->item;
        preOrdem(temp->esq);
        preOrdem(temp->dir);
    }
}

void emOrdem(No *raiz){
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->item);
        emOrdem(raiz->dir);
    }
}


void posOrdem(struct No *temp) {
    if (temp != NULL) {
        posOrdem(temp->esq);
        posOrdem(temp->dir);
        cout << " " << temp->item;
    }
}

struct No* inserir(struct No* no, int chave){
    if (no == NULL) return novoNo(chave);
    if (chave < no->item)
        no->esq = inserir(no->esq, chave);
    else
        no->dir = inserir(no->dir, chave);
    return no;
}

struct No * valorMinimoNo(struct No* node){
    struct No* current = node;
    while (current && current->esq != NULL)
        current = current->esq;
    return current;
}

No* excluirNo(No * root, int item){
	if (root == NULL) return root; 
    if (item < root->item) 
        root->esq = excluirNo(root->esq, item);
    else if (item > root->item) 
        root->dir = excluirNo(root->dir, item); 
    else
    {
		if (root->esq == NULL) 
        { 
            No *temp = root->dir; 
            free(root); 
            return temp; 
        } 
        else if (root->dir == NULL) 
        { 
            No *temp = root->esq; 
            free(root); 
            return temp; 
        }
        // node* temp = minNode(root->dir); 
        // root->value = temp->value; 
        // root->dir = remove(root->dir, temp->value); 
			No *temp=root->dir;				//Vou procurar à direita o menor valor de nó
		if(temp->esq==NULL){				//esse primeiro nó é o menor
			root->dir=temp->dir;			//penduro o restante da sub-árvore adequadamente
		}
		else {
			No *hold;						//hold tem o papel de nó exatamente anterior ao temp
			while(temp->esq!=NULL){		//caminho até achar o nó que não tem filho à esquerda. Significa que é o menor nó da subárvore de N->dir
				hold = temp;
				temp=temp->esq;
			}								//achei o menor valor temp
			hold->esq=temp->dir;			// quando eu removo temp, eu quero pendurar a sua única sub-árvore(que é temp-> dir) no hold.
		}
		temp->esq=root->esq;
		temp->dir=root->dir;
		free(root);
		return temp;
    } 
    return root;
}


int main(){
    struct No *raiz = NULL;
    int vet[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 11, 13, 15};
    for(int i = 0; i < 13; i++){
        raiz = inserir(raiz, vet[i]);
    }
    
    cout << "Em ordem: " ;
    emOrdem(raiz);
    cout << endl;
    cout << "Pos ordem: ";
    posOrdem(raiz);
    cout << endl;
    cout << "Pre ordem: ";
    preOrdem(raiz);
    cout << endl;
    cout << "Deletando raiz: ";
    raiz = excluirNo(raiz, 4);
    cout << 4;
    cout << endl << endl << endl;
    emOrdem(raiz);
    cout << endl;

    system("pause");
    return 0;
}