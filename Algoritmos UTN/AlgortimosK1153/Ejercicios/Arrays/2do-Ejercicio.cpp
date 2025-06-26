
/* Ejercicio N°2: Se requiere un programa que permita al usuario ingresar las notas de 5 estudiantes en 3 asignaturas
diferentes. Luego, muestra por pantalla la nota promedio de cada estudiante en las 3 asignaturas.

1. Identifique las estructuras necesarias
2. Implemente el programa

*/

struct alumno
{
    char nombre[30];
    int legajo;
    float notaPromedio;
}al[100];

struct asignaturas
{
    float notaTotal;
    float matematicas;
    float literatura;
    float ingles;
}materias[100];

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaracion de las funciones:
alumno crearAlumno(alumno [], int);
asignaturas cargarNotas(alumno [], asignaturas [], int);
void mostrarPromedio(alumno [], asignaturas [], int);


int main()
{
    int cantAlumnos;
    cout <<"\nIngrese la cantidad de alumnos: "; cin >> cantAlumnos;
    crearAlumno(al, cantAlumnos);
    system("cls");
    cargarNotas(al, materias, cantAlumnos);
    system("cls");
    mostrarPromedio(al, materias, cantAlumnos);


    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
alumno crearAlumno(alumno al[], int cantAlumnos)
{
    cout <<"Ingrese sus datos: " << endl;
    for(int i=0; i<cantAlumnos; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(al[i].nombre, 30, '\n');
        cout <<"Legajo: "; cin >> al[i].legajo;
    }

    return *al;
}

asignaturas cargarNotas(alumno al[], asignaturas materias[], int cantAlumnos)
{
    cout <<"\nIngrese sus notas." << endl;
    for(int i=0; i<cantAlumnos; i++)
    {
        cin.ignore();
        cout <<"\n" << al[i].nombre <<" | Legajo: " << al[i].legajo << endl;
        cout <<"Matematicas: "; cin >> materias[i].matematicas;
        cout <<"Literatura: "; cin >> materias[i].literatura;
        cout <<"Ingles: "; cin >> materias[i].ingles;

        materias[i].notaTotal += materias[i].matematicas+materias[i].literatura+materias[i].ingles;
    }

    return *materias;
}

void mostrarPromedio(alumno al[], asignaturas materias[], int cantAlumnos)
{
    cout <<"\nLista de notas promedio por alumno. " << endl;

    for(int i=0; i<cantAlumnos; i++)
    {
        cout <<"\n" << al[i].nombre <<" | Legajo: " << al[i].legajo << endl;
        al[i].notaPromedio = materias[i].notaTotal/3;
        cout <<"Nota promedio: " << al[i].notaPromedio << endl;
    }
}