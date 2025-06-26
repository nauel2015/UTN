
/* Ejercicio N°8: Dada una estructura llamada Alumno con los atributos de 'nombre', 'edad' y 'promedio', implementa un
sistema donde el usuario pueda ingresar los datos de 10 alumnos de una clase. Luego, el sistema solicitará al
usuario que ingrese el nombre de un alumno a buscar. Utilizando la búsqueda que considere correspondiente,
se determinará si el alumno está presente en el conjunto de alumnos cargados. Si se encuentra, se mostrará
su nombre, edad y promedio. Además, se informará la cantidad de alumnos que tienen un promedio mayor
que el del alumno buscado y la cantidad de alumnos que tienen un promedio menor que el del alumno
buscado.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct alumno
{
    char nombre [30];
    int edad;
    int promedio;
}alumnos[10];

// Declaracion de las funciones.
alumno cargarAlumnos(alumno [], int &);
int busquedaSecuencial(alumno [], int, char []);
void alumnoEncontrado(alumno [], int);

int main()
{
    int contAlumnos=0, opcion;
    do{
        cout <<"\n\tSiu guaranie \n" << endl;
        cout <<"Opcion 1: Cargar Alumnos. " << endl;
        cout <<"Opcion 2: Buscar Alumno. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarAlumnos(alumnos, contAlumnos); system("cls"); break;
            case 2: system("cls"); alumnoEncontrado(alumnos, contAlumnos); system("cls"); break;
            case 3: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
alumno cargarAlumnos(alumno alumnos[], int &contAlumnos)
{
    int cantAlumnos;
    cout <<"\n\tCantidad de alumnos [" << contAlumnos <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de alumnos a cargar: "; cin >> cantAlumnos;

    if(cantAlumnos+contAlumnos>=10)
    {
        cout <<"\nError. Solo se puede cargar hasta " << (10-contAlumnos) <<" alumnos mas. " << endl;

        return *alumnos;
        cout <<"\nVolviendo al menu..." << endl;
        system("PAUSE");
    }

    if(contAlumnos>10)
    {
        cout <<"\nEl almacenamiento esta lleno. Ya no se puede cargar mas alumnos. " << endl;

        return *alumnos;
        cout <<"\nVolviendo al menu..." << endl;
        system("PAUSE");
    }

    for(int i=0; i<cantAlumnos; i++)
    {
        cin.ignore();
        cout <<"\nAlumnos Nro" << contAlumnos+1 <<". " << endl;
        cout <<"Nombre: "; cin.getline(alumnos[contAlumnos].nombre, 30, '\n');
        cout <<"Edad: "; cin >> alumnos[contAlumnos].edad;
        cout <<"Promedio: "; cin >> alumnos[contAlumnos].promedio;

        contAlumnos++;
    }

    return *alumnos;
}

int busquedaSecuencial(alumno alumnos[], int len, char buscado[30])
{
    int i=0;
    while(i<len&&strcmp(alumnos[i].nombre, buscado)!=0)
    {
        i++;
    }

    if(i==len)
    {
        return -1;
    }else{
        return i;
    }
}

void alumnoEncontrado(alumno alumnos[], int contAlumnos)
{
    char buscado[30];
    int contPromedioMayor=0, contPromedioMenor=0;
    cout <<"\n\tCantidad de alumnos [" << contAlumnos <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese el nombre del alumno a buscar: "; cin.getline(buscado, 30, '\n');
    int pos = busquedaSecuencial(alumnos, contAlumnos, buscado);

    for(int i=0; i<contAlumnos; i++)
    {
        if(alumnos[i].promedio > alumnos[pos].promedio)
        {
            contPromedioMayor++;
        }

        if(alumnos[i].promedio < alumnos[pos].promedio)
        {
            contPromedioMenor++;
        }
    }

    if(pos!=-1)
    {
        if(contPromedioMayor==0&&contPromedioMenor>=0)
        {
            cout <<"\nAlumno encontrado (Tiene el Mejor promedio de la comision). " << endl;
            cout <<"Nombre: " << alumnos[pos].nombre << endl;
            cout <<"Edad: " << alumnos[pos].edad << endl;
            cout <<"Promedio: " << alumnos[pos].promedio << endl;
            cout <<"\nCantidad de alumnos con menor promedio que " << alumnos[pos].nombre <<": [" << contPromedioMenor <<"]. " << endl;
        }else if(contPromedioMayor>0&&contPromedioMenor==0){
            cout <<"\nAlumno encontrado (Tiene el peor promedio de la comision). " << endl;
            cout <<"Nombre: " << alumnos[pos].nombre << endl;
            cout <<"Edad: " << alumnos[pos].edad << endl;
            cout <<"Promedio: " << alumnos[pos].promedio << endl;
            cout <<"\nCantidad de alumnos con mayor promedio que " << alumnos[pos].nombre <<": [" << contPromedioMayor <<"]. " << endl;
            cout <<"\nCantidad de alumnos con menor promedio: " << contPromedioMenor <<"]. " << endl;   
        }else{
            cout <<"\nAlumno encontrado. " << endl;
            cout <<"Nombre: " << alumnos[pos].nombre << endl;
            cout <<"Edad: " << alumnos[pos].edad << endl;
            cout <<"Promedio: " << alumnos[pos].promedio << endl;
            cout <<"\nCantidad de alumnos con mayor promedio que " << alumnos[pos].nombre <<": [" << contPromedioMayor <<"]. " << endl;
            cout <<"\nCantidad de alumnos con menor promedio: " << contPromedioMenor <<"]. " << endl;
        }

        cout <<"\nVolviendo al menu..." << endl;
        system("PAUSE");
    }else{
        cout <<"\nNo se encontro al alumno. " << endl;

        cout <<"\nVolviendo al menu..." << endl;
        system("PAUSE");
    }
}