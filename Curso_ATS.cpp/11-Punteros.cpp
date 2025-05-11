
// Punteros:
// Ejercico n°1: Declaracion de punteros.
// &n = direccion de memoria de n.
// *n = variable de la direccion de memoria de n.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n=20;
    cout <<"\nMostrando el valor de n y su direccion de memoria... " << endl;
    cout <<"Numero: " << n << endl; // Imprimimos el valor de n.
    cout <<"Direccion de memoria de n: " << &n << endl; // Imprimimos la direccion de memoria de n.

    int *dir_num = &n; // Guardamos la direccion de memoria de n en dir_num.
    cout <<"\nMostrando el valor de n y su direccion de memoria a traves de punteros... " << endl;
    cout <<"Numero: " << *dir_num << endl; // Imprimimos el valor de n.
    cout <<"Direccion de memoria de n: " << dir_num << endl; // Imprimimos la direccion de memoria de n.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercico n°2: Comprobar si un numero es par o impar, y señalar la posicion de memoria donde se esta guardando el numero.
// Utilizar punteros.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n, *dir_n; // Declaramos la variable n y el puntero dir_n.
    cout <<"\nDigite un numero: "; cin >> n; // Pedimos al usuario que digite un numero.

    dir_n = &n; // Guardamos la direccion de memoria de n en dir_n.

    if(*dir_n %2==0)
    {
        cout <<"\nEl numero " << *dir_n <<" es par. " << endl; // Si el numero es par, imprimimos el mensaje.
        cout <<"Direccion de memoria del numero: " << dir_n << endl; // Imprimimos la direccion de memoria del numero.
    }

    if(*dir_n %2!=0)
    {
        cout <<"\nEl numero " << *dir_n <<" es impar. " << endl; // Si el numero es impar, imprimimos el mensaje.
        cout <<"Direccion de memoria del numero: " << dir_n << endl; // Imprimimos la direccion de memoria del numero.
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercico n°3: Determinar si un numero es primo o no.
// Utilizar punteros y ademas indicar en que posicion de memoria se guardo el numero.
// numeros primos: solo son divisibles por 1 y por si mismo.
// 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, ...

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n, *dir_n, contador=0; // Declaramos la variable n, el puntero dir_n y el contador.
    cout <<"\nDigite un numero: "; cin >> n; // Pedimos al usuario que digite un numero.

    dir_n = &n; // Guardamos la direccion de memoria de n en dir_n.

    for(int i=1; i<=*dir_n; i++) // Recorremos desde 1 hasta el numero ingresado.
    {
        if(*dir_n % i==0) // Si el numero ingresado es divisible por i.
        {
            contador++; // Aumentamos el contador.
        }
    }

    if(contador==2) // Si el contador es igual a 2.
    {
        cout <<"\nEl numero " << *dir_n <<" es primo. " << endl; // Imprimimos el mensaje.
        cout <<"Direccion de memoria del numero: " << dir_n << endl; // Imprimimos la direccion de memoria del numero.
    }
    else
    {
        cout <<"\nEl numero " << *dir_n <<" no es primo. " << endl; // Imprimimos el mensaje.
        cout <<"Direccion de memoria del numero: " << dir_n << endl; // Imprimimos la direccion de memoria del numero.
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Correspondencia entre vectores y punteros.
// Ejercico n°4: 

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int vector[5] = {1,2,3,4,5};
    int *dir_vector;

    dir_vector = &vector[0]; // Guardamos la direccion de memoria del primer elemento del vector.

    cout <<"\nMostrando los elementos del vector atravez de punteros: " << endl;
    for(int i=0; i<5; i++)
    {
        cout <<"Posicion [" << i <<"] = " << *dir_vector++ << endl; // Mostramos los elementos del vector.
    }

    cout <<"\nSe muestra las posiciones de memoria de cada variable del vector... " << endl;
    for(int i=0; i<5; i++)
    {
        cout <<"De la posicion [" << i <<"]" << " La posicion de memoria es: " << dir_vector++ << endl; // Mostramos la direccion de memoria de los elementos del vector.
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercico n°5: Rellenar un array de 10 numeros, posteriormente utilizando punteros indicar cuales son numeros pares y su posicion en memoria.

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int numeros[10], *dir_numeros;

    cout <<"\nIngrese una variable en cada posicion de memoria... " << endl;
    for(int i=0; i<10; i++)
    {
        cout <<"Posicion [" << i <<"]: "; cin >> numeros[i];
    }

    dir_numeros = &numeros[0];

    cout <<"\nVerificando cuales de las variables son pares..." << endl;
    for(int i=0; i<10; i++)
    {
        if(*dir_numeros%2==0)
        {
            cout <<"\nEl numero " << *dir_numeros <<" es par." << endl;
            cout <<"Posicion [" << i <<"] en memoria: " << dir_numeros << endl;
        }
        
        dir_numeros++;
    }

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercico n°6: Rellenar un arreglo con n numeros, Posteriormete utilizando punteros determinar el menor elemento del arreglo.


#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int nElementos, numeros[10], *dir_numeros, menor=99999, pos=0;

    cout <<"\nIngrese la cantidad de elementos del vector: "; cin >> nElementos;

    cout <<"\nIngrese una variable en cada posicion de memoria... " << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout <<"Posicion [" << i <<"]: "; cin >> numeros[i];
    }

    dir_numeros = &numeros[0];

    cout <<"\nVerificando cual es la variable menor ingresada..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        if(*dir_numeros < menor)
        {
            menor = *dir_numeros;
            pos = i;
        }
        
        dir_numeros++;
    }

    cout <<"\nLa menor variable fue encontrada en la posicion [" << pos <<"]: " << menor << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Asignacion dinamica de vectores.

// new: Reserva el numero de bytes solicitado por la declaracion.
// delete: Libera un bloque de bytes reservado con anterioridad.

// Ejercico n°7: pedir al usuario n calificaciones y almacenarlos en un vector dinamico.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de las funciones.
void pedirNotas();
void mostrarNotas();

int nCalificaciones, *calificaciones;

int main()
{
    pedirNotas();
    mostrarNotas();

    delete[] calificaciones; // Liberando el espacio en bytes utilizados anteriormente.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirNotas()
{
    cout <<"\nIngrese la cantidad de calificaciones: "; cin >> nCalificaciones;
    calificaciones = new int[nCalificaciones]; // Creamos el vector sin desperdiciar memoria. ej calificacion[1000]

    for(int i=0; i<nCalificaciones; i++)
    {
        cout <<"Ingrese calificacion: "; cin >> calificaciones[i];
    }
}

void mostrarNotas()
{
    cout <<"\nProcesando calificaciones..." << endl;

    for(int i=0; i<nCalificaciones; i++)
    {
        cout <<"alumno [" << i+1 <<"]: " << calificaciones[i] << endl;
    }
}

// Transmision de direcciones.
// Ejercico n°8: Intercambiar el valor de 2 variables reales.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de las funciones.
void intercambio(float*, float*);

int main()
{
    float a, b;
    cout <<"\nIngrese el primer numero real: "; cin >> a;
    cout <<"Ingrese el segundo numero real: "; cin >> b;
    cout <<"\nEl primer numero es: " << a << endl;
    cout <<"El segundo numero es: " << b << endl;

    intercambio(&a, &b);

    cout <<"\nEl nuevo primer numero es: " << a << endl;
    cout <<"El nuevo segundo numero es: " << b << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void intercambio(float* n1, float* n2)
{
    float aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

// Transmicion de vectores.
// Ejercico n°9: Hallar el maximo elemento de un vector.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de las funciones.
int hallarMax(int*, int);

int main()
{
    const int nElementos = 5;
    int numeros[nElementos] = {1, 2, 3, 4, 5};
    
    cout <<"\nEl mayor numero del vector es: " << hallarMax(numeros, nElementos) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
int hallarMax(int*dir_vec, int nElementos)
{
    int max=0;


    for(int i=0; i<nElementos; i++)
    {
        if(*(dir_vec+i) > max)
        {
            max = *(dir_vec+i);
        }

        // dir_vec++;
    }

    return max;
}

// Ejercico n°10: Pedir al usuario n numeros, almacenarlos en un vector dinamico y posteriormente
// ordenar los numeros en orden ascendente y mostrarlos en pantalla.

#include<iostream>
#include<stdlib.h>

using namespace std;

int nElementos, *elemento;

// Prototipo de las funciones.
void pedirDatos();
void metodoBurbuja(int*, int);
void mostrarDatos();

int main()
{
    pedirDatos();
    metodoBurbuja(elemento, nElementos);
    mostrarDatos();

    delete [] elemento; // liberar la memoria utilizada para el vector dinamico.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nIngrese la cantidad de elementos que tendra el vector: "; cin >> nElementos;
    elemento = new int[nElementos];

    cout <<"\nIngrese los valores para cada posicion..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout <<"Posicion [" << i <<"]: "; cin >> *(elemento+i); // elemento[i];
    }

    cout <<"\nSe muestra el vector ingresado..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout << *(elemento+i) <<" | ";
    }
    
}

void metodoBurbuja(int* elemento, int nElementos)
{
    int aux=0;

    for(int i=0; i<nElementos; i++)
    {
        for(int j=0; j<nElementos; j++)
        {
            if(*(elemento+j) > *(elemento+j+1)) // if(elemento[j] > elemento[j+1])
            {
                aux = *(elemento+j);
                *(elemento+j) = *(elemento+j+1);
                *(elemento+j+1) = aux; 
            }
        }
    }
}

void mostrarDatos()
{
    cout <<"\nVector ordenado por metodo burbuja..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout << *(elemento+i) <<" | ";
    }
}

// Ejercico n°11: Realizar una funcion para almacenar n numeros en un vector dinamico.
// Posteriormente en otra funcion buscar un numero en particular.

#include<iostream>
#include<stdlib.h>

using namespace std;

int nElementos, *elemento, superior, inferior, mitad, dato, buscado;

// Prototipo de las funciones.
void pedirDatos();
void metodoBurbuja(int*, int);
void busquedaBinaria(int[], int, int, int, int, int); // Para la busqueda binaria el vector tiene que estar ordenado de manera ascendente.
void mostrarDatos();

int main()
{
    pedirDatos();
    metodoBurbuja(elemento, nElementos);
    mostrarDatos();
    busquedaBinaria(elemento, nElementos, inferior, superior, mitad, buscado);

    delete [] elemento; // liberar la memoria utilizada para el vector dinamico.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nIngrese la cantidad de elementos que tendra el vector: "; cin >> nElementos;
    elemento = new int[nElementos];

    cout <<"\nIngrese los valores para cada posicion..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout <<"Posicion [" << i <<"]: "; cin >> *(elemento+i); // elemento[i];
    }

    cout <<"\nSe muestra el vector ingresado..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout << *(elemento+i) <<" | ";
    }

    cout <<"\n\nAhora ingrese el elemento a buscar: "; cin >> buscado;
    
}

