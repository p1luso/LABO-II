#include <string>
#pragma once

class Curso
{
private:
   int _idCurso;
   char _nombreCurso[100];

public:
   Curso(int idCurso, std::string nombrCurso);
   Curso();

   void setId(int id);
   int getId();
   void setNombrCurso(std::string nombrCurso);
   std::string getNombrCurso();

   void Cargar();

   void Mostrar();
};