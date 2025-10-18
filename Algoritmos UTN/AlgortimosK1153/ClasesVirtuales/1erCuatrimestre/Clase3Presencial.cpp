
// Clase N°3: 30/04/2025
// Profesor: Federico maidan.
// Correo: fedemaidan@frba.utn.edu.ar

#include<iostream>
#include<stdlib.h>

using namespace std;

// Ejercicio N°1: Realizar una estructura llamada persona y pareja: 

struct persona
{
    char nombre;
    int dni;
}p1, p2;

// Realizar una estructura llamada pareja:

struct pareja
{
    persona per1;
    persona per2;
}par;

// Prototipos de las funciones:

persona damePersona();
pareja damePareja();

int main ()
{
    cout <<"\n\tBienvenido\nIngrese las persona que son parejas.";

    p1 = damePersona();
    p2 = damePersona();
    par = damePareja();

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:
persona damePersona()
{
    persona per;
    cout <<"\nIngrese el nombre de la persona: "; cin >> per.nombre;
    cout <<"Ingrese el Dni de la persona: "; cin >> per.dni;

    return per;
}

pareja damePareja()
{
    par.per1 = damePersona();
    par.per2 = damePersona();
    
    return par;
}

// Ejercicio 2: Calcular el perimetro de un triangulo y un cuadrado y sumarlos en un perimetro total.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct triangulo
{
    float l1;
    float l2;
    float l3;
}tri;

struct cuadrado
{
    float lado;
}cua;

// Prototipo de las funciones:

float perimetro(triangulo);
float perimetro(cuadrado);
float perimetroTotal(float, float);

int main()
{
    cout <<"\n\tBienvenido.\nIngrese los lados del triangulo: " << endl;
    cout <<"Lado 1 = "; cin >> tri.l1;
    cout <<"Lado 2 = "; cin >> tri.l2;
    cout <<"Lado 3 = "; cin >> tri.l3;
    cout <<"\nIngrese el lado del cuadrado: "; cin >> cua.lado;
    
    float perimetroTriangulo = perimetro(tri);
    float perimetroCuadrado = perimetro(cua);
    cout <<"\nEl perimetro del triangulo es: " << perimetroTriangulo << endl;
    cout <<"El perimetro del cuadrado es: " << perimetroCuadrado<< endl;
    cout <<"El perimetro total es: " << perimetroTotal(perimetroTriangulo, perimetroCuadrado) << endl;


    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones:

float perimetro(triangulo t)
{
    return t.l1+t.l2+t.l3;
}

float perimetro(cuadrado c)
{
    return c.lado*4;
}

float perimetroTotal(float triangulo, float cuadrado)
{
    return triangulo+cuadrado;
}