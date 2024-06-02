#pragma once
#include <string>

class Rol
{
private:
   int _idRol;
   char _nombreRol[30];

public:
   Rol(int idRol, std::string nombreRol);
   Rol();

   void setId(int id);
   int getId();
   void setNombreRol(std::string nombreRol);
   std::string getNombreRol();

   void Cargar();
   void Mostrar();
};
