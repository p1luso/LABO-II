#include "persona.h"
#include <string>
#pragma once

class Director
{
private:
   int _idDirector;
   Persona _persona;

public:
   Director(int idDirector, Persona persona);
   ~Director();
   int getIdDirector();
   void setIdDirector(int idDirector);
   Persona getPersona();
   void setPersona(Persona persona);
};
