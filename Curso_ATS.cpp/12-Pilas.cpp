
// Explicacion de Pilas: 

// Una pila es una estructura de datos de entradas ordenadas tales que solo se pueden introducir y eliminar por un extremo llamado cima.
// Las operaciones usuales en la pila son Insertar y Quitar:
// Insertar (push) añade un elemento en la cima de la pila.
// Quitar (pop) elimina o saca un elemento de la pila.

#include<iostream>
#include<stdlib.h>

using namespace std;

// pasos para insertar elementos en la pila:
struct NodoCliente
{
    int dato;
    NodoCliente* sgte;
};

// Prototipo de la funcion.
void agregarPila(NodoCliente* &, int);
void sacarPila(NodoCliente* &, int&);

int main()
{
    NodoCliente* pila = NULL;
    int dato;
    cout <<"\nIngrese un numero: "; cin >> dato;
    agregarPila(pila, dato);
    cout <<"El elemento " << dato <<" fue agregado a la pila con exito. " << endl;

    cout <<"\nIngrese otro numero: "; cin >> dato;
    agregarPila(pila, dato);
    cout <<"El elemento " << dato <<" fue agregado a la pila con exito. " << endl;

    cout <<"\nSacando los elementos de la pila: ";
    while(pila != NULL) // Mientras no se el final de la pila.
    {
        sacarPila(pila, dato);

        if(pila != NULL)
        cout << dato <<" , ";
        if(pila==NULL)
        cout << dato <<" . ";
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void agregarPila(NodoCliente* &pila, int n) 
{
    // 1- Crear el espacio en memoria para almacenar un nodo.
    NodoCliente* nuevo_nodo = new NodoCliente(); // reservamos espacio en la memoria para un nodo.

    // 2- Cargar el valor dentro del nodo(dato).
    nuevo_nodo->dato = n;

    // 3- Cargar el puntero pila dentro del nodo(*sgte).
    nuevo_nodo->sgte = pila;

    // 4- Asignar el nuevo nodo a pila.
    pila = nuevo_nodo;
}

// pasos para retirar/sacar elementos de una pila.
void sacarPila(NodoCliente* &pila, int& n)
{
    // 1- Crear una variable *aux de tipo Nodo.
    NodoCliente* aux = pila; // Asi ambas señalarian a la cima de la pila

    // 2- Igualar el n a aux->dato;
    n = aux->dato; // n Señalara al valor del nodo y asi podremos eliminar dicho nodo.

    // 3- Pasar pila a sgte nodo.
    pila = aux->sgte; 

    // 4- Eliminar aux.
    delete aux;
}

// Ejercicio n°1: hacer un programa para agregar numero enteros a una pila, hasta que le usuario lo decida.
// Luego mostrar toso los numeros introducidos en la pila.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct NodoCliente
{
    int dato;
    NodoCliente* sgte;
}*nuevo_nodo, *pila = NULL;

// prototipo de funciones.
void agregarPila(NodoCliente* &, int);
void sacarPila(NodoCliente* &, int &);

int main()
{
    int dato;
    char respuesta;

    do{
        cout <<"\nIngrese un numero: "; cin >> dato;
        agregarPila(pila, dato);
        cout <<"\nEl elemento " << dato <<" fue agregado a la pila con exito. " << endl;
        cout <<"Desea agregar otro elemento a la pila: (S/N) "; cin >> respuesta;
    }while((respuesta == 'S')||(respuesta == 's'));

    cout <<"\nSacando los elementos de la pila: ";
    while(pila != NULL) // Mientras no se el final de la pila.
    {
        sacarPila(pila, dato);
    
        if(pila != NULL)
        cout << dato <<" , ";
        if(pila==NULL)
        cout << dato <<" . ";
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void agregarPila(NodoCliente* &pila, int n)
{
    nuevo_nodo = new NodoCliente();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = pila;
    pila = nuevo_nodo;
}

void sacarPila(NodoCliente* &pila, int &n)
{
    NodoCliente* aux = pila;
    n = aux->dato;
    pila = aux->sgte;
    delete aux;
}

// Ejercicio n°2: Hacer un programa utilizando pilas que contenga el siguiente menu:
// 1- insertar un caracter a la pila.
// 2- Mostrar todos los elementos de la pila.
// 3- Salir.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct NodoCliente
{
    char dato;
    NodoCliente* sgte;
}*nuevo_nodo, *pila = NULL;

char respuesta, caracter;

// prototipo de funciones.
void Menu();
void pushPila(NodoCliente* &, char);
void popPila(NodoCliente* &, char &);

int main()
{
    Menu();
    pushPila(pila, caracter);
    popPila(pila, caracter);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void Menu()
{
    int opcion=0;
    cout <<"\n\t!Bienvenido al menu!\n1- insertar un caracter a la pila.\n2- Mostrar todos los elementos de la pila.\n3- Salir.\n\nSeleccione su opcion: "; cin >> opcion;
    do{
        if(opcion==1)
        {
            cout <<"Ingrese un caracter: "; cin >> caracter;
            pushPila(pila, caracter);
            cout <<"\nEl elemento [" << caracter <<"] fue agregado a la pila con exito. " << endl;
            cout <<"\n1- insertar un caracter a la pila.\n2- Mostrar todos los elementos de la pila.\n3- Salir.\n\nSeleccione su opcion: "; cin >> opcion;

        }

        if(opcion==2)
        {
            cout <<"\nMostrando los elementos de la pila ingresados: ";
            while(pila != NULL) // Mientras no sea el final de la pila.
            {
                popPila(pila, caracter);
    
                if(pila != NULL)
                cout << caracter <<" , ";
                if(pila==NULL)
                cout << caracter <<" . " << endl;
            }
            break;
        }

        if(opcion==3)
        cout <<"\nHasta pronto. " << endl;

    }while(opcion != 3);
}

void pushPila(NodoCliente* &pila, char n)
{
    nuevo_nodo = new NodoCliente();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = pila;
    pila = nuevo_nodo;
}

void popPila(NodoCliente* &pila, char &n)
{
    NodoCliente* aux = pila;
    n = aux->dato;
    pila = aux->sgte;
    delete aux;
}