#include <iostream>
#include <string>
#include <cstring>

#include "../include/Admin.h"


int Admin::getId()
{
    return _idAdmin;
}

void Admin::setId(int idAdmin)
{
    _idAdmin = idAdmin;
}

int Admin::getIdRol(){
   return _idRol;
}

void Admin::Cargar()
{
    _idAdmin = getNuevoId();
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol()) << std::endl;

    Persona::Cargar();
    Persona::setEstado(true);
}

void Admin::Mostrar()
{
    if (getEstado() == true)
    {
        std::cout << "ID: " << getId() << std::endl;
        std::cout << "ID Usuario: " << getIdUser() << std::endl;
        std::cout << "DNI: " << getDni() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;
    }
}
