#include <iostream>
#include "../include/UserId.h"
#include "../utils/ArchivoManager.h"
/*
int UserId::VerificadorUsuario(int Code){
    UserId user;
    ArchivoManager<UserId> archivoUsuario("users.dat");

    int cant = archivoUsuario.cantidadRegistros();

    UserId *usuarios = new UserId[cant];
    if (usuarios == nullptr)
    {
        std::cout << "Error al reservar memoria" << std::endl;
        return -200;
    }
    for (int i = 0; i < cant; i++)
    {
       archivoUsuario.leerRegistro(user, i+1);
       if(Code == user.getDni()){
          delete[] usuarios;
          return user.getIdRol();
       }

    }

    delete[] usuarios;
    return -1;
}
*/
