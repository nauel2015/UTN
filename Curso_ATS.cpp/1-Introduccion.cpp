
// Introduccion a tipos de datos.

#include <iostream> // entrada y salida de datos.

using namespace std;

int main()
{
    int entero=89;
    float flotante=67.8; 
    double mayor=78.8787;
    char letra='N';

    cout << "Se muestra el entero: " << entero << endl;
    cout << "Se muestra el flotante: " << flotante << endl;
    cout << "Se muestra el flotante mayor: " << mayor << endl;
    cout << "Se muestra la letra asignada: " << letra << endl;

    return 0;
}


// Lectura o entrada de datos.

#include <iostream>
using namespace std;
int main()
{
    int a,b;
    float c;

    cout <<"Escriba un numero entero: "; cin >> a; // Se guarda en (a)
    cout <<"El primer numero es: " << a << endl;

    cout <<"Escriba otro numero entero: "; cin >> b; // Se guarda en (b)
    cout <<"El segundo numero es: " << b << endl;

    cout <<"Escriba un numero flotante: "; cin >> c; // Se guarda en (c)
    cout <<"El numero flotante es: " << c << endl;
    
    return 0;

}


// Operaciones aritmeticas.
// Escriba un programa que lea 2 numeros y muestre su suma, Resta, Multiplicacion y division.
#include <iostream>
using namespace std;

int main ()
{
    int a, b, suma=0, resta=0, multiplicacion=0, division=0;

    cout <<"Escriba el primer numero: "; cin >> a;
    cout <<"Escriba el segundo numero: "; cin >> b;

    suma = a+b;
    resta = a-b;
    multiplicacion = a*b;
    division = a/b;

    cout <<"El resultado de la suma: " << suma << endl;
    cout <<"El resultado de la resta: " << resta << endl;
    cout <<"El resultado de la multiplicacion: " << multiplicacion << endl;
    cout <<"El resultado de la divison: " << division << endl;

    return 0;

}


// Pedir datos al usuario.

#include <iostream>
using namespace std;

int main()
{
    char nombre[20];
    int edad;
    char sexo[10];
    float altura;

    cout <<"Escriba su nombre: "; cin >> nombre;
    cout <<"Escriba su edad: "; cin >> edad;
    cout <<"Escriba su sexo: "; cin >> sexo;
    cout <<"Escriba su altura: "; cin >> altura;

    cout <<"Su nombre es: " << nombre << endl;
    cout <<"Su edad es: " << edad << endl;
    cout <<"Su sexo es: " << sexo << endl;
    cout <<"Su altura es: " << altura << endl;

    return 0;
}
