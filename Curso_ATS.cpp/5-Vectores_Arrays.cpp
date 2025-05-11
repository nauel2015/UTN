
// Conceptos de arrays/vectores (Unidimensionales).

Un vector o arrays unidimensional es un tipo de dato que almacena una secuencia de datos del mismo tipo.
Los elementos de un vector se almacenan en zonas contiguas de memoria y se puede acceder a ellos de manera directa mediate un indice o posicion.

// Para definir un vector se utiliza:

tipo vector[tamaño de elementos];
Ejemlos: int numero[10]; char letras[5]; float reales[15];

// Iniciacion de un vector en su definicion.

int numero[] = {1,4,6,7,3}; // Almacena los enteros en el vector.
numero[0] = 1;
numero[1] = 4;
numero[2] = 6;
numero[3] = 7;
numero[4] = 3;

char letra[] = {'a','e','i','o','u'}; // Almacena los enteros en el vector.
letra[0] = 'a';
letra[1] = 'e';
letra[2] = 'i';
letra[3] = 'o';
letra[4] = 'u';



// Ejercicio 1: Programa que define un vector de numeros y calcula la suma de sus elementos.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al programa que define un vector de numeros y calcula la suma de sus elementos." << endl;
    int numeros[5] = {1,2,3,4,5};
    int suma=0;

    for(int i=0; i<5; i++)
    {
        suma = suma + numeros[i];
    }

    cout <<"\nLa suma de los elementos del vector es: " << suma << endl;

    system("pause");
    return 0;

}


// Ejercicio 2: Programa que define un vector de numeros y calcula la multiplicacion acumulada de sus elementos.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que define un vector de numeros y calcula la multiplicacion acumulada de sus elementos." << endl;
    int numeros[] = {1,2,3,4,5};
    int multiplicacion=1;

    for(int i=0; i<5; i++)
    {
        multiplicacion = multiplicacion * numeros[i];
    }

    cout <<"\nLa multiplicacion acumulada de los elementos del vector es: " << multiplicacion << endl;

    system("pause");
    return 0;

}


// Ejercicio 3: Programa que lee un vector de numeros y muestra los numeros del vector con sus Posiciones de memoria.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{   cout <<"\n\tBienvenido al Programa que lee un vector de numeros y muestra los numeros del vector con sus Posiciones de memoria." << endl;
    int numeros[100], elementos;

    cout <<"\nIngrese la cantidad de elementos que va a contener el vector: "; cin >> elementos;

    for(int i=0; i<elementos; i++)
    {
        cout <<"\nIngrese un numero: "; cin >> numeros[i]; // guardando todos los elementos del vector en memoria.
    }

    for(int i=0; i<elementos; i++)
    {
        cout << "La posicion de memoria [" << i << "] = |" << numeros[i] <<"|" << endl;
    }

    system("pause");
    return 0;

}


// Ejercicio 4: Programa que lee un vector de numeros y muestra los numeros del vector con sus Posiciones de memoria inversos.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{   cout <<"\n\tBienvenido al Programa que lee un vector de numeros y muestra los numeros del vector con sus indices/Posiciones de memoria asociados inversos." << endl;
    int numeros[100], elementos;

    cout <<"\nIngrese la cantidad de elementos que va a contener el vector: "; cin >> elementos;

    for(int i=0; i<elementos; i++)
    {
        cout <<"\nIngrese un numero: "; cin >> numeros[i]; // guardando todos los elementos del vector en memoria.
    }

    for(int i=elementos-1; i>=0; i--)
    {
        cout << "La posicion de memoria [" << i << "] = |" << numeros[i] <<"|" << endl;
    }

    system("pause");
    return 0;

}


// Ejercicio 5: Programa que lee un vector de numeros enteros y determina el mayor elemento del vector.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que lee un vector de numeros enteros y determina el mayor elemento del vector." << endl;
    int numeros[100], elementos, mayor=0;

    cout <<"\nIngrese la cantidad de elementos que contendra el vector: "; cin >> elementos;

    for(int i=0; i<elementos; i++)
    {
        cout << "Para la siguiente posicion de memoria[" << i <<"] Ingrese un numero: "; cin >> numeros[i];

    if(numeros[i] > mayor)
    {
        mayor = numeros[i];
    }

    }

    cout <<"\nEl mayor elemento dentro del vector es el numero: " << mayor << endl;

    system("pause");
    return 0;
}

// Ejercicio 6: Programa que define un vector de numeros y calcula si existe algun elemento en el vector cuyo valor es equivalente a la suma del resto de elementos.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que define un vector de numeros y calcula si existe algun elemento en el vector cuyo valor es equivalente a la suma del resto de elementos." << endl;
    int numeros[100], elementos, defecto=0, suma=0;

    cout <<"\nIngrese la cantidad de elementos que contendra el vector: "; cin >> elementos;

    for(int i=0; i<elementos; i++)
    {
        cout << "Para la siguiente posicion de memoria [" << i <<"] Ingrese un numero: "; cin >> numeros[i];

        suma = suma + numeros[i];
    }

    for(int i=0; i<elementos; i++) // Buscar si hay algún número que sea igual a la suma de todos los demás
    {
        if(suma-numeros[i] == numeros[i]) // Se verifica si el número actual numeros[i] es igual a la suma de los demás números
        {   
            // Si se cumple la condición, se imprime un mensaje
            cout <<"\nEl numero " << numeros[i] <<" es quivalente a la suma del resto de los numeros" << endl; 
            defecto = defecto + 1;
        }
    }

    if(defecto == 0)
    {
        cout <<"\nNingun numero es equivalente a la suma del resto." << endl;
    }

    system("pause");
    return 0;
}


// Ejercicio 7: Programa que define dos vectores de caracteres y despues almacena el contenido de ambos en un nuevo vector.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que define dos vectores de caracteres y despues almacena el contenido de ambos en un nuevo vector." << endl;
    char nombre[] = {'N','a','h','u','e','l',' '};
    char apellido[] = {'R','i','c','h','e','r','i'};
    char nombreApellido[13];

    for(int i=0; i<7; i++)
    {
        nombreApellido[i] = nombre[i];
    }

    for(int i=7; i<14; i++)
    {
        nombreApellido[i] = apellido[i-7];
    }

    cout <<"\nla suma de los vectores da como resultado: " << endl;

    for(int i=0; i<14; i++)
    {
        cout << nombreApellido[i];
    }

    cout <<"\n\n";

    system("pause");
    return 0;
}


// Ejercicio 8: Programa que lee 5 numeros de un vector y los copia a otro vector multiplicados por 2.

#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que lee n elementos de un vector y los copia a otro vector multiplicados por 2." << endl;
    int numeros[100], copia[100], elementos, multiplicacion;

    cout <<"\nIngrese la cantidad de elementos que contendra el vector: "; cin >> elementos;
    cout <<"\nIngrese el valor de la multiplicacion para los elementos del vector: "; cin >> multiplicacion;
    cout << endl;

    for(int i=0; i<elementos; i++)
    {
        cout << "Para la siguiente posicion de memoria [" << i <<"] Ingrese un numero: "; cin >> numeros[i];

        copia[i] = numeros[i]*multiplicacion;
    }

    for(int i=0; i<elementos; i++)
    {   
        cout <<"\nLa posicion de memoria ["<< i <<"] = " << numeros[i] << endl;
		cout<<"Multiplicado por "<< multiplicacion <<" = " << copia[i] << endl;
    }

    cout <<"\n";

    system("pause");
    return 0;
}
