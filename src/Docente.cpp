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

int Docente::getIdRol(){
   return _idRol;
}

Asignatura Docente::getIdAsignatura(){return _asignatura;}

std::string Docente::getTurno()
{
    return _turno;
}
Nivel Docente::getNivel()
{
    return _nivel;
}
Curso Docente::getCurso()
{
    return _curso;
}

void Docente::setTurno(std::string turno)
{
    strcpy(_turno, turno.c_str());
}
void Docente::setIdAsignatura(Asignatura asignatura){_asignatura = asignatura;}
void Docente::setCurso(Curso curso){_curso = curso;}
void Docente::setNivel(Nivel nivel)
{
    _nivel = nivel;
}

void Docente::Cargar()
{
    int idAsignaturas = _asignatura.getId();
    std::cout << "Id Docente: " << getNuevoId() << std::endl;
    _id = getNuevoId();
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol())<< std::endl;
    Persona::Cargar();
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
    _asignatura.Cargar();
    _curso.Cargar();
    _nivel.Cargar();
    //cargarCadena(_nivel, 15); //sacar?
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
    _curso.Mostrar();
    _nivel.Mostrar();
    std::cout << "-------------------" << std::endl;
}
