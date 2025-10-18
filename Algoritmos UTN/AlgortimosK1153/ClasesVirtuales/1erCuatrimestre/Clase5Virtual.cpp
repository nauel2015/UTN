
// Clase N°5: 14/05/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

/* Ejercicio N°1: Carnet de vacunacion.

Una salita de atención primaria lleva un registro de vacunación de 10 personas. De cada
persona se guarda:

nombre (string)
edad (int)
cantidad de dosis recibidas (int)

Tareas:
1. Crear la estructura PersonaVacunada .
2. Crear un array de 10 personas.
3. Cargar los datos por teclado.
4. Escribir una función que reciba el array y muestre por pantalla:
Cuántas personas tienen menos de 2 dosis.
El porcentaje de personas mayores de 60 con esquema completo (3 dosis).

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct personaVacunada
{
    char nombre[30];
    int edad;
    int cantDosis;
}vacunados[100];

void cargarDatos(int);
void personasVacunadas(personaVacunada [], int);

int main()
{  
    int listaPersonas;
    cout <<"Ingrese la cantidad de personas en la lista: "; cin >> listaPersonas;

    cargarDatos(listaPersonas);
    system("cls");
    personasVacunadas(vacunados, listaPersonas);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

void cargarDatos(int listaPersonas)
{
    cout <<"\nIngrese los datos de las personas. " << endl;
    for(int i=0; i<listaPersonas; i++)
    {
        cout <<"\nPersona N°" << i+1 << ": ";
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(vacunados[i].nombre, 30, '\n');
        cout <<"Edad: "; cin >> vacunados[i].edad;
        cout <<"Dosis aplicadas hasta el momento: "; cin >> vacunados[i].cantDosis;
    }
}

void personasVacunadas(personaVacunada vacunados[100], int listaPersonas)
{
    int dosDosis=0, mayoresTresDosis=0, mayores60=0;
    float porcentajeMayores=0, porcentajeDosDosis=0;

    cout <<"\nPersonas con menos de 2 dosis aplicadas: ";

    for(int i=0; i<listaPersonas; i++)
    {
        if(vacunados[i].cantDosis<=2)
        {
            dosDosis++;
        }
    }

    cout << dosDosis << endl;
    porcentajeDosDosis = (dosDosis*100)/listaPersonas;
    cout <<"porcentaje en base al total de personas de la lista: " << porcentajeDosDosis <<"% " << endl;

    for(int i=0; i<listaPersonas; i++)
    {
        if(vacunados[i].cantDosis<=2)
        {
            cout <<"\nNombre: " << vacunados[i].nombre << endl;
            cout <<"Edad: " << vacunados[i].edad << endl;
            cout <<"Dosis aplicadas: " << vacunados[i].cantDosis << endl;
        }
    }

    cout <<"\nPersonas mayores de 60 años con todas las dosis aplicadas: ";

    for(int i=0; i<listaPersonas; i++)
    {
        if(vacunados[i].edad>=60)
        {
            mayores60++;
        }

        if((vacunados[i].cantDosis==3)&&(vacunados[i].edad>=60))
        {
            mayoresTresDosis++;
        }
    }

    cout << mayoresTresDosis << endl;
    porcentajeMayores = (mayoresTresDosis*100)/listaPersonas;
    porcentajeMayores = (mayoresTresDosis*100)/mayores60;
    
    cout <<"porcentaje en base al total de personas mayores de 60: " << mayores60 <<"% " << endl;
    cout <<"porcentaje en base al total de personas de la lista: " << porcentajeMayores <<"% " << endl;

    for(int i=0; i<listaPersonas; i++)
    {
        if((vacunados[i].cantDosis==3)&&(vacunados[i].edad>=60))
        {
            cout <<"\nNombre: " << vacunados[i].nombre << endl;
            cout <<"Edad: " << vacunados[i].edad << endl;
            cout <<"Dosis aplicadas: " << vacunados[i].cantDosis << endl;
        }
    }
}
