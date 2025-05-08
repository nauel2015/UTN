
// En el restaurante "La vaca lola" el chef tiene que preparar los pedidos de comida de acuerdo a las solicitudes.
// para ello los mozos van generando las comandas que cargan en un vector de listas(de 30 posiciones).

// Las mismas llevan los siguientes datos:
// ID de pedido.
// ID de meza(30 mesas).
// Importe total a abonar.
// ID de mozo.
// Lista con los pedidos:
//    ID de plato.
//    Cantidad de platos.

// Se solicita:
// 1- Decalarar todas las estructuras necesarias para resolver las funciones siguientes.

// 2- Programar la funcion agregar pedido que dados:
// ID de mesa, ID de plato y cantidad de platos agregue el plato solicitado a la lista si no existia en la mesa
// o solo sume la cantidad en caso de esta repetido y ademas actualice el importe a abonar.
// El valor de los platos se encuentra en un archivo desordenado con los siguientes datos:
// ID de plato(50 platos) y precio unitario.

// 3-Programe la funcion cerrar mesa, que imprima el importe a abonar, el detalle de los pedidos y vacie la lista.
// 4- Haga la funcion que genere un listado con todos los ID de mesa y los importes a abonar de un mozo seleccionado.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct tipoPedido
{
    int ID_plato;
    int cantPlatos;
};

struct nodo
{
    tipoPedido info;
    nodo* sgte;
};

struct tipoComanda
{
    int ID_pedido;
    float importeTotal;
    int ID_mozo;
    nodo* listaPedidos;
};

struct tipoPlato
{
    int ID_Plato;
    float importe;
};

FILE* f = fopen("platos.dat", "rb+");
tipoComanda vectorMesas[30];

// Prototipo de funciones.
void cargarPlatos(FILE*, tipoPlato);
void agregarPedido(int, int, int, tipoComanda);

int main()
{
    

    system("PAUSE");
    return 0;
}

// Defincion de las funciones.
void cargarPlatos(FILE* f, tipoPlato vectorPlato[])
{
    int pos;
    tipoPlato registro;
    while(fread(&registro, sizeof(tipoPlato), 1, f))
    {
        pos = registro.ID_Plato-1;
        vectorPlato[pos] = registro;
    }
}

void agregarPedido(int ID_mesa, int ID_plato, int cantidad, tipoComanda vectorMesas[])
{
    tipoPedido x;
    nodo* puntero; // Variable para chequear si esta el plato.
    x.ID_plato = ID_plato;
    x.cantPlatos = 0;
    puntero = cargarSinRepetir(vectorMesas[ID_mesa-1].listaPedidos, x);

    // Actualizar la cantidad.
    puntero->info.cantPlatos += cantidad;
    // Actulizar importe total.
    vectorMesas[ID_mesa-1].importeTotal = vectorMesas[ID_mesa-1].importeTotal+cantidad*vectorPlatos[ID_plato-1].importe;

}