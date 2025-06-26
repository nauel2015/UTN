
/* Ejercicio N°3: Biblioteca de guardia.

Se registran hasta 15 libros en una biblioteca nocturna. 
De cada libro se guarda:

título (string)
autor (string)
año de publicación (int)
cantidad de ejemplares (int)

Tareas:
1. Cargar los datos de libros.
2. Hacer una función que muestre todos los libros con más de 3 ejemplares.
3. Hacer una función que devuelva cuántos libros son anteriores al año 2000
4. Permitir al usuario buscar libros de un autor y mostrar todos sus títulos

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct estanteria
{
    char titulo[50];
    char autor[30];
    int anioPublicacion;
    int cantidadEjemplares;
}libros[15];

// Declaracion de las funciones:
estanteria insertarLibro(estanteria [], int &);
void mostrarLibros(estanteria [], int);
void librosAnterioresAlAnio2000(estanteria [], int);
void librosAutor(estanteria [], int);

int main()
{
    int opcion, contLibros=0;
    do{
        cout <<"\n\tBiblioteca de guardia. " << endl << endl;
        cout <<"Opcion 1: Insertar libros a la estanteria. " << endl;
        cout <<"Opcion 2: Ver todos los libros con mas de 3 ejemplares. " << endl;
        cout <<"Opcion 3: Ver todos los ibros anteriores al año 2000. " << endl;
        cout <<"Opcion 4: Buscar libros por autor. " << endl;
        cout <<"Opcion 5: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;
        switch(opcion)
        {
            case 1: system("cls"); insertarLibro(libros, contLibros); system("cls"); break;
            case 2: system("cls"); mostrarLibros(libros, contLibros); system("cls"); break;
            case 3: system("cls"); librosAnterioresAlAnio2000(libros, contLibros); system("cls"); break;
            case 4: system("cls"); librosAutor(libros, contLibros); system("cls"); break;
            case 5: cout <<"\nHasta luego. " << endl; break;
        }

    }while(opcion!=5);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
estanteria insertarLibro(estanteria libros[], int &contLibros)
{
    int cantLibros;
    cout <<"\n\tHay [" << contLibros <<"] libros en la estanteria. " << endl;

    if (contLibros >= 15) 
    {
        cout <<"\n¡La estantería está llena! No se pueden cargar más libros." << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *libros;
    }

    cout <<"\nIngrese la cantidad de libros a cargar: "; cin >> cantLibros;

    if (contLibros + cantLibros > 15) 
    {
        cout <<"\nERROR: No hay suficiente espacio. Solo se pueden cargar " << (15 - contLibros) << " libros más." << endl;

        cout <<"\nVolviendo al menu [ENTER]..." << endl;
        system("PAUSE");
        return *libros;
    }

    for (int i = 0; i < cantLibros; i++) 
    {
        cin.ignore();
        cout <<"\nLibro Nro " << contLibros + 1 <<": " << endl;
        cout <<"Titulo: "; cin.getline(libros[contLibros].titulo, 50, '\n');
        cout <<"Autor: "; cin.getline(libros[contLibros].autor, 30, '\n');
        cout <<"Año de Publicacion: "; cin >> libros[contLibros].anioPublicacion;
        cout <<"Cantidad de Ejemplares: "; cin >> libros[contLibros].cantidadEjemplares;

        contLibros++; // pasar al siguiente espacio disponible
    }

    return *libros;
}

void mostrarLibros(estanteria libros[], int contLibros)
{
    cout <<"\n\tHay [" << contLibros <<"] libros en la estanteria. " << endl;
    for(int i=0; i<contLibros; i++)
    {
        if(libros[i].cantidadEjemplares>=3)
        {
            cout <<"\nTitulo: " << libros[i].titulo << endl;
            cout <<"Autor: " << libros[i].autor << endl;
            cout <<"Año de publicacion: " << libros[i].anioPublicacion << endl;
            cout <<"Cantidad de ejemplares: " << libros[i].cantidadEjemplares << endl;
        }
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}

void librosAnterioresAlAnio2000(estanteria libros[], int contLibros)
{
    bool encontrado = false;
    cout <<"\n\tHay [" << contLibros <<"] libros en la estanteria. " << endl;
    cout <<"\tLibros publicados antes del año 2000. " << endl;
    for(int i=0; i<contLibros; i++)
    {
        if(libros[i].anioPublicacion>0 && libros[i].anioPublicacion<2000)
        {
            cout <<"\nTitulo: " << libros[i].titulo << endl;
            cout <<"Autor: " << libros[i].autor << endl;
            cout <<"Año de publicacion: " << libros[i].anioPublicacion << endl;
            cout <<"Cantidad de ejemplares: " << libros[i].cantidadEjemplares << endl;

            encontrado = true;
        }
    }

    if(encontrado==false)
    {
        cout <<"\nNo hay libros de dicho autor en tu estanteria. " << endl;
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}

void librosAutor(estanteria libros[], int contLibros)
{
    char BuscarAutor[50];
    bool encontrado = false;
    cout <<"\n\tHay [" << contLibros <<"] libros en la estanteria. " << endl;
    cin.ignore();
    cout <<"\nIngrese el nombre del autor que busca: "; cin.getline(BuscarAutor, 50, '\n');
    for(int i=0; i<contLibros; i++)
    {
        if(strcmp(BuscarAutor, libros[i].autor)==0)
        {
            cout <<"\nTitulo: " << libros[i].titulo << endl;
            cout <<"Autor: " << libros[i].autor << endl;
            cout <<"Año de publicacion: " << libros[i].anioPublicacion << endl;
            cout <<"Cantidad de ejemplares: " << libros[i].cantidadEjemplares << endl;

            encontrado = true;
        }
    }

    if(encontrado==false)
    {
        cout <<"\nNo hay libros de dicho autor en tu estanteria. " << endl;
    }

    cout <<"\nVolviendo al menu [ENTER]..." << endl;
    system("PAUSE");
}