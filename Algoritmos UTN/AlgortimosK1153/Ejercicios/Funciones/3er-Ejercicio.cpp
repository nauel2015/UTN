
// Ejercicio N°3: Escribe una función que tome como entrada dos números enteros y devuelva su cociente y su resto.

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int division(int,int);
int restar(int, int);

int main()
{
    int n1, n2, n3;
    cout <<"\nIngrese un Numero: "; cin >> n1;
    cout <<"Ingrese el divisor: "; cin >> n2;
    cout <<"Ingrese el sustraendo: "; cin >> n3;

    cout <<"\nCociente: " << division(n1, n2);
    cout <<"\nResto: " << restar(n1, n3) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int division(int a,int b)
{
    return a/b;
}

int restar(int a, int b)
{
    return a-b;
}