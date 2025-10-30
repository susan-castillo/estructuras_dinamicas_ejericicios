#include <iostream>
using namespace std;

int sumaDosAnteriores(int n){
    //Caso base: Si es 0 retonarna 0 y si es 1 retorna 1
    if (n <= 1) return n;
    
    return sumaDosAnteriores(n-1) + sumaDosAnteriores(n-2);
}

int main(){
    
    int n = 5;
    cout << sumaDosAnteriores(n);
    return 0;
}