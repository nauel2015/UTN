
// Explicando que es una funcion:
// Una funcion realiza una tarea concreta y puede ser diseñada, implementada y depurada de manera independiente al resto de codigo.
// La sintaxis basica para la definicion de una funcion:
// Tipo(int, char, float, etc)

tipo nombre(tipo variable1, tipo variable2, tipo variable3)
{
    // Conjunto de instrucciones.
}

// Otros ejemplos:

int numMax(int x, int y);
double intercambio(double x, double y);
void desplegar(float x, float y);

// Ejercicio n°1: Encontrar el mayor de 2 numeros.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

// Prototipo de la Funcion:
int encontrarMayor(int a, int b);

int main()
{ 
    int x, y;
    // int mayor;
    cout <<"ingrese 2 numeros: "; cin >> x >> y;

    // mayor = encontrarMayor(x,y);

    cout <<"El mayor de los 2 numeros es: " << encontrarMayor(x,y) << endl;
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la Funcion:
int encontrarMayor(int a, int b)
{
    int numeroMayor;

    if(a>b)
    {
        numeroMayor = a;
    }else{
        numeroMayor = b;
    }

    return numeroMayor;
}

// Ejercicio n°2: Saca el valor absoluto de un numero.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

// prototipo de la Funcion.
// Plantilla de Funcion: Realizamos un tipo de dato general.

template <class tipoD> // Creamos un tipo de dato general llamado tipoD.
void mostrarAbsoluto(tipoD absoluto);

int main()
{ 
    int a = 5;
    float b = 34.56;
    double c = 23342.34345;

    mostrarAbsoluto(a);
    mostrarAbsoluto(b);
    mostrarAbsoluto(c);
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

template <class tipoD>
void mostrarAbsoluto(tipoD absoluto)
{
    if(absoluto < 0)
    absoluto *= -1;

    cout <<"El valor absoluto del numero es: " << absoluto << endl;

}

// Ejercicio n°3: Escriba una funcion llamada multiplicacion () que acepte dos numeros en punto flotante como parametros.
// Luego que multiplique estos dos numeros y muestre el resultado.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

// Prototipo de las Funciones.
void pedirDatos(); // No tiene parametros ya que solo voy a pedir datos al usuario.
void multiplicacion(float a, float b); // Utilizamos tipo void en la funcion ya que nos piden que esta sea la que despligue el resultado.
// Si nos pidieran que retornara algo, pondriamos en este caso: float multiplicacion(float a, float b);

float a, b; // Variables globales

int main()
{ 
    pedirDatos();
    multiplicacion(a,b);
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void pedirDatos()
{
    cout <<"\nIngrese los numeros a multiplicar: "; cin >> a >> b;
}

void multiplicacion(float a, float b)
{
    float multiplicar = a*b;

    cout <<"\nLa multiplicacion es: " << multiplicar << endl;
}

// Ejercicio n°3: Escriba una funcion llamada alCuadrado () que calcule el cuadrado del valor que se le transmite y despliegue el resultado.
// La funcion debera ser capaz de elevar al cuadrado numeros flotantes.

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

// Prototipo de las Funciones.
void alCuadrado(float a);

int main()
{ 
    float a;
    alCuadrado(a);
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.

void alCuadrado(float a)
{
    cout <<"\nIngrese el numero que se elevara al cuadrado: "; cin >> a;
    float cuadrado = pow(a,2); // cuadrado = a*a;

    cout <<"\nEl cuadrado del numero es: " << cuadrado << endl;
}

// Ejercicio n°4: Escriba una funcion nombrada funPotencia():
// que pida un numero entero al usuario, luego otro entero positivo para utilizarlo de exponente y mostrar asi el resultado.
// El numero entero positivo debera ser el segundo valor transmitido a la funcion.

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

// Prototipo de las Funciones.
void funPotencia(int a, int b);

int main()
{ 
    int numero, exponente;

    funPotencia(numero, exponente);
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.

void funPotencia(int numero, int exponente)
{
    cout <<"\nIngrese un numero: "; cin >> numero;
    cout <<"ingrese el exponente: "; cin >> exponente;

    long resultado=1;

    resultado = pow(numero, exponente);
    cout <<"\nEl resultado es: " << resultado << endl;
}

// Ejercicio n°5: Escriba una plantilla de funcion llamada despliegue():
// Tiene que desplegar el valor del argumento unico que se le transmite cunado es invocada la funcion.

#include<iostream>
#include<stdlib.h>

using namespace std;

template <class tipoD>
void despliegue(tipoD dato);

int main()
{
    int dato1 = 5;
    float dato2 = 34.34;
    double dato3 = 324232;
    long dato4 = 878675567;
    char dato5 = 'F';

    despliegue(dato1);
    despliegue(dato2);
    despliegue(dato3);
    despliegue(dato4);
    despliegue(dato5);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

template <class tipoD>
void despliegue(tipoD dato)
{
    cout <<"\nEl dato ingresado es: " << dato;
}

// Ejercicio n°6: Escriba una plantilla de funcion llamada maximo():
// Que devuelva el valor maximo de tres argumentos que se transmitan a la funcion cuando sea llamada.
// Suponga que los tres argumentos seran del mismo tipo de datos

#include<iostream>
#include<stdlib.h>

using namespace std;

template <class tipoD>
void maximo(tipoD argumento1, tipoD argumento2, tipoD argumento3);

int main()
{
    int a=8, b=9, c=5;
    float d=23.56, e=76.35, f=454.56;

    maximo(a, b, c);
    maximo(d, e, f);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

template <class tipoD>
void maximo(tipoD argumento1, tipoD argumento2, tipoD argumento3)
{
    if((argumento1 > argumento2) && (argumento1 > argumento3))
    cout <<"\nEl mayor de los argumentos es: " << argumento1;

    if((argumento2 > argumento3) && (argumento2 > argumento3))
    cout <<"\nEl mayor de los argumentos es: " << argumento2;

    if((argumento3 > argumento1) && (argumento3 > argumento2))
    cout <<"\nEl mayor de los argumentos es: " << argumento3;
}

// Paso de parametros por referencia (&).
// El paso por referencia lo que hace es pasarle la direccion de memoria donde esta almacenada el valor.
// Ejercicio n°7:


#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void valNuevos(int&, int&); // Parametros pasados por referencia.

int main()
{
    int a, b;

    valNuevos(a, b);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void valNuevos(int& a, int& b) // Al pasarse por referencia, Cuando el programa llama a la funcion, esta busca la posicion de memoria de las variables.
{
    cout <<"\nIngrese 2 numeros:"; cin >> a >> b;

    // Imprime el valor que encuentra en las posiciones de memoria de las variables.
    cout <<"El primer valor ingresado es: " << a << endl;
    cout <<"El segundo valor ingresado es: " << b << endl;

    // Se les asigna un nuevo valor a las posiciones de memoria de las variables.
    a=44; b=55;
    cout <<"El nuevo primer valor es: " << a << endl;
    cout <<"El nuevo segundo valor es: " << b << endl;
}

// Ejercico n°8: Devolver valores multiples.
// Sumas, restar, multiplicar y dividir 2 numeros.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void calculadora(int, int, int&, int&, int&, float&); // Paso por referencia.

int main()
{
    int a, b, suma=0, resta=0, producto=0;
    float division=0;

    calculadora(a, b, suma, resta, producto, division); // Calculamos los valores.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

void calculadora(int a, int b, int& suma, int& resta, int& producto, float& division) // Paso por referencia.
{
    cout <<"Ingrese 2 numeros: "; cin >> a >> b;

    suma = a+b;
    resta = a-b;
    producto = a*b;
    division = a/b;

    cout <<"La suma es: " << suma << endl;
    cout <<"La resta es: " << resta << endl;
    cout <<"El producto es: " << producto << endl;
    cout <<"La division es: " << division << endl;
}

// Ejercico n°9: intercambiar el valor de 2 variables utilizando paso de parametros por referencia.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void intercambio(int&, int&); // Paso de parametros por referencia.

int main()
{
    int a, b;
    intercambio(a, b);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.

void intercambio(int& a, int& b) // Paso de parametros por referencia.
{
    cout <<"\nIngrese el valor de a: "; cin >> a;
    cout <<"Ingrese el valor de b: "; cin >> b;

    cout <<"\nEl valor de a es: " << a << endl;
    cout <<"El valor de b es: " << b << endl;

    int aux = a;
    a = b;
    b = aux;

    cout <<"\nEl nuevo valor de a es: " << a << endl;
    cout <<"El nuevo valor de b es: " << b << endl;
}

// Ejercico n°10: Escriba una funcion nombrada cambio() que tenga lo siguiente:
// 1- Un parametro en numero entero.
// 2- Seis parametros de referencia en numero entero nombrados: cien, cincuenta, veinte, diez, cinco y uno, respectivamente.

// La funcion tiene que considerar:
// 1- El valor entero transmitido como una cantidad en dolares. 
// 2- Convertir el valor en el numero menor de billetes equivalentes.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void cambio(int, int&, int&, int&, int&, int&, int&);

int main()
{
    int dolares, cien=0, cincuenta=0, veinte=0, diez=0, cinco=0, uno=0;

    cambio(dolares, cien, cincuenta, veinte, diez, cinco, uno);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void cambio(int dolares, int& cien, int& cincuenta, int& veinte, int& diez, int& cinco, int& uno)
{
    cout <<"\nIngrese la cantidad de dolares: "; cin >> dolares;

    // Ingreso 33458 dolares.

    cien = dolares/100; // Realiza la division y guarda el cociente. // 33458/100 = 334.58
    dolares %= 100; // Realiza el modulo y guarda el residuo. // 33458%100 = 58

    cincuenta = dolares/50; // Realiza la division y guarda el cociente. // 58/50 = 1.16
    dolares %= 50; // Realiza el modulo y guarda el residuo. // 58%50 = 8

    veinte = dolares/20; // Realiza la division y guarda el cociente. // 8/20 = 0.4
    dolares %= 20; // Realiza el modulo y guarda el residuo. // 8%20 = 8

    diez = dolares/10; // Realiza la division y guarda el cociente. // 8/10 = 0.8
    dolares %= 10; // Realiza el modulo y guarda el residuo. // 8%10 = 8

    cinco = dolares/5; // Realiza la division y guarda el cociente. // 8/5 = 1.6
    dolares %= 5; // Realiza el modulo y guarda el residuo. // 8%5 = 3

    uno = dolares; // 3

    cout <<"\nLa cantidad de billetes minima a utilizar seria: " << endl;
    cout <<"\nBilletes de $100 dolares: " << cien <<" en total. " << endl;
    cout <<"Billetes de $50 dolares: " << cincuenta <<" en total. " << endl;
    cout <<"Billetes de $20 dolares: " << veinte <<" en total. " << endl;
    cout <<"Billetes de $10 dolares: " << diez <<" en total. " << endl;
    cout <<"Billetes de $5 dolares: " << cinco <<" en total. " << endl;
    cout <<"Billetes de $1 dolar: " << uno <<" en total. " << endl;
}

// Ejercico n°11:  Escriba una funcion nombrada tiempo() que tenga:
// 1- Un parametro en numero entero llamado totalSeg.
// 2- Tres parametros de referencia nombrados: horas, minutos y segundos.
// La funcion es convertir el numero de segundos transmitido por el usuario en un numero equivalente de horas, minutos y segundos.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void tiempo(int, int&, int&, int&);

int main()
{
    int segTotal, hs, min, seg;

    tiempo(segTotal, hs, min, seg);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void tiempo(int segTotal, int& hs, int& min, int& seg)
{
    cout <<"\nIngrese la cantidad de segundos: "; cin >> segTotal;

    hs = segTotal/3600; // 1 hora = 60 segundos * 60 minutos = 3600 segundos.
    segTotal %= 3600; // Guardamos el residuo de la division en segTotal
    min = segTotal/60; // 1 minuto = 60 segundos.
    seg = segTotal%60; // Guardamos el residuo de la division en seg.

    cout <<"\nEl tiempo equivalente a la cantidad de segundos ingresados es: " << hs << " horas, " << min << " minutos y " << seg << " segundos." << endl;
    cout <<"\nEn horario seria: " << hs << ":" << min << ":" << seg <<"hs" << endl;
}

// Ejercico n°12: Escriba una funcion nombrada calular_años() que tenga:
// 1- Un parametro entero que represente el numero total de dias desde la fecha 1/1/2000
// 2- Otros 3 parametros de referencia nombrados año, mes y dia.
// La funcion es calcular el año, mes y dia actual para el numero dado de dias qie se le transmitan
// Para este problema suponga que cada año tiene 365 dias y cada mes tiene 30 dias.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.

void calcular_años(int, int&, int&, int&);

int main()
{
    int dias, año=0, mes=0, dia=0;

    calcular_años(dias, año, mes, dia);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void calcular_años(int dias, int& año, int& mes, int& dia)
{
    cout <<"\nIngrese la cantidad de dias: "; cin >> dias;

    cout <<"\nIngreso: " << dias <<" dias en total. " << endl; // 1216 por ejemplo
    cout <<"Calculando la fecha provista..." << endl;

    año = dias/365; // 365 dias en un año. // Realiza la division y guarda el cociente. // 1216/365 = 3.33
    dias %= 365; // Guardamos el residuo de la division en dias. // 0.33
    mes = dias/30; // 30 dias en un mes. // Realiza la division y guarda el cociente. // 33/30 = 1.1
    dias %= 30; // Guardamos el residuo de la division en dias. // 0.1
    dia = dias; // Guardamos el valor de dias en dia. // 0.1 = 0.1

    cout <<"\nLa fecha segun los dias ingresados es: " << dia <<"/"<< mes <<"/"<< año + 2000 << endl;
}

// Paso de parametros de tipo vector.
// Ejercico n°13: Cuadrado de los elementos del vector.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void cuadrado(int v[], int);
void muestra(int v[], int);

int main()
{
    int tamaño = 10, v[] {1,2,3,4,5,6,7,8,9,10};

    cuadrado(v, tamaño);
    muestra(v, tamaño);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void cuadrado(int v[], int tamaño)
{
    for(int i=0; i<tamaño; i++)
    {
        v[i] *= v[i]; // Elevamos al cuadrado los elementos del vector.
    }
}

void muestra(int v[], int tamaño)
{
    cout <<"\nEl cuadrado de los elementos del vector es... " << endl;

    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion " << i+1 <<" = " << v[i];
    }

    cout <<"\n";
}

// Ejercico n°14: Realice una funcion que tome como parametros un vector de numeros enteros y devuelva  la suma de sus elementos.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
int suma(int v[], int);

int v[100], tamaño;

int main()
{
    pedirDatos();
    cout <<"\nLa suma de todos los elementos del vector es: " << suma(v, tamaño) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese el tamaño del vector: "; cin >> tamaño;

    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] Guarde un numero: "; cin >> v[i];
    }
}

int suma(int v[], int tamaño)
{
    int suma=0;

    for(int i=0; i<tamaño; i++)
    {
        suma += v[i];
    }

    return suma;
}

// Ejercico n°15: Realice una funcion que tome como parametros un vector y su tamaño y diga si el vector esta ordenado crecientemente.
// Sugerencia: Compruebe que para todas las posiciones del vector, salvo para
// la 0, el elemento del vector es mayor o igual que el elemento que le precede en el vector.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
void verificarOrdenV(int v[], int);
void mostrarV(int v[], int);

int v[100], tamaño;

int main()
{
    pedirDatos();
    verificarOrdenV(v, tamaño);
    mostrarV(v, tamaño); 

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese el tamaño del vector: "; cin >> tamaño;

    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] Guarde un numero: "; cin >> v[i];
    }
}

void verificarOrdenV(int v[], int tamaño)
{
    int aux=0;

    for(int i=0; i<tamaño; i++)
    {
        if(v[i] >= v[i-1])
        {
            aux++;
        }
    }

    if(aux == tamaño)
    {
        cout <<"\nEl vector esta ordenado crecientemente." << endl;
    }else{
        cout <<"\nEl vector no esta ordenado crecientemente." << endl;
    }
}

void mostrarV(int v[], int tamaño)
{
    cout <<"\nEl orden ingresado a la memoria del vector es: ";
    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] = " << v[i];
    }
    cout <<"\n";
}

// Ejercico n°16: realizar una funcion que tome como parametros:
// un vector de numeros y su tamaño y cambie el signo de los elementos del vector.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
void cambiarSigno(int v[], int);
void mostrarV(int v[], int);

int v[100], tamaño;

int main()
{
    pedirDatos();
    cambiarSigno(v, tamaño);
    mostrarV(v, tamaño); 

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese el tamaño del vector: "; cin >> tamaño;

    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] Guarde un numero: "; cin >> v[i];
    }

    cout <<"\nVector ingresado: " << endl;
    for(int i=0; i<tamaño; i++)
    {
        cout << v[i] << "|";
    }
}

void cambiarSigno(int v[], int)
{
    for(int i=0; i<tamaño; i++)
    {
        v[i] *= -1; // v[i] = v[i] * -1;
    }
}

void mostrarV(int v[], int tamaño)
{
    cout <<"\n\nMostramos el vector con los signos cambiados: ";
    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] = " << v[i];
    }
    cout <<"\n";
}

// Ejercico n°17: Realizar una funcion que tome como parametros:
// Un vector de enteros y su tamaño e imprima un vector con los elementos impares y otro con los elementos pares del vector recibido.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
void vectorPar(int v[], int);
void vectorImpares(int v[], int);

int v[100], tamaño;

int main()
{
    pedirDatos();
    vectorPar(v, tamaño);
    vectorImpares(v, tamaño);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese el tamaño del vector: "; cin >> tamaño;

    for(int i=0; i<tamaño; i++)
    {
        cout <<"\nPosicion [" << i+1 <<"] Guarde un numero: "; cin >> v[i];
    }

    cout <<"\nVariables del vector ingresados: " << endl;
    for(int i=0; i<tamaño; i++)
    {
        cout << v[i] << "|";
    }

    cout <<"\n";
}

void vectorPar(int v[], int)
{
    cout <<"\nVector de numeros pares: " << endl;
    for(int i=0; i<tamaño; i++)
    {
        if(v[i]%2 == 0) // Si el residuo de la division es igual a 0, es par.
        {
            cout << v[i] << "|";
        }
    }

    cout <<"\n";
}

void vectorImpares(int v[], int)
{
    cout <<"\nVector de numeros impares: " << endl;
    for(int i=0; i<tamaño; i++)
    {
        if(v[i]%2 != 0) // Si el residuo de la division es diferente de 0, es impar.
        {
            cout << v[i] << "|";
        }
    }

    cout <<"\n";
}

// Paso de parametros tipo Matriz.
// Ejercico n°18: Elevar al cuadrado Todos los elementos de una matriz.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void mostrarMatriz(int m[2][3], int, int);
void alCuadradoM(int m[2][3], int, int);
void mostrarAlCuadradoM(int m[2][3], int, int);

int main()
{
    int m[2][3] {{1,2,3},{4,5,6}}, nFilas=2, nColumnas=3;

    mostrarMatriz(m, nFilas, nColumnas);
    alCuadradoM(m, nFilas, nColumnas);
    mostrarAlCuadradoM(m, nFilas, nColumnas);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void mostrarMatriz(int m[2][3], int nFilas, int nColumnas)
{
    cout <<"\nMostrando la Matriz original... " <<endl;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout <<m[i][j] <<"|";
        }
        cout <<"\n";
    }
}

void alCuadradoM(int m[2][3], int nFilas, int nColumnas)
{
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            m[i][j] *= m[i][j]; // Elevamos al cuadrado los elementos de la matriz.
        }
    }
}

