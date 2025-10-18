
/* Ejercicio N°1: Organización de libros en una biblioteca

En una biblioteca, tu tarea es organizar los libros que van llegando.
Cada libro nuevo que llega debe colocarse encima de los libros anteriores.
Si alguien solicita un libro, debes entregar el que se encuentra en la parte superior de la pila de libros.
De cada libro se conoce su titulo y su escritor. 

Realiza un programa que permita:

1. Agregar libros a la pila de libros.
2. Mostrar el titulo del libro más reciente (el que está en la parte superior).
3. Retirar el libro más reciente (el que está en la parte superior).
4. Retirar todos los libros mostrando sus títulos y autores

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Libro
{
    int codigo_libro;
    char titulo[30];
    char escritor[30];
}libro[10];

struct Nodo
{
    Libro libreria;
    Nodo* sgte;
};

// Declaracion de las funciones.
Nodo* crearNodo(Libro libro);
void push(Nodo* &pila, Libro libro);
void cargarLibros(Nodo*& pila, Libro libro[], int &len);
Libro pop(Nodo* &pila);
void mostrarLibroReciente(Nodo*& pila);
void eliminarLibro(Nodo*& pila);
void MostrarLibreria(Nodo*& pila);

int main()
{
    int opcion, len=0;
    Nodo* pila = NULL;

    do{
        cout <<"\n\tOrganizacion de libros en una biblioteca. " << endl;
        cout <<"\nOpcion 1: Cargar libros en la biblioteca. ";
        cout <<"\nOpcion 2: Mostrar el libro mas reciente. ";
        cout <<"\nOpcion 3: Eliminar libro mas reciente. ";
        cout <<"\nOpcion 4: Mostrar todos los libros de la libreria. ";
        cout <<"\nOpcion 5: Salir. ";

        cout <<"\nIngrese su opcion: "; cin >> opcion;
        system("cls");

        switch(opcion)
        {
            case 1: cargarLibros(pila, libro, len); break;
            case 2: mostrarLibroReciente(pila); break;
            case 3: eliminarLibro(pila); break;
            case 4: MostrarLibreria(pila);
            case 5: cout <<"\nHasta Luego!!! " << endl; break;

            default: cout <<"\nOpcion incorrecta, intetelo de nuevo. " << endl;
        }

    }while(opcion!=5);

    cout <<"\n- Nahuel Richeri. \n";
    return 0;
}

// Definicion de las funciones.

Nodo* crearNodo(Libro libro)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->libreria = libro;
    nuevoNodo->sgte = NULL;
    return nuevoNodo;

}

void push(Nodo* &pila, Libro libro)
{
    Nodo* nuevoNodo = crearNodo(libro);
    nuevoNodo->sgte = pila;
    pila = nuevoNodo;
}

void cargarLibros(Nodo*& pila, Libro libro[], int &len)
{
    int cantLibros;
    cout <<"\nIngrese la cantidad de libros a cargar: "; cin >> cantLibros;

    for(int i=0; i<cantLibros; i++)
    {
        cout <<"\nCodigo del libro: "; cin >> libro[len].codigo_libro;
        cin.ignore();
        cout <<"Titulo del libro: "; cin.getline(libro[len].titulo, 30, '\n');
        cout <<"Autor: "; cin.getline(libro[len].escritor, 30, '\n');

        push(pila, libro[len]);
        len++;
    }
}

Libro pop(Nodo* &pila)
{
    if(pila==NULL)
    {
        cout <<"\nLa pila esta vacia. " << endl;

        cout <<"\nVolviendo al menu... " << endl;
        system("PAUSE");
        Libro aux;
        return aux;
    }

    Libro libro = pila->libreria;
    Nodo* temporal = pila;
    pila = pila->sgte;
    delete temporal;
    return libro;
}

void mostrarLibroReciente(Nodo*& pila)
{
    if(pila!=NULL)
    {
        cout <<"\n\tLibro mas reciente en la libreria. " << endl;
        cout <<"\nCodigo: " << pila->libreria.codigo_libro;
        cout <<"\nTitulo: " << pila->libreria.titulo;
        cout <<"\nAutor: " << pila->libreria.escritor;
    }else{
        cout <<"\nLa pila esta vacia. " << endl;

        cout <<"\nVolviendo al menu... " << endl;
        system("PAUSE");
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");

}

void eliminarLibro(Nodo*& pila)
{

    if(pila!=NULL)
    {
        Libro libro = pop(pila);

        cout <<"\n\tLibro eliminado de la libreria. " << endl;
        cout <<"\nCodigo: " << libro.codigo_libro;
        cout <<"\nTitulo: " << libro.titulo;
        cout <<"\nAutor: " << libro.escritor;
    }else{
        cout <<"\nNo hay libros para eliminar. " << endl;
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}

void MostrarLibreria(Nodo*& pila)
{
    while(pila!=NULL)
    {
        Libro libro = pop(pila);

        cout <<"\n\tLibro mas reciente en la libreria. " << endl;
        cout <<"\nCodigo: " << libro.codigo_libro;
        cout <<"\nTitulo: " << libro.titulo;
        cout <<"\nAutor: " << libro.escritor;

    }

    if(pila==NULL)
    {
        cout <<"\nLa pila esta vacia. " << endl;

    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}