//Contenido aplicados
//Templates(Creación de funciones mas generalizadas con mismos tipos de datos o diferentes)
#include <iostream>
using namespace std;

//Template functions
// Manera de crear un funcion sin especificar el tipo de dato. Funcion mas generalizada
template <typename T>
T max_number(T a, T b){
    return a > b ? a : b;
}

// Ahora permite mandar dos datos diferentes a la funcion (int, double)
// decltype se tiene que especificar que tiene que hacer la funcion
template <typename T, typename U>
auto max_number2(T a, U b) -> decltype(a > b ? a : b){
    return a > b ? a : b;
}

int main (){

    auto result = max_number(5,10);
    auto result2 = max_number(5.236, 1.25);

    cout << result << endl;
    cout << result2;

    
    result = max_number2(5,10.2365);

    cout << result << endl;
    cout << result;

    return 0;
}