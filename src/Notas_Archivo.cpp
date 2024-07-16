#include <iostream>

#include "../utils/ArchivoManager.h"
#include "../include/Notas.h"



void Notas::setIdTrimestre(int idTri){ _idTrimestre = idTri;}
void Notas::setIdNivel(int idNivel){ _idNivel = idNivel; }
void Notas::setIdCurso(int idCurso){ _idCurso = idCurso; }
void Notas::setIdAsignatura(int idAsignatura){ _idAsignatura = idAsignatura; }
void Notas::setIdDocente(int idDocente){ _idDocente = idDocente;}
void Notas::setIdEstudiante(int idEstudiante){ _idEstudiante = idEstudiante; }
void Notas::setNota(float nota){ _nota = nota; }

int Notas::getIdTrimestre(){ return _idTrimestre; }
int Notas::getIdNivel(){ return _idNivel; }
int Notas::getIdCurso(){ return _idCurso; }
int Notas::getIdAsignatura(){ return _idAsignatura; }
int Notas::getIdDocente(){ return _idDocente; }
int Notas::getIdEstudiante(){ return _idEstudiante; }
float Notas::getNota(){ return _nota; }

void Notas::CargarNotas(int id){
   system ("cls");
   Menus menus;
   Docente docente;
   Estudiante estudiante;
   Notas notas;
   ArchivoManager<Docente> archivoDocente("docentes.dat");
   ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
   ArchivoManager<Notas> archivoNotas("notas.dat");

   docente = archivoDocente.buscarRegistroPorIdUser(docente, id);

   int cantidad = archivoEstudiante.cantidadRegistros();
      std::cout << "Ingrese Trimestre: 1-2-3: " << std::endl;
      std::cin >> notas._idTrimestre;
      std::cout << "Nivel: ";
      nivel.MostrarNombre(docente.getIdNivel());
      notas.setIdNivel(docente.getIdNivel());
      std::cout << "Curso: ";
      curso.MostrarNombre(docente.getIdCurso());
      notas.setIdCurso(docente.getIdCurso());
      std::cout << "Asignatura: ";
      asignatura.MostrarNombre(docente.getIdAsignatura());
      notas.setIdAsignatura(docente.getIdAsignatura());
   for (int i = 0; i < cantidad; i++){
      estudiante = archivoEstudiante.leerRegistro(estudiante, i);
      notas.setIdDocente(docente.getId());

      if(docente.getIdNivel() == estudiante.getIdNivel() && docente.getIdCurso() == estudiante.getIdCurso() && estudiante.getEstado()){
         std::cout << "Estudiante: ";
         std::cout << estudiante.getApellido() << ", "<< estudiante.getNombre() << endl;
         notas.setIdEstudiante(estudiante.getId());
         std::cout << "Nota: ";
         std::cin >> notas._nota;
         if(!archivoNotas.guardarRegistro(notas)){
            cout << "No se pudo guardar!" << endl;
            system ("pause");
         }else{
            cout << "Se guardo con exito! " << endl;
            system ("pause");
         }
      }
    }

   system ("pause");
   system ("cls");
   menus.subMenuDoc();
}

void Notas::Mostrar(){
   //system ("cls");
      Docente docente;
      Estudiante estudiante;
      ArchivoManager<Docente> archivoDocente("docentes.dat");
      ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

      int idDocente = archivoDocente.buscarRegistro(docente, getIdDocente());
      int idEstu = archivoEstudiante.buscarRegistro(estudiante, getIdEstudiante());
      docente = archivoDocente.leerRegistro(docente, idDocente);
      estudiante = archivoEstudiante.leerRegistro(estudiante, idEstu);
      std::cout << "TRIMESTRE: " << getIdTrimestre() << std::endl;
      std::cout << "Nivel: ";
      nivel.MostrarNombre(docente.getIdNivel());
      std::cout << "Curso: ";
      curso.MostrarNombre(docente.getIdCurso());
      std::cout << "Asignatura: ";
      asignatura.MostrarNombre(docente.getIdAsignatura());
      std::cout << "Docente: " << docente.getApellido() << " " << docente.getNombre() << std::endl;
      std::cout << "Estudiante: " << estudiante.getApellido() << " " << estudiante.getNombre() << std::endl;
      std::cout << "Nota: " << getNota() << std::endl;
      std::cout << "******************" << std::endl;
}

void Notas::listar(int id){
    Menus menus;
    Docente docente;
    Notas notas;
    ArchivoManager<Notas> archivoNotas("notas.dat");
    ArchivoManager<Docente> archivoDocente("docentes.dat");
    docente = archivoDocente.buscarRegistroPorIdUser(docente, id);
    system ("cls");
    archivoNotas.listarNotas(notas, docente.getIdAsignatura());
    system("pause");
    system ("cls");
    menus.subMenuDoc();
}





