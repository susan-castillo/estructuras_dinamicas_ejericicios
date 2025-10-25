#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
using namespace std;

struct Libro
{
    string titulo;
    string autor;
};

//Vector de libros dentro de la estructura biblioteca
struct Biblioteca
{
    string nombre;
    string direccion;
    vector<Libro> libros;
};

void solicitarDatosBiblioteca(list<Biblioteca> &biblio)
{
    Biblioteca b;
    int cantidadLibros;

    cout << "Ingrese el nombre de la biblioteca: ";
    getline(cin >> ws, b.nombre);
    cout << "Ingrese la direccion de la biblioteca: ";
    getline(cin >> ws, b.direccion);
    cout << "Ingrese la cantidad de libros que desea agregar: ";
    cin >> cantidadLibros;
    cin.ignore(); // Limpiar el buffer de entrada

    Libro libro;
    for (int i = 0; i < cantidadLibros; ++i)
    {
        cout << "Ingrese el titulo del libro " << (i + 1) << ": ";
        getline(cin >> ws, libro.titulo);
        cout << "Ingrese el autor del libro " << (i + 1) << ": ";
        getline(cin, libro.autor);
        b.libros.push_back(libro);
    }

    biblio.push_back(b);
}

void imprimirDatosBiblioteca(list<Biblioteca> &biblio)
{
    for (const auto &b : biblio)
    {
        cout << "Nombre de la biblioteca: " << b.nombre << endl;
        cout << "Direccion de la biblioteca: " << b.direccion << endl;
        cout << "Libros en la biblioteca:" << endl;
        for (const auto &libro : b.libros)
        {
            cout << "  Titulo: " << libro.titulo << ", Autor: " << libro.autor << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
}

void ordenarBibliotecasPorNombre(list<Biblioteca> &biblio)
{
    biblio.sort([](const Biblioteca &a, const Biblioteca &b) {
        return a.nombre < b.nombre;
    });
    cout << "Bibliotecas ordenadas por nombre exitosamente!" << endl;

    // Mostrar las bibliotecas ordenadas
    imprimirDatosBiblioteca(biblio);
}

void buscarBibliotecaPorNombre(const list<Biblioteca> &biblio)
{
    if(biblio.empty()) {
        cout << "La lista de bibliotecas esta vacia." << endl;
        return;
    }

    string nombreBuscado;
    cout << "Ingrese el nombre de la biblioteca a buscar: ";
    getline(cin >> ws, nombreBuscado);

   auto it = find_if(
        biblio.begin(),
        biblio.end(),
        [&](const Biblioteca &b){ 
            return b.nombre == nombreBuscado;
        }
   );

   //Mostrar resultados
   if(it != biblio.end()) {
        cout << "Biblioteca encontrada:" << endl;
        cout << "Nombre: " << it->nombre << endl;
        cout << "Direccion: " << it->direccion << endl;
        cout << "Libros en la biblioteca:" << endl;
        for (const auto &libro : it->libros)
        {
            cout << "  Titulo: " << libro.titulo << ", Autor: " << libro.autor << endl;
        }
   } else {
        cout << "Biblioteca con nombre '" << nombreBuscado << "' no encontrada." << endl;
   }

}

void menu()
{
    int opcion;
    list<Biblioteca> nuevoBiblioteca;
    do
    {
        cout << "Seleccione una opcion: ";
        cout << "\n1. Agregar nueva biblioteca";
        cout << "\n2. Mostrar bibliotecas";
        cout << "\n3. Ordenar bibliotecas por nombre";
        cout << "\n4. Buscar biblioteca por nombre";
        cout << "\n5. Salir";
        cout << "\nIngrese su opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion)
        {
        case 1:
        {
            cout << endl;
            solicitarDatosBiblioteca(nuevoBiblioteca);
            cout << "Biblioteca agregada exitosamente!" << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            imprimirDatosBiblioteca(nuevoBiblioteca);
            break;
        }
        case 3:
        {
            cout << endl;
            ordenarBibliotecasPorNombre(nuevoBiblioteca);
            break;
        }
        case 4:
        {
            cout << endl;
            buscarBibliotecaPorNombre(nuevoBiblioteca);
            break;
        }
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}
int main()
{
    menu();
    return 0;
}