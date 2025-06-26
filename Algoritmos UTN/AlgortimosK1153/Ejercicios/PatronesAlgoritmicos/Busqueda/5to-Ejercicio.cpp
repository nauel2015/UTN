
/* Ejercicio N°5: Crea una estructura llamada "Producto" con los atributos "nombre", "precio" y "stock" e implementa un
sistema donde el usuario pueda ingresar los datos de 10 productos. Luego, el sistema solicitará al usuario que
ingrese el nombre de un producto a buscar. Utilizando un algoritmo de búsqueda adecuado, se determinará si
el producto está presente en el conjunto de productos cargados. Si se encuentra, se mostrará su nombre,
precio y stock.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct producto
{
    string nombre;
    float precio;
    int stock;
}productos[10];

// Declaracion de las funciones.
producto cargarProductos(producto [], int &);
int busquedaSecuencial(producto [], int, string);
void buscarProductos(producto [], int);

int main()
{
    int contProductos=0, opcion;
    do{
        cout <<"\n\tTienda. \n" << endl;
        cout <<"Opcion 1: Cargar Productos. " << endl;
        cout <<"Opcion 2: Buscar Producto. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarProductos(productos, contProductos); system("cls"); break;
            case 2: system("cls"); buscarProductos(productos, contProductos); system("cls"); break;
            case 3: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
producto cargarProductos(producto productos[], int &contProductos)
{
    int cantProductos;
    cout <<"\n\tTotal de productos en la lista [" << contProductos <<"]. " << endl;
    cout <<"\nIngrese la cantidad de productos a cargar: "; cin >> cantProductos;

    if(cantProductos+contProductos>10)
    {
        cout <<"\nERROR. Almacenamiento insuficiente. Solo se pueden agregar " <<(10-contProductos) <<" productos mas a la lista. " << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
        return *productos;
    }

    if(contProductos>10)
    {
        cout <<"\nListado de productos lleno. Ya no se pueden cargar mas productos. " << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
        return *productos;
    }

    cout <<"\nCargue el listado de productos. " << endl;
    for(int i=0; i<cantProductos; i++)
    {
        cin.ignore();
        cout <<"\nNombre del producto: "; getline(cin, productos[contProductos].nombre);
        cout <<"Precio: "; cin >> productos[contProductos].precio;
        cout <<"Stock: "; cin >> productos[contProductos].stock;
        contProductos++;
    }

    return *productos;
}

int busquedaSecuencial(producto productos[], int len, string buscarProducto)
{
    int i=0;
    while(i<len&&productos[i].nombre!=buscarProducto)
    {
        i++;
    }

    if(i==len)
    {
        return -1;
    }else{
        return i;
    }
}

void buscarProductos(producto productos[], int contProductos)
{
    string buscarProducto;
    cout <<"\n\tTotal de productos [" << contProductos <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese el nombre del producto que busca: "; getline(cin, buscarProducto);

    int pos = busquedaSecuencial(productos, contProductos, buscarProducto);
    if(pos!=-1)
    {
        cout <<"\nProducto encontrado. " << endl;
        cout <<"Nombre del producto: " << productos[pos].nombre << endl;
        cout <<"Precio: $" << productos[pos].precio << endl;
        cout <<"Stock: " << productos[pos].stock << endl;
        }else{
            cout <<"Producto no encontrado en el listado. " << endl;
        }

    cout <<"\nVolviendo al menu... [ENTER] " << endl;
    system("PAUSE");
}