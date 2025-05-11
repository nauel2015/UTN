
// Ejercicio N°2: Implementa una función que reciba dos números enteros y devuelva el resultado de multiplicarlos.

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int Multiplicacion(int,int);

int main()
{
    int n1, n2;
    cout <<"\nIngrese un numero: "; cin >> n1;
    cout <<"Ingrese el producto: "; cin >> n2;

    cout <<"\nResultado del producto: " << multiplicacion(n1, n2) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int multiplicacion(int a,int b)
{
    return a*b;
}