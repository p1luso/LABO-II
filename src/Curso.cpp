
#include <iostream>
#include <cstring>
#include "../include/Curso.h"
#include "../utils/utils.h"

Curso::Curso(int idCurso, std::string nombrCurso)
{
    _idCurso = 0;
    setNombrCurso(nombrCurso);
}

Curso::Curso() {}

void Curso::setId(int id) { _idCurso = id; }

int Curso::getId() { return _idCurso; }

void Curso::setNombrCurso(std::string nombrCurso) { strcpy(_nombreCurso, nombrCurso.c_str()); }

std::string Curso::getNombrCurso() { return _nombreCurso; }

void Curso::setEstado(bool estado) { _estado = estado; }

bool Curso::getEstado() { return _estado; }

void Curso::Cargar()
{
    std::cout << "Id Curso: " << getNuevoId() << std::endl;
    setId(getNuevoId());
    std::cout << "Nombre Curso: ";
    cargarCadena(_nombreCurso, 30);
    setEstado(true);
}

void Curso::Mostrar()
{
    if (getEstado() == false)
    {
        return;
    }
    else
    {

        std::cout << "ID: " << getId() << std::endl;
        std::cout << "Nombre: " << getNombrCurso() << std::endl;
    }
}
