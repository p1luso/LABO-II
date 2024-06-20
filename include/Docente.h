#pragma once
#include "persona.h"
#include <string>

class Docente : public Persona
{
private:
   int _id;
   char _turno[10];

public:
   Docente();
   ~Docente();
   int getId();
   std::string getTurno();
   void setId(int idDocente);
   void setTurno(std::string turno);

   void Cargar();

   void Mostrar();

   void altaDocente();

   void listarDocentes();

   void bajaDocente();
};