

/* Ejercicio N°1: Dos sucursales almacenan productos en arrays de estructuras.
Cada producto tiene:

Código de producto (entero)
Nombre del producto (string)
Ambos arrays están ordenados por código y no tienen códigos repetidos dentro de cada sucursal.

Se pide:
1. Aparear las dos listas en un nuevo array, manteniendo el orden por código.
2. Mostrar todos los productos ordenados por código.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct producto
{
    int codigoDeProducto;
    char nombre[30];
}productos1[3], productos2[3], productos3[6];

// Declaracion de las funciones.
void insertar(producto [], int &, producto, int);
void insertarOrdenado(producto [], int &, producto);
void cargarProductos(producto [], int &);
void apareo(producto productos1[], int contProductos1, producto productos2[], int contProductos2, producto productos3[], int &contProductos3);

int main()
{
    int contProductos1=0, contProductos2=0, contProductos3=0;

    cout <<"\n\tSucursal 1. " << endl;
    cargarProductos(productos1, contProductos1);
    cout <<"\n\tSucursal 2. " << endl;
    cargarProductos(productos2, contProductos2);

    apareo(productos1, contProductos1, productos2, contProductos2, productos3, contProductos3);

    for(int i=0; i<contProductos3; i++)
    {
        cout <<"\nCodigo " << productos3[i].codigoDeProducto <<" - ";
        cout << productos3[i].nombre;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void insertar(producto productos[], int &contProductos, producto nuevo, int pos)
{
    for(int i=contProductos; i>pos; i--)
    {
        productos[i] = productos[i-1];
    }

    productos[pos] = nuevo;
    contProductos++;
}

void insertarOrdenado(producto productos[], int &contProductos, producto nuevo)
{
    int i=0;

    while(i<contProductos&&productos[i].codigoDeProducto<=nuevo.codigoDeProducto)
    {
        i++;
    }

    insertar(productos, contProductos, nuevo, i);

}

void cargarProductos(producto productos[], int &contProductos)
{

    producto nuevo;
    for(int i=0; i<3; i++)
    {
        cout <<"\nNombre del Producto: "; cin.getline(nuevo.nombre, 30, '\n');
        cout <<"Codigo: "; cin >> nuevo.codigoDeProducto;
        insertarOrdenado(productos, contProductos, nuevo);
        cin.ignore();
    }

    system("CLS");
}

void apareo(producto productos1[], int contProductos1, producto productos2[], int contProductos2, producto productos3[], int &contProductos3)
{
    int i=0, j=0;

    while(i<contProductos1&&j<contProductos2)
    {
        if(productos1[i].codigoDeProducto<=productos2[j].codigoDeProducto)
        {
            productos3[contProductos3] = productos1[i];
            contProductos3++;
            i++;
        }else{
            productos3[contProductos3] = productos2[j];
            contProductos3++;
            j++;
        }
    }

    while(i<contProductos1)
    {
        productos3[contProductos3] = productos1[i];
        contProductos3++;
        i++;
    }

    while(j<contProductos2)
    {
        productos3[contProductos3] = productos2[j];
        contProductos3++;
        j++;
    }

}
