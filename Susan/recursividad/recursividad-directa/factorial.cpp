#include <iostream>
using namespace std;

int factorial(int n){
    //caso base
    if(n == 1) return 0;

    //caso recursivo
    return n * factorial(n-1);
}

int main(){
    return 0;
}