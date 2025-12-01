#include <iostream>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Jugador{
    int id;
    string nombre;
    int nivel;
    string clase;
    int poder;

    // Esta función le enseña a C++ a comparar dos jugadores, ya que por si solo set no sabe como hacerlo porque es una estructura
    // "const Jugador& otro" significa: compararme a mí (this) contra "otro"
    bool operator < (const Jugador& otro) const{
        return this->id < otro.id;
    }
};

void clasificarPorClase(const set<Jugador>& baseDeDatos){
    cout << "\nCLASIFICACION POR CLASE (MAP)" << endl;

    // Clave: String (Clase), Valor: Lista de IDs (list<int>)
    map<string, set<int>> indiceClases;

    for(const auto& j: baseDeDatos){
        // Accedemos a la categoría con [j.clase]
        // Y usamos .insert() porque ahora es un set
        // Automaticamente los clasifica y evitamos duplicados, si ya existe lo inserta en el set y si no existe lo crea
        indiceClases[j.clase].insert(j.id);
    }

    for(const auto& par : indiceClases){
        cout << "Clase - " << par.first << ": ";

        for (int id: par.second){
            cout << id << " ";
        }

        cout << endl;
    }

}

//Convertimos el set de jugadores en un mapa hash para acceso rapido por ID
unordered_map<int, Jugador> crearAccesoRapido(const set<Jugador>& baseDeDatos){
    
    unordered_map<int, Jugador> accesoRapido;

    // Recorremos la base de datos original
    for(const auto& j: baseDeDatos) {
        //La clave es el ID, el valor es toda la estructura Jugador
        accesoRapido[j.id] = j;
    }
    //Retornamos el mapa hash construido
    return accesoRapido;
}

void buscarJugador(int id, unordered_map<int, Jugador>& tablaHash){
    cout << "\nBUSQUEDA RAPIDA: " << endl;

    auto it = tablaHash.find(id);

    if(it != tablaHash.end()){
        cout << "ID: " << it->first << " | Encontrado: " << it->second.nombre << " | Poder: " << it->second.poder << endl;
    }else{
        cout << "El ID " << id << " no existe" << endl;    
    }
}

void analizarNiveles(const set<Jugador>& baseDeDatos){
    cout << "\nANALISIS DE NIVELES (VECTOR + BINARY SEARCH)" << endl;

    vector<int> niveles;

    // 1. Extraer niveles
    for(const auto& j: baseDeDatos){
        niveles.push_back(j.nivel);
    }

    // 2. Ordenar (Obligatorio para binary_search) como son numeros simples, no necesitamos lambda
    sort(niveles.begin(), niveles.end());

    cout << "Niveles ordenados: " << endl;
    for(int n: niveles) cout << n << " ";
    cout << endl;

    // 3. Busqueda binaria
    int nivelBuscado = 99;
    bool existe = binary_search(niveles.begin(), niveles.end(), nivelBuscado);

    if(existe){
        cout << "-> El nivel " << nivelBuscado << " si existe en el juego" << endl;
    }else{
        cout << "-> Nadie tiene el nivel " << nivelBuscado << endl;
    }

}

// Filtrar jugadores por poder mayor a un valor dado
void filtrarPorPoder(const set<Jugador>& baseDeDatos, int poderMinimo){
    cout << "\nFILTRO DE PODER " << poderMinimo << endl;

    // Recorremos todos los jugadores y mostramos los que cumplen la condicion
    for(const auto& j: baseDeDatos){
        if(j.poder > poderMinimo){
            cout << "- " << j.nombre << " (Poder: " << j.poder << ")" << endl;
        }
    }
}


void mostrarTop3(const set<Jugador>& baseDeDatos) {
    cout << "\nTOP 3 JUGADORES (Sort con Lambda)" << endl;

    //Paso 1: Copiar el set a un vector (porque el set NO se puede reordenar)
/*  Tipo: vector<Jugador> (un vector que contiene jugadores), Nombre: ranking, Inicialización: copia los elementos del set al vector usando iteradores */
    vector<Jugador> ranking(baseDeDatos.begin(), baseDeDatos.end());

    //Paso 2. Ordenar el vector usando lambda
    //Queremos descendete (Mayor > Menor), asi que usamor a.poder > b.poder
    sort(ranking.begin(), ranking.end(), [](const Jugador& a, const Jugador& b){
        return a.poder > b.poder;
    });

    // Paso 3: Mostrar los primeros 3 (con cuidado de no pasarnos si hay menos de 3)
    // Calculamos el limite como el minimo entre 3 y el tamaño del vector (ejem: si hay 5 jugadores, el limite minimo sera 3)
    int limite = min((int)ranking.size(), 3);

    // Mostramos los primeros 'limite' jugadores
    for(int i = 0; i < limite; i++){
        cout << "#" << (i + 1) << ": " << ranking[i].nombre << " - Poder: " << ranking[i].poder << endl;
    }
}

// Pasamos el set y el map por REFERENCIA (&) para que los cambios sean reales
void eliminarJugador(set<Jugador>& baseDeDatos, unordered_map<int, Jugador>& mapaRapido, int idParaBorrar) {
    
    // 1. ESTILO DE TU IMAGEN: Crear el objeto temporal en una línea
    // Sintaxis: {id, nombre, nivel, clase, poder}
    // Solo importa el idParaBorrar, lo demás es relleno (dummy data)
    Jugador tmp{idParaBorrar, "", 0, "", 0}; 

    // 2. Buscamos usando ese objeto temporal
    auto it = baseDeDatos.find(tmp);

    // 3. Verificamos si existe
    if (it != baseDeDatos.end()) {
        
        // A. Borrar del Set
        baseDeDatos.erase(it);
        
        // B. Borrar del Map (Aquí basta con pasar el ID directo)
        mapaRapido.erase(idParaBorrar); 

        cout << "-> Jugador eliminado correctamente." << endl;
    } 
    else {
        cout << "-> Error: No se encontro ese ID." << endl;
    }

    // Mostrar el total de jugadores restantes
    cout << "Total jugadores restantes: " << baseDeDatos.size() << endl;
    // Mostrar todos los jugadores restantes
    cout << "Jugadores restantes: " << endl;
    for (const auto& j : baseDeDatos) { 
        cout << "ID: " << j.id << " | Nombre: " << j.nombre << " | Nivel: " << j.nivel 
             << " | Clase: " << j.clase << " | Poder: " << j.poder << endl;
    }
}

int main(){

    // REQ 1: Set ordenado por ID (gracias al operator< de la struct)
    set<Jugador> dbJugadores = {
        {101, "Gandalf", 99, "Mago", 9500},
        {105, "Aragorn", 80, "Guerrero", 8000},
        {102, "Legolas", 85, "Arquero", 7500},
        {104, "Gimli",   70, "Guerrero", 7200},
        {103, "Frodo",   50, "Ladron",   1500}
    };

    cout << "DB Cargada. Total jugadores: " << dbJugadores.size() << endl;

    //Ejecutamos la funciones modulares
    clasificarPorClase(dbJugadores);

    //Preparamos el mapa rapido y buscamos a Legolas (102)
    unordered_map<int , Jugador> mapaRapido = crearAccesoRapido(dbJugadores);
    buscarJugador(103, mapaRapido);

    analizarNiveles(dbJugadores);
    filtrarPorPoder(dbJugadores, 7800);
    mostrarTop3(dbJugadores);

    cout << "\nELIMINACION DE JUGADOR (ID 102 - Legolas)" << endl;
    eliminarJugador(dbJugadores, mapaRapido, 102); // Eliminamos a Legolas (ID 102)
    
    return 0;
}