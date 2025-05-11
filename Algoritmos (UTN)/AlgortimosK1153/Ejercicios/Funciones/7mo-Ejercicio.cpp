
// Ejercicio N°6: Escribir una función que reciba un número entero y devuelva la longitud del mismo. 


#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Declaracion de la funcion:
int longitudEntero(int numero);

int main()
{
    int entero;
    cout <<"\nIngrese un entero: "; cin >> entero;
    cout <<"\nLongitud: " << longitudEntero(entero);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int longitudEntero(int numero)
{
    if(numero==0)
    return 1;

    else if(numero!=0)
    return log10(abs(numero)) + 1;
}