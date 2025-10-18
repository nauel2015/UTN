
/* Ejercicio: Participacion en concursos de ciencias.

Dos escuelas, la Escuela 1 y la Escuela 2, participaron en distintos **concursos de ciencia** durante el año. 
Cada participación se registra con:

- `codigo_concurso` (entero entre 1 y 100)
- `cantidad_participantes` (entero positivo)
- `escuela` (entero positivo) (1 o 2)

Los datos se ingresan por teclado para cada escuela, en **orden creciente por `codigo_concurso`**.
Se ingresa `codigo_concurso = 0` para finalizar la carga.

1. Permitir ingresar concursos a los arrays de cada escuela (Puede ingresar hasta 10 concursos por escuela).
2. Realizar el **apareo** de los datos de ambas escuelas para generar un array que indique, para cada concurso, el **total de participantes sumando ambas escuelas**.
3. Mostrar el listado combinado, ordenado por `codigo_concurso.`
4. Mostrar la cantidad de participantes por cada codigo de concurso.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Concurso
{
    int codigo_concurso;
    int cantidad_participantes;
    int escuela;
}concurso1[10], concurso2[10], concurso3[20];

// Declaracion de las funciones.
Concurso cargarConsurso(Concurso [], Concurso [], int &, int &);
void apareo(Concurso [], int, Concurso [], int, Concurso [], int &);
void totalParticipantes(Concurso [], int);
void listadoCompleto(Concurso [], int);
void mostrarParticipantesPorConcurso(Concurso [], int);

int main()
{
    int opcion, len1=0, len2=0, len3=0;
    do{
        cout <<"\n\tConsurso de ciencias. " << endl;
        cout <<"\nOpcion 1: Ingresar concurso. ";
        cout <<"\nOpcion 2: Total de participantes por concurso. ";
        cout <<"\nOpcion 3: Listado completo de participantes por concurso. ";
        cout <<"\nOpcion 4: Listado de participante por concurso. ";

        cout <<"\n\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("CLS"); cargarConsurso(concurso1, concurso2, len1, len2); system("CLS"); break;
            case 2: system("CLS"); apareo(concurso1, len1, concurso2, len2, concurso3, len3); totalParticipantes(concurso3, len3); system("CLS"); break;
            case 3: system("CLS"); listadoCompleto(concurso3, len3); system("CLS"); break;
            case 4: system("CLS"); mostrarParticipantesPorConcurso(concurso3, len3); system("CLS"); break;
            case 5: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=5);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
Concurso cargarConsurso(Concurso concurso[], Concurso concurso2[], int &len1, int &len2)
{
    cout <<"\n\tCantidad de concursos cargados [" << len1+len2 <<"]. " << endl;
    int i=0, cont1=0,cont2=0, codigoConcurso;

    while(cont1<=10||cont2<=10)
    {
        cout <<"\nIngrese el id de su escuela [1/2]: "; cin >> codigoConcurso;

        if(codigoConcurso==1&&cont1<=10)
        {
            cout <<"Codigo del concurso: "; cin >> concurso[len1].codigo_concurso;
            cout <<"Cantidad de participantes: "; cin >> concurso[len1].cantidad_participantes;
            i++;
            cont1++;
        }else if(codigoConcurso==1&&cont1>10){
            cout <<"\n\tCupos llenos para la escuela 1. " << endl;
        }

        if(codigoConcurso==2&&cont2<=10)
        {
            cout <<"Codigo del concurso: "; cin >> concurso2[len2].codigo_concurso;
            cout <<"Cantidad de participantes: "; cin >> concurso2[len2].cantidad_participantes;
            i++;
            cont2++;
        }else if(codigoConcurso==2&&cont2>10){
            cout <<"\n\tCupos llenos para la escuela 2. " << endl;
        }
    }

    if(cont1==10&&cont2==10)
    {
        cout <<"\nCupos completos. Ya no se puede cargar concursos. " << endl;

        cout <<"\nVolviendo al menu... " << endl;
        system("PAUSE");
    }
    
    return *concurso;
}



void apareo(Concurso concurso1[], int len1, Concurso concurso2[], int len2, Concurso concurso3[], int &len3)
{
    int i=0, j=0;

    while(i<len1&&j<len2)
    {
        if(concurso1[i].codigo_concurso<=concurso2[j].codigo_concurso)
        {
            concurso3[len3] = concurso1[i];
            len3++;
            i++;
        }else{
            concurso3[len3] = concurso2[j];
            len3++;
            j++;
        }
    }

    while(i<len1)
    {
        concurso3[len3] = concurso1[i];
        len3++;
        i++;
    }

    while(j<len2)
    {
        concurso3[len3] = concurso1[i];
        len3++;
        i++;
    }
}

void totalParticipantes(Concurso concurso3[], int len3)
{
    int totalParticipantes=0, i=0;
    cout <<"\n\tCantidad total de concursos [" << len3 <<"] " << endl;

    while(i<20)
    {
        int concursoActual = concurso3[i].codigo_concurso;

        while(i<20&&concurso3[i].codigo_concurso==concursoActual)
        {
            totalParticipantes += concurso3[i].cantidad_participantes;
            i++;
        }

        i++;
        cout <<"\nEl concurso nro " << concurso3[i].codigo_concurso <<"Tiene en total " << totalParticipantes <<" participantes juntando ambas escuelas. ";
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}

void listadoCompleto(Concurso concurso3[], int len3)
{
    int i=0;
    cout <<"\n\tLista de concursos. " << endl;

    while(i<len3)
    {
        int concurso = concurso3[i].codigo_concurso;
        cout <<"\nConcurso: " << concurso3[i].codigo_concurso;

        while(i<len3&&concurso==concurso3[i].codigo_concurso)
        {
            cout <<"Escuela: " << concurso3[i].escuela;
            cout <<"Participantes: " << concurso3[i].cantidad_participantes << endl;

            i++;
        }

        i++;
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}

void mostrarParticipantesPorConcurso(Concurso concurso3[], int len3)
{
    int i=0;
    cout <<"\n\tListado de participantes por concurso. " << endl;
    while(i<len3)
    {
        cout <<"\nConcurso Nro [" << concurso3[i].codigo_concurso <<"]. " << endl;
        cout <<"Participantes: " << concurso3[i].cantidad_participantes << endl;

        i++;
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}