#include <iostream>
#include <string>
#include <cstring>
#include "../include/Docente.h"
#include "../utils/utils.h"
#include "../include/Nivel.h"
#include "../include/Curso.h"

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

std::string Docente::getNombreRol(){ return _nombreRol; }

int Docente::getIdNivel(){ return _idNivel; }
int Docente::getIdCurso(){ return _idCurso; }
int Docente::getIdAsignatura(){ return _idAsignatura; }
std::string Docente::getTurno(){ return _turno; }

///void Docente::setIdAsignatura(Asignatura asignatura){_asignatura = asignatura;}
void Docente::setIdNivel(int idNivel){ _idNivel = idNivel; }
void Docente::setIdCurso(int idCurso){ _idCurso = idCurso; }
void Docente::setIdAsignatura(int idAsignatura){ _idAsignatura = idAsignatura; }
void Docente::setTurno(std::string turno){ strcpy(_turno, turno.c_str()); }

void Docente::Cargar()
{
   Nivel nivel;
   Curso curso;
   Asignatura asignatura;
    _id = getNuevoId();
    std::cout << "Rol: " << getNombreRol() << std::endl;
    Persona::Cargar();
    std::cout<<"Selecione el Nivel: " << std::endl;
    nivel.MostrarNombres();
    std::cin >> _idNivel;
    std::cout<< "Selecione Curso: " << std::endl;
    curso.MostrarNombresPorNivel(getIdNivel());
    std::cin >> _idCurso;
    std::cout<< "Asignatura: " << std::endl;
    asignatura.MostrarNombresPorNivel(getIdNivel());
    std::cin >> _idAsignatura;
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
    setEstado(true);
}

void Docente::Mostrar()
{
   Nivel nivel;
   Curso curso;
   Asignatura asignatura;
   //rlutil::locate(10,1);
   if (getEstado() == true){
    std::cout << "---------------------------" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Apellido: " << getApellido() << std::endl;
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
    std::cout << "Sexo: " << getSexo() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Telefono: " << getTelefono() << std::endl;
    std::cout << "Nivel: ";
    nivel.MostrarNombre(getIdNivel());
    std::cout << "Curso: ";
    curso.MostrarNombre(getIdCurso());
    std::cout << "Asignatura: ";
    asignatura.MostrarNombre(getIdAsignatura());
    std::cout << "Turno: " << getTurno() << std::endl;
    std::cout << "---------------------------" << std::endl;
   }
}
