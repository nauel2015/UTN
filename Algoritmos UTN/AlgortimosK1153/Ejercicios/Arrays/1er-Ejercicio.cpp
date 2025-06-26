
/* Ejercicio N°1: Se requiere un programa que permita al usuario ingresar el nombre y la edad de 5 personas.
Luego, muestra por pantalla el nombre y la edad de cada una de las personas.

1. Identifique las estructuras necesarias
2. Implemente el programa

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct persona
{
    char nombre[20];
    int edad;
}p[100];

// Declaracion de las funciones:
persona crearPersona(persona [], int);
void mostrarPersona(persona [], int);

int main()
{
    int cantPersona;
    cout <<"\nIngrese la cantidad de personas a agregar a lista: "; cin >> cantPersona;
    crearPersona(p, cantPersona);
    system("cls");
    mostrarPersona(p, cantPersona);
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
persona crearPersona(persona p[], int cantPersona)
{
    cout <<"Ingrese los datos de las personas a la lista. " << endl;

    for(int i=0; i<cantPersona; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(p[i].nombre, 20, '\n');
        cout <<"Edad: "; cin >> p[i].edad;
    }

    return *p;
}

void mostrarPersona(persona p[], int cantPersona)
{
    cout <<"\nLista de personas en el sistema.\n|Nombre     | Edad |" << endl;
    for(int i=0; i<cantPersona; i++)
    {
        cout << p[i].nombre <<" | " << p[i].edad <<" |" << endl;
    }
}