#include <string>
#pragma once

class Nivel
{
private:
   int _idNivel;
   char _nombreNivel[30];

public:
   Nivel(int idNivel, std::string nombreNivel);
   Nivel();

   void setId(int id);
   int getId();
   void setNombreNivel(std::string nombreNivel);
   std::string getNombreNivel();

   void Cargar();

   void Mostrar();
};
