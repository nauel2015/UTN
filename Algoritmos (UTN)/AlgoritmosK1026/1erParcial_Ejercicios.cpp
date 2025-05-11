#include <iostream>
#include "registroAcademico.h"
using namespace std;

bool recuperatorio1(int &nota1R1, int &notaActual1)
{
    char respuesta;
    cout << "¿Rindió el recuperatorio del primer parcial? (S/N): "; 
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's')
    {
        cout << "Ingrese la nota del recuperatorio: ";
        cin >> nota1R1;
        notaActual1 = nota1R1;
        return true;
    } else if (respuesta == 'N' || respuesta == 'n') {
        cout << "Continuando con la nota del segundo parcial." << endl;
        return false;
    } else {
        cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
        return false;
    }
}
    bool recuperatorio2(int &nota1R2, int &notaActual1) { 
        char respuesta;
        cout << "¿Rindió un segundo recuperatorio del primer parcial? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') { 
            cout << "Ingrese la nota del segundo recuperatorio: ";
            cin >> nota1R2;
            notaActual1 = nota1R2;
            cout << "Continuando con la nota del segundo parcial";
            return true;
    } else if (respuesta == 'N' || respuesta == 'n') {
        cout << "Continuando con la nota del segundo parcial." << endl;
        return false;
    } else {
        cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
        return false;
    }
}

    bool recuperatorio3(int &nota2R1, int&notaActual2) { 
        char respuesta;
        cout << "¿Rindió el recuperatorio del segundo parcial? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') { 
            cout << "Ingrese la nota del recuperatorio: ";
            cin >> nota2R1;
            notaActual2 = nota2R1;
            return true;
    } else if (respuesta == 'N' || respuesta == 'n') {
        cout << "Entendido." << endl;
        return false;
    } else {
        cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
        return false;
    }
}
    bool recuperatorio4(int &nota2R2, int &notaActual2) { 
        char respuesta;
        cout << "¿Rindió un segundo recuperatorio del segundo parcial? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') { 
            cout << "Ingrese la nota del segundo recuperatorio: ";
            cin >> nota2R2;
            notaActual2 = nota2R2;
            cout << "Entendido.";
            return true;
    } else if (respuesta == 'N' || respuesta == 'n') {
        cout << "Entendido." << endl;
        return false;
    } else {
        cout << "Respuesta no válida. Por favor, ingrese 'S' o 'N'." << endl;
        return false;
    }
}

