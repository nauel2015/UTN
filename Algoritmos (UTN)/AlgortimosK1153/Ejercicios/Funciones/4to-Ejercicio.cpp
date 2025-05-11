
// Ejercicio N°4: Crea una función que reciba dos números enteros y devuelva el máximo común divisor entre ambos. 

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int maximoComunDivisor(int, int);

int main()
{
    int n1, n2;
    cout <<"\nIngrese un Numero: "; cin >> n1;
    cout <<"Ingrese otro numero: "; cin >> n2;

    cout <<"\nEl maximo comun divisor es: " << maximoComunDivisor(n1, n2) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int maximoComunDivisor(int a, int b)
{
    if(a==0||b==0)
    return 0;
    else if(a==b)
    return a;
    else if(a>b)
    return maximoComunDivisor(a-b, b);
    else if(a<b)
    return maximoComunDivisor(a, b-a);
}