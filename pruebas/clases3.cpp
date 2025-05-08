
// archivo de ventas de n sucursales, con los siguientes datos:
// nombre de sucursal, mes de venta(1 año), cantidad unidades, monto vendido en el mes.
// No se sabe cuantos datos hay de cada sucursal.
// Listado por sucursal de todas las cantidades , solo aquellas que tengan ventas , con un total general.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct infoLS
{
	int mesVta;
	int unidades;
	int importe;
};
struct nodoLS
{
	infoLS info;
	nodoLS* sgte;
};
struct infoLP
{
  char nombreSuc[50+1];
  int totalGral=0;
  nodoLS* listaSec;
};
struct nodoLP
{
	infoLP info;
	nodoLP* sgte;
};

// Prototipo de las funciones.
void cargarEstructura(FILE*,nodoLP*);
void mostrarDatos(nodoLP*);

int main()
{
    

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
nodoLS* insertarOrdenado(nodoLS*,infoLS); //inserta ordenado por el campo...
void cargarEstructura(FILE* archivo,nodoLP* lista)
{
	archivo auxArch;
	nodoLP* auxNodoLP;
	infoLP auxInfoLP;
	infoLS auxInfoLS;

	while(fread(&auxArch,sizeof(archivo),1,archivo))
	{
		strcpy(auxInfoLP.nombreSuc,auxArch.nombreSuc);
		auxInfoLP.totalGral=0;
		auxInfoLP.listaSec = NULL;
		
		auxNodoLP = insertarSinRepetir(lista,auxInfoLP);
		
		auxNodoLP->info.totalGral+=auxArch.importe;
		
		//arma struct de la ls
		auxIn
		auxInfoLS.importe = auxArch.importe;
		auxInfoLS.mesVta = auxArch.mesVta;
		auxInfoLS.unidades = auxArch.unidades;
		//de la secundaria
		insertarOrdenado(auxNodoLP->info.listaSec,auxInfoLS);
	}
}

void mostrarDatos(nodoLP* lista)
{
	nodoLP* auxl=lista;
	nodoLS auxls;

	while(auxl!=NULL)
	{
		cout << " sucursal:" << auxl->info.nombreSuc;
		cout << " total gral:" << auxl->info.totalGral;
		auxls =  auxl->info.listaSec;
		while(auxls!=NULL){
			...
		}
		auxl=auxl->sgte;
	}
}