void metodoBurbuja(int* elemento, int nElementos)
{
    int aux=0;

    for(int i=0; i<nElementos; i++)
    {
        for(int j=0; j<nElementos; j++)
        {
            if(*(elemento+j) > *(elemento+j+1)) // if(elemento[j] > elemento[j+1])
            {
                aux = *(elemento+j);
                *(elemento+j) = *(elemento+j+1);
                *(elemento+j+1) = aux; 
            }
        }
    }
}

void mostrarDatos()
{
    cout <<"\nVector ordenado por metodo burbuja..." << endl;
    for(int i=0; i<nElementos; i++)
    {
        cout << *(elemento+i) <<" | ";
    }

}

void busquedaBinaria(int elemento[], int nElementos,  int inferior, int superior, int mitad, int buscado)
{
    inferior = 0; superior = nElementos;
    while(inferior <= superior)
    {
        mitad = (inferior+superior)/2;

        if(elemento[mitad] == buscado)
        {
            cout <<"\nSe encontro el elemento " << buscado <<" en la posicion [" << mitad <<"]" << endl;
            break;
        }
        if(elemento[mitad] > buscado)
        {
            superior = mitad;
            mitad = (inferior+superior)/2;
        }
        if(elemento[mitad] < buscado)
        {
            inferior = mitad;
            mitad = (inferior+superior)/2;
        }
    }
}

