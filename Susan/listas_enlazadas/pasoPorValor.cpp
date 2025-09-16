#include <iostream>
using namespace std;

// Paso por valor
// int a es solo una copia del valor de a
void cambiarValor(int a) { a = 20; }

// Paso por referencia
// int& a es la dirección de memoria de a
// Todo lo que le pase a int& a le pasara a la variabale original
void cambiarValorPorReferencia(int& a) { a = 0; }

// Paso por referencia de punteros
// int& a es la dirección de memoria de un puntero
//  Todo lo que le pase a int& a le pasara a la variabale original
void cambiarValorPorReferenciaPtr(int*& a) { a = nullptr; }

int main() {
  int a = 10;

  int* ptr = &a;

  cout << "ptr: " << ptr << "\n";

  cambiarValor(a);
  cambiarValorPorReferencia(a);
  cambiarValorPorReferenciaPtr(ptr);

  cout << "ptr: " << ptr << "\n";
  cout << "a = " << a;
  return 0;
}