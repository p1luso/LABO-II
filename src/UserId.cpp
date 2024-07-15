#include <iostream>
#include <string>
#include <cstring>
#include "../include/UserId.h"
#include "../utils/ArchivoManager.h"
#include "../utils/Menus.h"



void UserId::setId(int id){_userId = id;}
int UserId::getIdUser(){
   return _userId;
}

void UserId::setNombreRol(std::string nombreRol) { strcpy(_nombreRol, nombreRol.c_str()); }
std::string UserId::getNombreRol() { return _nombreRol; }

void UserId::setDni(int dni){_userDni = dni;}
int UserId::getDni(){
   return _userDni;
}

void UserId::setEstado(bool estado) { _userEstado = estado; }
bool UserId::getEstado() { return _userEstado; }

void UserId::Cargar(int id, int dni, std::string nombreRol, bool estado){
  setId(id);
  setDni(dni);
  setNombreRol(nombreRol);
  setEstado(estado);
}

void UserId::Mostrar()
{
    if (getEstado() == true)
    {
        std::cout << "ID: " << getIdUser() << std::endl;
        std::cout << "Dni: " << getDni() << std::endl;

    }
}
int UserId::VerificadorUsuario(int code){
    UserId user;

    ArchivoManager<UserId> archivoUsuario("users.dat");
    int pos = 0, idRol = 0;
    int cant = archivoUsuario.cantidadRegistros();
    if(code == 2024){
      return 1;
    }
    for(int i=0; i < cant; i++){
        user = archivoUsuario.leerRegistro(user, i);

        if(code == user.getDni()){
            if(user.getNombreRol()=="Administrador"){
               return 1;
            }
            if(user.getNombreRol()=="Director"){
               return 2;
            }
            if(user.getNombreRol()=="Docente"){
               return 3;
            }
            if(user.getNombreRol()=="Estudiante"){
               return 4;
            }
        }
        pos++;
    }

    return -1;
}

UserId UserId::ObtenerUserConDni(int dni){
    UserId user;

    ArchivoManager<UserId> archivoUsuario("users.dat");
    int pos = 0, idRol = 0;
    int cant = archivoUsuario.cantidadRegistros();

    for(int i=0; i < cant; i++){
        user = archivoUsuario.leerRegistro(user, i);

        if(dni == user.getDni()){
             return user;
        }
        pos++;
    }

      return user;

}
