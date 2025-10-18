
/* Sistema de Registro de Producción de una Fábrica de Sillas con Arrays.

Se le pide que haga un sistema donde la fábrica pueda registrar la producción de sillas.
Por cada silla se sabe su código, tipo de madera, fecha de producción, y el código de la línea de producción (De 1 a 10).
Por cada línea de producción sabemos su nombre y su capacidad máxima de producción diaria.

Sabemos que la fábrica puede producir un máximo de 500 sillas, y hay solo 10 líneas de producción.

1. Definí las estructuras necesarias para resolver el problema
2. Insertar líneas de producción**: Agregar líneas de producción con su nombre y capacidad máxima de producción diaria.
3. Insertar sillas**: Agregar sillas con su código, tipo de madera, fecha de producción y código de línea de producción.
4. Mostrar todos las sillas ordenadas por fecha de producción
5. Retornar la línea de producción con mayor capacidad: Identificar la línea de producción con la mayor capacidad de producción diaria.
6. Retornar la silla más reciente**: Identificar la silla producida más recientemente.
7. Retornar el día con más producción**: Determinar el día en que se produjo el mayor número de sillas.
8. Retornar la línea de producción con más sillas producidas**: Identificar la línea de producción con más sillas registradas.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Produccion
{
    int codigo_linea_de_produccion;
    char nombre[30];
    int capacidadMaxima; // (500/10) = 50
}produccionSilla[10];

struct Silla
{
    int codigo_silla;
    char tipoDeMadera[30];
    int fecha_de_produccion;
    int codigo_linea_de_produccion;
    Produccion datos;
}silla[500];


// Declaracion de las funciones.
void insertarLineas(Produccion produccion[], int &len, Produccion nuevaLinea, int pos);
void cargarLineas(Produccion produccion[], int &len);

void insertarSillas(Silla silla[], int &len, Silla nuevaSilla, int pos);
void cargarSillas(Silla silla[], int &len);

void ordenamientoBurbuja(Silla silla[], int len);
void sillasOrdenadasPorFechaProduccion(Silla silla[], int len);
Produccion lineaConMayorCapacidad(Produccion produccion[], int len);
Silla sillaMasReciente(Silla silla[], int len);
int diaConMasProduccion(Silla silla[], int len);
int lineaConMasSillas(Silla silla[], int len);
void cargarEnArchivo(Produccion produccion[], int len1, Silla silla[], int len2);

int main()
{
    int lenLineas = 0, lenSillas = 0, opcion;

    do{
        cout <<"\n\tSistema de Registro de Produccion de una Fabrica de Sillas. " << endl;
        cout <<"\nOpcion 1: Insertar lineas de produccion. ";
        cout <<"\nOpcion 2: Insertar sillas a producir. ";
        cout <<"\nOpcion 3: Mostrar las sillas por fecha de produccion. ";
        cout <<"\nOpcion 4: Mostrar linea con mayor capacidad de produccion. ";
        cout <<"\nOpcion 5: Mostrar la silla producida mas reciente. ";
        cout <<"\nOpcion 6: Mostrar el dia con mas produccion de sillas. ";
        cout <<"\nOpcion 7: Mostrar la lineas de produccion con mas sillas en produccion. ";
        cout <<"\nOpcion 8: Guardar datos. ";
        cout <<"\nOpcion 9: Salir. ";

        cout <<"\n\nIngrese su opcion: "; cin >> opcion;

        system("cls");

        switch(opcion)
        {
            case 1: cargarLineas(produccionSilla, lenLineas); break;
            case 2: cargarSillas(silla, lenSillas); break;
            case 3: sillasOrdenadasPorFechaProduccion(silla, lenSillas); break;
            case 4:
            {
                Produccion mayor = lineaConMayorCapacidad(produccionSilla, lenLineas);
                cout << "\nLinea con mayor capacidad: " << mayor.nombre << " (" << mayor.capacidadMaxima << " sillas/dia)\n";
                break;
            }

            case 5:
            {
                Silla reciente = sillaMasReciente(silla, lenSillas);
                cout << "\nSilla mas reciente: ";
                cout <<"\nCodigo: " << reciente.codigo_silla;
                cout <<"\nFecha: " << reciente.fecha_de_produccion;
                cout <<"\nTipo de madera: " << reciente.tipoDeMadera;
                cout <<"\nLinea de produccion: " << reciente.codigo_linea_de_produccion << endl;

                cout <<"\nVolviendo al menu... " << endl;
                system("PAUSE"); break;
            }
            case 6:
            {
                int dia = diaConMasProduccion(silla, lenSillas);
                cout << "\n\tDia con mayor produccion: " << dia << endl;

                cout <<"\nVolviendo al menu... " << endl;
                system("PAUSE"); break;
            }

            case 7:
            {
                int linea = lineaConMasSillas(silla, lenSillas);
                cout <<"\n\tLinea con mayor produccion de sillas: " << linea << endl;

                cout <<"\nVolviendo al menu... " << endl;
                system("PAUSE"); break;
            }

            case 8: cargarEnArchivo(produccionSilla, lenLineas, silla, lenSillas);
            system("PAUSE"); break;

            case 9: cout <<"\n\tHasta Luego!!! " << endl; break;

            default: cout << "Opcion invalida. Intente nuevamente. " << endl; system("PAUSE");
        }

    }while(opcion!=9);

    cout << "\n- Nahuel Richeri -\n";
    return 0;
}

// Definicion de las funciones.
void insertarLineas(Produccion produccion[], int &len, Produccion nuevaLinea, int pos)
{
    for(int i=len; i>pos; i--)
    {
        produccion[i] = produccion[i-1];
    }

    produccion[pos] = nuevaLinea;
    len++;
}

void cargarLineas(Produccion produccion[], int &len)
{
    int cantLineas;
    cout <<"\n\tRegistro de lineas de produccion. " << endl;
    cout <<"\nIngrese la cantidad de lineas de produccion a insertar: "; cin >> cantLineas;
    if(cantLineas+len<10)
    {
        for(int i=0; i<cantLineas; i++)
        {
            Produccion nuevaLinea;
            cout <<"\nCodigo de la linea de produccion: "; cin >> nuevaLinea.codigo_linea_de_produccion;
            cin.ignore();
            cout <<"Nombre de la linea de produccion: "; cin.getline(nuevaLinea.nombre, 30, '\n');
            cout <<"Capacidad maxima de produccion: "; cin >> nuevaLinea.capacidadMaxima;

            insertarLineas(produccion, len, nuevaLinea, i);

        }
    }else{
        cout <<"\nLa cantidad de lineas de produccion a agregar superan la capacidad de 10. " << endl;
        cout <<"Lineas de produccion trabajando: " << len <<"/10. " << endl;
        system("PAUSE");
    }

}

void insertarSillas(Silla silla[], int &len, Silla nuevaSilla, int pos)
{
    for(int i=len; i>pos; i--)
    {
        silla[i] = silla[i-1];
    }

    silla[pos] = nuevaSilla;
    len++;
}

void cargarSillas(Silla silla[], int &len)
{
    int cantSillas;
    cout <<"\n\tRegistro de sillas en produccion. " << endl;
    cout <<"\nIngrese la cantidad de sillas a insertar: "; cin >> cantSillas;

    if(cantSillas+len<500)
    {
        for(int i=0; i<cantSillas; i++)
        {
            Silla nuevaSilla;
            cout <<"\nCodigo de silla: "; cin >> nuevaSilla.codigo_silla;
            cin.ignore();
            cout <<"Tipo de madera: "; cin.getline(nuevaSilla.tipoDeMadera, 30, '\n');
            cout <<"Fecha de produccion (AAAAMMDD): "; cin >> nuevaSilla.fecha_de_produccion;
            do{
                cout <<"Codigo de la linea de produccion a asignar la tarea: "; cin >> nuevaSilla.codigo_linea_de_produccion;
                if(nuevaSilla.datos.capacidadMaxima>50)
                {
                    cout <<"\nSe llego a la capacidad maxima de silla en produccion para esa linea. Eliga otra: " << endl; 
                }

            }while(nuevaSilla.datos.capacidadMaxima>50);

            insertarSillas(silla, len, nuevaSilla, i);

        }

    }else{
        cout <<"\nLa cantidad de sillas a producir supera la disponibilidad de produccion. " << endl;
        cout <<"Sillas en produccion: " << len <<"/500. " << endl;
    }
}

void ordenamientoBurbuja(Silla silla[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(silla[j].fecha_de_produccion>silla[j+1].fecha_de_produccion)
            {
                Silla aux = silla[j];
                silla[j] = silla[j+1];
                silla[j+1] = aux;
            }
        }
    }
}

void sillasOrdenadasPorFechaProduccion(Silla silla[], int len)
{
    cout <<"\n\tSillas ordenas por fecha de produccion. " << endl;
    ordenamientoBurbuja(silla, len);

    for(int i=0; i<len; i++)
    {
        cout <<"\nFecha de produccion: " << silla[i].fecha_de_produccion << endl;
        cout <<"codigo de linea de produccion asignada: " << silla[i].codigo_linea_de_produccion << endl;
        cout <<"Codigo de silla: " << silla[i].codigo_silla << endl;
        cout <<"Tipo de madera: " << silla[i].tipoDeMadera << endl;
    }

    cout <<"\nVolviendo al menu... " << endl;
    system("PAUSE");
}

Produccion lineaConMayorCapacidad(Produccion produccion[], int len)
{
    Produccion mayor = produccion[0];

    for(int i=1; i<len; i++)
    {
        if(mayor.capacidadMaxima<produccion[i].capacidadMaxima)
        {
            mayor = produccion[i];
        }
    }

    return mayor;
}

Silla sillaMasReciente(Silla silla[], int len)
{
    Silla sillaReciente = silla[0];

    for(int i=1; i<len; i++)
    {
        if(sillaReciente.fecha_de_produccion>silla[i].fecha_de_produccion)
        {
            sillaReciente = silla[i];
        }
    }

    return sillaReciente;
}

int diaConMasProduccion(Silla silla[], int len)
{
    int sillasProducidas=0, diaMaximaProducion=0;

    for(int i=0; i<len; i++)
    {
        int contador=0;
        for(int j=0; j<len; j++)
        {
            if(silla[i].fecha_de_produccion==silla[j].fecha_de_produccion)
            {
                contador++;
            }
        }

        if(contador>sillasProducidas)
        {
            sillasProducidas = contador;
            diaMaximaProducion  = silla[i].fecha_de_produccion;
        }
    }

    return diaMaximaProducion;
}

int lineaConMasSillas(Silla silla[], int len)
{
    int lineaMaximoSillas=0, lineaMayor=0;

    for(int i=0; i<len; i++)
    {
        int contador=0;

        for(int j=0; j<len; j++)
        {
            if(silla[i].codigo_linea_de_produccion==silla[j].codigo_linea_de_produccion)
            {
                contador++;
            }
        }

        if(contador>lineaMaximoSillas)
        {
            lineaMaximoSillas = contador;
            lineaMayor = silla[i].codigo_linea_de_produccion;
        }
    }

    return lineaMayor;
}

void cargarEnArchivo(Produccion produccion[], int len1, Silla silla[], int len2)
{
    FILE* archivoFilasDeProducion = fopen("registro_fabrica_produccion.dat", "ab");
    if(archivoFilasDeProducion!=NULL)
    {
        fwrite(produccion, sizeof(Produccion), len1, archivoFilasDeProducion);
        fclose(archivoFilasDeProducion);
        cout << "Archivo de filas de produccion creado exitosamente." << endl;
    }else{
        cout << "No se pudo crear el archivo de filas de produccion." << endl;
    }

    FILE* archivoSillas = fopen("registro_fabrica_sillas.dat", "ab");
    if(archivoSillas!=NULL)
    {
        fwrite(silla, sizeof(Silla), len2, archivoSillas);
        fclose(archivoSillas);
        cout << "Archivo de sillas creado exitosamente." << endl;
    }else{
        cout << "No se pudo crear el archivo de sillas." << endl;
    }
}