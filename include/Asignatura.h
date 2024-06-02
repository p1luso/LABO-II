#include <string>
#pragma once

class Asignatura
{
private:
   int _idAsignatura;
   char _nombreAsignatura[30];

public:
   Asignatura(int idRol, std::string nombreAsignatura);

   void setIdAsignatura(int id);
   int getIdAsignatura();
   void setNombreAsignatura(std::string nombreAsignatura);
   std::string getNombreAsignatura();
};
