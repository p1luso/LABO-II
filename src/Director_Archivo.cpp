#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Director.h"

void Director::alta()
{
    Director director;
    Persona user;

    ArchivoManager<Director> archivoDirector("directores.dat");
    ArchivoManager<Persona> archivoUsers("users.dat");

    director.Cargar();

    archivoDirector.guardarRegistro(director);
    archivoUsers.guardarRegistro(user);
}

void Director::listar()
{
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");

    archivoDirector.listarRegistro(director);
}

void Director::baja()
{
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");
    int id;
    cout << "Ingrese el id de la Director a eliminar: ";
    cin >> id;

    int idPos = archivoDirector.buscarRegistro(director, id);
    if (idPos == -1)
    {
        cout << "No se encontro el Director" << endl;
        return;
    }

    director = archivoDirector.leerRegistro(director, idPos);

    if (director.getEstado() == true)
    {
        director.Mostrar();
        cout << "Desea eliminar la Director? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            director.setEstado(false);
            archivoDirector.modificarRegistro(director, idPos);
            cout << "Director eliminado " << endl;
        }
    }
    else
    {
        cout << "El Director ya no existe o fue eliminado " << endl;
    }
}
