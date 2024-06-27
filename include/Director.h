#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "../include/persona.h"
#include "../utils/IRegistros.h"

class Director : public Persona, public IRegistro
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

   void alta() override;

   void listar() override;

   void baja() override;
};
#endif // DIRECTOR_H
