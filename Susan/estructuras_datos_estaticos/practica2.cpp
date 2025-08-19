#include <iostream>
using namespace std;

int main(){
    int alumnos = 3;
    int examenes = 4;

//Asi queda la matriz
    int notas [alumnos][examenes] = 
    {
        {10,5,3,8},
        {2,4,6,8},
        {3,6,9,12},
    };

    for(int i= 0; i < alumnos; i++){
        int suma =0;
        for(int j = 0; j < examenes; j++){
            suma += notas[i][j];
        }
        double media = (double)suma/examenes;
        cout << "El alumno " << i;
        cout << " tiene una medida de: " << media << endl;
    }

//Finaliza el programa
    return 0;
}