#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

#pragma once

class Asignatura : public IRegistro
{
private:
   int _idAsignatura;
   char _nombreAsignatura[30];
   bool _estado;

public:

   Asignatura();

   void setId(int id);
   int getId();
   void setNombreAsignatura(std::string nombreAsignatura);
   std::string getNombreAsignatura();
   void setEstado(bool estado);
   bool getEstado();

   int getNuevoId();

   void Cargar();
   void Mostrar();
   void MostrarNombre(int id);

   void alta();

   void listar();

   void baja();
};
