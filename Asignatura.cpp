#include "Asignatura.h"
#include <cstring>

Asignatura::Asignatura(int idAsignatura, std::string nombreAsignatura)
{
   _idAsignatura = 0;
   strcpy(_nombreAsignatura, "");
}

void Asignatura::setIdAsignatura(int id)
{
   _idAsignatura = id;
}
int Asignatura::getIdAsignatura()
{
   return _idAsignatura;
}
void Asignatura::setNombreAsignatura(std::string nombreAsignatura)
{
   strcpy(_nombreAsignatura, nombreAsignatura.c_str());
}
std::string Asignatura::getNombreAsignatura()
{
   return std::string(_nombreAsignatura);
}