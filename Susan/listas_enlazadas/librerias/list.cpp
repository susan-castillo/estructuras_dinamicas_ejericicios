#include <iostream>
#include <list>
using namespace std;

// Usar la libreria cuando queremos utilizar listas pequeñas de lo contrario usar las listas dinamicas.
int main()
{
    list<int> numbers;

    // Agregando elementos al final
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    // Agregando elementos al principio
    numbers.push_front(40);

    // Por cada elemento se recorre, sin necesidad de poner un final
    for (int i : numbers)
    {
        cout << i << " -> ";
    }
    cout << endl;

    numbers.pop_front(); // Eliminaria el numero 40
    numbers.pop_back();  // Eliminaria el numero 30

    for (int i : numbers)
    {
        cout << i << " -> ";
    }

    return 0;
}