void mostrarAlCuadradoM(int m[2][3], int nFilas, int nColumnas)
{
    cout <<"\nMostrando la Matriz al cuadrado... " <<endl;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << m[i][j] <<"|";
        }
        cout <<"\n";
    }
}

// Ejercico n°19: Desarrollar una funcion que determine si una matriz es simetrica o no.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
void verificarSimetriaM(int m[100][100], int, int);
void mostrarMatriz(int m[100][100], int, int);

int m[100][100], nFilas, nColumnas;

int main()
{
    pedirDatos();
    verificarSimetriaM(m, nFilas, nColumnas);
    mostrarMatriz(m, nFilas, nColumnas);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese la cantidad de Filas de la matriz: "; cin >> nFilas;
    cout <<"Ingrese la cantidad de Columnas de la matriz: "; cin >> nColumnas;

    cout <<"\nGuarde los elementos en las posiciones de memoria de la matriz: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << "posicion [" << i << "][" << j << "]: "; cin >> m[i][j];
        }
    }

}

void verificarSimetriaM(int m[100][100], int nFilas, int nColumnas)
{
    int cont=0;

    if(nFilas == nColumnas)
    {
        for(int i=0; i<nFilas; i++)
        {
            for(int j=0; j<nColumnas; j++)
            {
                if(m[i][j] == m[j][i])
                {
                    cont++;
                }
            }
        }

        if(cont == nFilas*nColumnas)
        cout <<"\nLa matriz es simetrica." << endl;

        if(cont != nFilas*nColumnas)
        cout <<"\nLa matriz no es simetrica." << endl;
    }else{
        cout <<"\nLa matriz no es simetrica." << endl;
    }
}

