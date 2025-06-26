
/* Ejercicio N°1: Ejercicio de búsqueda secuencial:
Dado un array de números enteros, solicita al usuario ingresar un número y utiliza la búsqueda secuencial
para determinar si ese número está presente en el array. Muestra un mensaje indicando si se encontró o no.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Declaracion de las funciones.
int busquedaSecuencial(int [], int, int);

int main()
{
    int numeros[10], cont=0, buscarNumero, pos;
    cout <<"\n\tFuncion BusquedaSecuencial." << endl;
    cout <<"\nComplete el arrays. " << endl;
    for(int i=0; i<10; i++)
    {
        cout <<"Posicion[" << i <<"]: "; cin >> numeros[i];
        cont++;
    }

    cout <<"\nIngrese el entero a buscar: "; cin >> buscarNumero;
    pos = busquedaSecuencial(numeros, cont, buscarNumero);
    if(pos!=-1)
    {
        cout << "Valor encontrado en la posicion [" << pos <<"]. " << endl;
    }else{
        cout << "Valor no encontrado." << endl;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
int busquedaSecuencial(int numeros[], int len, int valor)
{
    int i=0;
    while (i < len && numeros[i] != valor)
    {
        i++;
    }

    if(i==len)
    {
        return -1;
    }else{
        return i;
    }
}