#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "../include/Asignatura.h"

void Docente::listarEstudiantesPorMateria()
{
    system("cls");
    ArchivoManager<Docente> archivoDocentes("docentes.dat");
    ArchivoManager<Asignatura> archivoAsig("asignaturas.dat");
    ArchivoManager<Estudiante> archivoEst("estudiantes.dat");

    Asignatura asignatura;
    Docente docente;
    Estudiante estudiante;

    int cantRDocentes = archivoDocentes.cantidadRegistros();
    int cantREstudiantes = archivoEst.cantidadRegistros();
    int cantRAsignatura = archivoAsig.cantidadRegistros();

    for(int j = 0; j < cantRAsignatura; j++)
    {

        asignatura = archivoAsig.leerRegistro(asignatura, j);

        if(asignatura.getId() == 1)
        {
            for(int x = 0; x < cantREstudiantes; x++)
            {
                estudiante = archivoEst.leerRegistro(estudiante,x);
                if(asignatura.getNombreAsignatura() == estudiante.getAsignatura())
                {
                    std::cout<<estudiante.getNombre()<<" "<<estudiante.getApellido()<<std::endl;
                    std::cout<<"--------------------------"<<std::endl;
                }
            }
        }

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
