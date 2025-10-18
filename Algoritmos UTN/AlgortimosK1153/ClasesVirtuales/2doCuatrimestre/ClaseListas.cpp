
#include <iostream>
#include <string.h>
using namespace std;

// Estructura Enlazada: Tipo Lista.

// Definición de la estructura Nodo
struct Nodo 
{
    int dato;
    Nodo* siguiente;
};

// Declaracion de las funciones.
Nodo* crearNodo(int valor);

int main() 
{


    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}
