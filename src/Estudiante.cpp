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

Asignatura Estudiante::getAsignatura() { return _asignatura; }
Curso Estudiante::getCurso() { return _curso; }
Nivel Estudiante::getNivel() { return _nivel; }
std::string Estudiante::getTurno() { return std::string(_turno); }

void Estudiante::setId(int idEstudiante) { _idEstudiante = idEstudiante; }
void Estudiante::setAsignatura(Asignatura asignatura) { _asignatura = asignatura; }
void Estudiante::setCurso(Curso curso) { _curso = curso; }
void Estudiante::setNivel(Nivel nivel) { _nivel = nivel; }
void Estudiante::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }

//cambiar!!
void Estudiante::agregarNota(std::string asignatura, float valor) {
    _notas.push_back(Nota(asignatura, valor));
}
//cambiar!!
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
    _asignatura.Cargar();
    _curso.Cargar();
    _nivel.Cargar();
    std::cout <<"Turno: ";
    cargarCadena(_turno, 30);
    setEstado(true);
}

//revisar esto, falta ¿asignatura?
void Estudiante::Mostrar() {
    if (getEstado()) {
        std::cout << "Id: " << getId() << std::endl;
        std::cout << "Id Usuario: " << getIdUser() << std::endl; //esto a que refiere? tiene dos id?
        std::cout << "DNI: " << getDni() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;
        std::cout << "Turno: "<<getTurno()<<std::endl;
        getNivel().Mostrar();
        getCurso().Mostrar();
        std::cout << "-------------------" << std::endl;
    }
}