void mostrarMatriz(int m[100][100], int nFilas, int nColumnas)
{
    cout <<"\nMostrando la matriz ingresada... " << endl;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << m[i][j] <<"|";
        }
        cout <<"\n";
    }
}

// Ejercico n°20: Realizar una funcion que dada una matriz y un numero de fila de la matriz 
// devuelva el menor de los elementos almacenados en dicha fila.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void pedirDatos();
void mostrarMatriz(int m[100][100], int, int);
void menorFilaM(int m[100][100], int, int);

int m[100][100], nFilas, nColumnas;

int main()
{
    pedirDatos();
    mostrarMatriz(m, nFilas, nColumnas);
    menorFilaM(m, nFilas, nColumnas);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese la cantidad de Filas de la matriz: "; cin >> nFilas;
    cout <<"Ingrese la cantidad de Columnas de la matriz: "; cin >> nColumnas;

    cout <<"\nGuarde los elementos en las posiciones de memoria de la matriz: " << endl;
    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << "posicion [" << i << "][" << j << "]: "; cin >> m[i][j];
        }
    }

}

void mostrarMatriz(int m[100][100], int nFilas, int nColumnas)
{
    cout <<"\nMostrando la matriz ingresada... " << endl;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            cout << m[i][j] <<"|";
        }
        cout <<"\n";
    }
}

