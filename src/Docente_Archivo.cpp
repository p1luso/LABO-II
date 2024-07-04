#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "../include/Asignatura.h"
#include "../include/UserId.h"

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
                if(asignatura.getNombreAsignatura() == estudiante.getAsignatura().getNombreAsignatura())
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

    ArchivoManager<Docente> archivoDocente("docentes.dat");

    docente.Cargar();

    archivoDocente.guardarRegistro(docente);
    Persona persona;
    UserId user;
    ArchivoManager<UserId> archivoUser("users.dat");

    int cant = archivoDocente.cantidadRegistros();
    archivoDocente.leerRegistro(docente, cant);
    int id = docente.getIdUser();
    int dni = docente.getDni();
    int idRol = docente.getIdRol();
    bool estado = docente.getEstado();
    user.Cargar(id, dni, idRol, estado);

    archivoUser.guardarRegistro(user);
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

int Docente::getNuevoId(){
    Docente docente;
    ArchivoManager<Docente> archivoDocente("docentes.dat");
    int cant = archivoDocente.cantidadRegistros();
    if(cant > 0){
      docente = archivoDocente.leerRegistro(docente, cant-1);
      return docente.getId() + 1;
    }
    else{
      return 1;
    }
}
