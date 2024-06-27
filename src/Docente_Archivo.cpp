#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Docente.h"

void Docente::listarEstudiantesPorMateria()
{
    system("cls");
    ArchivoManager<Docente> archivoDocentes("docentes.dat");

    // Obtener el ID del docente actual (suponiendo que tienes un método getId() en Docente)
    int idDocente = getId();

    // Obtener la asignatura del docente usando el ID
    std::string asignaturaDocente = archivoDocentes.obtenerAsignaturaPorId(idDocente);

    if (!asignaturaDocente.empty())
    {
        std::cout << "Estudiantes que cursan la asignatura " << asignaturaDocente << ":" << std::endl;

        // Listar estudiantes por la asignatura del docente
        ArchivoManager<Estudiante> archivoEstudiantes("estudiantes.dat");
        archivoEstudiantes.listarEstudiantesPorCriterio("asignatura", asignaturaDocente);
    }
    else
    {
        std::cout << "No se encontró la asignatura del docente con ID: " << idDocente << std::endl;
    }

    system("pause");
    system("cls");
}


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
