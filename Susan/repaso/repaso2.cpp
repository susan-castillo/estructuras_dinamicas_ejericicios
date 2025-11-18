#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> numeros = {7,2,3,2,7,1,6};
    set <int> numerosOrdenados(
        numeros.begin(),
        numeros.end()
    );

    for(int numero: numerosOrdenados){
        cout <<numero<< " ";
    }
    return 0;
}