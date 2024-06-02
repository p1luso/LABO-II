#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
#include "../utils/rlutil.h"
#include "../utils/ArchivoManager.h"
#include "../include/Director.h"
#include "../include/persona.h"
#include "../utils/utils.h"

// testeo de la clase Director con herencia de Persona
void GuardarDirector()
{
    ArchivoManager<Director> archivoDirector("directores.dat");
    Director director(1, "pedro", "fermin", Fecha(1, 1, 1990), "M", "Av. Siempre Viva 123", "123456789");

    archivoDirector.guardarRegistro(director);
}

void mostrarDirector()
{
    ArchivoManager<Director> archivoDirector("directores.dat");
    Director director;

    archivoDirector.listarRegistro(director);
    cout << endl;
}

void contarDirector()
{
    ArchivoManager<Director> archivoDirector("directores.dat");
    Director director;

    cout << "Cantidad de directores: " << archivoDirector.cantidadRegistros(director) << endl;
}