int registroAcademico (int curso, int nota1, int nota1R1, int nota1R2, int nota2, int nota2R1, int nota2R2, int notaActual1, int notaActual2) { 
    //int nota1 = nota primer parcial.
    //int nota1R1 = nota primer recuperatorio, primer parcial.
    //int nota1R2 = nota segundo recuperatorio, primer parcial.
    //int nota2 = nota segundo parcial.
    //int nota2R1 = nota primer recuperatorio, segundo parcial.
    //int nota2R2 = nota segundo recuperatorio, segundo parcial.
    //int notaActual1 y int notaActual2 = nota que pisa a las demas

    
    cout << "Registro academico Algoritmo y Estructura de datos." <<"\nA contiuación, escriba su numero de comision: ";
    cin >> curso;

    cout << "\nEntendido. su comision es: K" << curso << endl << "\nPara iniciar su registro academico, debemos saber sus notas. A continuación, ingrese sus calificaciones." << endl << "Nota primer parcial: ";
    cin >> nota1;

    bool rindioRecuperatorio = recuperatorio1(nota1R1, notaActual1);

    bool rindioRecuperatorio2 = recuperatorio2(nota1R2, notaActual1);

    cout << endl << "Nota segundo parcial: ";
    cin >> nota2;

    bool rindioRecuperatorio3 = recuperatorio3(nota2R1, notaActual2);

    bool rindioRecuperatorio4 = recuperatorio4(nota2R2, notaActual2);

    bool nota1aprobada = false, nota1promocionada = false;
    bool nota2aprobada = false, nota2promocionada = false;

    if (nota1R1 > nota1 && nota1R1 >= 8) { //primer recuperatorio del primer parcial.
        nota1 = 8;
    }

    if (nota2R1 > nota2 && nota2R1 >= 8) { //primer recuperatorio del segundo parcial.
        nota2 = 8;
    }

    if (nota1R2 > nota1 && nota1R2 > nota1R1 && nota1R2 >= 6) { //segundo recuperatorio del primer parcial.
        nota1 = 6;
        nota1R1 = 6;
    }

    if (nota2R2 > nota2 && nota2R2 > nota2R1 && nota2R2 >= 6) { //segundo recuperatorio del segundo parcial.
        nota1 = 6;
        nota2R1 = 6;
    }

    if ((8 > nota1 && nota1 >= 6) || (8 > nota1R1 && nota1R1 >= 6) || (nota1R2 >= 6)) {
        nota1aprobada = true;
    }

    if ((nota1 >= 8) || (nota1R1 >= 8)) {
        nota1promocionada = true;
    }

    if ((8 > nota2 && nota2 >= 6) || (8 > nota2R1 && nota2R1 >= 6) || (nota2R2 >= 6)) {
        nota2aprobada = true;
    }

    if ((nota2 >= 8) || (nota2R1 >= 8)) {
        nota2promocionada = true;
    }

    if (nota1 != nota1R1)

    cout << "Su registro en Algortimo y Estructura de Datos es el siguiente: " << endl;
if (nota1aprobada) {
    cout << "\nPrimer parcial aprobado." << endl;
} else if (nota1promocionada) {
    cout << "\nPrimer parcial promocionado." << endl;
}
    else {
        cout << "\nPrimer parcial desaprobado." << endl;
    }

if (nota2aprobada) {
    cout << "\nSegundo parcial aprobado." << endl;
} else if (nota2promocionada) {
    cout << "\nSegundo parcial promocionado." << endl;
}
    else {
        cout << "\nSegundo parcial desaprobado." << endl;
    }

if (nota1aprobada && nota2aprobada || nota1aprobada && nota2promocionada || nota1promocionada && nota2aprobada) {
    cout << "\nUsted ha aprobado la materia. Podra rendir el final, felicidades.";
} else if (nota1promocionada && nota2promocionada) { 
    cout << "\nUsted ha promocionado la materia. No le hara falta presentarse en el final, felicidades.";}
    else { 
        cout << "\nUsted ha desaprobado la materia... Lo lamentamos.";
    }

    cout << endl << "Este ha sido su Registro Academico.";
    return 0;

} 

int main () {
    int curso, nota1, nota1R1, nota1R2, nota2, nota2R1, nota2R2, notaActual1, notaActual2;
    NewFunction(curso, nota1, nota1R1, nota1R2, nota2, nota2R1, nota2R2, notaActual1, notaActual2);
    bool nota1aprobada = false, nota1promocionada = false;
    bool nota2aprobada = false, nota2promocionada = false;
 return 0;
}
void NewFunction(int curso, int nota1, int nota1R1, int nota1R2, int nota2, int nota2R1, int nota2R2, int notaActual1, int notaActual2)
{
    registroAcademico(curso, nota1, nota1R1, nota1R2, nota2, nota2R1, nota2R2, notaActual1, notaActual2);
}


/*// Ejercicio 2 y 3: Funcion fecha que retorna la fecha ingresada y informa si es valido que pertenece al siglo 20 y 21 

#include <iostream>
using namespace std;

int fecha(int dia, int mes, int anio) 
{
    if (anio < 1900 || anio > 2100) 
    {
        return 0;
    }

    if (1 > mes || mes > 12) 
    {
        return 0;
    }

    int diasEnMes;

    if (mes == 2) 
    {
            diasEnMes = 28;
        
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {

        diasEnMes = 30;
    } else 
    {
        diasEnMes = 31;
    }

    if (dia < 1 || dia > diasEnMes) 
    {
        return 0;
    }

    return 1;
}

int main() 
{
    int dia, mes, anio;
    cout << "Ingrese el día: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el año: " << endl;
    cin >> anio;

    if (fecha(dia, mes, anio)) {
        cout << "\nLa fecha ingresada: " << dia << "/" << mes << "/" << anio <<" Es valida pertenece al siglo 20 o 21." << endl;
    } else {
        cout << "\nLa fecha ingresada es inválida no pertenece al siglo 20 ni 21." << endl;
    }

    return 0;
}
*/

