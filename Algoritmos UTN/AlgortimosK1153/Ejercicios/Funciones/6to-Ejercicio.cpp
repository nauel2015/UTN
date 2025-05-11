
// Ejercicio N°5: Escribir una función para encontrar la suma de los dígitos de un número entero.
// Utilice esta función para imprimir la suma de los dígitos de los números entre 1 y 100.


#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de la funcion:
int sumaDigitos(int);

int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        cout << "Suma de los dígitos de " << i << " = " << sumaDigitos(i) << endl;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion:
int sumaDigitos(int numero)
{
    int suma = 0;
    while (numero > 0) 
    {
        suma += numero % 10; // Tomar el último dígito
        numero /= 10;        // Quitar el último dígito
    }
    return suma;
}