#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Curso.h"

void Curso::alta()
{
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");

    curso.Cargar();

    if(!archivoCurso.guardarRegistro(curso)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;
        system("pause");

}

void Curso::listar()
{
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    int posY = 1; // Inicializar posY para la posición vertical de inicio

    archivoCurso.listarRegistro(curso);
        system("pause");

}


void Curso::baja()
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
        int posY = 2; // Definir la posición inicial Y
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
        system("pause");

}


void Curso::MostrarNombres(){
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    int cant = archivoCurso.cantidadRegistros();

    for(int i=0; i<=cant; i++){
      curso = archivoCurso.leerRegistro(curso, i);
      cout << curso.getId() << ": " << curso.getNombrCurso() << " | ";
    }
    cout << endl;

}

void Curso::MostrarNombre(int id){
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    int cant = archivoCurso.cantidadRegistros();

    for(int i=0; i<cant; i++){
      curso = archivoCurso.leerRegistro(curso, i);
      if(curso.getId() == id && curso.getEstado()){
         std::cout << curso.getNombrCurso() << std::endl;
      }
    }
}
