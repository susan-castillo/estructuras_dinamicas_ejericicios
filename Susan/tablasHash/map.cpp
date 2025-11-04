#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

void insertar(unordered_set<string>& tablaHash, const string& valor){
    auto resultado = tablaHash.insert(valor);
    // second: true /
    if(resultado.second){
        cout << "Se agrego correctamente" << endl;
    }else{
        cout << "No se agrego correctamente" << endl;
    }
}

void eliminar(unordered_set<string>& tablaHash, const string& valor){
    // tablaHash.erase(valor) devuelve un true o false.
    if(tablaHash.erase(valor)){
        cout << "Se elimino correctamente" << endl;
    }else{
        cout << "El elemento no existe" << endl;
    }
}

void buscar(unordered_set<string>& tablaHash, const string& valor){
    //Si encuentra el valor devuelve un booleano, pero si no lo encuentra devuelve el  ultimo numero de la lista
    //Por lo que se maneja de la siguiente manera:
    if(tablaHash.find(valor) != tablaHash.end()) {
        cout << "El elemento existe" << endl;
    }else{
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

//Siempre es recomendable hacer una función para liberar la memoria
void limpiarMemoria(unordered_set<string>& tablaHash){
    tablaHash.clear();
}

int main(){
/*     unordered_set<string> nombres;

    insertar(nombres, "Ana");
    insertar(nombres, "Luis");
    insertar(nombres, "Latrel");
    insertar(nombres, "Ana"); // Tendría que mostrar error

    //Se muestrar los 
    mostrar(nombres);

    buscar(nombres, "Luis");
    eliminar(nombres, "Luis");

    mostrar(nombres);

    limpiarMemoria(nombres); */

    unordered_map<string, int> edades = {
        //clave - valor
        {"Ana", 25},
        {"Luis", 30},
        {"Pepe", 20},
        {"Marta", 20},
    };

    cout << edades["Marta"] << endl;
    return 0;
}