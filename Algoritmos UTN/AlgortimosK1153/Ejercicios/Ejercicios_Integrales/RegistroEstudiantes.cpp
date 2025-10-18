
/* Ejercicio: Sistema de Registro de Estudiantes de la Facultad con Arrays

Se le pide que haga un sistema donde la universidad pueda registrar los estudiantes de la facultad.
Por cada estudiante se sabe su nombre, fecha_nacimiento, año ingreso, código de barrio (De 1 a 20).
Por cada barrio sabemos el nombre y su distancia a la facultad y su código.

Sabemos que la facultad acepta máximo 200 estudiantes, y hay solo 20 barrios aceptados.

1. Defini las estructuras necesarias para resolver el problema
2. Insertar barrios: Agregar barrios con su nombre y distancia a la facultad.
3. Insertar estudiantes: Agregar estudiantes con su nombre, fecha de nacimiento, año de ingreso y código de barrio.
4. Mostrar todos los barrios ordenados por distancia a la facultad
5. Retornar el barrio más lejano a la facultad**: Identificar el barrio con la mayor distancia a la facultad.
6. Retornar el estudiante más joven**: Identificar al estudiante más joven registrado.
7. Retornar el año de ingreso que más estudiantes tuvo**: Determinar el año en que se inscribió el mayor número de estudiantes.
8. Retornar el barrio con más estudiantes**: Identificar el barrio con más estudiantes registrados.
9. Mostrar todos los barrios ordenados por distancia a la facultad y cantidad de estudiantes asignados.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Barrio
{
    char nombre[30];
    int Distancia;
    int codigo;
}barrio[];

struct Alumno
{
    char nombre[30];
    int fecha_Nacimiento;
    int año_Ingreso;
    Barrio barrio_Datos; // 1-20;
}alumno[];

// Declaracion de las funciones.
void insertarBarrio(Barrio barrio[], int &len, Barrio nuevoBarrio, int pos);
void insertarAlumno(Alumno alumno[], int &len, Alumno nuevoAlumno, int pos);
void insertarOrdenadoBarrio(Barrio barrio[], int &len, Barrio nuevoBarrio);
Barrio cargarBarrio(Barrio barrio[], int &len);
void ordenamientoBurbuja(Barrio barrio[], int len);
void mostrarBarriosPorDistancia(Barrio barrio[], int len);
int barrioMasLesjano(Barrio barrio[], int len);
int estudianteMasJoven(Alumno alumno[], int len);
int busquedaBinaria(Alumno alumno[], int len, int valor);
int mayorIngresoEstudiantes(Alumno alumno[], int len);

int main()
{
    int lenBarrio=3, lenAlumno=5;

    cout <<"\n- Nahuel Richeri \n";
};

// Definicion de las funciones.
void insertarBarrio(Barrio barrio[], int &len, Barrio nuevoBarrio, int pos)
{
    for(int i=len; i>pos; i--)
    {
        barrio[i] = barrio[i-1];
    }

    barrio[pos] = nuevoBarrio;
    len++;

}

void insertarAlumno(Alumno alumno[], int &len, Alumno nuevoAlumno, int pos)
{
    for(int i=len; i>pos; i--)
    {
        alumno[i] = alumno[i-1];
    }

    alumno[pos] = nuevoAlumno;
    len++;
}

void insertarOrdenadoBarrio(Barrio barrio[], int &len, Barrio nuevoBarrio)
{
    int i=0;
    while(i<len&&barrio[i].codigo<=nuevoBarrio.codigo)
    {
        i++;
    }

    if(i==len)
    {
        barrio[len] = nuevoBarrio;
        len++;
    }else{
        insertarBarrio(barrio, len, nuevoBarrio, i);
    }
}

Barrio cargarBarrio(Barrio barrio[], int &len)
{
    cout <<"\n\tIngrese los barrios. " << endl;
    Barrio nuevoBarrio;

    for(int i=0; i<len; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(nuevoBarrio.nombre, 30, '\n');
        cout <<"Codigo: "; cin >> nuevoBarrio.codigo;
        cout <<"Distancia hacia la facultad: "; cin >> nuevoBarrio.Distancia;

        insertarOrdenadoBarrio(barrio, len, nuevoBarrio);
    }
}

void ordenamientoBurbuja(Barrio barrio[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(barrio[j].Distancia>barrio[j+1].Distancia)
            {
                Barrio aux = barrio[j];
                barrio[j] = barrio[j+1];
                barrio[j+1] = aux;
            }
        }
    }
}

void mostrarBarriosPorDistancia(Barrio barrio[], int len)
{
    ordenamientoBurbuja(barrio, len);
    cout <<"\n\tBarrios ordenados por distancia a la facultad. " << endl;
    for(int i=0; i<len; i++)
    {
        cout <<"\nNombre: " << barrio[i].nombre;
        cout <<"Distancia: " << barrio[i].Distancia;
        cout <<"Codigo: " << barrio[i].codigo;
    }
    
    cout <<"\nVolviendo al menu..." << endl;
    system("PAUSE");
}

int barrioMasLejano(Barrio barrio[], int len)
{
    int distanciaMayor=barrio[0].Distancia;
    for(int i=1; i<len; i++)
    {
        if(distanciaMayor<barrio[i].Distancia)
        {
            distanciaMayor=barrio[i].Distancia;
        }
    }

    return distanciaMayor;
}

int estudianteMasJoven(Alumno alumno[], int len)
{
    int estudianteJoven = alumno[0].fecha_Nacimiento;
    for(int i=1; i<len; i++)
    {
        if(estudianteJoven<alumno[i].fecha_Nacimiento)
        {
            estudianteJoven=alumno[i].fecha_Nacimiento;
        }
    }

    return estudianteJoven;
}

int busquedaBinaria(Alumno alumno[], int len, int valor)
{
    int inicio=0;
    int fin = len-1;

    while(inicio<=fin)
    {
        int medio=(inicio+fin)/2;

        if(alumno[medio].año_Ingreso==valor)
        {
            return medio;
        }else if(alumno[medio].año_Ingreso<valor){
            inicio = medio+1;
        }else{
            fin = medio-1;
        }
    }

    return -1;
}

int mayorIngresoEstudiantes(Alumno alumno[], int len)
{
    int ingresantes[200]={0};
    int contador=0;

    for(int i=0; i<len; i++)
    {
        int ingresante = alumno[0].año_Ingreso;
        bool encontrado = false;

        for(int j=0; j<contador; j++)
        {
            if(ingresantes[j]==ingresante)
            {
                ingresantes[j+100]++;
                encontrado = true;
                break;
            }
        }

        if(!encontrado)
        {
            ingresantes[contador] = ingresante;
            ingresantes[contador+100]=1;
            contador++;
        }
    }

    int max = ingresantes[100];
    int maxIngresantes = ingresantes[0];

    for(int i=0; i<contador; i++)
    {
        if(ingresantes[i+100]>max)
        {
            max = ingresantes[i+100];
            maxIngresantes = ingresantes[i];
        }
    }


    cout << "\nEl año con más estudiantes ingresantes es: " << maxIngresantes << " (" << max << " estudiantes)" << endl;

    return maxIngresantes;

}