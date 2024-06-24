#pragma once
#include "persona.h"
#include <string>

class Estudiante : public Persona
{
private:
   int _idEstudiante;
   char _turno[10];

public:
   Estudiante();
   ~Estudiante();
   int getId();
   void setId(int idEstudiante);
   std::string getTurno();
   void setTurno(std::string turno);

   void Cargar();

   void Mostrar();

   void altaEstudiante();

   void listarEstudiantes();

   void bajaEstudiante();
};
