#include <string>
#pragma once

class Asignatura
{
private:
   int _idAsignatura;
   char _nombreAsignatura[30];
   bool _estado;

public:
   Asignatura(int idRol, std::string nombreAsignatura);
   Asignatura();

   void setId(int id);
   int getId();
   void setNombreAsignatura(std::string nombreAsignatura);
   std::string getNombreAsignatura();
   void setEstado(bool estado);
   bool getEstado();

   void Cargar();
   void Mostrar();

   void altaAsignatura();

   void listarAsignaturas();

   void bajaAsignatura();
};
