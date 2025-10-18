
#include <iostream>
#include <string.h>
using namespace std;

// Estructura Enlazada: Tipo Cola.

// Definición de la estructura Nodo
struct Nodo 
{
    int dato;
    Nodo* siguiente;
};

// Declaracion de las funciones.
Nodo* crearNodo(int valor);
void encolar(Nodo*& frente, Nodo*& final, int valor);
int desencolar(Nodo*& frente, Nodo*& final);
bool isEmpty(Nodo* frente);

int main() 
{
    Nodo* frente = nullptr;
    Nodo* final = nullptr;
    // Encolar elementos
    encolar(frente, final, 10);
    encolar(frente, final, 20);
    encolar(frente, final, 30);

    cout << "Elementos en la cola:" << endl;
    while (!isEmpty(frente)) 
    {
        // Desencolar y mostrar el elemento del frente de la cola
        int valor = desencolar(frente, final);
        cout << valor << " ";
    }

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

// Función para insertar un elemento en la cola
void encolar(Nodo*& frente, Nodo*& final, int valor)
{
    Nodo* nuevoNodo = crearNodo(valor);
    if (final == nullptr) 
    {
        frente = final = nuevoNodo;
    }else{
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

// Función para eliminar y obtener el elemento del frente de la cola
int desencolar(Nodo*& frente, Nodo*& final)
{
    if (frente == nullptr) 
    {
        cout << "La cola está vacía." << endl;
        return -1; // Valor de error
    }
        int valor = frente->dato;
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) 
    {
        final = nullptr; // Si se elimina el último elemento, actualizar 'final'
    }

    delete temp;
    return valor;
}

// Función para verificar si la cola está vacía
bool isEmpty(Nodo* frente)
{
    return frente == nullptr;
}

