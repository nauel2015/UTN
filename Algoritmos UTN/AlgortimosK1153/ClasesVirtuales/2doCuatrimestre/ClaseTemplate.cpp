
/* Ejercicio N°1: Crear una pila usando templates, Cargarle 3 alumnos (Cada alumno tiene dni y nombre)
y luego hacer pop de cada alumno y mostrarlo en pantalla.

*/

// Declaracion de las funciones.
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Alumno
{
    int dni;
    string nombre;
};

template <typename T>
struct Nodo
{   
    T dato;
    Nodo* siguiente;
};

// Declaracion de las funciones.
template <typename T>
Nodo<int> crearNodo(Nodo <T>*valor);
template <typename T>
void pila(Nodo<T>*&pila, T valor);
template <typename T>
int pop(Nodo<T>*& pila);
void mostrarAlumno(Alumno a);

int main()
{
    Nodo<Alumno>* pila = nullptr;

    // Cargar 3 alumnos
    Alumno a1 = {123, "Juan"};
    Alumno a2 = {456, "Ana"};
    Alumno a3 = {789, "Pedro"};

    push(pila, a1);
    push(pila, a2);
    push(pila, a3);

    cout << "Desapilando alumnos:" << endl;
    while (pila != nullptr) {
        Alumno a = pop(pila);
        mostrarAlumno(a);
    }

    cout <<"\n- Nahuel Richeri \n";

    return 0;
}

// Definicion de las funciones.
template <typename T>
Nodo<T> crearNodo(T valor)
{
    Nodo<T> nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

template <typename T>
void push(Nodo<T>*&pila, T valor)
{
    Nodo<T> nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

template <typename T>
T pop(Nodo<T>*& pila) 
{
    if (pila == nullptr) 
    {
        cout << "La pila está vacía." << endl;
        T aux;
        return aux; // Valor de error
    }

    T valor = pila->dato;
    Nodo<T> temp = pila;
    pila = pila->siguiente;
    delete temp;
    return valor;
}

void mostrarAlumno(Alumno a)
{
    cout << "DNI: " << a.dni << ", Nombre: " << a.nombre << endl;
}