/*// ejercicio 4: Funcion que recibe una fecha en forma AAAAMMDD.

#include <iostream>
using namespace std;

int fecha(int dia, int mes, int anio) 
{
    if (anio < 1900 || anio > 2100) 
    {
        return 0;
    }

    if (1 > mes || mes > 12) 
    {
        return 0;
    }

    int diasEnMes;

    if (mes == 2) 
    {
            diasEnMes = 28;
        
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {

        diasEnMes = 30;
    } else 
    {
        diasEnMes = 31;
    }

    if (dia < 1 || dia > diasEnMes) 
    {
        return 0;
    }

    return 1;
}

void descomponer(int AMD, int &dia, int &mes, int &anio) 
{
dia = AMD % 100; // El % funciona como una division, solo que en lugar de devolver el resultado, devuelve el resto (lo que sobra).
mes = (AMD / 100) % 100; //Al hacer la division por 100, vamos a lograr que nos quede un numero de 2 cifras. Vamos a hacer lo mismo que arriba y nos va a devolver el mes como el resto.
anio = AMD / 10000; //Tenemos en cuenta que es un numero de 6 digitos. Si dividimos por 10000, vamos a obtener 4 digitos y un par de decimales. Descartamos los decimales y obtenemos el año.
}

int main() 
{
    int AMD;
    cout << "Ingrese la fecha en forma AAAAMMDD: "; cin >> AMD;

    int dia, mes, anio;
    descomponer(AMD, dia, mes, anio);

    if (fecha(dia, mes, anio)) 
    {
        cout << "\nLa fecha descompuesta es: " << endl;
        cout << "Dia: " << dia << endl;
        cout << "Mes: " << mes << endl;
        cout << "Año: " << anio << endl;
    } else 
    {
        cout << "La fecha ingresada es inválida." << endl;
    }

    return 0;
}
*/

/*// Ejercicio 5: 

#include <iostream>
using namespace std;

float SueldoNeto(float sueldoBruto, int nivel, float sueldoBase) 
{
    float ISSS = 3.1f * sueldoBruto /100;
    float Ganancias = 9.3f * sueldoBruto /100;

    // Descuento adicional por seguro para niveles 2 y 3
    float Seguro = 0.0f;
    if (nivel == 2 || nivel == 3) 
    {
        Seguro = 11.4f * sueldoBase /100;
    }

    // Bono según el nivel
    float bono = 0.0f;
    switch (nivel) 
    {
        case 0: // Importe fijo en pesos
             bono = 0; break;
        case 1: // 6.4% del sueldo base
            bono = 6.4f * sueldoBase /100; break;
        case 2: // 13.94% del sueldo base
            bono = 13.94f * sueldoBase /100; break;
        case 3: // 21.04% del sueldo base
            bono = 21.04f * sueldoBase /100; break;
        default: cout << "Nivel de empleado inválido." << endl;
            return -1.0f; // Valor negativo para indicar un error
    }

    // Calcular sueldo neto
    float sueldoNeto = sueldoBruto - (ISSS + Ganancias) - Seguro + bono;
    return sueldoNeto;
}

int main() 
{
    float sueldoBruto;
    int nivel;
    float sueldoBase;

    cout << "Escriba el sueldo bruto: " << endl;
    cin >> sueldoBruto;
    cout << "¿De que nivel es el empleado?" << endl;
    cin >> nivel;
    cout << "¿Cual es el sueldo base?" << endl;
    cin >> sueldoBase;

    float sueldoNeto = SueldoNeto(sueldoBruto, nivel, sueldoBase);
    if (sueldoNeto >= 0.0f) 
    {
        cout << "El sueldo neto del empleado es: $" << sueldoNeto << endl;
    } else 
    {
        cout << "Hubo un error al calcular el sueldo neto." << endl;
    }

    return 0;
}
*/

