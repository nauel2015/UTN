
// Ordenamientos.
// Explicando el metodo burbuja: ¿Que es el metodo burbuja?

// Es un sencillo algortimo de reordenamiento. Funciona revisando cada elemento de la lista que va a ser ordenada
// con el siguiente, Intercambiandolos de posicion si estan en el orden equivocado.
// Ejemplo: [5|1|2|4|3] [1|5|2|4|3] [1|2|5|4|3] [1|2|4|5|3] [1|2|4|3|5] [1|2|3|4|5]

// Ejercicio n°1: Ordenamiento por Metodo burbuja.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main ()
{

    cout <<"\n\t!!Bienvenido a ordenamientos!!" <<endl;
    cout <<"\nSeleccione 1. Para el metodo de burbuja.";
    cout <<"\nSeleccione 2. Para el metodo de insercion.";
    cout <<"\nSeleccione 3. Para el metodo de seleccion.";
    cout <<"\nSeleccione 4. Para el metodo de buscqueda secuencial.";
    cout <<"\nSeleccione 5. Para el metodo de busqueda binaria.";

    int tipoOrdenamiento; cout <<"\n\nIngrese su opcion: "; cin >> tipoOrdenamiento;

    if(tipoOrdenamiento == 1)
    {
    cout <<"\n\tBienvenido al ordenamiento por metodo burbuja!! Este programa va a ordenar tus variables." << endl;

    int numeros[5];
    int aux;
    
    for(int i=0; i<5; i++)
    {
        cout <<"\nIngrese un numero entero para la posicion [" << i <<"]: "; cin >> numeros[i];
    }
    
    cout <<"\nEstos son tus numeros desordenados: " << endl;

    for(int i=0; i<5; i++)
    {
        cout << numeros[i] <<"|";
    }
    // Algoritmo del ordenamiento por metodo burbuja.
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(numeros[j] > numeros[j+1]) // Si la posicion j es mayor a la posicion j+1 intercambian de variables.
            {
                aux = numeros[j]; // Agrega j en aux.
                numeros[j] = numeros[j+1]; // Agrega j+1 en j.
                numeros[j+1] = aux; // Agrega aux a j+1.
            }
        }
    }

    cout <<"\n\nSe procede a mostrar los elementos ordenados de manera ascendente: " << endl;
    for(int i=0; i<5; i++)
    {
        cout << numeros[i] << "|";
    }

    cout <<"\n\nSe procede a mostrar los elementos ordenados de manera descendente: " << endl;
    for(int i=4; i>=0; i--)
    {
        cout << numeros[i] << "|";
    }

    }

// Explicando el metodo de ordenamiento por insercion.
// Puede usarse facilmente para ordenar un mazo de cartas enumeradas en forma arbitraria.
// Requiere O(n²) operaciones para ordenar una lista de n elementos

// Ejercicio n°2: Ordenamiento por Insercion.

    if(tipoOrdenamiento == 2)
    {
    cout <<"\n\tBienvenido al ordenamiento por metodo de insercion!!" << endl;

    int numeros[5];
    int i, pos, aux;

    for(int i=0; i<5; i++)
    {
        cout <<"\nIngrese un numero entero para la posicion [" << i <<"]: "; cin >> numeros[i];
    }
    
    cout <<"\nEstos son tus numeros desordenados: " << endl;

    for(int i=0; i<5; i++)
    {
        cout << numeros[i] <<"|";
    }
    // Algoritmo del ordenamientopor insercion.
    for(i=0; i<5; i++)
    {
        pos = i;
        aux = numeros[i];

        while((pos>0) && (numeros[pos-1] > aux))
        {
            numeros[pos] = numeros [pos-1];
            pos --;
        }

        numeros[pos] = aux;
    }

    cout <<"\n\nOrden ascendente: ";
    for(i=0; i<5; i++)
    {
        cout << numeros[i] <<"|";
    }
    
    cout <<"\n\nOrden descendente: ";
    for(i=4; i>=0; i--)
    {
        cout << numeros[i] <<"|";
    }

    }

// Explicando el metodo de ordenamiento por seleccion.

// Algoritmo que requiere O(n²) operaciones para ordenar una lista de n numeros.
// Su funcionamiento es el siguiente:

// 1- Buscar el minimo elemento de la lista.
// 2- Intercambiarlo con el primer elemento.
// 3- Buscar el minimo del resto de la lista.
// 4- intercambiarlo con el segundo.
// y asi sucesivamente.

