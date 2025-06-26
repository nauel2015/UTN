
/* Ejercicio N°4: Ejercicio de búsqueda binaria en un array ordenado de fechas:

Crea un array con 10 fechas ordenadas cronológicamente. Solicita al usuario ingresar una fecha y utiliza la
búsqueda binaria para determinar si esa fecha está presente en el array. Si se encuentra, muestra un mensaje
indicando la posición de la fecha en el array.

Para manejar fechas usar un numero con este formato: AAAAMMDD

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Declaracion de las funciones.
int busquedaBinaria(int [], int, int);

int main()
{
    int pos, anioBuscado, contFechas=10, fechas[10] = {1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007};
    cout <<"\n\tBusqueda Binaria. " << endl;
    cout <<"\nIngrese el año a buscar: "; cin >> anioBuscado;
    pos = busquedaBinaria(fechas, contFechas, anioBuscado);

    if(pos!=-1)
    {
        cout <<"\nLa fecha buscada se encuentra en la posicion [" << pos <<"]. " << endl;
    }else{
        cout <<"\nFecha no encontrada. " << endl;
    }
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
int busquedaBinaria(int fechas[], int len, int buscado)
{
    int inicio=0, final=len-1; // Ejemplo Final vale 10.
    while(inicio<=final) 
    {
        int medio = (inicio+final)/2; // medio valdria 5.
        if(fechas[medio]==buscado)
        {
            return medio;
        }else if(fechas[medio]<buscado){
            inicio = medio+1;
        }else{
            final = medio-1;
        }
    }

    return -1;
}