/*// ejercicio 6: Funcion que muestra una tabla de pontencias del numero 1-6.

#include <iostream>
using namespace std;

void potencia(int N, int& P2, int& P3, int& P4, int& P5, int& P6, int& P7, int& P8, int& P9, int& P10) {
    if (N < 1 || N > 6) 
    {
        cout << "ERROR, imposible generar tabla de potencia requerida" << endl;
        return;
    }

    if (N == 1) 
    {
        P2 = N;
        P3 = P2;
        P4 = P3;
        P5 = P4;
        P6 = P5;
        P7 = P6;
        P8 = P7;
        P9 = P8;
        P10 = P9;
    }

    if (N == 2) 
    {
        P2 = (N + N);
        P3 = (P2 + P2);
        P4 = (P3 + P3);
        P5 = (P4 + P4);
        P6 = (P5 + P5);
        P7 = (P6 + P6);
        P8 = (P7 + P7);
        P9 = (P8 + P8);
        P10 = (P9 + P9);
    }

    if (N == 3) 
    {
        P2 = (N + N + N);
        P3 = (P2 + P2 + P2);
        P4 = (P3 + P3 + P3);
        P5 = (P4 + P4 + P4);
        P6 = (P5 + P5 + P5);
        P7 = (P6 + P6 + P6);
        P8 = (P7 + P7 + P7);
        P9 = (P8 + P8 + P8);
        P10 = (P9 + P9 + P9);
    }

    if (N == 4) 
    {
        P2 = (N + N) + (N + N);
        P3 = (P2 + P2) + (P2 + P2);
        P4 = (P3 + P3) + (P3 + P3);
        P5 = (P4 + P4) + (P4 + P4);
        P6 = (P5 + P5) + (P5 + P5);
        P7 = (P6 + P6) + (P6 + P6);
        P8 = (P7 + P7) + (P7 + P7);
        P9 = (P8 + P8) + (P8 + P8);
        P10 = (P9 + P9) + (P9 + P9);
    }
    if(N == 5)
    {
        P2 = (N + N + N + N + N);
        P3 = (P2 + P2) + (P2 + P2 + P2);
        P4 = (P3 + P3) + (P3 + P3 + P3);
        P5 = (P4 + P4) + (P4 + P4 + P4);
        P6 = (P5 + P5) + (P5 + P5 + P5);
        P7 = (P6 + P6) + (P6 + P6 + P6);
        P8 = (P7 + P7) + (P7 + P7 + P7);
        P9 = (P8 + P8) + (P8 + P8 + P8);
        P10 = (P9 + P9) + (P9 + P9 + P9);

    }
    if(N == 6)
    {
        P2 = N + N + N + N + N + N;
        P3 = (P2 + P2 + P2) + (P2 + P2 + P2);
        P4 = (P3 + P3 + P3) + (P3 + P3 + P3);
        P5 = (P4 + P4 + P4) + (P4 + P4 + P4);
        P6 = (P5 + P5 + P5) + (P5 + P5 + P5);
        P7 = (P6 + P6 + P6) + (P6 + P6 + P6);
        P8 = (P7 + P7 + P7) + (P7 + P7 + P7);
        P9 = (P8 + P8 + P8) + (P8 + P8 + P8);
        P10 = (P9 + P9 + P9) + (P9 + P9 + P9);
    }

    cout << N << " ^ 1 = " << N << endl;
    cout << N << " ^ 2 = " << P2 << endl;
    cout << N << " ^ 3 = " << P3 << endl;
    cout << N << " ^ 4 = " << P4 << endl;
    cout << N << " ^ 5 = " << P5 << endl;
    cout << N << " ^ 6 = " << P6 << endl;
    cout << N << " ^ 7 = " << P7 << endl;
    cout << N << " ^ 8 = " << P8 << endl;
    cout << N << " ^ 9 = " << P9 << endl;
    cout << N << " ^ 10 = " << P10 << endl;
}

int main() 
{
    int N, P2, P3, P4, P5, P6, P7, P8, P9, P10;
    cout << "Ingrese el número que desea elevar (de 1 a 6): ";
    cin >> N;

    potencia(N, P2, P3, P4, P5, P6, P7, P8, P9, P10);

    return 0;
}
*/

/*// Ejercicio 8: 

#include <iostream>
using namespace std;

bool primo(int numero) 
{
    if (numero <= 1) return false;
    if (numero == 2) return true;
    if (numero % 2 == 0) return false;

    for (int i = 3; i * i <= numero; i += 2) 
    {
        if (numero % i == 0) return false;
    }
    return true;
}

void ListaPrimos(int N) 
{
    for (int i = 1; i <= N; ++i) {
        if (primo(i)) 
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Mostraremos los números primos desde el 1 hasta el: ";
    cin >> N;
    ListaPrimos(N);
    return 0;
}
*/