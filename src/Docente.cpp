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

///Asignatura Docente::getIdAsignatura(){return _asignatura;}

int Docente::getIdNivel(){ return _idNivel; }
int Docente::getIdCurso(){ return _idCurso; }
int Docente::getIdAsignatura(){ return _idAsignatura; }
std::string Docente::getTurno(){ return _turno; }

///void Docente::setIdAsignatura(Asignatura asignatura){_asignatura = asignatura;}
void Docente::setIdNivel(int idNivel){ _idNivel = idNivel; }
void Docente::setIdCurso(int idCurso){ _idCurso = idCurso; }
void Docente::setIdAsignatura(int idAsignatura){ _idAsignatura = idAsignatura; }
void Docente::setTurno(std::string turno){ strcpy(_turno, turno.c_str()); }

void CargarNotas(){


}

void Docente::Cargar()
{
    _id = getNuevoId();
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol()) << std::endl;
    Persona::Cargar();
    std::cout<<"Nivel: ";
    std::cin >> _idNivel;
    ///_asignatura.Cargar();
    std::cout<< "Curso: ";
    std::cin >> _idCurso;
    std::cout<< "Asignatura: ";
    std::cin >> _idAsignatura;
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
    setEstado(true);
}

void Docente::Mostrar()
{
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Apellido: " << getApellido() << std::endl;
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
    std::cout << "Sexo: " << getSexo() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Telefono: " << getTelefono() << std::endl;
    std::cout << "Nivel: "<<getIdNivel()<<std::endl;
    std::cout << "Curso: " <<getIdCurso()<<std::endl;
    std::cout << "Turno: " << getTurno() << std::endl;
    ///_asignatura.Mostrar();
    std::cout << "-------------------" << std::endl;
}
