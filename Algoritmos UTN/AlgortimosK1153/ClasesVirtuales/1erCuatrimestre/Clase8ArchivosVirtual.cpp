
// Clase N°7: 18/06/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

/* Ejercicio en clase N°1:  Participación en concursos de ciencia

Dos escuelas, la Escuela 1 y la Escuela 2, participaron en distintos **concursos de ciencia** durante el año.
Cada participación se registra con:

- `codigo_concurso` (entero entre 1 y 100)
- `cantidad_participantes` (entero positivo)
- `escuela` (entero positivo) (1 o 2)

Los datos se ingresan por teclado para cada escuela, en **orden creciente por `codigo_concurso`**.
Se ingresa `codigo_concurso = 0` para finalizar la carga.
Se pide:

1. Permitar ingresar concursos a los arrays de cada escuela. Puede ingresar hasta 10 concursos por escuela.
2. Realizar el **apareo** de los datos de ambas escuelas para generar un array que indique, para cada concurso, el **total de participantes sumando ambas escuelas**.
3. Mostrar el listado combinado, ordenado por `codigo_concurso.`
4. Mostrar la cantidad de participantes por cada codigo de concurso.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct concurso
{
    int codigoConcurso;
    int cantParticipantes;
    int escuela;
}concursos[20], concursoOrdenado[20];

// Declaracion de la funcion.
void insertar(concurso [], int &, int, int);
void insertarOrdenado(concurso [], int &, int);
concurso cargarConcurso(concurso[], concurso []);
void apareo(concurso [], int, concurso [], int, concurso [], int &);

int main()
{

    int opcion, len1=0, len2=0, len3=0;
    
    do{
        cout <<"\n\tConcurso de ciencias. " << endl << endl;
        cout <<"Opcion 1: Cargar concurso a la base de datos. " << endl;
        cout <<"Opcion 2: Mostrar total de participantes. " << endl;
        cout <<"Opcion 3: Buscar historia academica de un alumno. " << endl;
        cout <<"Opcion 4: Salir. " << endl;
        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls");  system("cls"); break;
            case 2: system("cls");  system("cls"); break;
            case 3: system("cls");  system("cls"); break;
            case 4: cout <<"\nHasta Luego. " << endl; break;
        }

    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void insertar(concurso vec[], int &len, int valor, int pos)
{
    for (int i = len; i > pos; i--) 
    {
        vec[i].cantParticipantes = vec[i - 1].cantParticipantes;
    }

    vec[pos].cantParticipantes = valor;
    len++;
}

void insertarOrdenado(concurso vec[], int &len, int valor)
{
    int i = 0;
    while (i < len && vec[i].cantParticipantes <= valor) 
    {
        i++;
    }

    if (i == len) 
    {
        vec[len].cantParticipantes = valor;
        len++;
    }else{
        insertar(vec, len, valor, i);
    }
}

concurso cargarConcurso(concurso escuela1[], concurso escuela2[])
{
    int opEscuela;
    cout <<"Ingrese a que escuela pertenece el concurso [1/2]: "; cin >> opEscuela;
    if(opEscuela==1)
    {
        for(int i=0; i<10; i++)
        {
            cout <<"Codigo de concurso: "; cin >> escuela1[i].codigoConcurso;
            cout <<"Cantidad de participantes: "; cin >> escuela1[i].cantParticipantes;
            escuela1[i].escuela++;
        }
    }else if(opEscuela==2)
    {
        for(int i=0; i<10; i++)
        {
            cout <<"Codigo de concurso: "; cin >> escuela2[i].codigoConcurso;
            cout <<"Cantidad de participantes: "; cin >> escuela2[i].cantParticipantes;
            escuela2[i].escuela++;
        }
    }

}

void apareo(concurso A[], int lenA, concurso B[], int lenB, concurso C[], int &lenC)
{
    int i = 0, j = 0;
    lenC = 0;

    while (i < lenA && j < lenB)
    {
        if (A[i].codigoConcurso <= B[j].codigoConcurso)
        {
		        C[lenC] = A[i];
		        lenC++;
		        i++;
        }else{
            C[lenC] = B[j];
            lenC++;
            j++;
        }
    }

    while (i < lenA)
    {
        C[lenC] = A[i];
        lenC++;
        i++;
    }

    while (j < lenB) 
    {
        C[lenC] = B[j];
        lenC++;
        j++;
    }
}