void menorFilaM(int m[100][100], int nFilas, int nColumnas)
{
    int menor=99999;

    for(int i=0; i<nFilas; i++)
    {
        for(int j=0; j<nColumnas; j++)
        {
            if(m[i][j] < menor)
            {
                menor = m[i][j];
            }
        }
    }
    
    cout <<"\nEl menor elemento de la fila es: " << menor << endl;
}

// Paso de parametros de tipo structura.
// Ejercico n°21: Realizar una funcion que tome como parametros una estructura alumno y que devuelva los datos del alumno.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct alumno
{
    char nombre[30];
    int edad=0;
}al;

// Prototipo de la funcion.
void pedirDatos();
void mostrarDatos(alumno);

int main()
{
    pedirDatos();
    mostrarDatos(al);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese su nombre: "; cin.getline(al.nombre, 30, '\n');
    cout <<"Ingrese su edad: "; cin >> al.edad;
}

void mostrarDatos(alumno alumno)
{
    cout <<"\nCargando los datos del alumno... " << endl;
    cout <<"Nombre: " << alumno.nombre << endl;
    cout <<"Edad: " << alumno.edad << endl;
}

// Ejercico n°22: Suma de numeros complejos.
// nComplejo1 = 5-3i
// nComplejo2 = -4+2i
// resultado  = 1-i

