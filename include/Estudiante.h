#include "persona.h"
#include <string>
#pragma once

class Estudiante
{
private:
   int _idEstudiante;
   char _turno[2];
   Persona _persona;

public:
   Estudiante(int idEstudiante, std::string turno, Persona persona);
   ~Estudiante();
   int getIdEstudiante();
   void setIdEstudiante(int idEstudiante);
   std::string getTurno();
   void setTurno(std::string turno);
   Persona getPersona();
   void setPersona(Persona persona);
};
