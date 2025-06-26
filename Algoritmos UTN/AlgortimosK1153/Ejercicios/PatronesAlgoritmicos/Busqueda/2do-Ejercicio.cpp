
/* Ejercicio N°2: Ejercicio de búsqueda binaria:
Dado un array de nombres, ordenar el array y luego solicitar al usuario ingresar un nombre y utiliza la
búsqueda binaria para determinar si ese nombre está presente en el array. Muestra un mensaje indicando si
se encontró o no.


*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Declaracion de las funciones.
int busquedaSecuencial(string [], int, string);

int main()
{
    string nombres[5], buscarNombre;
    int contNombres=0, pos;

    cout <<"\n\tBusquedaSecuencial. " << endl;
    cout <<"\nComplete el arrays de nombres. " << endl;
    for(int i=0; i<5; i++)
    {
        cout <<"Nombre Nro " << i+1 <<": "; getline(cin, nombres[i]);
        contNombres++;
    }

    cout <<"\nIngrese el nombre a buscar: "; getline(cin, buscarNombre);
    pos = busquedaSecuencial(nombres, contNombres, buscarNombre);
    if(pos!=-1)
    {
        cout << "Nombre encontrado en la posicion [" << pos <<"]. " << endl;
    }else{
        cout << "Nombre no encontrado." << endl;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
int busquedaSecuencial(string nombres[], int len, string BuscarNombre)
{
    int i=0;
    while(i<len&&nombres[i]!=BuscarNombre)
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