#include <iostream>
#include <set>
#include <map>
using namespace std;

// ###################### ORDENADOS - UTILIZAN ARBOLES ######################################
int main()
{
    // -------------------- DEMOSTRACION CON SET --------------------------
    cout << "------------ DEMOSTRACION DE SET --------------" << endl;
    // Declaracion de set de tipo string
    set<string> canasta;

    // Insertamos frutas - No permite duplicados
    canasta.insert("Manzana");
    canasta.insert("Pera");
    canasta.insert("Uva");

    // Imprimimos el set
    // Nota: Se ordenan alfabeticamente
    for (const auto &fruta : canasta)
    {
        cout << "Fruta disponible: " << fruta << endl;
    }

    //----------------- USO DEL FIND CON SET ----------------------
    string valorABuscar = "Manzana";

    auto it = canasta.find(valorABuscar);

    if(it != canasta.end()){
        cout << "Fruta encontrada: " << *it << endl;
    }else{
        cout << "Fruta no encontrada" << endl;
    }

    cout << "\n";

    // ---------------- DEMOSTRACION CON MAP ------------------------
    cout << "----------- DEMOSTRACION CON MAP ----------" << endl;

    // Clave: string (nombre), valor: int (precio)"
    map<string, int> precios;

    precios["Manzana"] = 50;
    precios["Pera"] = 15;
    precios["Uva"] = 20;

    //Imprimimos el map
    //pair.first es la clave
    //pair.second es el valor
    for(const auto&par: precios){
        cout << "Fruta: " << par.first << " | Precio: $" << par.second << endl;
    }

    //----------------- USO DEL FIND CON MAP --------------------------
    string frutaABuscar = "Uva";
    auto it2 = precios.find(frutaABuscar);

    //Se verifica si el iterador llego al final
    if(it2 != precios.end()){
        cout << "Fruta encontrada! - Fruta: " << it2->first << " | Precio : " << it2->second << endl;

    }else{
        cout << "Fruta no encontrada" << endl;
    }

    return 0;
}