// Ejercico n°12: Pedir nombre al usuario y devolver el numero de vocales.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

char nombreUsuario[30];

// Prototipo de las funciones.
void pedirDatos();
int contandoVocales(char*);

int main()
{
    pedirDatos();
    cout <<"nEl numero de vocales del nombre es: " << contandoVocales(&nombreUsuario[0]) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nIngrese su nombre de usuario: "; cin.getline(nombreUsuario, 30, '\n');
    strupr(nombreUsuario); // transformando a mayuscula el nombre.
}

int contandoVocales(char* nombre)
{
    int cont=0;

    while(*nombre) // Mientras nombre no se nulo '\0'.
    {
        switch(*nombre)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': cont++;
        }

        nombre++;
    }

    return cont;
}

// Ejercico n°12: Pedir una cadena de caracteres al usuario, e indicar cuantas veces aparece la vocal a, e, i, o, u.
// Usar punteros.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

char cadenaUsuario[500], vocal_a=0, vocal_e=0, vocal_i=0, vocal_o=0, vocal_u=0;

// Prototipo de las funciones.
void pedirDatos();
int contandoVocales(char*);
void cantidadVocales(char*);
void mostrarDatos();

int main()
{
    pedirDatos();
    contandoVocales(&cadenaUsuario[0]);
    mostrarDatos();
    cantidadVocales(&cadenaUsuario[0]);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nEscriba su texto: "; cin.getline(cadenaUsuario, 500, '\n');
    strupr(cadenaUsuario); // transformando a mayuscula el texto
}

