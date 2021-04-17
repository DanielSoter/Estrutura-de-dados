#include <bits/stdc++.h>//biblioteca abstrata
#include "Lista.h"

using namespace std;
  
// Classe para implementar pilha usando Lista
class Pilha : public Lista {
public:

    // push para empurrar o elemento no topo da pilha
    // usando inserir na última função do Lista
    void push(int item)
    {
        insereFim(item);
    }
 
    // pop para remover o elemento no topo da pilha
    // usando remove a última função do Lista
    void pop()
    {
        removeFim();
    }
    
};
 
// classe para implementar a fila usando o Lista
class Queue : public Lista {
public:
    // enfileirar para inserir o elemento no final
    // usando inserir na última função da Lista
    void enqueue(int item) //sobrecarga de metodo
    {
        insereFim(item);
    }
 
    // Lista para remover o primeiro elemento
    // usando remove na primeira função do Lista
    void dequeue() //sobrecarga de metodo
    {
        removeInicio();
    }
};

int main()
{   
    // Objeto pilha
    Pilha stk;
    // Inserindo 8, 10, 4, 5 na pilha
    stk.push(8);      //O(1) Pois o processo é direto
    stk.push(10);     //O(1) Pois o processo é direto
    stk.push(4);      //O(1) Pois o processo é direto
    stk.push(5);      //O(1) Pois o processo é direto
    cout << "Pilha: ";
    stk.exibe();      //O(n) Pois o algoritmo ser de percurso é linear simples
 
    // removendo o ultimo elemento do topo
    stk.pop();       //O(1) Pois o processo é direto
    cout << "Pilha: ";
    stk.exibe();      //O(n) Pois o algoritmo ser de percurso é linear simples

    // Objeto fila
    Queue que;
 
    // insirerindo 8, 10, 4, 5 na fila
    que.enqueue(8);   //O(1) Pois o processo é direto
    que.enqueue(10);  //O(1) Pois o processo é direto
    que.enqueue(4);   //O(1) Pois o processo é direto
    que.enqueue(5);   //O(1) Pois o processo é direto
    cout << "Queue: ";
    que.exibe();     //O(n) Pois o algoritmo ser de percurso simples
 
    // deleta um elemento da fila
    que.dequeue();  //O(1) Pois o processo é direto
    cout << "Queue: ";
    que.exibe();    //O(n) Pois o algoritmo ser de percurso é linear simples
 
    cout << "O tamanho da pilha e: " << stk.contNo() << endl; //O(n) posso alterar para O(1) porém perco em complexidade espacial!
    cout << "O tamanho da filha e: " << que.contNo() << endl; //O(n) posso alterar para O(1) porém perco em complexidade espacial!

    return 0;
}
