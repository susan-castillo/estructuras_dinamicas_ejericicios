#include <iostream>
using namespace std;

//Estructuras:

struct Address{
    string road;
    string city;
};

struct Persona{
    string name;
    int age;
    Address address;
};

int main(){
    //Objeto de tipo Persona.
    Persona person;
    person.name = "Juan";
    person.age = 15;
    person.address = {"Calle", "Bolivar"};

    //Otra manera de escribirlo
    Persona person2 = {
        "Maria", 30, {
            "Calle 1", "Ciudad 1"
        }
    };

    cout << "Nombre: " << person2.name << endl;
    cout << "Edad: " << person2.age << endl;
    cout << "Calle: " << person2.address.road << endl;
    cout << "Ciudad: " << person2.address.city << endl;
    return 0;
}