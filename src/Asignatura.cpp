#include <cstring>
#include <iostream>
#include "../include/Asignatura.h"
#include "../utils/utils.h"

Asignatura::Asignatura(int idAsignatura, std::string nombreAsignatura)
{
    _idAsignatura = 0;
    setNombreAsignatura(nombreAsignatura);
}

Asignatura::Asignatura(){}

void Asignatura::setId(int id) { _idAsignatura = id; }

int Asignatura::getId() { return _idAsignatura; }

void Asignatura::setNombreAsignatura(std::string nombreAsignatura) { strcpy(_nombreAsignatura, nombreAsignatura.c_str()); }

std::string Asignatura::getNombreAsignatura() { return std::string(_nombreAsignatura); }

void Asignatura::Cargar()
{
    std::cout << "Id Asignatura: ";
    std::cin >> _idAsignatura;
    std::cout << "Nombre Asignatura: ";
    cargarCadena(_nombreAsignatura, 30);
}

void Asignatura::Mostrar()

{
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombreAsignatura() << std::endl;
}
