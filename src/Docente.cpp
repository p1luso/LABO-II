#include <iostream>
#include <string>
#include <cstring>
#include "../include/Docente.h"
#include "../utils/utils.h"

Docente::Docente() {}
Docente::~Docente() {}

int Docente::getId()
{
    return _id;
}

void Docente::setId(int idDocente)
{
    _id = idDocente;
}

Asignatura Docente::getIdAsignatura(){return _asignatura;};

std::string Docente::getTurno()
{
    return _turno;
}
std::string Docente::getNivel()
{
    return _nivel;
}
std::string Docente::getCurso()
{
    return _curso;
}

void Docente::setTurno(std::string turno)
{
    strcpy(_turno, turno.c_str());
}
void Docente::setIdAsignatura(Asignatura asignatura){_asignatura = asignatura;};
void Docente::setCurso(std::string curso)
{
    strcpy(_curso, curso.c_str());
}
void Docente::setNivel(std::string nivel)
{
    strcpy(_nivel, nivel.c_str());
}

void Docente::Cargar()
{
    int idAsignaturas = _asignatura.getId();


    std::cout << "IdDocente: ";
    std::cin >> _id;
    Persona::Cargar();
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
    _asignatura.Cargar();
    std::cout<< "Curso: ";
    cargarCadena(_curso, 50);
    std::cout<<"Nivel: ";
    cargarCadena(_nivel, 15);
    setEstado(true);
}

void Docente::Mostrar()
{
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Apellido: " << getApellido() << std::endl;
    std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
    std::cout << "Sexo: " << getSexo() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Telefono: " << getTelefono() << std::endl;
    std::cout << "Turno: " << getTurno() << std::endl;
    _asignatura.Mostrar();
    std::cout << "Curso: " <<getCurso()<<std::endl;
    std::cout << "Nivel: "<<getNivel()<<std::endl;
    std::cout << "-------------------" << std::endl;
}
