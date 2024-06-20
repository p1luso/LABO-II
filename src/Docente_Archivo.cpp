#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Docente.h"

void Docente::altaDocente()
{
    Docente docente;
    Persona user;

    ArchivoManager<Docente> archivoDocente("docentes.dat");
    ArchivoManager<Persona> archivoUsers("users.dat");

    docente.Cargar();

    archivoDocente.guardarRegistro(docente);
    archivoUsers.guardarRegistro(user);
}

void Docente::listarDocentes()
{
    Docente docente;
    ArchivoManager<Docente> archivoDocente("docentes.dat");

    archivoDocente.listarRegistro(docente);
}

void Docente::bajaDocente()
{
    Docente docente;
    ArchivoManager<Docente> archivoDocente("docentes.dat");
    int id;
    cout << "Ingrese el id de la Docente a eliminar: ";
    cin >> id;

    int idPos = archivoDocente.buscarRegistro(docente, id);
    if (idPos == -1)
    {
        cout << "No se encontro el Docente" << endl;
        return;
    }

    docente = archivoDocente.leerRegistro(docente, idPos);

    if (docente.getEstado() == true)
    {
        docente.Mostrar();
        cout << "Desea eliminar la Docente? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            docente.setEstado(false);
            archivoDocente.modificarRegistro(docente, idPos);
            cout << "Docente eliminado " << endl;
        }
    }
    else
    {
        cout << "El Docente ya no existe o fue eliminado " << endl;
    }
}