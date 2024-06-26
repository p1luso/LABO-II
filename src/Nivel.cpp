
#include <cstring>
#include <iostream>
#include "../include/Nivel.h"
#include "../utils/utils.h"


Nivel::Nivel(int idNivel, std::string nombreNivel)
{
    _idNivel = idNivel;
    setNombreNivel(nombreNivel);
}

Nivel::Nivel() {}

void Nivel::setId(int id) { _idNivel = id; }

int Nivel::getId() { return _idNivel; }

void Nivel::setNombreNivel(std::string nombreNivel) { strcpy(_nombreNivel, nombreNivel.c_str()); }

std::string Nivel::getNombreNivel() { return _nombreNivel; }

void Nivel::setEstado(bool estado) { _estado = estado; }

bool Nivel::getEstado() { return _estado; }

void Nivel::Cargar()
{
    std::cout << "Ingrese el id del nivel: ";
    std::cin >> _idNivel;
    std::cout << "Ingrese el nombre del nivel: ";
    cargarCadena(_nombreNivel, 30);
    setEstado(true);
}

void Nivel::Mostrar()
{
    if (getEstado() == true)
    {

        std::cout << "Id Nivel: " << getId() << std::endl;
        std::cout << "Nombre Nivel: " << getNombreNivel() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}
