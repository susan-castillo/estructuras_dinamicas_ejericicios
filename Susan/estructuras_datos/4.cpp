#include <iostream>
using namespace std;

//A esto se le conoce como abstracción - Cuando de algo general se parte de los específico
//Por ejemplo se parte de la super clase de Animal y esta se divide en las subclases de Perro y Gato
struct Animal{
    string nombre;
    int n_patas;

    //Metodos
    void emitir_sonido(){
        cout <<"*Emite un sonido*"<< endl;
    }
};

//Herencia de Animal a Perro (Es lo contrario a abstracción, se parte de lo mas especifico a lo mas general)
struct Perro : Animal{
    void emitir_sonido(){
        cout <<"*Hace guau*" << endl;
    }
};

//Herencia de Animal a Gato
struct Gato : Animal{
    void emitir_sonido(){
        cout <<"*Hace miau*" << endl;
    }
};

int main(){
    
    Perro perro1;
    perro1.nombre = "Capy";
    perro1.emitir_sonido();

    return 0;
}