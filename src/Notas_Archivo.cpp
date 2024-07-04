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
   Docente docente;
   //UserId user;
   ArchivoManager<Docente> archivoDocente("docentes.dat");
   //ArchivoManager<UserId> archivoUser("Users.dat");
   docente = archivoDocente.buscarRegistroPorIdUser(docente, id);

   std::cout << "Ingrese Trimestre: 1-2-3: " << std::endl;
   std::cin >> _idTrimestre;
   std::cout << "Nivel: " << std::endl;
   nivel.MostrarNombre(docente.getIdNivel());
   std::cout << "Curso: " << std::endl;


   std::cout << "Asignatura: " << std::endl;
   std::cout << _idAsignatura;

}
