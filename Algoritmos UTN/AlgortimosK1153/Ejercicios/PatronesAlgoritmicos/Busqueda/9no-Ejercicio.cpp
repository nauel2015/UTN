
/* Ejercicio N°9: Crea una estructura llamada "Cliente" con los atributos "nombre", "edad" y "saldo" e implementa un sistema
donde el usuario pueda ingresar los datos de 10 clientes. Luego, el sistema solicitará al usuario que ingrese el
nombre de un cliente a buscar. Utilizando un algoritmo de búsqueda adecuado, se determinará si el cliente
está presente en el conjunto de clientes cargados. Si se encuentra, se mostrará su nombre, edad y saldo y
cuantos clientes tienen un saldo más alto que el cliente encontrado.

// Planificacion del codigo.

1- Crear funcion cliente cargarClientes(cliente clientes[], int &contCliente)
2- Crear funcion int busquedaSecuencial(cliente clientes[], int contCliente, char buscarCliente[30])
3- Crear funcion int calcularMayorSaldo(cliente clientes[], int contCliente)
4- Crear funcion void buscarCliente(cliente clientes[], int contCliente, char buscarCliente[30])

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct cliente
{
    char nombre[30];
    int edad;
    long saldo;
}clientes[10];

// Declaracion de las funciones.
cliente cargarClientes(cliente [], int&);
int busquedaSecuencial(cliente [], int, char []);
int calcularMayorSaldo(cliente [], int);
void buscarCliente(cliente [], int);

int main()
{
    int contClientes=0, opcion;
    do{
        cout <<"\n\tCajero \n" << endl;
        cout <<"Opcion 1: Cargar Clientes. " << endl;
        cout <<"Opcion 2: Buscar Cliente. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarClientes(clientes, contClientes); system("cls"); break;
            case 2: system("cls"); buscarCliente(clientes, contClientes); system("cls"); break;
            case 3: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
cliente cargarClientes(cliente clientes[], int &contCliente)
{
    int cantClientes;
    cout <<"\n\tClientes en el sistema [" << contCliente <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de clientes a cargar: "; cin >> cantClientes;
    
    for(int i=0; i<cantClientes; i++)
    {
        cin.ignore();
        cout <<"\nCliente Nro [" << contCliente+1 <<"]." << endl;
        cout <<"Nombre: "; cin.getline(clientes[contCliente].nombre, 30, '\n');
        cout <<"Edad: "; cin >> clientes[contCliente].edad;
        cout <<"Saldo en Cuenta: "; cin >> clientes[contCliente].saldo;

        contCliente++;
    }

    return *clientes;
}

int busquedaSecuencial(cliente clientes[], int contCliente, char buscarCliente[30])
{
    int i=0;
    while(i<contCliente&&strcmp(clientes[i].nombre, buscarCliente)!=0)
    {
        i++;
    }

    if(i==contCliente)
    {
        return -1;
    }else{
        return i;
    }
}

int calcularMayorSaldo(cliente clientes[], int contCliente)
{
    int posMayor, clienteMayor;

    for(int i=0; i<contCliente; i++)
    {
        if(clientes[i].saldo>clienteMayor)
        {
            clienteMayor = clientes[i].saldo;
            posMayor=i;
        }
    }

    return posMayor;
}

void buscarCliente(cliente clientes[], int contCliente)
{
    cout <<"\n\tClientes en el sistema [" << contCliente <<"]. " << endl;
    cin.ignore();
    char buscarCliente[30];
    cout <<"\nIngrese el nombre del cliente a buscar: "; cin.getline(buscarCliente, 30, '\n');

    int posCliente = busquedaSecuencial(clientes, contCliente, buscarCliente);
    int posMayorSaldo = calcularMayorSaldo(clientes, contCliente);
    int contMejoresSaldos=0, contPeoresSaldos=0;

    if(posCliente!=-1)
    {
        cout <<"\nCliente encontrado. " << endl;
        cout <<"Nombre: " << clientes[posCliente].nombre << endl;
        cout <<"Edad: " << clientes[posCliente].edad << endl;
        cout <<"Saldo en cuenta: $" << clientes[posCliente].saldo << endl;

        for(int i=0; i<contCliente; i++)
        {
            if(posMayorSaldo<clientes[i].saldo)
            {
                contMejoresSaldos++;
            }else if(posMayorSaldo>clientes[i].saldo){
                contPeoresSaldos++;
            }
        }

        if(contMejoresSaldos>0&&contPeoresSaldos==0)
        {
            cout <<"\nCliente con peor saldo. " << endl;
            cout <<"Hay [" << contMejoresSaldos <<"] clientes con mayor saldo. " << endl;
        }else if(contMejoresSaldos>0&&contPeoresSaldos>0){
            cout <<"\nCliente con saldo promedio. " << endl;
            cout <<"Hay [" << contMejoresSaldos <<"] clientes con mayor saldo y [" << contPeoresSaldos <<"] clientes con peor saldo. " << endl;
        }else if(contMejoresSaldos==0&&contPeoresSaldos>0)
        {
            cout <<"\nCliente con mayor saldo. " << endl;
            cout <<"Hay [" << contPeoresSaldos <<"] Clientes con peores saldos. " << endl;
        }

        cout <<"\nVolviendo al menu... " << endl;
        system("PAUSE");
    }else{
        cout <<"\nCliente no encontrado. " << endl;

        cout <<"\nVolviendo al menu... " << endl;
        system("PAUSE");
    }

}

