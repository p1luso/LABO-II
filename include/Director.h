#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "../include/persona.h"

class Director : public Persona
{
private:
   int _idDirector;

public:
   Director(int idDirector, const std::string &nombre, const std::string &apellido, const Fecha &fechaNacimiento, const std::string &sexo, const std::string email, const std::string &direccion, const std::string &telefono);
   Director();
   ~Director();
   int getId();
   void setId(int idDirector);
   void Cargar();
   void Mostrar();
};
#endif // DIRECTOR_H
