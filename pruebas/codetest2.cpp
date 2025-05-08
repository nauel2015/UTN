
// Ejercicio en clase: 

// Abrir archivos(vuelos y pedidos)
// Cargar vuelos(vuelos,vector)
// rv(codigo, disponibles, no vendidos)
// Recorrer vuelos

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

    struct vuelo
    {
        int codigoDeVuelo;
        int pasajesDisponibles;
    }rv;

    struct pedido
    {
        int codigoDeVuelo;
        int cantPasajes;
        string DNI;
        string apellidoNombre;
    }rp;

    struct vector
    {
        vuelo unVuelo;
        int pasajesNoVendidos;
    }

    void abrirArchivos(FILE* vuelos, FILE* Pedidos)
    {
        vuelos = fopen("vuelos.dat","rb+");
        pedidos = fopen("pedidos.dat","rb+");
    }

    void cerrarArchivos(FILE* vuelos, FILE* Pedidos)
    {
        fclose(vuelos);
        fclose(pedidos);
    }

    void cargarVuelos(vector vuelos[], FILE* VUELOS)
    {
        vuelo rv;
        fread(&rv, sizeof(rv), 1, VUELOS);

        while(!feof(VUELOS))
        {
            vuelos[i].unVuelo.codigoDeVuelo = rv.codigoDeVuelo;
            vuelos[i].unVuelo.pasajesDisponibles = rv.pasajesDisponibles;
            vuelos[i].pasajesNoVendidos = 0;
        }
    }

    void recorrerVuelos(vector vuelos[])
    {
        for(int i=0; i<500; i++)
        {
            cout << vector[i].unVuelo.codigoDeVuelo;
            cout << vector[i].unVuelo.pasajesDisponibles;
            cout << vector[i].pasajesNoVendidos;
        }
    }

    void evaluar(vector vuelos[], FILE* pedidos, nodo*& lista)
    {
        int i;
        pedido rp;
        fread(&rp, sizeof(rp), 1, pedidos);
        i = buscarEnVector(vuelos, rp.codigoDeVuelo)

        if(rv.pasajesDisponibles <= vuelos[i].unVuelo.pasajesDisponibles)
        {
            insertarOrdenado(lista, rp); // Lista ordenada por apellido y nombre.
            vuelos[i].unVuelo.pasajesDisponibles -= rp.cantPasajes;
        }else{
            vuelos[i].pasajesNoVendidos += rp.cantPasajes;
        }
    }

    void mostrarPedidos(nodo*& lista)
    {
        pedido rp;

        while(lista != NULL)
        {
            rp = pop.lista;
            cout << rp.codigoDevuelo;
            cout << rp.cantPasajes;
            cout << rp.DNI;
            cout << rp.apellidoNombre;
        }
    }

    int main()
    {



        system("pause");
        return 0;
    }