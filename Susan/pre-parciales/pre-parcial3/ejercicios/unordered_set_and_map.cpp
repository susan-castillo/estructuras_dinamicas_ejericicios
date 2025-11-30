#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ###################### NO ORDENADOS - UTILIZAN TABLAS HASH ######################################
int main() {
    
    //USO DEL UNORDERED_SET
    cout << "---- UNORDERED_SET ----" << endl;
    unordered_set<string> lista_vip;
    lista_vip.insert("Carlos");
    lista_vip.insert("Susan");
    lista_vip.insert("David");
    lista_vip.insert("Ana");

    //Busqueda rapida - Es mas corto que find si solo queremos saber si existe o no.
    string invitadoABuscar = "Susan";

    if(lista_vip.count(invitadoABuscar)){
        cout << "Invitado encontrado: " << invitadoABuscar << endl; 
    }else{
        cout << "Invitado no encontrado" << endl;
    }

    //Imprimir (No sale en orden)
    cout << "Lista completa de invitados: " << endl;
    for(const auto& nombre: lista_vip){
        cout << nombre << endl;
    }

    cout << "\n";


    //USO DEL UNORDERED_MAP
    cout << "---- UNORDERED_MAP ---- " << endl;
    
    unordered_map<string, int> bar;
    bar["Chocolate"] = 50;
    bar["Agua"] = 20;
    bar["Soda"] = 15;

    string bebidaABuscar =  "Agua";
    auto it = bar.find(bebidaABuscar);

    if(it != bar.end()){
        cout << "Bebida encontrada: " << it->first << " y quedan " << it->second << endl;
    }else {
        cout << "Bebida no disponible" << endl;
    }

    //Imprimir bebidas (No sale en orden)
    cout << "Inventario final: " << endl;
    for(const auto& par: bar){
        cout << "- " << par.first << ": " << par.second << endl;
    }
    return 0;
}