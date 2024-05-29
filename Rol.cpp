
#include "Rol.h"
#include <cstring>

Rol::Rol(int idRol, std::string nombreRol){
   _idRol = 0;
   strcpy(_nombreRol, "");
}

void Rol::setIdRol(int id){
   _idRol = id;
}
int Rol::getIdRol(){
   return _idRol;
}
void Rol::setNombreRol(std::string nombreRol){
   strcpy(_nombreRol, nombreRol.c_str());
}
std::string Rol::getNombreRol(){
   return std::string(_nombreRol);
}
