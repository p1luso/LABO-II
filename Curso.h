#include <string>
#pragma once

class Curso
{
private:
   int _idCurso;
   char _nombreCurso[30];

public:
   Curso(int idCurso, std::string nombrCurso);

   void setICurso(int id);
   int getICurso();
   void setNombrCurso(std::string nombrCurso);
   std::string getNombrCurso();
};