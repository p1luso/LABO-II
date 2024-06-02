#pragma once
#include "persona.h"
#include <string>

class Estudiante : public Persona
{
private:
   int _idEstudiante;
   char _turno[10];

public:
   Estudiante(int idEstudiante, std::string turno, const std::string &nombre, const std::string &apellido, const Fecha &fechaNacimiento, const std::string &sexo, const std::string email, const std::string &direccion, const std::string &telefono);
   Estudiante();
   ~Estudiante();
   int getId();
   void setId(int idEstudiante);
   std::string getTurno();
   void setTurno(std::string turno);

   void Cargar();

   void Mostrar();
};
