#include <string>
#pragma once

class Nivel
{
private:
   int _idNivel;
   char _nombreNivel[30];

public:
   Nivel(int idRol, std::string nombrenivel);

   void setIdNivel(int id);
   int getIdNivel();
   void setNombreNivel(std::string nombreNivel);
   std::string getNombreNivel();
};