int contandoVocales(char* nombre)
{
    int cont=0;

    while(*nombre) // Mientras nombre no se nulo '\0'.
    {
        switch(*nombre)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': cont++;
        }

        nombre++;
    }

    return cont;
}

void mostrarDatos()
{
    cout <<"\nVerificando cantidad de vocales q contiene el nombre y su total..." << endl;
    cout <<"Cantidad total de vocales: " << contandoVocales(cadenaUsuario) << endl;
}

void cantidadVocales(char* nombre)
{
    int vocal_a=0, vocal_e=0, vocal_i=0, vocal_o=0, vocal_u=0;

/*
    while(*nombre) // Mientras nombre no se nulo '\0'.
    {
        switch(*nombre)
        {
            case 'A': vocal_a++; break;
            case 'E': vocal_e++; break;
            case 'I': vocal_i++; break;
            case 'O': vocal_o++; break;
            case 'U': vocal_u++; break;
        }

        nombre++;
    }
*/

    while(*nombre) // Mientras nombre no sea nulo '\0'.
    {
        if(*nombre=='A')
        vocal_a++;
        if(*nombre=='E')
        vocal_e++;
        if(*nombre=='I')
        vocal_i++;
        if(*nombre=='O')
        vocal_o++;
        if(*nombre=='U')
        vocal_u++;

        nombre++;
    }

    cout <<"\nVocales a: " << vocal_a;
    cout <<"\nVocales e: " << vocal_e;
    cout <<"\nVocales i: " << vocal_i;
    cout <<"\nVocales o: " << vocal_o;
    cout <<"\nVocales u: " << vocal_u << endl;
}

