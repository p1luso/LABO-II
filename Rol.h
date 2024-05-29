#include <string>
#pragma once


class Rol{
private:
   int _idRol;
   char _nombreRol[30];

public:
   Rol(int idRol, std::string nombreRol);

   void setIdRol(int id);
   int getIdRol();
   void setNombreRol(std::string nombreRol);
   std::string getNombreRol();

};
