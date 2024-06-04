#include <string>
#pragma once

class Asignatura
{
private:
   int _idAsignatura;
   char _nombreAsignatura[30];

public:
   Asignatura(int idRol, std::string nombreAsignatura);
   Asignatura();

   void setId(int id);
   int getId();
   void setNombreAsignatura(std::string nombreAsignatura);
   std::string getNombreAsignatura();

   void Cargar();
   void Mostrar();
};
