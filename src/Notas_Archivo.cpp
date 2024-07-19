#include <iostream>
#include <ctime>
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
   Notas notas2;
   Trimestre trimestre;
   ArchivoManager<Docente> archivoDocente("docentes.dat");
   ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
   ArchivoManager<Notas> archivoNotas("notas.dat");
   ArchivoManager<Trimestre> archivoTrimestre("trimestres.dat");

   docente = archivoDocente.buscarRegistroPorIdUser(docente, id);

   int cantidad = archivoEstudiante.cantidadRegistros();
   int cant = archivoNotas.cantidadRegistros();
   int cant2 = archivoTrimestre.cantidadRegistros();

   time_t t = time(NULL);
   struct tm *f = localtime(&t);
   int dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
   int mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
   int anio = f->tm_year + 1900;

//int dia = 3;
//int mes = 4;
//int anio = 2024;

      std::cout << "Trimestre: ";
      for(int i=0;i<cant2;i++){
         trimestre = archivoTrimestre.leerRegistro(trimestre, i);
         if(mes>=trimestre.getFechaInicio().getMes() && mes<=trimestre.getFechaFinal().getMes()){
               std::cout << trimestre.getTrimestre() << std::endl;
               notas._idTrimestre = trimestre.getTrimestre();
         }
      }

      std::cout << "Nivel: ";
      nivel.MostrarNombre(docente.getIdNivel());
      notas.setIdNivel(docente.getIdNivel());
      std::cout << "Curso: ";
      curso.MostrarNombre(docente.getIdCurso());
      notas.setIdCurso(docente.getIdCurso());
      std::cout << "Asignatura: ";
      asignatura.MostrarNombre(docente.getIdAsignatura());
      notas.setIdAsignatura(docente.getIdAsignatura());
      notas.setIdDocente(docente.getId());
      std::cout << "------------------------------------------------" << std::endl;

   for (int i = 0; i < cantidad; i++){
      estudiante = archivoEstudiante.leerRegistro(estudiante, i);
      bool aux = false;
      if(docente.getIdNivel() == estudiante.getIdNivel() && docente.getIdCurso() == estudiante.getIdCurso() && estudiante.getEstado()){
         std::cout << "Estudiante: ";
         std::cout << estudiante.getApellido() << ", "<< estudiante.getNombre() << endl;
         notas.setIdEstudiante(estudiante.getId());
         if(cant<0){
            std::cout << "Nota: ";
            std::cin >> _nota;
            notas.setNota(_nota);
            if(!archivoNotas.guardarRegistro(notas)){
               cout << "No se pudo guardar!" << endl;
               cout << "------------------" << endl;
               system ("pause");
            }
            else{
               cout << "Se guardo con exito! " << endl;
               system ("pause");
            }
         }
         else if(cant>0){
            for(int j=0;j<cant;j++){
               notas2 = archivoNotas.leerRegistro(notas2, j);
               if(notas2.getIdEstudiante() == estudiante.getId() && notas2.getNota()>0 && docente.getIdAsignatura() == notas2.getIdAsignatura() && notas2.getIdTrimestre() == trimestre.getTrimestre()){
                  std::cout << "El Estudiante ya tiene Nota en este trimestre: " << std::endl;
                  std::cout << "Nota: " <<notas2.getNota() << std::endl;
                  aux = true;
                  system ("pause");
                  std::cout << "------------------------------------------------" << std::endl;
               }
            }
         }
         if(!aux){
            std::cout << "Nota: ";
            std::cin >> _nota;
            notas.setNota(_nota);
            if(!archivoNotas.guardarRegistro(notas)){
               cout << "No se pudo guardar!" << endl;
               cout << "------------------" << endl;
               system ("pause");
            }else{
               cout << "Se guardo con exito! " << endl;
               system ("pause");
            }
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

      int idDocente = archivoDocente.buscarRegistro(docente, Notas::getIdDocente());
      int idEstu = archivoEstudiante.buscarRegistro(estudiante, getIdEstudiante());
      docente = archivoDocente.leerRegistro(docente, idDocente);
      estudiante = archivoEstudiante.leerRegistro(estudiante, idEstu);

      std::cout << std::endl;
      std::cout << "TRIMESTRE:      " << getIdTrimestre() << std::endl;
      std::cout << std::endl;
      std::cout << "Id Estudiante:  " << getIdEstudiante() << std::endl;
      std::cout << "Estudiante:     " << estudiante.getApellido() << " " << estudiante.getNombre() << std::endl;
      std::cout << "Nivel:          ";
      nivel.MostrarNombre(getIdNivel());
      std::cout << "Curso:          ";
      curso.MostrarNombre(getIdCurso());
      std::cout << "Asignatura:     ";
      asignatura.MostrarNombre(getIdAsignatura());
      std::cout << "Docente:        " << docente.getApellido() << " " << docente.getNombre() << std::endl;
      std::cout << "Nota:           " << getNota() << std::endl;
      std::cout << std::endl;
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

void Notas::modificar(){
   int idEstu;
   float nota;
   int pos;
   Menus menus;
   Notas notas;
   ArchivoManager<Notas> archivoNotas("notas.dat");
   int cant = archivoNotas.cantidadRegistros();
   system ("cls");
   std::cout << "Ingrese Id del estudiante a modificar la nota: ";
   std::cin >> idEstu;
   for(int i=0;i<cant;i++){
      notas = archivoNotas.leerRegistro(notas, i);
      if(idEstu == notas.getIdEstudiante()){
         notas.Mostrar();
         std::cout << "Ingrese nueva nota: ";
         std::cin >> nota;
         std::cout << "Desea modificar la nota? (s/n): " << std::endl;
         char opcion;
         std::cin >> opcion;
         if (opcion == 's' || opcion == 'S')
         {
            pos = archivoNotas.buscarNotas(notas, idEstu);
            notas.setNota(nota);
            archivoNotas.modificarNotas(notas, nota, pos);
            std::cout << "Nota modificada " << std::endl;
            std::cout << notas.getNota() << std::endl;
         }
      }
   }
   system("pause");
   system ("cls");
   menus.subMenuDoc();
}





