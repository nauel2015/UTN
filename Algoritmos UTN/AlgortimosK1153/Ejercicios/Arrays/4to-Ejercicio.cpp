
/* Ejercicio N°4: Se requiere un programa que permita al usuario ingresar las ventas diarias de una tienda durante una de las semanas del año.
Luego, permite al usuario colocar un valor de ventas mínimo que se espera y debe mostrar por pantalla
cuantos días superan el valor mínimo colocado por el usuario.

1. Identifique las estructuras necesarias
2. Implemente el programa

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct ventasSemana
{
    int minimoVentas=0;
    int lunes=0;
    int martes=0;
    int miercoles=0;
    int jueves=0;
    int viernes=0;
    int sabado=0;
    int domingo=0;
}ventas[52];

// Declaracion de las funciones:
ventasSemana cargarMinimoVentas(ventasSemana []);
ventasSemana cargarVentasDeLaSemana(ventasSemana []);
void MostrarVentasDeLaSemana(ventasSemana []);
void mostrarMejoresVentas(ventasSemana [], int);
void mostrarPeoresVentas(ventasSemana [], int);

int main()
{
    int opcion;
    do{
        cout <<"\n\tLista de ventas del año." << endl;
        cout <<"\nOpcion 1: Establecer un minimo de ventas para la semana de cada año." << endl;
        cout <<"Opcion 2: Cargar Ventas de la semana." << endl;
        cout <<"Opcion 3: Mostrar Las Ventas de Una Semana Del Año [1-52]." << endl;
        cout <<"Opcion 4: salir." << endl;
        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: cargarMinimoVentas(ventas); system("cls"); break;
            case 2: system("cls"); cargarVentasDeLaSemana(ventas); system("cls");break;
            case 3: system("cls"); MostrarVentasDeLaSemana(ventas); system("cls"); break;
            case 4: cout <<"\nHasta Luego."; break;
        }

    }while(opcion!=4);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
ventasSemana cargarMinimoVentas(ventasSemana ventas[])
{
    int minimo;
    cout <<"\nIngrese el minimo de ventas diarias para la semana: "; cin >> minimo;
    for(int i=0; i<53; i++)
    {
        ventas[i].minimoVentas = minimo;
    }

    return *ventas;
}

ventasSemana cargarVentasDeLaSemana(ventasSemana ventas[])
{
    int semanaDelAño;
    bool flag = false;
    do{
        cout <<"\nIndique la semana del año a cargar. slots[1-52]: "; cin >> semanaDelAño;
        if(semanaDelAño >0 && semanaDelAño < 53)
        {
            flag = true;
        }else{
            cout <<"\n\tERROR no existe esa semana en el año." << endl;
            system("cls");
        }
    }while(flag == false);

    cout <<"\nIngrese las ventas diarias de la semana. " << endl;
    for(int i=semanaDelAño; i<semanaDelAño+1; i++)
    {
        cout <<"Lunes: "; cin >> ventas[i].lunes;
        cout <<"Martes: "; cin >> ventas[i].martes;
        cout <<"Miercoles: "; cin >> ventas[i].miercoles;
        cout <<"Jueves: "; cin >> ventas[i].jueves;
        cout <<"Viernes: "; cin >> ventas[i].viernes;
        cout <<"Sabado: "; cin >> ventas[i].sabado;
        cout <<"Domingo: "; cin >> ventas[i].domingo;
    }

    return *ventas;
}

void MostrarVentasDeLaSemana(ventasSemana ventas[])
{
    int semanaDelAño;
    cout <<"\nIndique la semana del año a mostrar. slots[0-52]: "; cin >> semanaDelAño;
    cout <<"\nVentas de la semana " << semanaDelAño <<"." << endl;
    for(int i=semanaDelAño; i<semanaDelAño+1; i++)
    {
        cout <<"Lunes: " << ventas[i].lunes <<" Ventas realizadas." << endl;
        cout <<"Martes: " << ventas[i].martes <<" Ventas realizadas." << endl;
        cout <<"Miercoles: " << ventas[i].miercoles <<" Ventas realizadas." << endl;
        cout <<"Jueves: " << ventas[i].jueves <<" Ventas realizadas." << endl;
        cout <<"Viernes: " << ventas[i].viernes <<" Ventas realizadas." << endl;
        cout <<"Sabado: " << ventas[i].sabado <<" Ventas realizadas." << endl;
        cout <<"Domingo: " << ventas[i].domingo <<" Ventas realizadas." << endl << endl;
        system("Pause"); system("cls");

        mostrarMejoresVentas(ventas, semanaDelAño);
        mostrarPeoresVentas(ventas, semanaDelAño);
    }

    cout <<"\n\n";
    system("Pause");
}

void mostrarMejoresVentas(ventasSemana ventas[], int semanaDelAño)
{
    for(int i=semanaDelAño; i<semanaDelAño+1; i++)
    {
        cout <<"\nDias con mejores ventas al minimo establecido -> [" << ventas[i].minimoVentas <<"]. " << endl;
        if(ventas[i].lunes >= ventas[i].minimoVentas)
        {
            cout <<"Lunes: " << ventas[i].lunes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].martes >= ventas[i].minimoVentas)
        {
            cout <<"Martes: " << ventas[i].martes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].miercoles >= ventas[i].minimoVentas)
        {
            cout <<"Miercoles: " << ventas[i].miercoles <<" Ventas realizadas." << endl;
        }
        if(ventas[i].jueves >= ventas[i].minimoVentas)
        {
            cout <<"Jueves: " << ventas[i].jueves <<" Ventas realizadas." << endl;
        }
        if(ventas[i].viernes >= ventas[i].minimoVentas)
        {
            cout <<"Viernes: " << ventas[i].viernes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].sabado >= ventas[i].minimoVentas)
        {
            cout <<"Sabado: " << ventas[i].sabado <<" Ventas realizadas." << endl;
        }
        if(ventas[i].domingo >= ventas[i].minimoVentas)
        {
            cout <<"Domingo: " << ventas[i].domingo <<" Ventas realizadas." << endl;
        }
    }
}

void mostrarPeoresVentas(ventasSemana ventas[], int semanaDelAño)
{
    for(int i=semanaDelAño; i<semanaDelAño+1; i++)
    {
        cout <<"\nDias con peores ventas al minimo establecido -> [" << ventas[i].minimoVentas <<"]. " << endl;
        if(ventas[i].lunes < ventas[i].minimoVentas)
        {
            cout <<"Lunes: " << ventas[i].lunes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].martes < ventas[i].minimoVentas)
        {
            cout <<"Martes: " << ventas[i].martes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].miercoles < ventas[i].minimoVentas)
        {
            cout <<"Miercoles: " << ventas[i].miercoles <<" Ventas realizadas." << endl;
        }
        if(ventas[i].jueves < ventas[i].minimoVentas)
        {
            cout <<"Jueves: " << ventas[i].jueves <<" Ventas realizadas." << endl;
        }
        if(ventas[i].viernes < ventas[i].minimoVentas)
        {
            cout <<"Viernes: " << ventas[i].viernes <<" Ventas realizadas." << endl;
        }
        if(ventas[i].sabado < ventas[i].minimoVentas)
        {
            cout <<"Sabado: " << ventas[i].sabado <<" Ventas realizadas." << endl;
        }
        if(ventas[i].domingo < ventas[i].minimoVentas)
        {
            cout <<"Domingo: " << ventas[i].domingo <<" Ventas realizadas." << endl;
        }
    }
}