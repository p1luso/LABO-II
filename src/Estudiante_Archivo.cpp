#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Estudiante.h"

void Estudiante::alta()
{
    Estudiante estudiante;
    Persona user;

    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
    ArchivoManager<Persona> archivoUsers("users.dat");

    estudiante.Cargar();

    archivoEstudiante.guardarRegistro(estudiante);
    archivoUsers.guardarRegistro(user);
}

void Estudiante::listar()
{
    Estudiante estudiante;
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

    archivoEstudiante.listarRegistro(estudiante);
}

void Estudiante::baja()
{
    Estudiante estudiante;
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
    int id;
    cout << "Ingrese el id del Estudiante a eliminar: ";
    cin >> id;

    int idPos = archivoEstudiante.buscarRegistro(estudiante, id);
    if (idPos == -1)
    {
        cout << "No se encontro el Estudiante" << endl;
        return;
    }

    estudiante = archivoEstudiante.leerRegistro(estudiante, idPos);

    if (estudiante.getEstado() == true)
    {
        estudiante.Mostrar();
        cout << "Desea eliminar el Estudiante? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            estudiante.setEstado(false);
            archivoEstudiante.modificarRegistro(estudiante, idPos);
            cout << "Estudiante eliminado " << endl;
        }
    }
    else
    {
        cout << "El Estudiante ya no existe o fue eliminado " << endl;
    }
}
