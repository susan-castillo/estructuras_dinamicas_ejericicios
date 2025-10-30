#include <iostream>
#include <set>
using namespace std;

//La desventaja de usar libreria es que solo podemos hacer recorrido en inOrder.
//Ya balancea los datos.
 
int main(){
    set<int> arbol;

    arbol.insert(10);
    arbol.insert(6);
    arbol.insert(15);
    arbol.insert(4);

    for(int i: arbol){
        cout << i << " ";
    }

    //Metodo de buqueda: Devuelve 1 si existe y 0 si no.
    cout << endl << arbol.count(6);

}
