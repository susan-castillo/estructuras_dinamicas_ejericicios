#include <iostream>
using namespace std;

struct Contact {
    int id = 0;
    string name;
    string phone;
    string email;
};

const int maxContacts = 100;
Contact agenda[maxContacts];
int totalContacts = 0;

void showAgenda(Contact agenda[], int n){
    cout << "Agenda de Contactos:" << endl;

    if(n == 0){
        cout << "No hay contactos en la agenda." << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Contacto " << (i + 1) << ":" << endl;
        cout << "Nombre: " << agenda[i].name << endl;
        cout << "Teléfono: " << agenda[i].phone << endl;
        cout << "Email: " << agenda[i].email << endl;
        cout << "------------------------" << endl;
    }
}

int addContact(Contact agenda[], int n) {
    if (n >= maxContacts) {
        cout << "La agenda está llena. No se pueden agregar más contactos." << endl;
        return n;
    }

    Contact newContact;
    cout << "Ingrese el nombre del contacto: ";
    // >> ws para ignorar espacios en blanco iniciales
    getline(cin >> ws, newContact.name);
    cout << "Ingrese el teléfono del contacto: ";
    getline(cin, newContact.phone);
    cout << "Ingrese el email del contacto: ";
    getline(cin, newContact.email);

    agenda[n] = newContact;
    cout << "Contacto agregado exitosamente" << endl;
    return n + 1;
}

int searchContact(Contact agenda[], int n, const string& searchName) {
    for (int i= 0; i < n; i++) {
        if (agenda[i].name == searchName) {
            return i;
        }
    }
    // Si no se encuentra el contacto, retorna -1
    return -1;
}

void updateContact(Contact agenda[], int n) {
    string name;
    cout << "Ingrese el nombre del contacto a actualizar: ";
    getline(cin >> ws, name);
    int index = searchContact(agenda, n, name);
    if (index != -1) {
        cout << "Ingrese el nuevo teléfono del contacto: ";
        getline(cin, agenda[index].phone);
        cout << "Ingrese el nuevo email del contacto: ";
        getline(cin, agenda[index].email);
        cout << "Contacto actualizado exitosamente" << endl;
    } else {
        cout << "Contacto no encontrado" << endl;
    }
}

int deleteContact(Contact agenta[], int n) {
    string name;
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin >> ws, name);
    int index = searchContact(agenta, n, name);

    if (index != -1) {
        for (int i = index; i < n - 1; i++) {
            agenta[i] = agenta[i - 1];
        }
        cout << "Contacto eliminado exitosamente" << endl;
        return n - 1;
    } else {
        cout << "Contacto no encontrado" << endl;
        return n;
    }

}

int main() {
    int choice = 0;

    cout << "Bienvenido a la Agenda de Contactos" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Mostrar contactos" << endl;
    cout << "2. Agregar contacto" << endl;
    cout << "3. Actualizar contactos" << endl;
    cout << "2. Eliminar contacto" << endl;
    cout << "0. Salir" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            showAgenda(agenda, totalContacts);
            break;
        case 2:
            totalContacts = addContact(agenda, totalContacts);
            break;
        case 3:
            updateContact(agenda, totalContacts);
            break;
        case 4:
            totalContacts = deleteContact(agenda, totalContacts);
            break;
        case 0:
            cout << "Saliendo de la agenda. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intente de nuevo." << endl;
            break;
    }
    return 0;
}
