#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../utils/utils.h"
#include "../include/UserId.h"
#include "../include/Rol.h"

// constructor
Persona::Persona() {}

// destructor

// set y get de Id

void Persona::setIdUser(int id) { _idUser = id;}

int Persona::getIdUser(){
   return _idUser;
}

// set y get de dni
void Persona::setDni(int dni) { _dni = dni; }
int Persona::getDni() { return _dni; }

// set y get de nombre
void Persona::setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }
std::string Persona::getNombre() { return _nombre; }

// set y get de apellido
void Persona::setApellido(std::string apellido) { strcpy(_apellido, apellido.c_str()); }
std::string Persona::getApellido() { return _apellido; }

// set y get de edad
void Persona::setFechaNacimiento(Fecha fechaNacimiento) { _fechaNacimiento = fechaNacimiento; }
Fecha Persona::getFechaNacimiento() { return _fechaNacimiento; }

// set y get de sexo
void Persona::setSexo(std::string sexo) { strcpy(_sexo, sexo.c_str()); }
std::string Persona::getSexo() { return _sexo; }

// set y get de email
void Persona::setEmail(std::string email) { strcpy(_email, email.c_str()); }
std::string Persona::getEmail() { return _email; }

// set y get de direccion
void Persona::setDireccion(std::string direccion) { strcpy(_direccion, direccion.c_str()); }
std::string Persona::getDireccion() { return _direccion; }

// set y get de telefono
void Persona::setTelefono(std::string telefono) { strcpy(_telefono, telefono.c_str()); }
std::string Persona::getTelefono() { return _telefono; }

// set y get de estado
void Persona::setEstado(bool estado) { _estado = estado; }
bool Persona::getEstado() { return _estado; }


void Persona::Cargar()
{
    Rol rol;
    cout << "UserId: " << getNuevoId() << endl;
    _idUser = getNuevoId();
    cout << "DNI: ";
    cin >> _dni;
    cout << "Nombre: ";
    cargarCadena(_nombre, 50);
    cout << "Apellido: ";
    cargarCadena(_apellido, 50);
    cout << "Fecha de nacimiento: " << endl;
    _fechaNacimiento.Cargar();
    cout << "Sexo: ";
    cargarCadena(_sexo, 10);
    cout << "Email: ";
    cargarCadena(_email, 50);
    cout << "Direccion: ";
    cargarCadena(_direccion, 100);
    cout << "Telefono: ";
    cargarCadena(_telefono, 50);
    setEstado(true);
}
void Persona::Mostrar(){
      std::cout << "ID: " << getIdUser() << std::endl;
      std::cout << "Nombre: " << getDni() << std::endl;
}

int Persona::getNuevoId(){
    UserId user;
    ArchivoManager<UserId> archivoUser("users.dat");
    int cant = archivoUser.cantidadRegistros();
    if(cant > 0){

      user = archivoUser.leerRegistro(user, cant-1);
      return user.getIdUser()+1;
    }
    else{
      return 1;
    }
}

