#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main(){
    string text = "hola buenas tardes hola";

    //string palabra
    //int: cantidad de repeticiones
    map<string, int> frecuencia;

    string palabra;

    //Fragmenta la palabra, los separa.
    stringstream ss(text);

    while(ss >> palabra) {
        frecuencia[palabra]++;
    }

    for(auto& par: frecuencia){
        cout <<par.first<< ": "<<par.second << endl;
    }

    return 0;
}