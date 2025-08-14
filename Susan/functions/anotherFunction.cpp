#include <iostream>
#include <cstdarg>
using namespace std;

//Creacion de funcion sin saber la cantidad de parametros que tendra
int sum(int count, ...){
    //En args se guardaran todos los parametros que vienen en la funcion con el uso de va_list(Es un arreglo)
    va_list args;
    //con va_start me ubico en el primer elemento(el 1)
    va_start(args, count);

    //Se suman todos los parametros recibidos
    int total = 0;
    for(int i = 0; i < count; i++){
        //va_arg pasa a la siguiente iteración
        total += va_arg(args, int);
    }

    //Con va_end libero la memoria
    va_end(args);

    return total;
}


int main (){

    //El primer numero representa el total de numero que se mandaran. exem: Si son 2 sería: (2,1,5)
    cout << sum(5,1,2,3,4,5);

    return 0;
}