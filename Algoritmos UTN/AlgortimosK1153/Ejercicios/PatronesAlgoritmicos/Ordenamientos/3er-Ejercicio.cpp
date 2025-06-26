
/* Ejercicio N°3: Siendo Persona { int documento; string nombre}. Crear una función para ordenar un array de Persona por su documento
en orden ascendente utilizando el algoritmo de burbuja.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct persona
{
    char nombre[30];
    int documento;
}personas[5];

// Declaracion de las funciones.
persona cargarPersona(persona [], int &);
persona ordenamientoBurbuja(persona [], int);
void mostrarPersonas(persona [], int);

int main()
{
    int contPersonas=0, opcion=0;
    do{
        cout <<"\n\tOrdenamientoBurbuja con personas. " << endl << endl;
        cout <<"Opcion 1: Cargar personas. " << endl;
        cout <<"Opcion 2: Mostrar personas. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarPersona(personas, contPersonas); system("cls"); break;
            case 2: system("cls"); ordenamientoBurbuja(personas, contPersonas);
            mostrarPersonas(personas, contPersonas); system("cls"); break;
            case 3: cout <<"\nHasta Luego. " << endl; break;
        }

    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

persona cargarPersona(persona personas[], int &contPersonas)
{
    int cantPersonas;
    cout <<"\n\tPersonas ingresadas [" << contPersonas <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de personas a cargar: "; cin >> cantPersonas;

    if(cantPersonas+contPersonas>5)
    {
        cout <<"ERROR. Espacio insuficiente. Solo se pueden cargar hasta " <<(5-contPersonas) <<" persona mas. " << endl;

        cout <<"\nVolviendo al menu.. [ENTER]" << endl;
        system("PAUSE");
        return *personas;
    }

    if(contPersonas>5)
    {
        cout <<"\nAlmacenamiento lleno, no se pueden cargar mas personas. " << endl;

        cout <<"\nVolviendo al menu.. [ENTER]" << endl;
        system("PAUSE");
        return *personas;
    }

    for(int i=0; i<cantPersonas; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(personas[contPersonas].nombre, 30, '\n');
        cout <<"Documento de identidad (DNI): "; cin >> personas[contPersonas].documento;
        contPersonas++;
    }

    return *personas;
}

persona ordenamientoBurbuja(persona personas[], int len)
{
    persona aux;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-1; j++)
        {
            if(personas[j].documento>personas[j+1].documento)
            {
                aux = personas[j];
                personas[j] = personas[j+1];
                personas[j+1] = aux;
            }
        }
    }

    return *personas;
}

void mostrarPersonas(persona personas[], int contPersonas)
{
    cout <<"\n\tPersonas en el sistema [" << contPersonas <<"]. " << endl;
    for(int i=0; i<contPersonas; i++)
    {
        if(personas[i].documento!=0)
        {
            cout <<"\nNombre: " << personas[i].nombre;
            cout <<"\nDNI: " << personas[i].documento;
            cout <<"\n";
        }
    }

    cout <<"\nVolviendo al menu.. [ENTER]" << endl;
    system("PAUSE");
}