// Clase 3 virtual.

/*// Tipos de ciclos y operadores logicos.

#include <iostream> // Inclusion de biblioteca 
using namespace std; // Uso de espacio nombre estandar para poder usar cin y cout y endl sin tener que poner std::

int main() { // Encabezado de la fusion principal
   // Uso de distintos ciclos de repeticion
   // for(valor inicial; control; modificacion;)sentencia;
   // while(expresion)sentencia;
   // do{sentencia}expresion();
   
   // Dado un conjunto de valores enteros determinar cantidad de ceros, cantidad de positivos y cantidad de negativos utilizando distintas estructuras de repeticiones
 
   int valor; // declaramos la variable "valor" como un dato de tipo entero
   int ceros=0,negativos=0,positivos=0; // se inicilizan en 0 los tres contadores
   // = operador de asignacion, ++operador de incremento
   int i; // ariable que utilizaremos para las iteraciones
   // 1. Se dan una cantidad fija de valores.. dado diez valores
   for(i=0;i<10;i++) // ciclo que se repite 10 veces y toma valores de 0 a 9
   {
        cout<<"ingrese un valor: ";// mensaje que aparece por pantalla
        cin>>valor; // se ingresa por el teclado un numero que se le asigna a "valor"
        // para ver como es el valor respecto de 0 corresponde un analisis de caso
        if (valor==0)
        {
            ceros++; // si el valor es 0, el contador ceros se incrementa en 1
        }else 
        if(valor>0) // si el valor no es 0 queda por ver si es positivo o negativo 
        {
            positivos++;
        }else
        {
           negativos++;
        } 
        
   }//llave del fin del "for", debemos mostrar lo que calculamos.

   cout<<"\n la cantidad de ceros es: "<< ceros << endl;
   cout<<"\n la cantidad de positivos es: "<< positivos << endl;
   cout<<"\n la cantidad de negativos es: "<< negativos << endl;
   cin>> valor;
   
   return 0;//como la funcion main retorna un entero este es el punto de finalizacion 
}
*/

// Clase 4 virtual.

/*// Dado tres valores arbitrarios mayor, medio y menor desarrollar un programa que coloque mayor que mayor que los tres de menor al mas chico y el medio el del medio

#include <iostream>
using namespace std;

int main ()
{
    int mayor=4, medio=12, menor=14, auxiliar;

    // primero buscamos el mayor entre mayor y medio.
    if (medio > mayor)
    {
        auxiliar = mayor;
        mayor = medio;
        medio = auxiliar; // intercambio los valores de mayor y medio con el auxiliar.
    }

    // buscamos el mayor entre mayor y menor.
    if (menor > mayor)
    {
        auxiliar = mayor;
        mayor = menor;
        menor = auxiliar; // intercambio los valores de mayor y menor con el auxiliar
    }

    // buscamos el mayor entre medio y menor
    if (menor > medio)
    {
        auxiliar = medio;
        medio = menor;
        menor = auxiliar; // intercambiamos los valores de menor y medio con el auxiliar
    }

    cout << "El mayor es: " << mayor << ", El medio es: " << medio << ", El menor es: " << menor; cin >> mayor;
    
    return 0;
}
*/

/*// Programa que describe cual numero es mayor, mediano y menor:
#include <iostream>
using namespace std;

void intercambio (int&,int&); //Prototipo o firma de la funcion.

int main()
{
    int mayor, medio, menor;

    cout << "Ingrese un valor"; cin >>  mayor;
    cout << "Ingrese un valor"; cin >>  medio;
    cout << "Ingrese un valor"; cin >>  menor;

    intercambio(mayor, medio); //invoca la funcion con los valores mayor y medio.
    intercambio(mayor, menor);
    intercambio(medio, menor);
    cout << "El mayor es: " << mayor << ", El medio es: " << medio << ", El menor es: " << menor << endl;
    cin >> mayor; //linea de codigo para poder probarlo

    return 0;
}

//definicon de la función.

void intercambio(int& a, int& b) //encabezado de la funcion con dos parametros.
{
    int auxiliar; //variable local a la funcion
    if(b > a)
    {
        auxiliar = b;
        b = a;
        a = auxiliar;
    }
}
*/

