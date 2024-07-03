
#include <iostream>
#include <cstring>
#include "../include/Curso.h"
#include "../utils/utils.h"
#include "../utils/ArchivoManager.h"

Curso::Curso(int idCurso, std::string nombrCurso)
{
    _idCurso = 0;
    setNombrCurso(nombrCurso);
}

Curso::Curso() {}

void Curso::setIdNivel(int id){ _idNivel = id;}
int Curso::getIdNivel(){ return _idNivel;}

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
    std::cout << "Selecione el Nivel: " << std::endl;
    nivel.MostrarNombres();
    std::cout << ": ";
    std::cin >> _idNivel;
    std::cout << "Nombre Curso: ";
    cargarCadena(_nombreCurso, 50);
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
        std::cout << "Nivel: " << getIdNivel() << std::endl;
        std::cout << "ID: " << getId() << std::endl;
        std::cout << "Nombre: " << getNombrCurso() << std::endl;

    }
}

int Curso::getNuevoId(){
    Curso curso;
    ArchivoManager<Curso> archivoCurso("cursos.dat");
    int cant = archivoCurso.cantidadRegistros();
    if(cant > 0){
      curso = archivoCurso.leerRegistro(curso, cant-1);
      return curso.getId() + 1;
    }
    else{
      return 1;
    }
}
