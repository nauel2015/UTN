
/* Ejercicio N°8: Escribir una función que tome como entrada un número entero y devuelva la suma de los dígitos pares del
número. Utilice esta función para imprimir la suma de los dígitos pares de los números entre 1 y un número
ingresado por el usuario.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int sumarParesdelNumero(int);

int main()
{
    int cant, sumaTotal=0;
    cout <<"\nIngrese un numero entero positivo: "; cin >> cant;

    if (cant < 1) 
    {
        cout << "El número debe ser mayor o igual a 1." << endl;
        return 1;
    }

    for(int i=1; i<=cant; i++)
    {
        sumaTotal += sumarParesdelNumero(i);
    }

    cout <<"La suma total de los pares del numero ingresado es: " << sumaTotal << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int sumarParesdelNumero(int numero)
{
    int suma=0;
    while(numero > 0)
    {
        int digito = numero %10;
        if(digito %2 == 0)
        {
            suma+=digito;
        }

        numero/=10;
    }

    return suma;
}