#include <iostream>
#include <string>
#include <cstring>
#include "../include/Estudiante.h"
#include "../utils/utils.h"

Estudiante::Estudiante() {}

Estudiante::~Estudiante() {}

int Estudiante::getId() { return _idEstudiante; }

int Estudiante::getIdRol(){
   return _idRol;
}

std::string Estudiante::getAsignatura() { return std::string(_asignatura); }
std::string Estudiante::getCurso() { return std::string(_curso); }
std::string Estudiante::getNivel() { return std::string(_nivel); }
std::string Estudiante::getTurno() { return std::string(_turno); }

void Estudiante::setId(int idEstudiante) { _idEstudiante = idEstudiante; }
void Estudiante::setAsignatura(std::string asignatura) { strcpy(_asignatura, asignatura.c_str()); }
void Estudiante::setCurso(std::string curso) { strcpy(_curso, curso.c_str()); }
void Estudiante::setNivel(std::string nivel) { strcpy(_nivel, nivel.c_str()); }
void Estudiante::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }

void Estudiante::agregarNota(std::string asignatura, float valor) {
    _notas.push_back(Nota(asignatura, valor));
}

void Estudiante::listarNotas() {
    std::cout << "Notas del estudiante " << getNombre() << " " << getApellido() << ":" << std::endl;
    for (const auto& nota : _notas) {
        std::cout << "Asignatura: " << nota.asignatura << ", Nota: " << nota.valor << std::endl;
    }
}

void Estudiante::Cargar() {
    std::cout << "Id Estudiante: " << getNuevoId() << std::endl;
    setId(getNuevoId());
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol())<< std::endl;
    Persona::Cargar();
    std::cout << "Asignatura: ";
    cargarCadena(_asignatura, 50);
    std::cout << "Curso: ";
    cargarCadena(_curso, 50);
    std::cout << "Nivel: ";
    cargarCadena(_nivel, 50);
    std::cout <<"Turno: ";
    cargarCadena(_turno, 30);
    setEstado(true);
}

void Estudiante::Mostrar() {
    if (getEstado()) {
        std::cout << "Id: " << getId() << std::endl;
        std::cout << "Id Usuario: " << getIdUser() << std::endl;
        std::cout << "DNI: " << getNombre() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;
        std::cout << "Turno: "<<getTurno()<<std::endl;
        std::cout << "Nivel: "<<getNivel()<<std::endl;
        std::cout << "Curso: "<<getCurso()<<std::endl;
        std::cout << "-------------------" << std::endl;
    }
}
