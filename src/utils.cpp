#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
#include "../utils/rlutil.h"
#include "../utils/ArchivoManager.h"
#include "../include/Admin.h"
#include "../include/Director.h"
#include "../include/persona.h"
#include "../include/Asignatura.h"
#include "../include/Curso.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "../include/Nivel.h"
#include "../utils/Menus.h"

// testeo de la clase Director con herencia de Persona
// void GuardarDirector()
// {
//     ArchivoManager<Director> archivoDirector("directores.dat");
//     Director director(1, "pedro", "fermin", Fecha(1, 1, 1990), "M", "Av. Siempre Viva 123", "123456789");

//     archivoDirector.guardarRegistro(director);
// }

// void mostrarDirector()
// {
//     ArchivoManager<Director> archivoDirector("directores.dat");
//     Director director;

//     archivoDirector.listarRegistro(director);
//     cout << endl;
// }

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = cin.get();
        if (pal[i] == '\n')
            break;
    }
    pal[i] = '\0';
    fflush(stdin);
}

/*void contarDirector()
{
    ArchivoManager<Director> archivoDirector("directores.dat");
    Director director;

    cout << "Cantidad de directores: " << archivoDirector.cantidadRegistros(director) << endl;
}*/

void tests()
{
    Menus menu;
    menu.Login();
}