#include<iostream>
#include<stdlib.h>

using namespace std;

struct numeroComplejo
{
    float real;
    float imaginario;
}nComplejo1, nComplejo2;

// Prototipo de la funcion.
void pedirDatos();
numeroComplejo sumaComplejos(numeroComplejo, numeroComplejo);
void mostrarComplejo(numeroComplejo);

int main()
{
    pedirDatos();
    numeroComplejo resultado = sumaComplejos(nComplejo1, nComplejo2);
    mostrarComplejo(resultado);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese los numeros del primer numero complejo: " <<endl;
    cout <<"1. Parte Real del primer numero complejo: "; cin >> nComplejo1.real;
    cout <<"2. Parte imaginaria del primer numero complejo: "; cin >> nComplejo1.imaginario;
    cout <<"\nIngrese los numeros del segundo numero complejo: " <<endl;
    cout <<"1. Parte real del segundo numero complejo: "; cin >> nComplejo2.real;
    cout <<"2. Parte imaginaria del segundo numero complejo: "; cin >> nComplejo2.imaginario;
}

numeroComplejo sumaComplejos(numeroComplejo nComplejo1, numeroComplejo nComplejo2)
{
    nComplejo1.real += nComplejo2.real;
    nComplejo1.imaginario += nComplejo2.imaginario;

    return nComplejo1;
}

