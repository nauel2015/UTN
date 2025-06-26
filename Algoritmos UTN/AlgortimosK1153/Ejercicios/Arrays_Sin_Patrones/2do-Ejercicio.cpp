
/* Ejercicio N°2: Liga de metegol.

Se está organizando un torneo relámpago de metegol. Se anotan 8 jugadores. De cada
jugador se conoce:

nombre (string)
puntaje total (int)

Tareas:
1. Cargar los jugadores.
2. Implementar una función que reciba el array y devuelva el jugador con más puntaje.
3. Permitir al usuario buscar un jugador por nombre y mostrar su puntaje (si existe).
4. Mostrar el promedio de puntajes de todos los jugadores.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct futbolistas
{
 char nombre[30];
 int puntaje;
}f1[100];

// Declaracion de las funciones:
futbolistas cargarJugadores(futbolistas [], int);
void mostrarPuntaje(futbolistas[], int);
void mayorPuntaje(futbolistas [], int);
float promedioPuntajes(futbolistas[], int);
void buscarJugador(futbolistas[], int);

int main ()
{
    int cantFut, opcion;
    cout << "\nIngrese la cantidad de futbolistas: "; cin >> cantFut;
    cargarJugadores(f1, cantFut); system("cls");

    do{
        cout <<"\n\tLiga de metegol. " << endl << endl;
        cout <<"Opcion 1: Mostrar puntajes. " << endl;
        cout <<"Opcion 2: Jugador MVP " << endl;
        cout <<"Opcion 3: Promedio de puntajes. " << endl;
        cout <<"Opcion 4: Buscar Jugador. " << endl;
        cout <<"Opcion 5: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("cls"); mostrarPuntaje(f1, cantFut); system("cls"); break;
            case 2: system("cls"); mayorPuntaje(f1, cantFut); system("cls"); break;
            case 3: system("cls"); cout <<"\nPromedio Total de Puntos: " << promedioPuntajes(f1, cantFut) << endl;
            cout <<"\n[Volviendo al menu..]" << endl; system("PAUSE"); system("cls"); break;
            case 4: system("cls"); buscarJugador(f1, cantFut); system("cls"); break;
            case 5: cout <<"\nHasta luego. " << endl; break;
        }

    }while(opcion!=5);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
futbolistas cargarJugadores(futbolistas futbolista[], int cantFut)
{
    cout <<"\nIngrese los datos del futbolista. " << endl;
    for(int i=0; i<cantFut; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(futbolista[i].nombre, 30, '\n');
        cout <<"Puntaje: "; cin >> futbolista[i].puntaje;
    } 

    return *futbolista;
}

void mostrarPuntaje(futbolistas futbolista[], int cantFut)
{
    cout <<"\n\tTablero de puntajes. " << endl << endl;
    for(int i=0; i<cantFut; i++)
    {
        cout << i+1 << ". " << futbolista[i].nombre << ": " << futbolista[i].puntaje <<" Puntos."<< endl;
    }

    cout <<"\n[Volviendo al menu..] " << endl;
    system("PAUSE");
}

void mayorPuntaje(futbolistas futbolista[], int cantFut)
{
    int mayor=0;
    for(int i=0; i<cantFut; i++)
    {
        if(futbolista[i].puntaje > mayor)
        {
            mayor = futbolista[i].puntaje;
        }
    }

    cout <<"\nJugador MPV. " << endl << endl;
    for(int i=0; i<cantFut; i++)
    {
        if(futbolista[i].puntaje == mayor)
        {
            cout << futbolista[i].nombre <<": " << mayor <<" Puntos. " << endl;
        }
    }

    cout <<"\n[Volviendo al menu..]" << endl;
    system("PAUSE");
}

float promedioPuntajes(futbolistas futbolista[], int cantFut)
{
    float totalPuntos=0;
    float promedio=0;
    for(int i=0; i<cantFut; i++)
    {
        totalPuntos += futbolista[i].puntaje;
    }

    promedio = totalPuntos/cantFut;

    return promedio;
}

void buscarJugador(futbolistas futbolista[], int cantFut)
{
    char buscado[30];
    bool encontrado = false;

    cin.ignore(); // Limpiar el buffer antes de getline
    cout <<"\nIngrese el nombre del jugador a buscar: "; cin.getline(buscado, 30, '\n');

    for(int i=0; i<cantFut; i++)
    {
        if(strcmp(buscado, futbolista[i].nombre) == 0)
        {
            cout <<"Jugador encontrado. \n" << futbolista[i].nombre <<": " << futbolista[i].puntaje <<" Puntos." << endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado)
    {
        cout <<"\nNo se encontró al jugador." << endl;
    }

    cout <<"\n[Volviendo al menu..]" << endl;
    system("PAUSE");
}
