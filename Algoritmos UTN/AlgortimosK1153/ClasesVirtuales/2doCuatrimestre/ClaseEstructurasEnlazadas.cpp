
/* Ejercicio N°1: Organización de libros en una biblioteca

En una biblioteca, tu tarea es organizar los libros que van llegando.
Cada libro nuevo debe colocarse encima de los libros anteriores.
Si alguien solicita un libro, debes entregar el que se encuentra en la parte superior de la pila de libros.
De cada libro se conoce su titulo y su escritor.

Realiza un programa que permita:

Agregar libros a la pila de libros.
Mostrar el titulo del libro más reciente (el que está en la parte superior).
Retirar el libro más reciente (el que está en la parte superior).
Retirar todos los libros mostrando sus títulos y autores

*/

#include <iostream>
#include <string.h>
using namespace std;

struct Libro
{
    int codigoLibro;
    char titulo[30];
    char escritor[30];
};

struct Nodo 
{
    Libro libro;
    Nodo* siguiente;
};

// Declaracion de las funciones.
Libro cargarLibro(Libro, int);
Nodo* crearNodo(Libro);
void push(Nodo* &, Libro);

int main() 
{
    Nodo* pila = nullptr;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
Nodo* crearNodo(Libro libro)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->libro = libro;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void push(Nodo*& pila, Libro libro)
{
    Nodo* nuevoNodo = crearNodo(libro);
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

int pop(Nodo*& pila)
{
    if (pila == nullptr) 
    {
        cout << "La pila está vacía." << endl;
        return -1; // Valor de error
    }
    int valor = pila->libro;
    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
    return valor;
}

Libro cargarLibro(Libro libro, int contLibro)
{
    cout <<"\nID del Libro: "; cin >> libro.codigoLibro;
    cout <<"Titulo: "; cin.getline(libro.titulo, 30, '\n');
    cin.ignore();
    cout <<"Escritor: "; cin.getline(libro.escritor, 30, '\n');

    return libro;

}
