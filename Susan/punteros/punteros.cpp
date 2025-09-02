#include <iostream>
using namespace std;

//PUNTEROS
int main(){
    int n = 10;
    //10 se accede a traves de n o *p
    //F2X15(Direccion) se accede a traves de p o &n

    //Variable que guarda la ubicacion en memoria de la variable que guarda 10
    //*p porque no sera una variable que espera un entero, espera una direccion
    int *p = &n;

    cout << "Valor de n: " << n << endl;
    cout << "La direccion en memoria de n (Como su Id): " << &n << endl;


    cout << "Valor de p:" << p << endl;
    cout << "A lo que apunta p: " << *p << endl;

    //Cambio de valor de n
    *p = 11;

    cout << "Nuevo valor de n: " << n << endl;
    return 0;
}