#include <iostream>
#include <stack>
#include <string>
using namespace std;

//Para ahorrar recursos lo pasaremos por referencia y ademas como constante
bool isBalanced(const string& expression){
    stack<char> stack;

    for(char i: expression){
        if( i == '(' || i == '[' || i == '{'){
            stack.push(i);
        } else if( i == ')' || i == ']' || i == '}'){
            //Si la pila esta vacia, entonces quiere decir que no se ha encontrado ningun signo de abertura.
            if(stack.empty()){
                return false;
            }

            char top =  stack.top();
            stack.pop();

            if((i == ')' && top != '(') || 
                (i == ']' && top != '[') || 
                (i == '}' && top != '{' )){
                return false;
            }
        }
    }
    return stack.empty();
}

int main(){
    string expression;
    cin >> expression;

    if(isBalanced(expression)){
        cout << "La expresion esta balanceada" << endl;
    }else{
        cout << "La expresion no esta balanceada" << endl;
    }
    return 0;
}