#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int array[] = {5,2,9,1,5,6};
    int n = sizeof(array)/sizeof(array[0]);

    //Ordenando array
    sort(array, array+n);
    int inicio = 0;
    int fin = n - 1;

    int search = 3;

    //ALGORITMO DE BUSQUEDA BINARIA
    while(inicio <= fin){
        int mitad = (inicio + fin) /2;  

        if(array[mitad] == search){
            cout << "Elemento encontrado: " << mitad;
            break;
        }else if(array[mitad] < search){
            //Verifica si esta en la mitad derecha
            inicio = mitad + 1;
        }else{
            //Verifica si esta en la mitad izquierda
            fin = mitad - 1;
        }
    }

    //Funcion que ya hace lo mismo que hicimos anteriormente.
    //Parametros: Inicio, final y elemento a buscar.
    binary_search(array, array+n, search);

    return 0;
}