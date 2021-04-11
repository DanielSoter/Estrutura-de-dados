#include <stdio.h>
#include <cstdlib>

class sobrecargaOperador
{
public:
    int n1, n2;

    sobrecargaOperador(int n1, int n2)
    {
        this->n1 = n1;
        this->n2 = n2;
    }

    sobrecargaOperador operator+(sobrecargaOperador& c)
    {
        return sobrecargaOperador(this->n1 + c.n1, this->n2 + c.n2);
    }
};

struct no{
    int valor;
    no *anterior;
    no *proximo;
};

typedef struct
{
    no *inicio;
    no *fim;
    int tamanho;
} List;

class sobrecargaImprime
{
public:
    void imprime(List *list) {
        no *current = list->inicio;
        if(list->inicio == NULL) {
            printf("List is empty\n");
            return;
        }
        while(current) {
            printf("%d ", current->valor);
            current = current->proximo;
        }
        printf("\n");
    }

    void imprime() {
        printf("Lista atualizada: \n");
    }
};

void addNo(List *list, int data) {
    no *newNode = (no*)malloc(sizeof(no));
    newNode->valor = data;

    if(list->inicio == NULL) {

        list->inicio = list->fim = newNode;
        list->inicio->anterior = NULL;
        list->fim->proximo = NULL;
    }
    else {

        list->fim->proximo = newNode;

        newNode->anterior = list->fim;

        list->fim = newNode;

        list->fim->proximo = NULL;
    }

    list->tamanho++;
}

List *criarLista()
{
    List *list = (List *)malloc(sizeof(List));
    list->inicio = NULL;
    list->fim = NULL;
    list->tamanho = 0;
    return list;
}

void removeInicio(List *list)
{
    no *current = list->inicio;
    list->inicio = current->proximo;
    list->inicio->anterior = NULL;
    list->tamanho--;
    free(current);
}

void removeFim(List *list)
{
    no *current = list->fim;
    list->fim = current->anterior;
    list->fim->proximo = NULL;
    list->tamanho++;
    free(current);
}

void addMeio(List *list, int data) {

    no *newNode = (no*)malloc(sizeof(no));
    newNode->valor = data;

    if(list->inicio == NULL) {

        list->inicio = list->fim = newNode;

        list->inicio->anterior = NULL;

        list->fim->proximo = NULL;
    }

    else {

        no *current = list->inicio, *temp = NULL;

        int mid = (list->tamanho % 2 == 0) ? (list->tamanho / 2) : ((list->tamanho + 1) / 2);

        for(int i = 1; i < mid; i++){
            current = current->proximo;
        }
        temp = current->proximo;
        current->proximo = newNode;
        newNode->anterior = current;
        newNode->proximo = temp;
        temp->anterior = newNode;
    }
    list->tamanho++;
}

void display(List *list) {
    no *current = list->inicio;
    if(list->inicio == NULL) {
        printf("List is empty\n");
        return;
    }
    while(current) {
        printf("%d ", current->valor);
        current = current->proximo;
    }
    printf("\n");
}

int main()
{
    sobrecargaOperador c1(2, 2), c2(3, 4);
    sobrecargaOperador c3 = c1 + c2;
    sobrecargaImprime text;

    List *list = criarLista();

    addNo(list, 1);
    addNo(list, 2);
    addNo(list, 3);
    addNo(list, 4);

    printf("Lista original fila \n");
    display(list);

    printf("Adiciona valor 5 no meio: \n");
    addMeio(list, c3.n1);
    text.imprime();
    text.imprime(list);
    printf("Adiciona valor 6 no meio: \n");
    addMeio(list, c3.n2);
    text.imprime();
    text.imprime(list);

    printf("remove inicio: \n");
    removeInicio(list);
    text.imprime(list);

    printf("remove Fim: \n");
    removeFim(list);
    text.imprime(list);
    printf("Tamanho da lista: %d",list->tamanho);

    system("pause");
    return 0;
}