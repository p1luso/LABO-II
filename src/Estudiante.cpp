#include <iostream>
#include <string>
#include <cstring>
#include "../include/Estudiante.h"
#include "../utils/utils.h"

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
    setEstado(true);
}

void Estudiante::Mostrar()
{
    if (getEstado() == true)
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
}
