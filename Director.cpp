#include <string>
#include <cstring>
#include "Director.h"

Director::Director(int idDirector, Persona persona)
{
   setIdDirector(idDirector);
   setPersona(persona);
}
void Director::setIdDirector(int idDirector)
{
   _idDirector = idDirector;
}
int Director::getIdDirector()
{
   return _idDirector;
}
Persona Director::getPersona()
{
   return _persona;
}