//Contenidos aplicados:
// tipo de dato auto, almacenamiento de funcion en una variable, introducción al polimorfismo
#include <iostream>
#include <functional>
using namespace std;

double sum(int a, int b){
    double result = 0;
    return result = a + b;
}

int main (){

    auto result = sum(2.4, 3.1);
    auto result2 = sum(2, 3);
    cout << result << endl;
    cout << result2 << endl;

    //Almacenamos esta funcion en la variable f
    //int significa el tipo de dato que retorna la funcion
    //(int, int) Cantidad de parametros que recibe la funcion

    //Utilidad: Nos ayuda para hacer uso del polimorfismo
    function<int(int, int)> f = sum;
    result = f(2,3);
    cout << "Suma: " << result << endl;

    //Polimorfismo, cambiar la logica de la funcion sin necesidad de alterar la funcion original
    f = [](int a, int b){
        return a * b;
    };
    
    result = f(2,3);
    cout << "Multiplicacion: " << result << endl;

    //Otra manera de crear una función, utilidad de los corchetes.
    //En los corchetes podemos enviar valores quemados
    int n = 10;
    auto sumarN = [n](int a){
        return a + n;
    };

    cout << "Inyeccion en la funcion: " << sumarN(20);

    return 0;

}