
/* Ejercicio N°1: Crear una función para ordenar un array de enteros de menor a mayor

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Declaracion de las funciones.
int ordenamientoBurbuja(int [], int);
void mostrarOrdenado(int [], int);

int main()
{
    int numeros[10], cont=0;
    cout <<"\n\tFuncion ordenamientoBurbuja." << endl;
    cout <<"\nComplete el arrays. " << endl;
    for(int i=0; i<10; i++)
    {
        cout <<"Posicion[" << i <<"]: "; cin >> numeros[i];
        cont++;
    }

    ordenamientoBurbuja(numeros, cont);
    mostrarOrdenado(numeros, cont);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Defincion de las funciones.
int ordenamientoBurbuja(int numeros[], int len)
{
    int aux=0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(numeros[j]>numeros[j+1])
            {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }

    return *numeros;
}

void mostrarOrdenado(int numeros[], int len)
{
    cout <<"\nSe muesta el arrays ordenado de menor a mayor. " << endl;

    for(int i=0; i<len; i++)
    {
        cout <<"|" << numeros[i] <<"| ";
    }

    cout <<"\n";
}