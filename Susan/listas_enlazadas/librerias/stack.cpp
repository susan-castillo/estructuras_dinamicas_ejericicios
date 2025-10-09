#include <iostream>
#include <stack>
using namespace std;

int main()
{   
    stack<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);

    //Top solo muestra no desapila
    cout << "Elemento top: " << numbers.top() << '\n';
    
    //Desapila el elemento top
    numbers.pop();
    numbers.pop();
    cout << "Elemento top luego de desapilar: " << numbers.top() << '\n';

    return 0;
}