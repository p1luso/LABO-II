#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "../include/persona.h"

class Director : public Persona
{
private:
   int _idDirector;

public:
   Director();
   ~Director();
   void setId(int idDirector);
   void Cargar();
   int getId();
   void Mostrar();

   void altaDirector();

   void listarDirectores();

   void bajaDirector();
};
#endif // DIRECTOR_H
