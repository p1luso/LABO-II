
#include <iostream>
#include <cstring>
#include "../include/Curso.h"
#include "../utils/utils.h"

Curso::Curso(int idCurso, std::string nombrCurso)
{
    _idCurso = 0;
    setNombrCurso(nombrCurso);
}

Curso::Curso(){};

void Curso::setId(int id) { _idCurso = id; }

int Curso::getId() { return _idCurso; }

void Curso::setNombrCurso(std::string nombrCurso) { strcpy(_nombreCurso, nombrCurso.c_str()); }

std::string Curso::getNombrCurso() { return _nombreCurso; }

void Curso::Cargar()
{
    std::cout << "Id Curso: ";
    std::cin >> _idCurso;
    std::cout << "Nombre Curso: ";
    cargarCadena(_nombreCurso, 30);
}

void Curso::Mostrar()
{
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombrCurso() << std::endl;
}