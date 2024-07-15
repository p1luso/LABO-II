#include <iostream>
#include <string>
#include <cstring>

#include "../include/Director.h"
#include "../include/Nivel.h"


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

std::string Director::getNombreRol(){ return _nombreRol; }

void Director::setIdNivel(int idNivel){ _idNivel = idNivel; }
int Director::getIdNivel(){ return _idNivel; }

void Director::Cargar()
{
   Nivel nivel;
    _idDirector = getNuevoId();
    std::cout << "Rol: " << getNombreRol() << std::endl;
    std::cout<<"Selecione el Nivel: " << std::endl;
    nivel.MostrarNombres();
    std::cin >> _idNivel;
    Persona::Cargar();
    Persona::setEstado(true);
}

void Director::Mostrar()
{
    Nivel nivel;
    if (getEstado() == true)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "ID: " << getId() << std::endl;
        std::cout << "ID Usuario: " << getIdUser() << std::endl;
        std::cout << "Nivel: ";
        nivel.MostrarNombre(getIdNivel());
        std::cout << "DNI: " << getDni() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;

        std::cout << "--------------------------" << std::endl;
    }
}
