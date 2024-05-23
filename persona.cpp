#include <iostream>
#include <string>
using namespace std;
#include "persona.h"

// constructor
Persona::Persona()
{
    _id = 0;
    _dni = 0;
    _nombre = "";
    _apellido = "";
    _edad = 0;
    _sexo = "";
    _direccion = "";
    _telefono = "";
}

// set y get de Id
void Persona::setId(int id) { _id = id; }
int Persona::getId() { return _id; }

// set y get de dni
void Persona::setDni(int dni) { _dni = dni; }
int Persona::getDni() { return _dni; }

// set y get de nombre
void Persona::setNombre(string nombre) { _nombre = nombre; }
string Persona::getNombre() { return _nombre; }

// set y get de apellido
void Persona::setApellido(string apellido) { _apellido = apellido; }
string Persona::getApellido() { return _apellido; }

// set y get de edad
void Persona::setEdad(int edad) { _edad = edad; }
int Persona::getEdad() { return _edad; }

// set y get de sexo
void Persona::setSexo(string sexo) { _sexo = sexo; }
string Persona::getSexo() { return _sexo; }

// set y get de direccion
void Persona::setDireccion(string direccion) { _direccion = direccion; }
string Persona::getDireccion() { return _direccion; }

// set y get de telefono
void Persona::setTelefono(string telefono) { _telefono = telefono; }
string Persona::getTelefono() { return _telefono; }
