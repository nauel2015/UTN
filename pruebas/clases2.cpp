
// Ejercicio n°7: 
// Dadas 20 regionales y 10 carreras de la utn y un archivo con los legajos de los alumnos de todas la facultades con los siguientes datos:
// IDRegional | numericos [20] | IDCarreras | numericos [10] | num.legajo 

// Se solicita 
// 1- Un listado de los legajos ordenado por regional, carrera, legajo
// 2- Un listado de los legajos ordenado por carrera, regional, legajo.
// En ambos casos mostrar antes de listar los alumnos la cantidad total.



#include<iostream>
#include<stdlib.h>

using namespace std;

struct NodoCliente // Nodo porque es una lista.
{
    int legajo;
    NodoCliente* sgte;
};

// Prototipo de las funciones.
NodoCliente* insertarOrdenado(NodoCliente*& lista, int legajo);
int pop(NodoCliente*&, lista);

struct tipoRegistro
{
    int regional;
    int carrera;
    int legajo;
};

struct tipoMatriz
{
    int cantAlumnos;
    NodoCliente* lista;
};

int main()
{
    int i, j;
    tipoRegistro r;
    int legajo;
    NodoCliente* aux;
    tipoMatriz matriz[20][10]; // 20 Regionales, 10 Carreras.
    FILE* f = fopen("universidad.dat", "rb+");


    // Inicializar la matriz.
    for(i=0; i<20; i++)
    {
        for(j=0; j<10; i++)
        {
            matriz[i][j].cantAlumnos=0;
            matriz[i][j].lista=NULL;
        }
    }

    while(fread(&r, sizeof(r), 1, f))
    {
        i = r.regional-1;
        j = r.carrera-1;
        matriz[i][j].cantAlumnos++;
        legajo = r.legajo;
        insertarOrdenado(matriz[i][j].lista, legajo);
    }

    // Mostrar por regional, carrera, legajo.
    // Tener en cuenta que no tenemos que eliminar el nodo en esta primera pasada.

    for(i=0; i<20; i++) // Recorre las regionales.
    {
        for(j=0; j<10; j++) // Recorre las carreras.
        {
            aux = matriz[i][j].lista; // Un punteroa aux para recorrer la lista porque no debemos eliminar los nodos. 

            while(aux != NULL) // Recorre los legajos.
            {
                cout << aux->legajo << endl;
                aux = aux->sgte
            }
        }
    }

    // Mostrar por carrera, regional, legajo (Es decir, recorrer por columna).
    // En este caso, vamos a sacar el nodoo porque no lo vamos a necesitar mas.

    for(j=0; j<10; j++)
    {
        for(i=0; i<20; i++)
        {
            while(matriz[i][j].lista != NULL)
            {
                legajo = pop(matriz[i][j].lista); // En este caso, pop hace avanzar el conteo.
                cout << legajo << endl;
            }
        }
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
