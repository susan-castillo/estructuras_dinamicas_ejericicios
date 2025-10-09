#include <iostream>
using namespace std;

void swap(int *a, int* b){
    int temp = *a; 
    *a = *b;
    *b = temp;

}

int main()
{

    int numbers[5] = {10, 20, 30, 40, 50};
    int *p = numbers;

    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento: " << *(p+i) << endl;
    }

    int x= 5, y= 6;
    cout << "Antes del swap: " << endl;
    cout<< "X: " << x << endl;
    cout<< "y: " << y << endl;

    swap(&x, &y);

    cout << "Despues del swap: " << endl;
    cout<< "X: " << x << endl;
    cout<< "y: " << y << endl;
    
    return 0;
}