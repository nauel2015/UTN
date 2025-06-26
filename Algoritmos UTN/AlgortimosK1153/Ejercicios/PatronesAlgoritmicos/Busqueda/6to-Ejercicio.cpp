
/* Ejercicio N°6: Crea una estructura llamada "Instagamer" con los atributos "nombre", "edad" y una estructura anidada
llamada "Redes" con los atributos "instagram" y "twitter" e implementa un sistema donde el usuario pueda
ingresar los datos de 10 Instagamers. Luego, el sistema solicitará al usuario que ingrese el nombre de un
Instagamer a buscar. Utilizando un algoritmo de búsqueda adecuado, se determinará si el Instagamer está
presente en el conjunto de Instagamers cargados. Si se encuentra, se mostrará su nombre, edad, instagram y
twitter.

*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct redes
{
    string instagram;
    string twitter;
};

struct instaGamer
{
    char nombre[30];
    int edad;
    redes redesSociales;
}usuarios[10];

// Declaracion de las funciones.
instaGamer cargarUsuarios(instaGamer [], int &);
int busquedaSecuencial(instaGamer [], int, string);
void usuarioEncontrado(instaGamer [], int);

int main()
{

    int contUsuarios=0, opcion;
    do{
        cout <<"\n\tInstaGamer. \n" << endl;
        cout <<"Opcion 1: Registrar usuarios. " << endl;
        cout <<"Opcion 2: Buscar usuario. " << endl;
        cout <<"Opcion 3: Salir. " << endl;

        cout <<"\nIngrese su opcion: "; cin >> opcion;

        switch(opcion)
        {
            case 1: system("cls"); cargarUsuarios(usuarios, contUsuarios); system("cls"); break;
            case 2: system("cls"); usuarioEncontrado(usuarios, contUsuarios); system("cls"); break;
            case 3: cout <<"\nHasta luego. " << endl; break;
        }
    }while(opcion!=3);

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Definicion de las funciones.
instaGamer cargarUsuarios(instaGamer usuarios[], int &contUsuarios)
{
    int cantUsuarios;
    cout <<"\n\tCantidad de usuarios en la red [" << contUsuarios <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese la cantidad de usuarios a registrar: "; cin >> cantUsuarios;
    
    for(int i=0; i<cantUsuarios; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(usuarios[contUsuarios].nombre, 30, '\n');
        cout <<"Edad: "; cin >> usuarios[contUsuarios].edad;

        cout <<"\nRedes sociales. " << endl; 
        cin.ignore();
        cout <<"Instagram: "; getline(cin, usuarios[contUsuarios].redesSociales.instagram);
        cout <<"Twitter: "; getline(cin, usuarios[contUsuarios].redesSociales.twitter);

        contUsuarios++;
    }

    return *usuarios;
}

int busquedaSecuencial(instaGamer usuarios[], int len, string buscado)
{
    int i=0;
    while(i<len&&usuarios[i].nombre!=buscado)
    {
        i++;
    }

    if(i==len)
    {
        return -1;
    }else{
        return i;
    }
}

void usuarioEncontrado(instaGamer usuarios[], int contUsuarios)
{
    string buscado;
    cout <<"\n\tCantidad de usuarios en la red [" << contUsuarios <<"]. " << endl;
    cin.ignore();
    cout <<"\nIngrese el nombre del usuario: "; getline(cin, buscado);

    int pos = busquedaSecuencial(usuarios, contUsuarios, buscado);

    if(pos!=-1)
    {
        cout <<"\nUsuario encontrado. " << endl;
        cout <<"Nombre: " << usuarios[pos].nombre << endl;
        cout <<"Edad: " << usuarios[pos].edad << endl;
        cout <<"\nRedes sociales. " << endl;
        cout <<"Instagram: " << usuarios[pos].redesSociales.instagram << endl;
        cout <<"Twitter: " << usuarios[pos].redesSociales.twitter << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
    }else{
        cout <<"\nUsuario no encontrado. " << endl;

        cout <<"\nVolviendo al menu... [ENTER] " << endl;
        system("PAUSE");
    }
}