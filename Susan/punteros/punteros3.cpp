#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Ingrese la cantidad de elementos" << endl;
    cin >> n;

    //New: Reservo memoria
    int* vector = new int[n];

    for(int i=0; i<n; i++){
        cout << "Ingrese un numero: " << endl;
        cin >> vector[i];
    }

    cout << "Los elementos del vector son: " << endl;
    for(int i=0; i<n; i++){
        cout << vector[i] << " ";
    } 

    //Delete: Libero memoria
    delete[] vector;
    
    return 0;
}