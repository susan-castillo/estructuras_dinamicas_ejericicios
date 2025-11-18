#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Cliente {
  float monto;
  int cuenta;
  string fecha;
};

void insertar(unordered_map<int, Cliente>& tablaHash, const int& valor, Cliente& cliente) {
  auto resultado = tablaHash.insert(make_pair(valor, cliente));
  // second: true /
  if (resultado.second) {
    cout << "Se agrego correctamente" << endl;
  } else {
    cout << "No se agrego correctamente" << endl;
  }
}

void eliminar(unordered_set<string>& tablaHash, const string& valor) {
  // tablaHash.erase(valor) devuelve un true o false.
  if (tablaHash.erase(valor)) {
    cout << "Se elimino correctamente" << endl;
  } else {
    cout << "El elemento no existe" << endl;
  }
}

void buscar(unordered_set<string>& tablaHash, const string& valor) {
  // Si encuentra el valor devuelve un booleano, pero si no lo encuentra
  // devuelve el  ultimo numero de la lista Por lo que se maneja de la siguiente
  // manera:
  if (tablaHash.find(valor) != tablaHash.end()) {
    cout << "El elemento existe" << endl;
  } else {
    cout << "El elemento no existe" << endl;
  }
}

void mostrar(unordered_set<string>& tablaHash){
    if(tablaHash.empty()){
        cout << "Tabla vacía" << endl;
        return;
    }

    for(const auto& n: tablaHash){
        cout << n << endl;
    }
}


// Siempre es recomendable hacer una función para liberar la memoria
void limpiarMemoria(unordered_set<string>& tablaHash) { tablaHash.clear(); }

int main() {
  unordered_map<int, Cliente> clientes = {
    {1, {100, 123654, "22/11/25"}}
  };
  
  insertar(clientes, 1, clientes[1].cuenta);
  cout << clientes[1].cuenta << endl;

  return 0;
}