/*// funcion que retorna un entero y recibe 2 parametros basados por valor:

#include <iostream>
using namespace std;
// prototipo de las funciones.
int suma1(int, int); //prototipo de la funcion con 2 datos de tipo entero basados por valor
void suma2(int, int, int&); // funcion que retorna un valor ausente y tiene 3 parametros, 2 pasados por valor y 1 por refere4ncia
int main()
{
    int x=10, y=15, r=4, s=6L, t, u;
    t=suma1 (x,y); // t recibe el valor de la funcion suma1 con los argumentos x e y.
    cout << t << endl;
    t=suma1 (3*2, suma1(5*8,4)); // funcion invocada con una extension y con una funcion (suma1).
    cout << t << endl;
    suma2 (5,suma1(3,4),t); // t es un argumento que se vincula con un parametro pasado por referencia
    cout << t;
    return 0;
}
// definicion de la funcion
int suma1 (int a, int b) // encabezado de la funcion.
{
    return a+b; // cuerpo de la funcion.
}

void suma2 (int a, int b, int& c)
{
    c = a+b; // el parametro c se vincula con el argumento t y lo modifica.
}
*/

/*// Clase 5 virtual: Desarrollar una funcion que da 3 valores enteros, retorne 1 si sus valores representan los lados de un triangulo y 0 en caso contrario.

#include <iostream>
using namespace std;

 // Pascale case EsTriangulo; camelcase esTriangulo.
int EsTriangulo(int,int,int);//El prototipo evalua 3 parametros pasados por valor.
int TipoTriangulo(int, int, int);// Recibe 3 parametros que representas segmentos que forman un triangulo.

int main () // Desarrollar un programa que dado un conjunto de ternas de valores distintas de 0, determine cuantas ternas forman triangulos equilateros, isoceles y escalenos y cuantas ternas no forman triangulos
{
    int a, b, c, equilateros=0, isoceles=0, escalenos=0, NoTerna=0, tipoT;
    cout << "\nIngrese un valor: "; cin >> a;
    cout << "\nIngrese un valor: "; cin >> b;
    cout << "\nIngrese un valor: "; cin >> c;

    // Conjunto de ternas mayores a 0:
    while(a>0 && b>0 && c>0)
    {
        if(EsTriangulo(a, b, c)==1)
    {
        tipoT = TipoTriangulo(a, b, c); 
        // tipoT=TipoTriangulo[<int>](a, b, c) se invoca la funcion con datos de tipo entero.
        // tpoT=TipoTriangulo (<float>)(x,y,z) se invoca la funcion con datos de tipo float.
    }else
    {
        NoTerna++;
    }

    if(tipoT==1)
    {
        equilateros++;
    }else if(tipoT==2)
    {
        isoceles++;
    }else
    {
        escalenos++;
    }
    cout << "\nIngrese un valor: "; cin >> a;
    cout << "\nIngrese un valor: "; cin >> b;
    cout << "\nIngrese un valor: "; cin >> c;

    }

    cout << "Ternas que no forman triangulo: " << NoTerna << endl;
    cout << "Ternas que forman triangulos equilateros: " << equilateros << endl;
    cout << "Ternas que forman triangulos isoceles: " << isoceles << endl;
    cout << "Ternas que forman triangulos escalenos: " << escalenos << endl;
    
    return 0;
}

// Definicion de la funcion.
// Esta funcion recibe valores mayores a 0.

int EsTriangulo(int L1, int L2, int L3)
{
    if(L1 < L2+L3 && L2 < L1+L3 && L3 < L1+L2)
    {
    return 1; // Si se cumple la condicion retorna 1.
    } else
    {
    return 0; // si no retorna 0.
    }
    // Otra forma seria:
    //    int EsTriangulo(int a, int b, int c)
    //    {
    //        return (L1 < L2+L3 && L2 < L1+L3 && L3 < L1+L2 ? 1:0)
    //    }
}
    int TipoTriangulo(int a, int b, int c)
    {
        // Retorna 1 si es equilatero, 2 si es isoseles y 3 si es escaleno.
        if(a==b && a==c)
        {
            return 1;
        }else if(a==b || a==c || b==c)
        {
            return 2;
        }else
        {
            return 3;
        }
    }

*/

