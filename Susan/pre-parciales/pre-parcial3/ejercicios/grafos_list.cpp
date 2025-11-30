#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

int main(){
    //USANDO LIST
    // Definimos el Grafo:
    // Clave (int): El nodo origen
    // Valor (list<int>): La lista de nodos destino (vecinos)
    unordered_map<int, list<int>> miGrafo;

    // El nodo 4 se conecta con 6, 3 y 5.
    miGrafo[4].push_back(6);
    miGrafo[4].push_back(3);
    miGrafo[4].push_back(5);

    // Como es un grafo "no dirigido" (la línea va y viene),
    // también deberíamos decirle al 6 que conoce al 4:
    miGrafo[6].push_back(4);

    //Imprimir los vecino del nodo 4
    cout << "El nodo 4 esta conectado con: " << endl;

    // Accedemos al mapa con [4], eso nos devuelve la LISTA.
    // Luego recorremos esa lista.
    for(int vecino: miGrafo[4]){
        cout << vecino << " ";
    }  
    
    return 0;
}