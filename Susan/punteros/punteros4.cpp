#include <iostream>
using namespace std;

int main(){

    int x = 10;
    int *puntero = &x; //puntero a x
    int **puntero2 = &puntero; //puntero a puntero

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;
    cout << "Valor del puntero: " << puntero << endl;
    cout << "Valor al que apunta el puntero: " << *puntero << endl;
    cout << "Direccion del puntero: " << &puntero << endl;
}