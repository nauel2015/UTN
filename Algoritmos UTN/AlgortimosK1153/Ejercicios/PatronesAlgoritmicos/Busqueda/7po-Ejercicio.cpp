
/* Ejercicio N°7: Crea una estructura llamada "Factura" con los atributos "numero", "fecha" y "monto" e implementa un sistema
donde el usuario pueda ingresar los datos de 10 facturas. Luego, el sistema solicitará al usuario que ingrese
un número de factura a buscar. Utilizando un algoritmo de búsqueda adecuado, se determinará si la factura
está presente en el conjunto de facturas cargadas. Si se encuentra, se mostrará su número, fecha y monto. 

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct tipoFecha
{
    int dia;
    int mes;
    int anio;
};

struct factura
{
    int numero;
    tipoFecha fecha;
    int monto;
}facturas[10];

// Declaracion de las funciones.
factura cargarFacturas(factura [], int &);
void ordenamientoBurbuja(factura [], int);
int busquedaBinaria(factura[], int, int);
void facturaEncontrada(factura[], int);

int main()
{
    int contFacturas=0, opcion;
    do{
        cout <<"\n\tCaja \n" << endl;
        cout <<"Opcion 1: Cargar Facturas. " << endl;
        cout <<"Opcion 2: Buscar Factura por numero. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarFacturas(facturas, contFacturas); system("cls"); break;
            case 2: system("cls"); facturaEncontrada(facturas, contFacturas); system("cls"); break;
            case 3: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
factura cargarFacturas(factura facturas[], int &contFacturas)
{
    int cantFacturas;
    cout <<"\n\tCantidad de facturas [" << contFacturas <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de facturas a agregar: "; cin >> cantFacturas;

    for(int i=0; i<cantFacturas; i++)
    {
        cin.ignore();
        cout <<"\nFactura Nro " << contFacturas+1 <<". " << endl;
        cout <<"Numero de factura: "; cin >> facturas[contFacturas].numero;
        cout <<"\nFecha de la factura. " << endl;
        cout <<"Dia: "; cin >> facturas[contFacturas].fecha.dia;
        cout <<"Mes: "; cin >> facturas[contFacturas].fecha.mes;
        cout <<"Año: "; cin >> facturas[contFacturas].fecha.anio;
        cout <<"\nMonto de la factura: "; cin >> facturas[contFacturas].monto;

        contFacturas++;
    }

    return *facturas;
}

void ordenamientoBurbuja(factura facturas[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(facturas[j].numero > facturas[j+1].numero)
            {
                factura aux = facturas[j];
                facturas[j] = facturas[j+1];
                facturas[j+1] = aux;
            }
        }
    }
}

int busquedaBinaria(factura facturas[], int len, int buscado)
{
    int inicio=0, final=len-1;
    while(inicio<=final)
    {
        int medio = (inicio+final)/2;
        if(facturas[medio].numero==buscado)
        {
            return medio;
        }else if(facturas[medio].numero<buscado){
            inicio = medio+1;
        }else{
            final = medio-1;
        }
    }

    return -1;
}

void facturaEncontrada(factura facturas[], int contFacturas)
{
    int buscado;
    cout <<"\n\tCantidad de facturas [" << contFacturas <<"]. " << endl;
    ordenamientoBurbuja(facturas, contFacturas);
    cin.ignore();
    cout <<"\nIngrese el numero de factura a buscar: "; cin >> buscado;
    int pos = busquedaBinaria(facturas, contFacturas, buscado);

    if(pos!=-1)
    {
        cout <<"\nFactura encontrada. " << endl;
        cout <<"Numero de factura: " << facturas[pos].numero << endl;
        cout <<"Fecha: " << facturas[pos].fecha.dia <<"/" << facturas[pos].fecha.mes <<"/" << facturas[pos].fecha.anio << endl;
        cout <<"Monto: $" << facturas[pos].monto << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
    }else{
        cout <<"\nFactura no encontrada. " << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
    }
}