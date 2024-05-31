#include "Curso.h"
#include <cstring>

Curso::Curso(int idCurso, std::string nombrCurso)
{
   _idCurso = 0;
   strcpy(_nombreCurso, "");
}

void Curso::setICurso(int id)
{
   _idCurso = id;
}
int Curso::getICurso()
{
   return _idCurso;
}

void Curso::setNombrCurso(std::string nombrCurso)
{
   strcpy(_nombreCurso, nombrCurso.c_str());
}

std::string Curso::getNombrCurso()
{
   return std::string(_nombreCurso);
}