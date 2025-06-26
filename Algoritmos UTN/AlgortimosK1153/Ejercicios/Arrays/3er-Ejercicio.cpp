
/* Ejercicio N°3:  Se requiere un programa que permita al usuario ingresar la información de 10 libros, incluyendo su título,
autor y año de publicación. Luego, permite al usuario consultar todos los libros que se publicaron en un año en
particular que el usuario debe poner.

1. Identifique las estructuras necesarias
2. Implemente el programa

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct libreria
{
    char titulo[50];
    char autor[30];
    int anioPublicacion;
}libro[10];

// Declaracion de las funciones:
libreria insertarLibro(libreria []);
void consultarLibro(libreria []);

int main()
{
    int opcion;
    do{
        cout <<"\n\tBienvenido a la libreria." << endl;
        cout <<"Opcion 1: Insertar 10 libros a la libreria. " << endl;
        cout <<"Opcion 2: Buscar un libro de la libreria. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); insertarLibro(libro); system("cls"); break;
            case 2: system("cls"); consultarLibro(libro); system("cls"); break;
            case 3: cout <<"\nHasta Luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
libreria insertarLibro(libreria libro[])
{
    cout <<"\nInserte los libros." << endl;
    for(int i=0; i<10; i++)
    {
        cout <<"\nSlot " << i+1 << ". [Enter]";
        cin.ignore();
        cout <<"Titulo del libro: "; cin.getline(libro[i].titulo, 50, '\n');
        cout <<"Autor: "; cin.getline(libro[i].autor, 30, '\n');
        cout <<"Año de publicacion: "; cin >> libro[i].anioPublicacion;

        cin.ignore();
    }

    system("cls");
    return *libro;
}

void consultarLibro(libreria libro[])
{
    int buscarLibroAño;
    cout <<"\nIngrese el año de publicacion de los libros que busca: "; cin >> buscarLibroAño;
    cout <<"Los libros coincidentes al año " << buscarLibroAño <<": " << endl;

    if(buscarLibroAño >= 868 && buscarLibroAño <= 2025)
    {
        for(int i=0; i<10; i++)
        {
            if(buscarLibroAño == libro[i].anioPublicacion)
            {
                cout <<"\nSlot " << i+1 << ". " << endl;
                cout <<"Titulo del libro: " << libro[i].titulo << endl;
                cout <<"Autor: " << libro[i].autor << endl;
            }else{
                cout<<"\nNo existe un libro de ese año en la libreria. " << endl << endl;
                system("Pause"); break;
            }
        }
    }else{
        cout<<"\nNo existe un libro publicado antes o despues del año " << buscarLibroAño <<". " << endl << endl;
        system("Pause");
    }
}