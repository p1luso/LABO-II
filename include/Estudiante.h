#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"

class Estudiante : public Persona, public IRegistro
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

   void alta() override;

   void listar() override;

   void baja() override;
};