void mostrarComplejo(numeroComplejo resultado)
{
    cout <<"\nEl resultado de la suma de los numeros complejos es: " << resultado.real <<" + " << resultado.imaginario <<"i" << endl;
}

// Ejercico n°23: Realizar una funcion llamada mayor() que devuelva la fecha mas reciente de cualquier par de fechas que se transmitan.
// Por ejemplo, si se transmiten las fechas 10/9/2005 y 11/3/2015 a mayor(), sera devuelta la segunda fecha.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct fechaMayor
{
    int dia;
    int mes;
    int anio;
}d1, m1, a1, d2, m2, a2;

// Prototipo de la funcion.
void pedirDatos();
void fecha(fechaMayor, fechaMayor, fechaMayor, fechaMayor, fechaMayor, fechaMayor);

int main()
{
    pedirDatos();
    fecha(d1, m1, a1, d2, m2, a2);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void pedirDatos()
{
    cout <<"\nIngrese la primer fecha: " << endl;
    cout <<"Dia: "; cin >> d1.dia;
    cout <<"Mes: "; cin >> m1.mes;
    cout <<"Año: "; cin >> a1.anio;
    cin.ignore();
    cout <<"\nIngrese la segunda fecha: " << endl;
    cout <<"Dia: "; cin >> d2.dia;
    cout <<"Mes: "; cin >> m2.mes;
    cout <<"Año: "; cin >> a2.anio;
}

void fecha(fechaMayor d1, fechaMayor m1, fechaMayor a1, fechaMayor d2, fechaMayor m2, fechaMayor a2)
{
    if(a1.anio > a2.anio)
    cout <<"\nLa fecha mas reciente es: " << d1.dia <<"/" << m1.mes <<"/" << a1.anio << endl;
    if(a1.anio < a2.anio)
    cout <<"\nLa fecha mas reciente es: " << d2.dia <<"/" << m2.mes <<"/" << a2.anio << endl;
    if(a1.anio == a2.anio)
    {
        if(m1.mes > m2.mes)
        cout <<"\nLa fecha mas reciente es: " << d1.dia <<"/" << m1.mes <<"/" << a1.anio << endl;
        if(m1.mes < m2.mes)
        cout <<"\nLa fecha mas reciente es: " << d2.dia <<"/" << m2.mes <<"/" << a2.anio << endl;
        if(m1.mes == m2.mes)
        {
            if(d1.dia > d2.dia)
            cout <<"\nLa fecha mas reciente es: " << d1.dia <<"/" << m1.mes <<"/" << a1.anio << endl;
            if(d1.dia < d2.dia)
            cout <<"\nLa fecha mas reciente es: " << d2.dia <<"/" << m2.mes <<"/" << a2.anio << endl;
            if(d1.dia == d2.dia)
            cout <<"\nLas fechas son iguales." << endl;
        }
    }
}

// Recursividad: Es una funcion que se llama a si misma.
// Ejercico n°24: Factorial de un numero 3! = 3*2*1 = 6

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
int factorial(int);

int main()
{
    cout <<"\nEl factorial es: " << factorial(3) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
int factorial(int n)
{
    if(n==0) // Caso base
    n=1; // 0! = 1

    if(n>0) // Caso general
    n *= factorial(n-1); // Llamada recursiva

    return n;
}

// Ejercico n°25: Realizar una funcion recursiva que sume los primeros n enteros positivos.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
int sumaRecursiva(int);

int main()
{
    int nElementos=0;

    do{
        cout <<"\nIngrese el numero de elementos a sumar: "; cin >> nElementos;
    }while(nElementos<=0);
    
    cout <<"\nLa suma de los primeros " << nElementos <<" enteros positivos es: " << sumaRecursiva(nElementos) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
int sumaRecursiva(int n)
{
    int suma=0;
    if(n==1) // Caso base
    suma=1; // 1+0 = 1

    if(n>1) // Caso general
    suma =  n+sumaRecursiva(n-1); // Llamada recursiva

    return suma;
}

// Ejercico n°26: Realizar una funcion recursiva para la serie fibonacci.
// La serie fibonacci esta formada por la secuencia de numeros: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void fibonacci(int, int , int);

int main()
{
    int nElementos=0;

    do{
        cout <<"\nIngrese el numero de elementos a mostrar de la serie fibonacci: "; cin >> nElementos;
    }while(nElementos<=0);

    cout <<"\nLa serie fibonacci es: ";
    fibonacci(0, 1, nElementos); // Llamada a la funcion.

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void fibonacci(int n1, int n2, int n)
{
    if(n>0)
    {
        cout << n1 <<", ";
        fibonacci(n2, n1+n2, n-1); // Llamada recursiva.
    }
}

// Ejercico n°27: Realizar una funcion recursiva que calcule un numero elevado a una potencia entera mayor o igual que cero.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
int potencia(int, int);

int main()
{
    int base, exponente;

    cout <<"\nIngrese la base: "; cin >> base;
    cout <<"\nIngrese la potencia: "; cin >> exponente;
    cout <<"\nEl resultado de " << base <<" elevado a " << exponente <<" es: " << potencia(base, exponente) << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
int potencia(int base, int exponente)
{
    int pot;

    if(exponente==1) // Caso base
    pot=base;
    
    if(exponente>1) // Caso general
    pot = base*potencia(base, exponente-1); // Llamada recursiva.

    return pot;
}

// Ejercico n°28: Realizar una funcion escribeNumeros(int inicio, int fin) que devuelva en la salida estandar los numeros del ini al fin.
// Escriba una version que escriba los numeros en orden ascendente.

#include<iostream>
#include<stdlib.h>

using namespace std;

// Prototipo de la funcion.
void escribeNumeros(int, int);

int main()
{
    int inicio, fin;

    cout <<"\nDigite el numero de inicio: "; cin >> inicio;
    cout <<"\nDigite el numero de fin: "; cin >> fin;

    escribeNumeros(inicio, fin);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de la funcion.
void escribeNumeros(int inicio, int fin)
{
    for(int i=inicio; i<=fin; i++)
    {
        cout << i <<"|";
    }
    cout <<"\n";
}

