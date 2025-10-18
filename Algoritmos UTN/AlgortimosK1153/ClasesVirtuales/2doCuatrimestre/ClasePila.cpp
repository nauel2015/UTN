

#include <iostream>
#include <string.h>
using namespace std;

// Estructura Enlazada: Tipo Pila.

// Definición de la estructura Nodo
struct Nodo 
{
    int dato;
    Nodo* siguiente;
};

// Declaracion de las funciones.
Nodo* crearNodo(int valor);
void push(Nodo*& pila, int valor);
int pop(Nodo*& pila);
bool isEmpty( Nodo* pila);

int main() 
{
    Nodo* pila = nullptr; // Inicializar la pila
    // Apilar elementos en la pila
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);

    cout << "Elementos en la pila:" << endl;
    while (!isEmpty(pila)) 
    {
        // Mostrar y eliminar el elemento en la cima de la pila
        int valor = pop(pila);
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
// Función para insertar un elemento en la pila
void push(Nodo*& pila, int valor)
{
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}
// Función para eliminar y obtener el elemento en la cima de la pila
int pop(Nodo*& pila)
{
    if (pila == nullptr) 
    {
        cout << "La pila está vacía." << endl;
        return -1; // Valor de error
    }
    int valor = pila->dato;
    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
    return valor;
}

// Función para verificar si la pila está vacía
bool isEmpty( Nodo* pila)
{
    return pila == nullptr;
}
