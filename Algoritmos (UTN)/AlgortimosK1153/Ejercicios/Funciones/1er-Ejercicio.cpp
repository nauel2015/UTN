
// Ejercicio N°1: Crea una función que reciba dos números y devuelva su suma.

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int suma(int,int);

int main()
{
    int n1, n2;
    cout <<"\nIngrese un numero: "; cin >> n1;
    cout <<"Ingrese el numero que le va a sumar: "; cin >> n2;
    cout <<"\nResultado de la suma: " << suma(n1, n2) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int suma(int a,int b)
{
    return a+b;
}