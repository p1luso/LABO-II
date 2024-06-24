#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Curso.h"

void Curso::altaCurso()
{
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    curso.Cargar();

    archivoCurso.guardarRegistro(curso);
}

void Curso::listarCursos()
{
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");

    archivoCurso.listarRegistro(curso);
}

void Curso::bajaCurso()
{
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    int id;
    cout << "Ingrese el id de la Curso a eliminar: ";
    cin >> id;

    int idPos = archivoCurso.buscarRegistro(curso, id);
    if (idPos == -1)
    {
        cout << "No se encontro la Curso" << endl;
        return;
    }

    curso = archivoCurso.leerRegistro(curso, idPos);

    if (curso.getEstado() == true)
    {
        curso.Mostrar();
        cout << "Desea eliminar la Curso? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            curso.setEstado(false);
            archivoCurso.modificarRegistro(curso, idPos);
            cout << "Curso eliminado " << endl;
        }
    }
    else
    {
        cout << "El Curso ya no existe o fue eliminado " << endl;
    }
}