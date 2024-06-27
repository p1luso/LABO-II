#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Docente.h"


void Docente::alta()
{
    Docente docente;
    Persona user;

    ArchivoManager<Docente> archivoDocente("docentes.dat");
    ArchivoManager<Persona> archivoUsers("users.dat");

    docente.Cargar();

    archivoDocente.guardarRegistro(docente);
    archivoUsers.guardarRegistro(user);
    system("pause");

}

void Docente::listar()
{
    Docente docente;
    ArchivoManager<Docente> archivoDocente("docentes.dat");
    int posY = 1; // Inicializar posY para la posición vertical de inicio
    archivoDocente.listarRegistro(docente);
    system("pause");

}

void Docente::baja()
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
        int posY = 2; // Definir la posición inicial Y
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
    system("pause");
}