// Matrices dinamicos
// Ejercico n°13: Rellenar una matriz NxM y mostrar su contenido.

// **puntero_Matriz -> * puntero_fila -> [int] {int}
//                     * puntero_fila -> [int] {int}
//                     * puntero_fila -> [int] {int}

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int **puntero_Matriz, nFilas, nColumnas;

// Prototipo de las funciones.
void pedirDatos();
void mostrarMatriz(int**, int, int);

int main()
{
    pedirDatos();
    mostrarMatriz(puntero_Matriz, nFilas, nColumnas);

    // Liberando memoria...
    for(int i=0; i<nFilas; i++)
    {
        delete[] puntero_Matriz[i];
    }

    delete[] puntero_Matriz;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nIngrese la cantidad de filas de la matriz: "; cin >> nFilas;
    cout <<"Ingrese la cantidad de columnas de la matriz: "; cin >> nColumnas;

    puntero_Matriz = new int*[nFilas]; // Reservamos espacio en la memoria para las filas.

    for(int i=0; i<nFilas; i++)
    {
        puntero_Matriz[i] = new int[nColumnas]; // Reservamos espacio en la memoria para las columnas.
    }

    cout <<"\nIngrese los valores para cada posicion de la matriz. " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout <<"Posicion [" << i <<"][" << j <<"]: "; cin >> *(*(puntero_Matriz+i)+j); // puntero_Matriz[i][j]; 
        }
    }
}

void mostrarMatriz(int**, int, int)
{
    cout <<"\nProcesando el contenido de variables de la matriz..." << endl;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << *(*(puntero_Matriz+i)+j) << " | ";
        }
        cout <<"\n";
    }
}

// Ejercico n°14: Realize un programa que calcule la suma de dos matrices dinamicas.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int **p_matriz1, **p_matriz2, nFilas, nColumnas;

// Prototipo de funciones.
void pedirDatos();
void sumarMatricesP(int**, int**, int, int);
void mostrarMatrices(int**, int, int);

int main()
{
    pedirDatos();
    sumarMatricesP(p_matriz1, p_matriz2, nFilas, nColumnas);
    mostrarMatrices(p_matriz1, nFilas, nColumnas);

    // Liberando la memoria utilizada en matriz2:
    for(int i=0; i<nFilas; i++)
    {
        delete[] p_matriz2[i];
    }

    delete[] p_matriz2;

    // Liberando la memoria utilizada en matriz1:
    for(int i=0; i<nFilas; i++)
    {
        delete[] p_matriz1[i];
    }

    delete[] p_matriz1;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{   
    cout <<"\nIngrese: " << endl;
    cout <<"1- Cantidad de filas de las matrices: "; cin >> nFilas;
    cout <<"2- Cantidad de columnas de las matrices: "; cin >> nColumnas;

    p_matriz1 = new int*[nFilas];

    for(int i=0; i<nFilas; i++)
    {
        p_matriz1[i] = new int[nColumnas];
    }

    cout <<"\nIngrese las variables de la primera matriz: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout <<"Posicion [" << i <<"][" << j <<"]: "; cin >> *(*(p_matriz1+i)+j);
        }
    }

    p_matriz2 = new int*[nFilas];

    for(int i=0; i<nFilas; i++)
    {
        p_matriz2[i] = new int[nColumnas];
    }

    cout <<"\n\nIngrese las variables de la segunda matriz: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout <<"Posicion [" << i <<"][" << j <<"]: "; cin >> *(*(p_matriz2+i)+j);
        }
    }

}

void sumarMatricesP(int** p_matriz1, int** p_matriz2, int nFilas, int nColumnas)
{
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            *(*(p_matriz1+i)+j) += *(*(p_matriz2+i)+j);
        }
    }
}

