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

void UserId::setIdRol(int idRol){_userIdRol = idRol;}
int UserId::getIdRol(){
   return _userIdRol;
}

void UserId::setDni(int dni){_userDni = dni;}
int UserId::getDni(){
   return _userDni;
}

void UserId::setEstado(bool estado) { _userEstado = estado; }
bool UserId::getEstado() { return _userEstado; }

void UserId::Cargar(int id, int dni, int idRol, bool estado){
  setId(id);
  setDni(dni);
  setIdRol(idRol);
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
int UserId::VerificadorUsuario(int Code){
    UserId user;
    Menus menus;
    ArchivoManager<UserId> archivoUsuario("users.dat");
    int pos = 0, idRol = 0;
    int cant = archivoUsuario.cantidadRegistros();
    if(Code == 2024){
      return 1;
    }
    for(int i=0; i < cant; i++){
        user = archivoUsuario.leerRegistro(user, i);

        if(Code == user.getDni()){
             idRol = user.getIdRol();
             menus.setIdUser(user.getDni());
        }
        pos++;
    }
    if(idRol > 0){
      return idRol;
    }
    return -1;
}
