
/* Ejercicio N°5: Se requiere un programa que permita al usuario ingresar los datos de una serie de estudiantes, incluyendo su
nombre, edad y calificaciones en 3 asignaturas diferentes. Luego, permite al usuario buscar un estudiante por
su nombre y mostrar su información completa.

1. Identifique las estructuras necesarias
2. Implemente el programa

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct asignaturas
{
    float matematicas;
    float literatura;
    float ingles;
};

struct alumno
{
    char nombre[30];
    int edad;
    int legajo=0;
    asignaturas calificaciones;
}al[100];

// Declaracion de las funciones:
alumno cargarAlumno(alumno [], int &);
alumno cargarNotas(alumno []);
void BuscarHistoriaAcademica(alumno []);

int main()
{
    int contAlumno=0, opcion;
    do{
        cout <<"\n\tHistoria Academica. " << endl << endl;
        cout <<"Opcion 1: Cargar alumnos a la base de datos. " << endl;
        cout <<"Opcion 2: Cargar notas de un alumno a su historia academica. " << endl;
        cout <<"Opcion 3: Buscar historia academica de un alumno. " << endl;
        cout <<"Opcion 4: Salir. " << endl;
        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarAlumno(al, contAlumno); system("cls"); break;
            case 2: system("cls"); cargarNotas(al); system("cls"); break;
            case 3: system("cls"); BuscarHistoriaAcademica(al); system("cls"); break;
            case 4: cout <<"\nHasta Luego. " << endl; break;
        }

    }while(opcion!=3);


    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
alumno cargarAlumno(alumno al[], int &contAlumno)
{
    int cantAlumno;
    cout <<"\n\tCantidad de alumnos en la base de datos -> [" << contAlumno <<"]. " << endl;
    cout <<"\nIngrese la cantidad de estudiantes que quiere cargar a la base de datos: "; cin >> cantAlumno;
    cout <<"Proceda con la carga de datos. " << endl;

    for(int i=0; i<cantAlumno; i++)
    {
        if(al[i].legajo == 0 && contAlumno < 100)
        {
            cin.ignore();
            cout <<"\nNombre: "; cin.getline(al[i].nombre, 30, '\n');
            cout <<"Edad: "; cin >> al[i].edad;
            cout <<"Legajo: "; cin >> al[i].legajo;

            contAlumno++;
        }else if(al[i].legajo!=0){
            cantAlumno++;
        }else if(contAlumno > 100){
            cout <<"\nLa base de datos se encuentra llena. " << endl;
        }
    }

    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
    return *al;
}

alumno cargarNotas(alumno al[])
{
    int buscarLegajo;
    cout <<"\nIngrese el legajo del estudiante para cargar sus notas: "; cin >> buscarLegajo;
    system("cls");
    for(int i=0; i<100; i++)
    {
        if(buscarLegajo == al[i].legajo)
        {
            cout <<"\n\tLegajo encontrado. \n\nCargue las notas del alumno." << endl;
            cin.ignore();
            cout <<"Matematicas: "; cin >> al[i].calificaciones.matematicas;
            cout <<"Literatura: "; cin >> al[i].calificaciones.literatura;
            cout <<"Ingles: "; cin >> al[i].calificaciones.ingles;
        }
    }
    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
    return *al;
}

void BuscarHistoriaAcademica(alumno al[])
{
    int buscarLegajo;
    cout <<"\nIngrese el legajo del estudiante para ver su historia academica: "; cin >> buscarLegajo;
    system("cls");
    for(int i=0; i<100; i++)
    {
        if(buscarLegajo == al[i].legajo)
        {
            cout <<"\n\tLegajo encontrado. " << endl;
            cout <<"\nNombre: " << al[i].nombre <<" | ";
            cout <<"Edad: " << al[i].edad <<" | ";
            cout <<"Legajo: " << al[i].legajo << " | " << endl;

            cout <<"Matematicas: " << al[i].calificaciones.matematicas << endl;
            cout <<"Literatura: " << al[i].calificaciones.literatura << endl;
            cout <<"Ingles: " << al[i].calificaciones.ingles << endl;

        }
    }

    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
}