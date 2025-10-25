#include <iostream>
using namespace std;

// int contarHatasN(int n){
//     for(int i=0; i <= n; i++){
//         cout <<i<<endl;
//     }
// }

//Los cout no se ejecutan, si no tuviese condicion seguiria al infinito.
void contarHastaRecursivo(int n){
    //Cuando n llega a 0 entonces todos los cout en espera se ejecutan.
    //Los cout se ejecutan del ultimo al primero, es decir (0,1,2,3)
    if(n==0) return; // Caso base
    contarHastaRecursivo(n-1); // Caso recursivo
    cout << n;
}

int main(){
    int n = 5;
    contarHastaRecursivo(n);
    return 0;
}