/*// Generalizar la funcion para distintos tipos de datos
template<tipename T> int TipoTriangulo(T a, T b, T c)
    {
        // Retorna 1 si es equilatero, 2 si es isoseles y 3 si es escaleno.
        if(a==b && a==c)
        {
            return 1;
        }else if(a==b || a==c || b==c)
        {
            return 2;
        }else
        {
            return 3;
        }
    }
*/

/*// Clase 6 presencial: Funcion mayor.

#include <iostream>
using namespace std;

float funcion(float a, float b, float c);

float funcion(float a, float b, float c)
{
    float mayor = 0

    if(a>b && a>c)
    mayor = a;
    else if(b>a && b>c)
    mayor = b;
    else if(c>a && c>b)
    mayor = c;

return mayor;

}

int main ()
{
    float a, b, c, mayor;
    cout <<"Escriba el valor de las 3 variables a comparar: "; cin >> a >> b >> c;

    mayor = funcion(a, b, c)
    cout << mayor << endl;

    return 0;

}
*/

// Clase virtual: Vectores de registro.

#include <iostream>
#include <stdlib.h>
using namespace std;

    struct registro //declarar el tipo registro
    {
        int campo1;
        int campo2;
    };

    int busquedaBinaria(int x, registro v[], int n) // Retorna la posicion donde lo encuentra (si esta) o -1 si no esta. Recibe en x un valor a buscar. Recibe en v el vector con los datos. Recibe en n el tamaño logico del vector.
   {
    int primero = 0; // Indica la posicion del primer elemento.
    int ultimo = n-1; // Indica la posicion del ultimo elemento.
    int j; // El indice del elemento que buscamos.
    
    while(primero <= ultimo) // Si el primero supera al ultimo es que el dato no esta.
    {
        j = (primero + ultimo)/2; // Busca la mitad  con division de enteros.
        if(v[j].campo1 == x)
        {
            return j; // Si lo encuentra retorna su posicion.
        }else if(x > v[j].campo1)
            {
                primero = j+1; // Si el buscado es mayor, remplazamos el indice del primero.
            }else{
                ultimo = j-1; // 
            }
        }

        return -1;
    }


    int busquedaSecuencial(int x, registro v[], int n) // Retorna la posicion donde lo encuentra (si esta) o -1 si no esta. Recibe en x un valor a buscar. Recibe en v el vector con los datos. Recibe en n el tamaño logico del vector.
    {
        int j=0; // Para recorrer el vector comenzamos desde el principio.
        while(j<n && v[j].campo1 != x) // Verifica que halla datos y como es respecto al buscado.
        {
            j++; // Va a la siguiente posicion si corresponde.
        }

        if(j == n)
        {
            return -1; // Retorna -1 si no lo enncuentra.
        }
    
        return j; // En caso de encontrarlo, retorna en donde esta.
    }

int main()
{
    registro vector[5]; // decalaracion del vector de 5 registros
    int i, pos, buscado, n=5;

    // Carga secuencial del vector de registros:
    for(i=0; i<5; i++)
    {
        cout <<"Ingrese el valor del campo 1: "; cin >> vector[i].campo1;
        cout <<"Ingrese el valor del campo 2: "; cin >> vector[i].campo2;

    }

    // mostrar los datos del vector:
    for(i=0; i<5; i++)
    {
        cout << vector[i].campo1 << " " << vector[i].campo2 << endl;
    }

    // Busqueda lineal:
    cout <<"Ingrese el valor a buscar en busqueda secuencial. " << endl; cin >> buscado;
    pos = busquedaSecuencial(buscado,vector,n);
    if(busquedaSecuencial(buscado, vector, n) > -1)
    {
        cout <<"El valor buscado esta en la posicion: " << pos << endl;
    }else{
        cout <<"El valor: " << buscado <<" No esta en el vector." << endl; 
    }

    // Busqueda binaria.
    cout <<"Ingrese el valor a buscar en busqueda binaria. " << endl; cin >> buscado;
    pos=busquedaBinaria(buscado,vector,n);
    if(busquedaBinaria(buscado, vector, n) > -1)
    {
        cout <<"El valor buscado esta en la posicion: " << pos << endl;
    }else{
        cout <<"El valor: " << buscado <<" No esta en el vector." << endl; 
    }

    return 0;
}