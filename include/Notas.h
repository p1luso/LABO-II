#pragma once
#include <iostream>
#include "../utils/ArchivoManager.h"
#include "../include/Nivel.h"
#include "../include/Curso.h"
#include "../include/Asignatura.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "../utils/Menus.h"

class Notas {
private:
   int _idTrimestre;
   int _idNivel;
   int _idCurso;
   int _idAsignatura;
   int _idDocente;
   int _idEstudiante;
   float _nota;

public:
   Nivel nivel;
   Curso curso;
   Asignatura asignatura;
   Docente docente;
   Estudiante estudiante;


   void setIdTrimestre(int idTri);
   void setIdNivel(int idNivel);
   void setIdCurso(int idCurso);
   void setIdAsignatura(int idAsignatura);
   void setIdDocente(int idDocente);
   void setIdEstudiante(int idEstudiante);
   void setNota(float nota);

   int getIdTrimestre();
   int getIdNivel();
   int getIdCurso();
   int getIdAsignatura();
   int getIdDocente();
   int getIdEstudiante();
   float getNota();

   void listar();
   void CargarNotas(int dni);
   void Mostrar();



};



