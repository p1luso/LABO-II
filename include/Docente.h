#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"

class Docente : public Persona, public IRegistro
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

   void alta() override;

   void listar() override;

   void baja() override;
};
