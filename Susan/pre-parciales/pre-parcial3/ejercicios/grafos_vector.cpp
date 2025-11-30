#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 1. LA LISTA DE NOMBRES (Para saber quién es el 0, el 1, etc.)
    vector<string> nombres = {"Ana", "Beto", "Carla"};
    
    // 2. LA RED SOCIAL (El Grafo)
    // Es un vector que ADENTRO tiene otros vectores de enteros.
    // Lo iniciamos con tamaño 3 (uno para cada persona).
    vector<vector<int>> red(3);

    // --- MOMENTO DE HACER AMIGOS ---
    // Queremos que Ana (0) sea amiga de Beto (1).
    
    // Vamos al "piso" 0 (Ana) y agregamos al 1.
    red[0].push_back(1);
    
    // Como la amistad es mutua, vamos al "piso" 1 (Beto) y agregamos al 0.
    red[1].push_back(0);

    // --- VER LOS RESULTADOS ---
    // Vamos a ver quiénes son amigos de Ana (Índice 0)
    cout << "Amigos de " << nombres[0] << ":" << endl;

    // Recorremos el vector que está DENTRO de la posición 0
    for(int idAmigo : red[0]) {
        // idAmigo será 1.
        cout << "- " << nombres[idAmigo] << endl;
    }

    return 0;
}