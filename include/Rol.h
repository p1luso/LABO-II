#pragma once
#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"


class Rol : public IRegistro
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

   void alta();

   void listar();

   void baja();
};
