#pragma once
#include <string>

class Rol
{
private:
   int _idRol;
   char _nombreRol[30];
   bool _estado;

public:
   Rol(int idRol, std::string nombreRol);
   Rol();

   void setId(int id);
   int getId();
   void setNombreRol(std::string nombreRol);
   std::string getNombreRol();

   void setEstado(bool estado);
   bool getEstado();

   void Cargar();

   void Mostrar();

   void altaRol();

   void listarRoles();

   void bajaRol();
};
