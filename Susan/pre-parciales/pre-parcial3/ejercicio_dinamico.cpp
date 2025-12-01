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

// Función para pedir datos al usuario
set<Jugador> registrarJugadoresDinamicamente() {
    set<Jugador> baseDeDatos;
    char continuar = 's'; // Variable para controlar el bucle

    cout << "--- SISTEMA DE REGISTRO DE JUGADORES RPG ---\n";

    do {
        Jugador j;
        
        cout << "\nIngrese ID (numero unico): ";
        cin >> j.id;

        cout << "Ingrese el nombre: ";
        getline(cin >> ws, j.nombre);
    
        cout << "Ingrese Nivel (numero): ";
        cin >> j.nivel;

        cout << "Ingrese Clase (Mago, Guerrero, Arquero): ";
        cin >> j.clase;

        cout << "Ingrese Poder (numero): ";
        cin >> j.poder;

        // --- MOMENTO CLAVE: INSERTAR EN EL SET ---
        // Aquí ocurre la magia del ordenamiento automático
        baseDeDatos.insert(j);
        cout << "-> Jugador guardado exitosamente.\n";

        cout << "\nDesea agregar otro jugador? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return baseDeDatos;
}

int main(){

    // REQ 1: Set ordenado por ID (gracias al operator< de la struct)
    set<Jugador> dbJugadores = registrarJugadoresDinamicamente();

    // Verificación rápida
    if (dbJugadores.empty()) {
        cout << "No se registraron jugadores. Cerrando programa.\n";
        return 0;
    }

    cout << "DB Cargada. Total jugadores: " << dbJugadores.size() << endl;

    //Ejecutamos la funciones modulares
    clasificarPorClase(dbJugadores);

    //Preparamos el mapa rapido y buscamos a Legolas (102)
    unordered_map<int , Jugador> mapaRapido = crearAccesoRapido(dbJugadores);
    buscarJugador(103, mapaRapido);

    analizarNiveles(dbJugadores);
    filtrarPorPoder(dbJugadores, 7800);
    mostrarTop3(dbJugadores);
    
    return 0;
}