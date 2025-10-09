#include <iostream>
using namespace std;

struct Node
{
    int data;
    // Nos mantiene los nodos conectados, unos con otros, interlazados entre si.
    Node *next;
    Node *prev;
};

void insert(Node *&head, int value)
{
    Node *newNode = new Node{value, head, nullptr};
/*     if (head != nullptr)
    {
        head->prev = newNode;
    } */

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    //Define el elemento que sera el final
    Node* tail = head->prev;

    //Conexiones centrales
    newNode->next = head;
    newNode->prev = tail;

    //Conexiones a los extremos
    tail->next = newNode;
    head->prev = newNode;

    head = newNode;
    
}

// Funcion que permitira al usuario ingresar un valor hasta el final de la lista
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Ejemplo, si el usuario ingresa el dato numero 4 se guardara en current
    Node *current = head;
    // Se ingresa al bucle el cual se estara verificando si el siguiente valor al current es nulo.
    while (current->next != nullptr)
    {
        // De no encontrar un dato vacio en el siguiente, entonces se asigna current a ese dato (Como una escalera) y sigue el bucle.
        current = current->next;
    }

    // Cuando encuentra que el siguiente dato a current es nulo, entonces current se posiciona en la ultima posicion.
    current->next = newNode;
    newNode->prev = current;
}

// Funcion que libera la memoria
void free(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void search(Node *head, int value)
{
    Node *current = head;
    bool found = false;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found)
    {
        cout << "El valor " << value << " fue encontrado en la lista." << endl;
    }
    else
    {
        cout << "El valor " << value << " no fue encontrado en la lista." << endl;
    }
}

void printList(Node *head)
{
    // Le estamos diciendo que se coloque en la primera posición, osea head.
    Node *i = head;
    // Se va detener cuando encuentre un valor vacio
    while (i != nullptr)
    {
        // Cuando trabajamos con punteros, vamos acceder al estruct a traves de  una flechita ->, es lo equivalente al punto.
        cout << i->data << "->";
        i = i->next;
    }
}

void circularPrint(Node *head){
    if(head == nullptr){
        return;
    }

    Node* i = head;

    do{
        cout << i->data<< " ->";
        i = i->next;
    }while(i != head);
}

// Imprimir la lista en orden
void imprimirOrden(Node *head)
{
    // Se valida si la lista esta vacia
    if (head == nullptr)
    {
        // Si esta vacia, se retorna y no hace nada.
        return;
    }

    // Llamada, se va a llamar a si misma hasta que head sea nulo
    imprimirOrden(head->next);
    // Se imprime el valor de head despues de que la llamada ha llegado al final de la lista
    cout << head->data << "->";
}

void menu()
{
    Node *lista1 = nullptr;
    int opt = 5;

    do
    {
        cout << "\n1. Insertar" << "\n";
        cout << "2. Insertar al final" << "\n";
        cout << "3. Imprimir" << "\n";
        cout << "4. Imprimir en orden" << "\n";
        cout << "5. Liberar memoria" << "\n";
        cout << "6. Buscar un numero" << "\n";
        cout << "7. Salir" << "\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            int num;
            cout << "Ingrese el numero: ";
            cin >> num;
            insert(lista1, num);
            break;
        case 2:
            int num2;
            cout << "Ingrese el numero: ";
            cin >> num2;
            insertAtEnd(lista1, num2);
            break;
        case 3:
            circularPrint(lista1);
            break;
        case 4:
            imprimirOrden(lista1);
            break;
        case 5:
            free(lista1);
            break;
        case 6:
            int searchNum;
            cout << "Ingrese el numero a buscar: ";
            cin >> searchNum;
            search(lista1, searchNum);
            break;
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "\nOpcion invalida";
            break;
        }
    } while (opt != 6);
}

int main()
{
    menu();

    return 0;
}