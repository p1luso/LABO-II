#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "../include/Director.h"

    Director::Director(int idDirector, const string &nombre, const string &apellido, const Fecha &fechaNacimiento, const string &sexo, const string &direccion, const string &telefono)
{
   setIdDirector(idDirector);
   setNombre(nombre);
   setApellido(apellido);
   setFechaNacimiento(fechaNacimiento);
   setSexo(sexo);
   setDireccion(direccion);
   setTelefono(telefono);
}

Director::Director(){};

Director::~Director(){};

int Director::getIdDirector() { return _idDirector; }

void Director::setIdDirector(int idDirector) { _idDirector = idDirector; }

void Director::Mostrar()
{
   cout << "ID: " << getIdDirector() << endl;
   cout << "Nombre: " << getNombre() << endl;
   cout << "Apellido: " << getApellido() << endl;
   cout << "Fecha de nacimiento: " << getFechaNacimiento().getDia() << "/" << getFechaNacimiento().getMes() << "/" << getFechaNacimiento().getAnio() << endl;
   cout << "Sexo: " << getSexo() << endl;
   cout << "Direccion: " << getDireccion() << endl;
   cout << "Telefono: " << getTelefono() << endl;
}
