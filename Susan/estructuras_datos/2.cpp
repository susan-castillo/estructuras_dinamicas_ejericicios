#include <iostream>
using namespace std;

//Estructuras:

struct Student{
    string name;
    double note;
};

int main(){
    //Objeto de tipo Student.
    Student students[3] = {
        {"Juan", 8.5},
        {"Maria", 9.8},
        {"Pedro", 7.5}
    };

    for( int i = 0; i<3; i++){
        cout << "Nombre: " << students[i].name << endl;
        cout << "Nombre: " << students[i+1].note << endl;
    }

    return 0;
}