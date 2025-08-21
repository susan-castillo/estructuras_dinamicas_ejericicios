#include <iostream>
using namespace std;

//Structura semejante a una clase.
struct Rectangulo{
    //Atributos
    int base;
    int altura;

    //Metodos
    int area(){
        return base*altura;
    }
};

int main(){
    Rectangulo rect1 = {10,5};

    cout<< "Area: " << rect1.area();
    return 0;
}