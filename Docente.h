#include "persona.h"
#include <string>
#pragma once

class Docente
{
private:
   int _idDocente;
   char _turno[2];
   Persona _persona;

public:
   Docente(int idDocente, std::string turno, Persona persona);
   ~Docente();
   int getIdDocente();
   void setIdDocente(int idDocente);
   std::string getTurno();
   void setTurno(std::string turno);
   Persona getPersona();
   void setPersona(Persona persona);
};