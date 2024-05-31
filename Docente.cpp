#include <string>
#include <cstring>
#include "Docente.h"

Docente::Docente(int idDocente, std::string turno, Persona persona)
{
   setIdDocente(idDocente);
   setTurno(turno);
   setPersona(persona);
}
void Docente::setIdDocente(int idDocente)
{
   _idDocente = idDocente;
}
int Docente::getIdDocente()
{
   return _idDocente;
}
void Docente::setTurno(std::string turno)
{
   std::strcpy(_turno, turno.c_str());
}
std::string Docente::getTurno()
{
   return std::string(_turno);
}
Persona Docente::getPersona()
{
   return _persona;
}
void Docente::setPersona(Persona persona)
{
   _persona = persona;
}
