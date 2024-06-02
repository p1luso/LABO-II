#pragma once
#include "persona.h"
#include <string>

class Docente : public Persona
{
private:
   int _id;
   char _turno[10];

public:
   Docente(int idDocente, std::string turno, const std::string &nombre, const std::string &apellido, const Fecha &fechaNacimiento, const std::string &sexo, const std::string &direccion, const std::string &email, const std::string &telefono);
   Docente();
   ~Docente();
   int getId();
   void setId(int idDocente);
   std::string getTurno();
   void setTurno(std::string turno);
   void Cargar();
   void Mostrar();
};