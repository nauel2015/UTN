
/* Ejercicio N°4: Gestor de Notas.

En una cursada, cada estudiante tiene:
nombre (string)
legajo (int)
notas de 3 parciales (array de 3 float )

Tareas:
1. Crear la estructura Estudiante .
2. Cargar 5 estudiantes y sus 3 notas.
3. Crear una función que calcule y retorne el promedio de un estudiante.
4. Mostrar cuál es el estudiante con mejor promedio.
5. Mostrar los estudiantes que aprobaron todos los parciales (nota ≥ 6).

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct estudiante
{
    char nombre[30];
    int edad;
    int legajo;
    float notas[3];
    float promedio;
}alumnos[5];

// Declaracion de las funciones.
estudiante cargarAlumno(estudiante [], int &);
void promedioAlumno(estudiante [], int);
void mejorPromedioAlumno(estudiante [], int);
void alumnosAprobados(estudiante [], int);

int main()
{
    int opcion, contAlumnos=0;
    do{
        cout <<"\n\tGestor de Notas. " << endl << endl;
        cout <<"Opcion 1: Cargar Estudiantes. " << endl;
        cout <<"Opcion 2: Buscar el promedio de un estudiante. " << endl;
        cout <<"Opcion 3: Estudiante con mejor promedio. " << endl;
        cout <<"Opcion 4: Estudiantes que aprobaron todos los parciales. " << endl;
        cout <<"Opcion 5: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("cls"); cargarAlumno(alumnos, contAlumnos); system("cls"); break;
            case 2: system("cls"); promedioAlumno(alumnos, contAlumnos); system("cls"); break;
            case 3: system("cls"); mejorPromedioAlumno(alumnos, contAlumnos); system("cls"); break;
            case 4: system("cls"); alumnosAprobados(alumnos, contAlumnos); system("cls"); break;
            case 5: cout <<"\nHasta luego. " << endl; break;
        }

    }while(opcion!=5);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
estudiante cargarAlumno(estudiante alumnos[], int &contAlumnos)
{
    int cantAlumno;
    cout <<"\n\tCantidad de alumnos en el gestor de notas -> [" << contAlumnos <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de estudiantes que quiere cargar a la base de datos: "; cin >> cantAlumno;
    if(cantAlumno+contAlumnos > 5)
    {
        cout <<"ERROR. No hay suficiente espacio, solo se pueden cargar " << (5 - contAlumnos) <<" alumnos mas. " << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *alumnos;
    }

    if(contAlumnos>5)
    {
        cout <<"ERROR. El gestor de Notas se encuentra completo. Ya no se pueden cargar mas alumnos. " << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *alumnos;
    }

    cout <<"Proceda con la carga de datos. " << endl;

    for(int i=0; i<cantAlumno; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(alumnos[contAlumnos].nombre, 30, '\n');
        cout <<"Edad: "; cin >> alumnos[contAlumnos].edad;
        cout <<"Legajo: "; cin >> alumnos[contAlumnos].legajo;
        cout <<"Nota 1er Parcial: "; cin >> alumnos[contAlumnos].notas[0];
        cout <<"Nota 2do Parcial: "; cin >> alumnos[contAlumnos].notas[1];
        cout <<"Nota T.P Final: "; cin >> alumnos[contAlumnos].notas[2];

        alumnos[contAlumnos].promedio = (alumnos[contAlumnos].notas[0]+alumnos[contAlumnos].notas[1]+alumnos[contAlumnos].notas[2])/3;

        contAlumnos++;
    }

    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
    return *alumnos;
}

void promedioAlumno(estudiante alumnos[], int contAlumnos)
{
    int legajo;
    bool encontrado = false;
    cout <<"\n\tCantidad de alumnos en el gestor de notas -> [" << contAlumnos <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese el legajo del alumno para ver su promedio: "; cin >> legajo;

    for(int i=0; i<contAlumnos; i++)
    {
        if(legajo == alumnos[i].legajo)
        {
            cout <<"\nAlumno Encontrado. " << endl;
            cout <<"Nombre: " << alumnos[i].nombre << endl;
            cout <<"Edad: " << alumnos[i].edad << endl;
            cout <<"Legajo: " << alumnos[i].legajo << endl;
            cout <<"promedio: " << alumnos[i].promedio << endl;

            encontrado = true;
        }
    }

    if(encontrado==false)
    {
        cout <<"\nERROR. No existe un alumno con ese legajo en el gestor de notas. " << endl;
    }

    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
}

void mejorPromedioAlumno(estudiante alumnos[], int contAlumnos)
{
    float mejorPromedio=0;
    int edad, legajo;
    char nombre[30];
    cout <<"\n\tCantidad de alumnos en el gestor de notas -> [" << contAlumnos <<"]. " << endl;

    for(int i=0; i<contAlumnos; i++)
    {
        if(alumnos[i].promedio>mejorPromedio)
        {
            mejorPromedio = alumnos[i].promedio;
            edad = alumnos[i].edad;
            legajo = alumnos[i].legajo;
            strcpy(nombre, alumnos[i].nombre);
        }
    }

    cout <<"\nAlumno con mejor Promedio. " << endl;
    cout <<"Nombre: " << nombre << endl;
    cout <<"Edad: " << edad << endl;
    cout <<"Legajo: " << legajo << endl;
    cout <<"Promedio: " << mejorPromedio <<" de nota. " << endl;

    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
}

void alumnosAprobados(estudiante alumnos[], int contAlumnos)
{
    bool aprobado = false;
    cout <<"\n\tCantidad de alumnos en el gestor de notas -> [" << contAlumnos <<"]. " << endl;
    for(int i=0; i<contAlumnos; i++)
    {
        if((alumnos[i].notas[0]&&alumnos[i].notas[1]&&alumnos[i].notas[2])>=6)
        {
            cout <<"\nAlumno Aprobado. " << endl;
            cout <<"Nombre: " << alumnos[i].nombre << endl;
            cout <<"1er Parcial: " << alumnos[i].notas[0] << endl;
            cout <<"2do Parcial: " << alumnos[i].notas[1] << endl;
            cout <<"T.P Final: " << alumnos[i].notas[2] << endl;
            cout <<"Promedio: " << alumnos[i].promedio << endl;
            if((alumnos[i].notas[0]&&alumnos[i].notas[1]&&alumnos[i].notas[2])>=8)
            {
                cout <<"\nEl alumno promociono la materia. " << endl;
            }
            aprobado = true;
        }
    }

    if(aprobado==false)
    {
        cout <<"\nNingun alumno aprobo la cursada. " << endl;
    }


    cout <<"\nVolviendo al menu [ENTER PARA CONTINUAR]. " << endl;
    system("pause");
}