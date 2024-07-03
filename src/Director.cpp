#include <iostream>
#include <string>
#include <cstring>

#include "../include/Director.h"


Director::Director() {}

Director::~Director() {}

int Director::getId()
{
    return _idDirector;
}

void Director::setId(int idDirector)
{
    _idDirector = idDirector;
}

int Director::getIdRol(){
   return _idRol;
}

void Director::Cargar()
{
    _idDirector = getNuevoId();
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol()) << std::endl;
    Persona::Cargar();
    Persona::setEstado(true);
}

void Director::Mostrar()
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
