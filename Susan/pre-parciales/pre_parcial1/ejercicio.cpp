#include <iostream>
using namespace std;

const int cantidad_facultades = 5;

struct Facultad {
  int id;
  string carrera_principal;
  int numero_estudiantes;
};

struct Universidad {
  string nombre;
  string direccion;
  Facultad facultades[5];
};

// Podemos hacer funciones de tipo universidad
Universidad solicitarDatos() {
  Universidad u;
  cout << "Ingrese el nombre de la universidad: ";
  getline(cin, u.nombre);
  cout << "Ingrese la direccion de la universidad: ";
  getline(cin, u.direccion);
  // Ingresamos los datos relacionados a la facultad.
  for (int i = 0; i < cantidad_facultades; i++) {
    cout << "Ingrese el numero de la facultad: ";
    cin >> u.facultades[i].id;
    cin.ignore();
    cout << "Ingrese la carrera principal: ";
    getline(cin, u.facultades[i].carrera_principal);
    cout << "Ingrese el numero de estudiantes: ";
    cin >> u.facultades[i].numero_estudiantes;
    // Limpia el buffer
    cin.ignore();
    // Salto de linea
    cout << "\n";
  }

  return u;
}

void imprimirDatos(Universidad u) {
  cout << "Nombre: " << u.nombre << "\n";
  cout << "Direccion: " << u.direccion << "\n" ;
  for (int i = 0; i < cantidad_facultades; i++) {
    cout << "Id:" << u.facultades[i].id << "\n";
    cout << "Carrera principal:" << u.facultades[i].carrera_principal << "\n";
    cout << "Numero de estudiantes: " << u.facultades[i].numero_estudiantes << "\n";
  }
}

void buscarUniversidad(Universidad u){
  string nombre;
  cout << "Ingresa el nombre de la universidad a buscar: ";
  getline(cin, nombre);

  for (int i=0; i < cantidad_facultades; i++){
    if(nombre == u.nombre){
      if()
    }
  }  
}

int main() {
  Universidad u;
  int option = 0;
  do {
    cout << "Ingresa una opcion: ";
    cin >> option;

    switch (option) {
      case 1:
        // La funcion espera un retorno de tipo Univerdad(Esto para que exista
        // compatibilidad) puesto que la variable en la que se guardara es de
        // tipo universidad)
        u = solicitarDatos();
        break;
      case 2:
        imprimirDatos(u);
        break;
      case 3: 
        buscarUniversidad(u);  
      default:
        break;
    };

  } while (option == 5);
}