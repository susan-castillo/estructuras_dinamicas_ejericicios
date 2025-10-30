#include <iostream>
using namespace std;

struct Nodo{
    int data;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int valor){
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->data = valor;
    nuevo_nodo->izq = nullptr;
    nuevo_nodo->der = nullptr;
    return nuevo_nodo;
}

Nodo* insertar(Nodo* raiz, int valor){
    if(raiz == nullptr){
        return crearNodo(valor);
    }

    if(valor < raiz->data){
        raiz->izq = insertar(raiz->izq, valor);
    }else if(valor > raiz->data){
        raiz->der = insertar(raiz->der, valor);
    }

    return raiz;
}

void inorder(Nodo* raiz){
    if(raiz != nullptr){
        //Izquierda
        inorder(raiz->izq);
        
        //Raiz
        cout << raiz->data << " ";

        //Derecha
        inorder(raiz->der);
    }
}

void preorder(Nodo* raiz){
    if(raiz != nullptr){
        //Raiz
        cout << raiz->data << " ";

        //Izquierda
        preorder(raiz->izq);

        //Derecha
        preorder(raiz->der);
    }
}

void postorder(Nodo* raiz){
    if(raiz != nullptr){

        //Izquierda
        postorder(raiz->izq);

        //Derecha
        postorder(raiz->der);

        //Raiz
        cout << raiz->data << " ";

    }
}

//Aplicamos postOrder
void liberar(Nodo* raiz){
    if(raiz != nullptr){
        //Izquierda
        liberar(raiz->izq);
        //Derecha
        liberar(raiz->der);
        //Raiz
        delete raiz;
    }
}
int main(){

    Nodo* arbol1 = nullptr;
    arbol1 = insertar(arbol1, 10);
    arbol1 = insertar(arbol1, 6);
    arbol1 = insertar(arbol1, 15);
    arbol1 = insertar(arbol1, 4);

    cout << "Inorder: ";
    inorder(arbol1);

    //Por precaución: Por si ha quedado alguna basura en memoria.
    liberar(arbol1);
    return 0;
}