void mostrarMatrices(int** p_matriz1, int nFilas, int nColumnas)
{
    cout <<"\nCalculando la suma de matrices..." << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << *(*(p_matriz1+i)+j) <<" | ";
        }

        cout <<"\n";
    }
}

// Ejercico n°15: Realice un programa lea una matriz dinamica de NxM y cree su matriz transpuesta.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int **p_matriz1, nFilas, nColumnas;

// Prototipo de funciones.
void pedirDatos();
void matrizTranspuesta(int**, int, int);

int main()
{
    pedirDatos();
    matrizTranspuesta(p_matriz1, nFilas, nColumnas);

    // Liberando la memoria utilizada en matriz1:
    for(int i=0; i<nFilas; i++)
    {
        delete[] p_matriz1[i];
    }

    delete[] p_matriz1;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{   
    cout <<"\nIngrese: " << endl;
    cout <<"1- Cantidad de filas de la matriz: "; cin >> nFilas;
    cout <<"2- Cantidad de columnas de la matriz: "; cin >> nColumnas;

    p_matriz1 = new int*[nFilas];

    for(int i=0; i<nFilas; i++)
    {
        p_matriz1[i] = new int[nColumnas];
    }

    cout <<"\nIngrese las variables de la matriz: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout <<"Posicion [" << i <<"][" << j <<"]: "; cin >> *(*(p_matriz1+i)+j);
        }
    }

}

void matrizTranspuesta(int** p_matriz1, int nFilas, int nColumnas)
{
    cout <<"\nMatriz ingresada: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << *(*(p_matriz1+i)+j) <<" | ";
        }

        cout <<"\n";
    }

    cout <<"\nMatriz transpuesta: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << *(*(p_matriz1+j)+i) <<" | ";
        }

        cout <<"\n";
    }
}

// Punteros a estructuras.
// Ejercico n°16: Realice una estructura tipo alumno utilizando punteros.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct alumno
{
    char nombre[30];
    int edad;
}al, *puntero_al = &al;

// prototipo de funciones.
void pedirDatos();
void datosAlumno(alumno*);

