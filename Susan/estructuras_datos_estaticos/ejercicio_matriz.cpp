#include <iostream>
using namespace std;

int main(){
    int n = 5;

//Asi queda la matriz
    int matrix [n][n] = 
    {
/*      {1,2,3,4,5},
        {2,4,6,8,10},
        {3,6,9,12,15},
        {4,8,12,16,20},
        {5,10,15,20,25} */
    };

//Se llena la matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = (i+1) * (j+1);
        }
    }

//Se imprime la matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << "\t"; // \t agrega una tabulación
        }
        cout << endl; //Espacio luego de recorrer el buble principal
    }

//Finaliza el programa
    return 0;
}