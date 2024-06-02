#include <iostream>
#include <string>
#include <cstring>
#include "../include/Estudiante.h"
#include "../utils/utils.h"

Estudiante::Estudiante(int idEstudiante, std::string turno, const std::string &nombre, const std::string &apellido, const Fecha &fechaNacimiento, const std::string &sexo, const std::string email, const std::string &direccion, const std::string &telefono)
{
    setId(idEstudiante);
    setTurno(turno);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
    setSexo(sexo);
    setEmail(email);
    setDireccion(direccion);
    setTelefono(telefono);
}

Estudiante::Estudiante() {}

Estudiante::~Estudiante() {}

int Estudiante::getId() { return _idEstudiante; }

void Estudiante::setId(int idEstudiante) { _idEstudiante = idEstudiante; }

std::string Estudiante::getTurno() { return _turno; }

void Estudiante::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }

void Estudiante::Cargar()
{
    std::cout << "IdEstudiante: ";
    std::cin >> _idEstudiante;
    Persona::Cargar();
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
}

void Estudiante::Mostrar()
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
    std::cout << "-------------------" << std::endl;
}