int main()
{
    pedirDatos();
    datosAlumno(puntero_al);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

void pedirDatos()
{
    cout <<"\nBienvenido alumno. \n\nIngrese sus datos: " << endl;
    cout <<"1- Nombre: "; cin.getline(puntero_al->nombre, 30, '\n');
    cout <<"2- Edad: "; cin >> puntero_al->edad; 
}

void datosAlumno(alumno* puntero_al)
{
    cout <<"\nDatos del alumno:" << endl;
    cout <<"Nombre: " << puntero_al->nombre << endl;
    cout <<"Edad: " << puntero_al->edad << endl;
}

// Ejercico n°17: Realizar una estructura llamada alumno, en la cual se tendran los campos:
// nombre | edad | promedio, pedir datos al usuario para 3 alumnos y comprobar cual de los 3 tinene el mejor promedio.
// Posteriormente imprimir los datos del alumno.
// Utilizar punteros a estructura.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct alumno
{
    char nombre[30];
    int edad;
    int promedio;
}al, *puntero_al = &al; // Estas variables se podrian poner en el main.

int *alumnos, nAlumnos;

// prototipo de funciones.
void pedirDatos();
void mejorPromedioAl(alumno*);

int main()
{
    pedirDatos();
    mejorPromedioAl(puntero_al);

    delete[] alumnos; // Liberamos espacio de la memoria.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void pedirDatos()
{
    cout <<"\nBienvenido. \n\nIngrese la cantidad de estudiantes: "; cin >> nAlumnos;
    alumnos = new int[nAlumnos];

    for(int i=0; i<nAlumnos; i++)
    {
        cin.ignore();
        cout <<"1- Nombre: "; cin.getline((puntero_al+i)->nombre, 30, '\n');
        cout <<"2- Edad: "; cin >> (puntero_al+i)->edad;
        cout <<"3- Promedio: "; cin >> (puntero_al+i)->promedio;
        cout <<"\n";
    }

}

void mejorPromedioAl(alumno* puntero_al)
{
    float mayor = 0.0;
    int pos=0;

    for(int i=0; i<nAlumnos; i++)
    {
        if((puntero_al+i)->promedio > mayor) // puntero_al[i].promedio
        {
            mayor = (puntero_al+i)->promedio; // Comprobar el mayor
            pos = i; // Guardar posicion del alumno
        }
    }

    cout <<"\nEl alumno con mejor promedio: " << endl;
    cout <<"Nombre: " << (puntero_al+pos)->nombre << endl;
    cout <<"Edad: " << (puntero_al+pos)->edad << endl;
    cout <<"Promedio: " << (puntero_al+pos)->promedio << endl << endl;
}

// Ejercico n°18: Defina una estructura que indicque el tiempo empleado por un ciclista en recorrer una etapa.
// La estructura debe tener tres campos: horas | minutos | segundos.
// Escriba un programa que dado 3 etapas calcule el tiempo total empleado en correr todas las etapas.

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct etapa
{
    int horas;
    int minutos;
    int segundos;
}etapas, *puntero_Etapas = &etapas;

int *seg, segTotal=0, *vueltas, cantVueltas;

// prototipo de funciones.
void pedirDatos();
void Tiempo_Total_Etapas(etapa*, int);

int main()
{
    pedirDatos();
    Tiempo_Total_Etapas(puntero_Etapas, segTotal);

    // Liberar memoria
    delete[] puntero_Etapas;
    delete[] seg;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de funciones.
void pedirDatos()
{
    cout <<"\nBienvenido competidor.\n\nIngrese la cantidad de vueltas que recorrio: "; cin >> cantVueltas;
    puntero_Etapas = new etapa[cantVueltas];
    vueltas = new int[cantVueltas];
    seg = new int[cantVueltas];

    cout <<"Ingrese el tiempo empleado en segundos de cada vuelta." << endl;
    for(int i=0; i<cantVueltas;i++)
    {
        cout <<"Vuelta [" << i+1 <<"]: "; cin >> *(seg+i);
        segTotal += *(seg+i);
    }

    cout <<"\nCalculando el tiempo empleado a recorrer cada vuelta..." << endl;
    for(int i=0; i<cantVueltas; i++)
    {
        (puntero_Etapas+i)->horas = *(seg+i)/3600; // 1 hora = 60 segundos * 60 minutos = 3600 segundos.
        *(seg+i) %= 3600; // Guardamos el residuo de la division en segTotal.
        (puntero_Etapas+i)->minutos = *(seg+i)/60; // 1 minuto = 60 segundos.
        (puntero_Etapas+i)->segundos = *(seg+i)%60; // Guardamos el residuo de la division en segundos.

        cout <<"Etapa " << i+1 <<": " << (puntero_Etapas+i)->horas <<":" <<(puntero_Etapas+i)->minutos <<":" << (puntero_Etapas+i)->segundos <<"hs." << endl;
    }

}

void Tiempo_Total_Etapas(etapa* puntero_Etapas, int segTotal)
{
    (puntero_Etapas)->horas = segTotal/3600; // 1 hora = 60 segundos * 60 minutos = 3600 segundos.
    segTotal %= 3600; // Guardamos el residuo de la division en segTotal.
    (puntero_Etapas)->minutos = segTotal/60; // 1 minuto = 60 segundos.
    (puntero_Etapas)->segundos = segTotal%60; // Guardamos el residuo de la division en segundos.

    cout <<"\nCantidad total de tiempo realizado " << (puntero_Etapas)->horas <<":" <<(puntero_Etapas)->minutos <<":" << (puntero_Etapas)->segundos <<"hs." << endl;
    cout <<"Horas: " << (puntero_Etapas)->horas <<"\nMinutos: " << (puntero_Etapas)->minutos <<"\nSegundos: " << (puntero_Etapas)->segundos << endl;
}