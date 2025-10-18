
/* Ejercicio 2: Operaciones con punteros y estructuras.

1. Define una estructura Libro que contenga los atributos titulo (cadena de caracteres) y paginas (entero).
2. Crea una función que reciba un puntero a Libro y permita al usuario modificar sus atributos.
3. En el main , crea una instancia dinámica de Libro , muestra sus atributos, y luego llama a la función para modificarlos.

*/
#include <iostream>
#include <string.h>
using namespace std;

struct Libro
{
    char titulo[30];
    int paginas;
};

// Declaracion de las funciones.
void modificarLibro(Libro *);

int main() 
{
    Libro *libro = new Libro;
    strcpy(libro->titulo, "Star wars");
    libro->paginas = 200;

    cout <<"\nTitulo: " << libro->titulo << endl;
    cout <<"Paginas: " << libro->paginas << endl;

    modificarLibro(libro);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
void modificarLibro(Libro *libro)
{
    cout <<"\nCambie el titulo del libro: "; cin.getline(libro->titulo, 30, '\n');
    cout <<"Cambie la cantidad de paginas: "; cin >> libro->paginas;

    cout <<"\nTitulo: " << libro->titulo << endl;
    cout <<"Paginas: " << libro->paginas << endl;

}