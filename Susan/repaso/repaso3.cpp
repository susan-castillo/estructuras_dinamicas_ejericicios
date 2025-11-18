#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Libro {
  string titulo;
  string autor;
  int anio;
};

int main() {
  // {1, {"1984", "George Orwall", 1958}}
  map<int, Libro> libros;

  libros[1] = {"1984", "George Orwall", 1958};
  libros[2] = {"La iliada", "Homero", 1958};
  libros[3] = {"La odisea", "Homero", 1958};
  libros[4] = {"Cien años de soledad", "Gabriel Garcia Marquez", 1958};
  libros[5] = {"Romeo y julieta", "Shakespeare", 1958};

  map<string, set<int>> generos;
  generos["Tragedia griega"].insert(2);
  generos["Tragedia griega"].insert(3);
  generos["Ficcion"].insert(1);
  generos["Realismo magico"].insert(4);
  generos["Tragedia"].insert(5);

  cout << "Mostrando generos y sus libros" << endl;
  //Complejidad: O(n x m)
  // Recorre lista de generos
  for (auto& par : generos) {
    cout << par.first << ": ";
    // Recorre lista de libros por cada genero
    for (int id : par.second) {
      cout << id << " ";
    }
    cout << endl;
  }

  for(int id: generos["Tragedia griega"]){
    cout << id << endl;
    cout << libros[id].titulo<< endl;
    cout << libros[id].autor<< endl;
    cout << libros[id].anio<< endl;
    cout << endl;
  }
  return 0;
}