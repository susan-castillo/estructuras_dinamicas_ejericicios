#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct Jugador {
  int id;
  string nombre;
  int nivel;
  string clase;
  int poder;
};

struct CompJugador {
  bool operator()(const Jugador& a, const Jugador& b) const {
    return a.id < b.id;
  }
};

// Guardar todos los jugadores en un set<Player> ordenados por id.
void registrarJugador(set<Jugador, CompJugador>& registro) {
  Jugador j;
  Jugador j2;
  Jugador j3;

  j.id = 4;
  j.nombre = "Mauricio";
  j.nivel = 5;
  j.clase = "Mago";
  j.poder = 3;

  j2.id = 1;
  j2.nombre = "Susan";
  j2.nivel = 2;
  j2.clase = "Arquero";
  j2.poder = 4;

  
  j3.id = 2;
  j3.nombre = "Adamaris";
  j3.nivel = 2;
  j3.clase = "Arquero";
  j3.poder = 1;

  registro.insert(j);
  registro.insert(j2);
  registro.insert(j3);
  
}

void mostrarJugador(const set<Jugador, CompJugador>& registro) {
  if (registro.empty()) {
    cout << "No hay jugadores registrodos";
    return;
  }

  cout << "Jugadores registrados:" << endl;
  for (const auto& v : registro) {
    cout << v.id << " - " << v.nombre << " - " << v.nivel << " - " << v.clase
         << " - " << v.poder << endl;
  }
}

/* void buscarJugadorId(unordered_map<int, Jugador>& jugador){
  for(int id: clase)
} */

int main() {
  set<Jugador, CompJugador> registro;

  registrarJugador(registro);
  mostrarJugador(registro);

  //Se muestran los jugador por clase
  map<string, set<int>> clase;
  clase["Mago"].insert(4);
  clase["Arquero"].insert(2);
  clase["Arquero"].insert(1);

  cout << "Mostrando jugadores y su clase" << endl;
  // Complejidad: O(n x m)
  //  Recorre lista de generos
  for (auto& par : clase) {
    cout << par.first << ": ";
    // Recorre lista de libros por cada genero
    for (int id : par.second) {
      cout << id << " ";
    }
    cout << endl;
  }

  

  return 0;
}