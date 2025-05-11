
// Represente en c++ la siguiente expresion (a/b + 1)

#include <iostream>
using namespace std;

int main()
{
    float a, b, resultado=0;

    cout <<"Escriba el primer numero: "; cin >> a;
    cout <<"Escriba el segundo numero: "; cin >> b;

    resultado = (a/b) + 1;

    cout.precision(2);
    cout <<"El resultado es:" << resultado << endl;

    return 0;
}


// Represente en c++ la siguiente expresion (a + (b/c))/(d + (e/f))

#include <iostream>
using namespace std;

int main()
{
    float a, b, c, d, e, f, resultado=0;

    cout <<"Escriba la variable a: "; cin >> a;
    cout <<"Escriba la variable b: "; cin >> b;
    cout <<"Escriba la variable c: "; cin >> c;
    cout <<"Escriba la variable d: "; cin >> d;
    cout <<"Escriba la variable e: "; cin >> e;
    cout <<"Escriba la variable f: "; cin >> f;

    resultado = (a + (b/c))/(d + (e/f));

    cout.precision(2);
    cout <<"El resultado es:" << resultado << endl;

    return 0;
}


// Represente en c++ la siguiente expresion (a + (b/(c-d)))

#include <iostream>
using namespace std;

int main()
{
    float a, b, c, d, resultado=0;

    cout <<"Escriba la variable a: "; cin >> a;
    cout <<"Escriba la variable b: "; cin >> b;
    cout <<"Escriba la variable c: "; cin >> c;
    cout <<"Escriba la variable d: "; cin >> d;

    resultado = (a + (b/(c-d)));

    cout.precision(2);
    cout <<"El resultado es:" << resultado << endl;

    return 0;
}


// Programa que intercambia los valores de 2 variables.

#include <iostream>
using namespace std;

int main()
{
    float a, b, aux;

    cout <<"Escriba el valor de a: "; cin >> a;
    cout <<"Escriba el valor de b: "; cin >> b;
    
    aux = a;
    a = b;
    b = aux;

    cout <<"El nuevo valor de a es: " << a << endl;
    cout <<"El nuevo valor de b es: " << b << endl;

    return 0;
}


// Programa que lee la nota de 4 alumnos y calcula la nota final promedio de este grupo de 4 alumnos. 

#include <iostream>
using namespace std;

int main()
{
    cout <<"\n\tBienvenido al Programa que lee la nota de 4 alumnos y calcula la nota final promedio de este grupo de 4 alumnos. " << endl;
    float A1, A2, A3, A4, NotaPromedioFinal;

    cout <<"Escriba la nota del primer alumno: "; cin >> A1;
    cout <<"Escriba la nota del segundo alumno: "; cin >> A2;
    cout <<"Escriba la nota del tercer alumno: "; cin >> A3;
    cout <<"Escriba la nota del cuarto alumno: "; cin >> A4;

    NotaPromedioFinal = (A1 + A2 + A3 + A4)/(4);

    cout.precision(2);
    cout <<"La nota promedio final de los 4 alumnos es: " << NotaPromedioFinal << endl;

    return 0;
}


// Programa que lee las 3 notas de un alumno y devuelve su nota final.
//nota n°1.Practica 30%.
//nota n°2.teorica 60%.
//nota n°3.participacion 10%.

#include <iostream>
using namespace std;

int main()
{
    float practica, teorica, participacion, NotaFinal;

    cout <<"Escriba la nota sobre la practica: "; cin >> practica;
    cout <<"Escriba la nota sobre la teorica: "; cin >> teorica;
    cout <<"Escriba la nota sobre la participacion: "; cin >> participacion;

    practica *= 0.30; // practica = practica * 0.30;
    teorica *= 0.60; // teorica = teorica * 0.60;
    participacion *= 0.10; // participacion = participacion * 0.10;
    NotaFinal = practica + teorica + participacion;

    cout.precision(2);
    cout <<" La nota final es: " << NotaFinal << endl;

    return 0;
}


// Programa que calcula el valor que toma la siguiente funcion: f(x,y) = (sqrt(a))/(pow(b,2)-1)

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, resultado=0;

    cout <<"Escriba el valor de a: "; cin >> a;
    cout <<"Escriba el valor de b: "; cin >> b;

    resultado = (sqrt(a))/(pow(b,2)-1); // sqrt (raiz cuadrada) pow(b,2) (b elevado al cuadrado)

    cout.precision(2);
    cout <<"El resultado de la funcion es: " << resultado << endl;

    return 0;
}


// Programa que da la solucion a una Ecuacion de segundo grado.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c, resultado1=0, resultado2=0;

    cout <<"Escriba el valor de la variable a: "; cin >> a;
    cout <<"Escriba el valor de la variable b: "; cin >> b;
    cout <<"Escriba el valor de la variable c: "; cin >> c;

    resultado1 = (-b + sqrt(pow(b,2)- 4*a*c))/(2*a);
    resultado2 = (-b - sqrt(pow(b,2)- 4*a*c))/(2*a);

    cout.precision(2);
    cout <<"El primer resultado de la ecuacion: " << resultado1 << endl;
    cout <<"El segundo resultado de la ecuacion: " << resultado2 << endl;

}
