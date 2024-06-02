#include <string>
#pragma once

class Nivel
{
private:
   int _idNivel;
   char _nombreNivel[30];

public:
   Nivel(int idNivel, std::string nombreNivel);

   void setIdNivel(int id);
   int getIdNivel();
   void setNombreNivel(std::string nombreNivel);
   std::string getNombreNivel();
};
