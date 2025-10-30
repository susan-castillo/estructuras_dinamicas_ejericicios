#include <iostream>
using namespace std;

int contarDigitos(int n){
    //Caso base:
    if(n < 10) return 1;

    //Caso recursivo:
    return 1 + contarDigitos(n / 10);
}


int main(){

    int numero = 12345;
    cout << "El numero " << numero << " tiene " << contarDigitos(numero) << " digitos." << endl;
    return 0;
}