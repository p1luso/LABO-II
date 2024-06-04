#include <iostream>
#include <string>
#include <cstring>
#include "../include/Docente.h"
#include "../utils/utils.h"

Docente::Docente(int idDocente, std::string turno, const std::string &nombre, const std::string &apellido, const Fecha &fechaNacimiento, const std::string &sexo, const std::string &direccion, const std::string &email, const std::string &telefono)
{
    setId(idDocente);
    setTurno(turno);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
    setSexo(sexo);
    setDireccion(direccion);
    setEmail(email);
    setTelefono(telefono);
}
Docente::Docente() {}
Docente::~Docente() {}

int Docente::getId() { return _id; }

void Docente::setId(int idDocente) { _id = idDocente; }

std::string Docente::getTurno() { return _turno; }

void Docente::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }

void Docente::Cargar()
{
    std::cout << "IdDocente: ";
    std::cin >> _id;
    Persona::Cargar();
    std::cout << "Turno: ";
    cargarCadena(_turno, 10);
}

void Docente::Mostrar()
{
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Apellido: " << getApellido() << std::endl;
    std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
    std::cout << "Sexo: " << getSexo() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Telefono: " << getTelefono() << std::endl;
    std::cout << "Turno: " << getTurno() << std::endl;
}