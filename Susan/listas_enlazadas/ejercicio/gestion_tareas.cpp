#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Tarea
{
    string nombre;
    int prioridad; // 1: alta, 2: media, 3: baja
};

void agregarTarea(list<Tarea> &tareas, string &nombre, int prioridad)
{
    Tarea nuevaTarea = {nombre, prioridad};
    tareas.push_back(nuevaTarea);
}

void mostrarTareas(list<Tarea> &tareas){
    cout << "\nTareas:\n";
    for(Tarea tarea : tareas){
        cout << "Nombre: " << tarea.nombre;
        cout << "\nPrioridad: " << tarea.prioridad << "\n";
        cout << "----------------------------------------\n";
    }
}

void tareasUrgente(list<Tarea> &tareas){
    //Procesar tareas urgentes (prioridad alta)
    stack<Tarea> pilaTareas;
    for(Tarea tarea : tareas){
        if(tarea.prioridad == 1){
            pilaTareas.push(tarea);
        }
    }

    cout << "\nProcesando tareas urgentes (prioridad alta):\n";
    while(!pilaTareas.empty()){
        Tarea tarea = pilaTareas.top();
        cout << "Procesando tarea: " << tarea.nombre << " con prioridad: " << tarea.prioridad << "\n";
        pilaTareas.pop();
    }
}

void tareasEspera(list<Tarea> &tareas){
    //Procesar tareas en espera (prioridad media y baja)
    queue<Tarea> colaTareas;
    for(Tarea tarea : tareas){
        if(tarea.prioridad == 2 || tarea.prioridad == 3){
            colaTareas.push(tarea);
        }
    }

    cout << "\nProcesando tareas en espera (prioridad media y baja):\n";
    while(!colaTareas.empty()){
        Tarea tarea = colaTareas.front();
        cout << "Procesando tarea: " << tarea.nombre << " con prioridad: " << tarea.prioridad << "\n";
        colaTareas.pop();
    }
}

void ordenarPorPrioridad(list<Tarea> &tareas){
    tareas.sort([](const Tarea &a, const Tarea &b) {
        return a.prioridad < b.prioridad; // Orden ascendente por prioridad
    });
    cout << "\nTareas ordenadas por prioridad:\n";
    mostrarTareas(tareas);
}

void  buscarTarea(list<Tarea> &tareas, const string &nombre){
    auto it = find_if(tareas.begin(), tareas.end(), [&nombre](const Tarea &tarea) {
        return tarea.nombre == nombre;
    });

    if(it != tareas.end()){
        cout << "Tarea encontrada: " << it->nombre << " con prioridad: " << it->prioridad << "\n";
    } else {
        cout << "Tarea no encontrada.\n";
    }
}


void menu()
{
    int option = 0;
    list<Tarea> tareas;

    do
    {
        cout << "\nMenu de gestion de tareas:\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Ordenar tareas por prioridad\n";
        cout << "4. Buscar tarea por nombre\n";
        cout << "5. Procesar tareas urgentes\n";
        cout << "6. Procesar tareas en espera\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            string nombre;
            int prioridad;
            cout << "Ingrese el nombre de la tarea: ";
            cin >> ws; // Limpiar el buffer
            getline(cin, nombre);
            cout << "Ingrese la prioridad (1: alta, 2: media, 3: baja): ";
            cin >> prioridad;
            agregarTarea(tareas, nombre, prioridad);
            break;
        }
        case 2:
        {
            mostrarTareas(tareas);
            break;
        }
        case 3:
        {
            ordenarPorPrioridad(tareas);
            break;
        }
        case 4:
        {
            cout << "Ingrese el nombre de la tarea a buscar: ";
            string nombreBuscar;
            cin >> ws; // Limpiar el buffer
            getline(cin, nombreBuscar);
            buscarTarea(tareas, nombreBuscar);
            break;
        }
        case 5:
        {
            tareasUrgente(tareas);
            break;
        }
        case 6:
        {
            tareasEspera(tareas);
            break;
        }
        case 7:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (option != 7);
}

int main()
{
    menu();
    return 0;
}