
/* Ejercicio N°1: Una empresa almacena las ventas de sus vendedores en un array de estructuras ordenado por código de
vendedor. Cada registro contiene:
Código de vendedor (entero)
Monto de venta (float)

Se pide:
1. Para cada vendedor, calcular el total vendido.
2. Mostrar el código de vendedor y el total de ventas correspondiente.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct ventas
{
    int codigoDeVendedor;
    float montoDeVenta;
}vendedores[5];

// Declaracion de las funciones.
ventas cargarVenta(ventas [], int &, long &);
void corteDeControl(ventas[], int);

int main()
{
    int contGestiones=0;
    long VentasTotal=0;
    cargarVenta(vendedores, contGestiones, VentasTotal);
    corteDeControl(vendedores, contGestiones);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
ventas cargarVenta(ventas vendedores[], int &contGestiones, long &VentasTotal)
{
    int cantGestiones;
    cout <<"\n\tCantidad de ventas realizadas [" << VentasTotal <<"]. " << endl;
    cout <<"\nIngrese la cantidad de gestiones a realizar: "; cin >> cantGestiones;

    for(int i=0; i<cantGestiones; i++)
    {
        cin.ignore();
        cout <<"\nCargue la gestion de las ventas por el vendedor correspondiente. " << endl;
        cout <<"Codigo del Vendedor: "; cin >> vendedores[contGestiones].codigoDeVendedor;
        cout <<"Monto de la Venta Realizada: "; cin >> vendedores[contGestiones].montoDeVenta;
        VentasTotal += vendedores[contGestiones].montoDeVenta;

        contGestiones++;
    }

    return *vendedores;
}

void corteDeControl(ventas vendedores[], int contGestiones)
{
    int i=0;

    while(i<contGestiones)
    {
        int vendedorActual = vendedores[i].codigoDeVendedor;
        long totalMontoVentas=0;

        // Mientras las ventas sean del mismo vendedor.
        while(i<contGestiones&&vendedores[i].codigoDeVendedor==vendedorActual)
        {
            totalMontoVentas += vendedores[i].montoDeVenta;
            i++;
        }

        cout <<"\nVendedor: " << vendedores[i].codigoDeVendedor <<"- " << endl;
        cout <<"Total: $" << totalMontoVentas << endl;
    }
}