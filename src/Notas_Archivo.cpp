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
   int opcion;
   Menus menus;
   Docente docente;
   Estudiante estudiante;




   ArchivoManager<Docente> archivoDocente("docentes.dat");
   ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

   docente = archivoDocente.buscarRegistroPorIdUser(docente, id);

   std::cout << "Ingrese Trimestre: 1-2-3: " << std::endl;
   std::cin >> _idTrimestre;
   std::cout << "Nivel: ";
   nivel.MostrarNombre(docente.getIdNivel());
   std::cout << "Curso: ";
   curso.MostrarNombre(docente.getIdCurso());
   std::cout << "Asignatura: ";
   asignatura.MostrarNombre(docente.getIdAsignatura());
   std::cout << "Estudiante: ";
   //estudiante.MostrarNombre(estudiante.());

   std::cout << "Notas: ";

    Notas notas;
    ArchivoManager<Notas> archivoNotas("notas.dat");

    if(!archivoNotas.guardarRegistro(notas)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;

   std::cout << "Desea cargar otra nota: 1 - SI, 2 - NO: ";
   std::cin >> opcion;
   system ("pause");


   system ("cls");
   menus.subMenuDoc();
}