// Ejercicio n°3: Ordenamiento por seleccion.

    if(tipoOrdenamiento == 3)
    {
    cout <<"\n\tBienvenido al metodo de ordenamiento por seleccion!!" << endl;

    int numeros[5];
    int i, j, aux, minimo;
    
    for(int i=0; i<5; i++)
    {
        cout <<"\nIngrese un numero entero para la posicion [" << i <<"]: "; cin >> numeros[i];
    }
    
    cout <<"\nEstos son tus numeros desordenados: " << endl;

    for(int i=0; i<5; i++)
    {
        cout << numeros[i] <<"|";
    }

    // Algoritmo del ordenamiento por seleccion.
    for(i=0; i<5; i++)
    {
        minimo = i;
        for(j=i+1; j<5; j++)
        {
            if(numeros[j] < numeros[minimo])
            {
                minimo = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[minimo];
        numeros[minimo] = aux;
    }

    cout <<"\n\nOrden ascendente: ";
    for(i=0; i<5; i++)
    {
        cout << numeros[i] <<"|";
    }
    
    cout <<"\n\nOrden descendente: ";
    for(i=4; i>=0; i--)
    {
        cout << numeros[i] <<"|";
    }

    }

// Ejercicio N°4: Metodo de ordenamineto por busqueda secuencial.

    if(tipoOrdenamiento == 4)
    {
    cout <<"\n\tBienvenido al metodo de ordenamiento por busqueda secuencial!!" << endl;
    int opcion;
    cout <<"\nSeleccione 1. Para ordenar numeros enteros. " << endl;
    cout <<"Seleccione 2. Para ordenar caracteres. " << endl;
    cout <<"\nSeleccione su opcion: "; cin >> opcion;

    if(opcion == 1)
    {
    int numeros[5];
    int i=0, dato;
    char flag = 'F';
    
    for(int i=0; i<5; i++)
    {
        cout <<"Ingrese un numero entero para la posicion [" << i << "]: "; cin >> numeros[i];
    }
    cout <<"\nIngrese el numero entero a buscar: "; cin >> dato;

    // Algoritmo del ordenamiento por busqueda secuencial de enteros.
    while((flag == 'F') && (i<5))
    {
        if(numeros[i] == dato)
        {
            flag = 'V';
        }
        i++;
    }

    if(flag == 'F')
    cout <<"\nEl numero a buscar no existe en el vector.";

    if(flag == 'V')
    cout <<"\nEl numero [" << dato <<"] fue encontrado en la posicion: " << i-1;
    }

    if(opcion == 2)
    {
    char letras[] = {'a','e','i','o','u'};
    int i=0;
    char flag = 'F', dato;

    cout <<"Ingrese la vocal a buscar: "; cin >> dato;

    // Algoritmo del ordenamiento por busqueda secuencial de caracteres.
    while((flag == 'F') && (i<5))
    {
        if(letras[i] == dato)
        {
            flag = 'V';
        }
        i++;
    }

    if(flag == 'F')
    cout <<"\nEl caracter a buscar no existe en el vector.";

    if(flag == 'V')
    cout <<"\nEl caracter [" << dato << "] fue encontrado en la posicion: " << i-1;
    }

    }

// Ejercicio N°5: Metodo de ordenamineto por busqueda binaria.

    if(tipoOrdenamiento == 5)
    {
    cout <<"\n\tBienvenido al metodo de ordenamiento por busqueda binaria. " << endl;
    
    // Para la busqueda binaria el vector tiene que estar ordenado de manera ascendente.
    int numeros[] = {1,2,3,4,5};
    int superior, inferior, mitad, dato;
    char flag = 'F';

    cout <<"\nIngrese el numero entero a buscar: "; cin >> dato;

    // Algoritmo de la busqueda binaria.
    inferior = 0; superior = 5;
    while(inferior <= superior)
    {
        mitad = (inferior+superior)/2;

        if(numeros[mitad] == dato)
        {
        flag = 'V';
        break; // Para detener el bucle ya que se encontro el entero que buscabamos.
        }
        if(numeros[mitad] > dato)
        {
            superior = mitad;
            mitad = (inferior+superior)/2;
        }
        if(numeros[mitad] < dato)
        {
            inferior = mitad;
            mitad = (inferior+superior)/2;
        }
    }

    if(flag == 'V')
    cout <<"\nEl numero [" << dato <<"] fue encontrado en la posicion: " << mitad;
    
    if(flag == 'F')
    cout <<"\nEl numero a buscar no existe en el vector.";
    }

    cout <<"\n\n";
    system("PAUSE");
    return 0;
}