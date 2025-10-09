#include <iostream>
#include <queue>
using namespace std;

int main()
{   
    queue<string> nombres;

    nombres.push("Ana");
    nombres.push("Beto");
    nombres.push("Carlos");
    nombres.push("Daniel");

    //Top solo muestra no desapila
    cout << "Elemento front: " << nombres.front() << '\n';
    
    //Desapila el elemento top
    nombres.pop();
    nombres.pop();
    cout << "Elemento top luego de desapilar: " << nombres.front() << '\n';

    return 0;
}