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

int Estudiante::getIdCurso() { return _idCurso; }
int Estudiante::getIdNivel() { return _idNivel; }
int Estudiante::getIdAsignatura(){ return _idAsignatura; }
std::string Estudiante::getTurno() { return std::string(_turno); }

void Estudiante::setId(int idEstudiante) { _idEstudiante = idEstudiante; }
void Estudiante::setIdCurso(int idCurso) { _idCurso = idCurso; }
void Estudiante::setIdNivel(int  idNivel) { _idNivel = idNivel; }
void Estudiante::setIdAsignatura(int idAsignatura){ _idAsignatura = idAsignatura; }
void Estudiante::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }
/*
void Estudiante::agregarNota(std::string asignatura, float valor) {
    _notas.push_back(Nota(asignatura, valor));
}

void Estudiante::listarNotas() {
    std::cout << "Notas del estudiante " << getNombre() << " " << getApellido() << ":" << std::endl;
    for (const auto& nota : _notas) {
        std::cout << "Asignatura: " << nota.asignatura << ", Nota: " << nota.valor << std::endl;
    }
}
*/
void Estudiante::Cargar() {
    _idEstudiante = getNuevoId();
    std::cout << "Rol: " << rol.MostrarNombre(getIdRol()) << std::endl;
    Persona::Cargar();
    std::cout << "Nivel: ";
    std::cin >> _idNivel;
    std::cout << "Curso: " << std::endl;
    curso.MostrarNombres();
    std::cin >> _idCurso;
    std::cout <<"Turno M - Mañana | T - Tarde: ";
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
        std::cout << "Nivel: "<<getIdNivel()<<std::endl;
        std::cout << "Curso: "<<getIdCurso()<<std::endl;
        std::cout << "Turno: "<<getTurno()<<std::endl;
        std::cout << "-------------------" << std::endl;
    }
}


