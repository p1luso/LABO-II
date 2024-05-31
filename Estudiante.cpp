#include <string>
#include <cstring>
#include "Estudiante.h"

Estudiante::Estudiante(int idEstudiante, std::string turno, Persona persona)
{
   setIdEstudiante(idEstudiante);
   setTurno(turno);
   setPersona(persona);
}
void Estudiante::setIdEstudiante(int idEstudiante)
{
   _idEstudiante = idEstudiante;
}
int Estudiante::getIdEstudiante()
{
   return _idEstudiante;
}
void Estudiante::setTurno(std::string turno)
{
   std::strcpy(_turno, turno.c_str());
}
std::string Estudiante::getTurno()
{
   return std::string(_turno);
}
Persona Estudiante::getPersona()
{
   return _persona;
}
void Estudiante::setPersona(Persona persona)
{
   _persona = persona;
}