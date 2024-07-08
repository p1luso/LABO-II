#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

#pragma once

class Asignatura : public IRegistro
{
private:
   int _idAsignatura;
   char _nombreAsignatura[30];
   int _idNivel;
   bool _estado;

public:

   Asignatura();

   void setId(int id);
   int getId();
   void setIdNivel(int id);
   int getIdNivel();
   void setNombreAsignatura(std::string nombreAsignatura);
   std::string getNombreAsignatura();
   void setEstado(bool estado);
   bool getEstado();

   int getNuevoId();

   void Cargar();
   void Mostrar();
   void MostrarNombre(int id);
   void MostrarNombresPorNivel(int id);

   void alta();

   void listar();

   void baja();
};
