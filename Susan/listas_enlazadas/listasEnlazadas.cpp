#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node*& head, int value){
    Node* newNode = new Node{value, head};
    head = newNode;
}

void printList(Node* head){
    //Le estamos diciendo que se coloque en la primera posición, osea head.
    Node* i = head;
    //Se va detener cuando encuentre un valor vacio
    while(i != nullptr){
        //Cuando trabajamos con punteros, vamos acceder al estruct a traves de  una flechita ->, es lo equivalente al punto.
        cout << i->data << "->";
        i = i->next;
    }
}

int main(){
    Node* lista1 = nullptr;

    insert(lista1, 1);
    insert(lista1, 2);
    insert(lista1, 3);

    printList(lista1);

    return 0;
}