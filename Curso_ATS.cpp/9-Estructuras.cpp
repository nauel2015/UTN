
// Estructuras (struct).
// Coleccion de uno a mas tipos de elemento denominados campos.
// De los cuales cada uno puede ser un tipo de dato diferente.

// Ejercicio n°1: Se desea almacenar los datos de una collecion de discos compactos (CD) de musica.
// Estos datos serian:
// Titulo | Artista | Numero de canciones | Precio | Fecha de compra.

struct collecion_CD // Nombre de la estructura.
{
    // Campos de la estructura.
    char titulo[50]; // <Tipo de dato> | <Nombre del campo>.
    char artista[50]; // <Tipo de dato> | <Nombre del campo>.
    int numCanciones; // <Tipo de dato> | <Nombre del campo>.
    float precio; // <Tipo de dato> | <Nombre del campo>.
    char fechaCompra[20]; // <Tipo de dato> | <Nombre del campo>.
}; // Otra forma de declarar las variables seria desde aca. cd1, cd2, cd3;

int main ()
{
    collecion_CD cd1, cd2, cd3; // Cada variable contiene todos los campos del struct collecion_CD.
}

// Ejercicio n°2: Estructuras simples.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct persona
{
    char nombre[30];
    int edad;
};

int main ()
{
    persona persona1 = {"nahuel richeri", 21}, persona2 = {"alexander richeri", 21}, persona3;

    cout <<"\nNombre: " << persona1.nombre << endl;
    cout <<"Edad: " << persona1.edad << endl;

    cout <<"\nNombre: " << persona2.nombre << endl;
    cout <<"Edad: " << persona2.edad << endl;

    cout <<"\nIngrese su nombre: "; cin.getline(persona3.nombre, 30, '\n');
    cout <<"\nIngrese su edad: "; cin >> persona3.edad;

    cout <<"Imprimiendo los datos del usuario..." << endl;
    cout <<"\nNombre: " << persona3.nombre << endl;
    cout <<"Edad: " << persona3.edad << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Estructuras anidadas: Son estructuras dentro de otras estructuras (siempre de arriba hacia abajo).

struct infoDireccion
{
    char direccion[30];
    char ciudad[30];
    char localidad[30];
};

struct empleado
{
    char nombre[30];
    struct infoDireccion direccionEmpleado;
    float salario;
}

// Ejercicio n°3: Estructuras anidadas: empleados.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct infoDireccion
{
    char direccion[30];
    char ciudad[30];
    char localidad[30];
};

struct empleado
{
    char nombre[30];
    infoDireccion direccionEmpleado;
    float salario;
};

int main ()
{
    empleado empleados[2];

    for(int i=0; i<2; i++)
    {
        cout <<"\nIngrese su nombre: "; cin.getline(empleados[i].nombre, 30, '\n');
        cout <<"Ingrese su direccion: "; cin.getline(empleados[i].direccionEmpleado.direccion, 30, '\n');
        cout <<"Ingrese su ciudad: "; cin.getline(empleados[i].direccionEmpleado.ciudad, 30, '\n');
        cout <<"Ingrese su localidad: "; cin.getline(empleados[i].direccionEmpleado.localidad, 30, '\n');
        cout <<"Ingrese su salario: "; cin >> empleados[i].salario;
        cin.ignore(); // Permite ingresar los valores.
    }

    cout <<"\nImprimiendo los datos de los empleados..." << endl;

    for(int i=0; i<2; i++)
    {
        cout <<"\nNombre: " << empleados[i].nombre << endl;
        cout <<"Direccion: " << empleados[i].direccionEmpleado.direccion << endl;
        cout <<"Ciudad: " << empleados[i].direccionEmpleado.ciudad << endl;
        cout <<"Localidad:" << empleados[i].direccionEmpleado.localidad << endl;
        cout <<"Salario: " << empleados[i].salario << endl;
    }
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}


// Ejercicio n°4: 
// 1- Hacer una estructura llamada corredor, con los siguientes campos:
// Nombre | Edad | Sexo | club.
// 2- Pedir datos al usuario para un corredor, y asignarle una categoria de competicion:
// Juvenil <= 18 | senior <= 40 | veterano > 40.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct corredor
{
    char nombre[30];
    int edad;
    char sexo[10];
    char club[20];
};

int main()
{
    char categoria[10];
    corredor c1;

    cout <<"\nBienvenido corredor. \nIngrese sus datos: " << endl;
    cout <<"\nNombre: "; cin.getline(c1.nombre, 30, '\n');
    cout <<"Edad: "; cin >> c1.edad;
    cin.ignore();
    cout <<"Sexo: "; cin.getline(c1.sexo, 10, '\n');
    cout <<"Club: "; cin.getline(c1.club, 20, '\n');

    if(c1.edad <= 18) strcpy(categoria, "Juvenil");
    if(c1.edad <= 40) strcpy(categoria, "Senior");
    if(c1.edad > 40) strcpy(categoria, "Veterano");

    cout <<"\nBuscando datos del corredor... " << endl;
    cout <<"\nNombre:" << c1.nombre << endl;
    cout <<"Edad: " << c1.edad << endl;
    cout <<"Sexo: " << c1.sexo << endl;
    cout <<"Club: " << c1.club << endl;
    cout <<"Categoria: " << categoria << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°5: 
// 1- Hacer una estructura llamada alumno, con los siguientes campos:
// Nombre | Edad | Promedio.
// 2- Pedir datos al usuario para 3 alumnos.
// 3- Comprobar cual de los 3 tiene el mejor promedio.
// 4- Imprimir los datos del alumno.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct alumno
{
    char nombre[30];
    int edad;
    float promedio;
};

int main()
{
    int mejor=0, mejorPromedio=0;
    alumno alumno[3];

    cout <<"\nBienvenido alumno. \nIngrese sus datos: " << endl;

    for(int i=0; i<3; i++)
    {
        cout <<"\nNombre: "; cin.getline(alumno[i].nombre, 30, '\n');
        cout <<"Edad: "; cin >> alumno[i].edad;
        cout <<"Promedio de notas: "; cin >> alumno[i].promedio;
        cin.ignore();

        if(alumno[i].promedio > mejor)
        {
            mejor = alumno[i].promedio;
            mejorPromedio = i;
        }
    }
    
    cout <<"\nBuscando al alumno con mejor promedio... " << endl;
    cout <<"\nNombre: " << alumno[mejorPromedio].nombre << endl;
    cout <<"Edad: " << alumno[mejorPromedio].edad << endl;
    cout <<"promedio: " << mejor << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°5: Realizar un programa que lea de un vector de estrucutras los datos de n empleados de la empresa.
// Que imprima los datos del empleado con mayor y menor salario.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct empleado
{
    char nombre[30];
    float salario;
};

int main()
{  
    int cantEmpleados, mayorSalario=0, menorSalario=999999999, posMenor, posMayor;
    empleado empleado[1000];

    cout <<"\nIngrese la cantidad de empleados que tiene su empresa: "; cin >> cantEmpleados;

    for(int i=0; i<cantEmpleados; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(empleado[i].nombre, 30, '\n');
        cout <<"Salario: "; cin >> empleado[i].salario;

        if(empleado[i].salario > mayorSalario)
        {
            mayorSalario = empleado[i].salario;
            posMayor = i;
        }
        if(empleado[i].salario < menorSalario)
        {
            menorSalario = empleado[i].salario;
            posMenor = i;
        }
    }

    cout <<"\nEmpleado con mayor salario en la empresa: " << endl; 
    cout <<"nombre: " << empleado[posMayor].nombre << endl;
    cout <<"Salario: " << empleado[posMayor].salario << endl;
    cout <<"\nEmpleado con menor salario en la empresa: " << endl; 
    cout <<"nombre: " << empleado[posMenor].nombre << endl;
    cout <<"Salario: " << empleado[posMenor].salario << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°6: Atletas 
// 1- realizar un vector de estructura llamada atleta para n atletas con los siguientes campos:
// Nombre | Pais | Cantidad de medallas.
// 2- Que devuelva los datos ingresados (nombre,pais) y el atleta con mayor cantidad de medallas.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct atleta
{
    char nombre[30];
    char pais[20];
    int cantMedallas;
};

int main()
{  
    int cantAtletas, atletaMayor=0, posMayor=0;

    cout <<"\nIngrese la cantidad de atletas que hay en la competencia: "; cin >> cantAtletas;

    atleta atleta[1000];

    for(int i=0; i<cantAtletas; i++)
    {
        cin.ignore();
        cout <<"\nNombre: "; cin.getline(atleta[i].nombre, 30, '\n');
        cout <<"Pais: "; cin.getline(atleta[i].pais, 20, '\n');
        cout <<"Medallas ganadas: "; cin >> atleta[i].cantMedallas;

        if(atleta[i].cantMedallas > atletaMayor)
        {
            atletaMayor = atleta[i].cantMedallas;
            posMayor = i;
        }
    }

    cout <<"\nAtleta con mayor cantidad de medallas en la competicion: " << endl; 
    cout <<"\nNombre: " << atleta[posMayor].nombre << endl;
    cout <<"Pais: " << atleta[posMayor].pais << endl;
    cout <<"Cantidad de medallas ganadas: " << atletaMayor << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°7: Promedio de un alumno. Hacer 2 estructuras:
// 1- Una llamada promedio con los siguientes campos: nota1 | nota2 | nota3.
// 2- Otra llamada alumno con los siguientes campos: nombre | sexo | edad | anidar la estructura promedio a la estructura alumno.
// Luego pedir todos los datos al alumno, calcular su promedio y por ultimo mostrar todos sus datos junto al promedio.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct promedio
{
    float nota1;
    float nota2;
    float nota3;
};

struct alumno
{
    char nombre[30];
    char sexo[10];
    int edad;
    promedio promedio;
};

int main()
{  
    float promedioAlumno;
    alumno al;

    cout <<"\n\tBienvendio alumno. \n\nIngrese sus datos:" << endl;
    cout <<"\nNombre: "; cin.getline(al.nombre, 30, '\n');
    cout <<"Sexo: "; cin.getline(al.sexo, 10, '\n');
    cout <<"Edad: "; cin >> al.edad;

    cout <<"\nIngrese sus notas: " << endl;
    cout <<"Nota 1: "; cin >> al.promedio.nota1;
    cout <<"Nota 2: "; cin >> al.promedio.nota2;
    cout <<"Nota 3: "; cin >> al.promedio.nota3;

    promedioAlumno = (al.promedio.nota1 + al.promedio.nota2 + al.promedio.nota3)/3;

    cout <<"\nDatos del alumno: " <<endl;
    cout <<"Nombre: " << al.nombre << endl;
    cout <<"Sexo: " << al.sexo << endl;
    cout <<"Edad: " << al.edad << endl;
    cout <<"Promedio de notas: " << promedioAlumno << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°8: Promedio de n alumnos. Hacer 2 estructuras:
// 1- Una llamada promedio con los siguientes campos: nota1 | nota2 | nota3.
// 2- Otra llamada alumno con los siguientes campos: nombre | sexo | edad | anidar la estructura promedio a la estructura alumno.
// Luego pedir todos los datos a los n alumnos, calcular sus promedios y por ultimo mostrar todos sus datos junto al mejor promedio de alumnos.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct promedio
{
    float nota1;
    float nota2;
    float nota3;
};

struct alumno
{
    char nombre[30];
    char sexo[10];
    int edad;
    promedio promedio;
};

int main()
{  
    float promedioAlumno, mejorPromedio;
    int cantAlumnos, posAlumno;
    alumno al[1000];

    cout <<"\n\tBienvendio. \n\nIngrese la cantidad de alumnos a evaluar: "; cin >> cantAlumnos;

    for(int i=0; i<cantAlumnos; i++)
    {
        cout <<"\n" << i+1 << ". Alumno." << endl;
        cin.ignore();
        cout <<"Nombre: "; cin.getline(al[i].nombre, 30, '\n');
        cout <<"Sexo: "; cin.getline(al[i].sexo, 10, '\n');
        cout <<"Edad: "; cin >> al[i].edad;

        cout <<"\nIngrese sus notas: " << endl;
        cout <<"Nota 1: "; cin >> al[i].promedio.nota1;
        cout <<"Nota 2: "; cin >> al[i].promedio.nota2;
        cout <<"Nota 3: "; cin >> al[i].promedio.nota3;

        promedioAlumno = (al[i].promedio.nota1 + al[i].promedio.nota2 + al[i].promedio.nota3)/3;

        if(promedioAlumno > mejorPromedio)
        {
            mejorPromedio = promedioAlumno;
            posAlumno = i;
        }

    }

    cout <<"\nDatos del alumno con mejor promedio: " <<endl;
    cout <<"Nombre: " << al[posAlumno].nombre << endl;
    cout <<"Sexo: " << al[posAlumno].sexo << endl;
    cout <<"Edad: " << al[posAlumno].edad << endl;
    cout <<"Promedio de notas: " << mejorPromedio << endl;

    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°9: Defina una estrucutra que indique el tiempo empleado por un ciclista en una etapa.
// 1- La estructura debe tener tres campos: horas | minutos | segundos.
// 2- Escriba un programa que dado n etapas calcule el tiempo total empleado en recorrer todas las etapas.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct etapas
{
    int horas;
    int minutos;
    int segundos;
};

int main()
{  
    int nEtapas=0, horasT=0, minutosT=0, segundosT=0;
    etapas etapas[1000];

    cout <<"\n\tBienvenido ciclista. \n\nIngrese la cantidad de etapas recorridas: "; cin >> nEtapas;
    cout <<"\nProceda a ingresar los tiempos de cada etapa: " << endl;
    for(int i=0; i<nEtapas; i++)
    {
        cout <<"\nEtapa " << i+1 <<"." << endl;
        cout <<"Horas: "; cin >> etapas[i].horas;
        horasT += etapas[i].horas;
        cout <<"Minutos: "; cin >> etapas[i].minutos;
        minutosT += etapas[i].minutos;
        if(minutosT >= 60)
        {
            minutosT -= 60;
            horasT++;
        }
        cout <<"Segundos: "; cin >> etapas[i].segundos;
        segundosT += etapas[i].segundos;
        if(segundosT >= 60)
        {
            segundosT -= 60;
            minutosT++;
        }
    }

    cout <<"\nTiempo total empleado: " << horasT <<":" << minutosT <<":" << segundosT <<"hs." << endl;
    cout <<"Horas: " << horasT << endl;
    cout <<"Minutos: " << minutosT << endl;
    cout <<"Segundos: " << segundosT << endl;

    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

// Ejercicio n°10: Defina una estructura que sirva para representar a una persont.
// 1- La estructura debe contener 2 campos: nombre | Valor logico que indica si la persona tiene algun tipo de discapacidad.
// 2- Realice un programa que dado un vector de personas rellene 2 nuevos vectores:
// Uno que contenga las persona que no tienen ninguna discapacidad
// Otra que contenga las personas con discapacidad.

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct pacientes
{
    char nombre[30];
    bool discapacidad;
};

int main()
{ 
    int cantPacientes=0, posCon=0, posSin=0;
    pacientes pacientes[1000], Discapacitados[1000], noDicapacitados[1000];

    cout <<"\n\tBienvenido.\n\nIngrese la cantidad de pacientes: "; cin >> cantPacientes;

    for(int i=0; i<cantPacientes; i++)
    {
        cin.ignore();
        cout <<"\n" << i+1 <<". Paciente." << endl;
        cout <<"Nombre: "; cin.getline(pacientes[i].nombre, 30, '\n');
        cout << pacientes[i].nombre <<" tiene alguna discapacidad? (1 = true o 0 = false): "; cin >> pacientes[i].discapacidad;
        if(pacientes[i].discapacidad == 1)
        {
            strcpy(Discapacitados[posCon].nombre, pacientes[i].nombre);
            posCon++;
        }else{
            strcpy(noDicapacitados[posSin].nombre, pacientes[i].nombre);
            posSin++;
        }
    }

    cout<<"\n Personas con discapacidad: "<<endl;
	for(int i=0; i<posCon; i++){
		cout<< i+1 <<". "<<Discapacitados[i].nombre<<endl;
	}

	cout<<"\n Personas sin discapacidad: "<<endl;
	for(int i=0; i<posSin; i++){
		cout<< i+1 <<". "<<noDicapacitados[i].nombre<<endl;
	}
    
    cout <<"\n- Nahuel richeri\n";

    system("PAUSE");
    return 0;
}

