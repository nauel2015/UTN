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