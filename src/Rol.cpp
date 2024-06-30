#include <iostream>
#include <cstring>
#include "../include/Rol.h"
#include "../utils/utils.h"
#include "../utils/ArchivoManager.h"

Rol::Rol(int idRol, std::string nombreRol)
{
    _idRol = idRol;
    setNombreRol(nombreRol);
}

Rol::Rol() {}

void Rol::setId(int id) { _idRol = id; }

int Rol::getId() { return _idRol; }

void Rol::setNombreRol(std::string nombreRol) { strcpy(_nombreRol, nombreRol.c_str()); }

std::string Rol::getNombreRol() { return std::string(_nombreRol); }

void Rol::setEstado(bool estado) { _estado = estado; }

bool Rol::getEstado() { return _estado; }

void Rol::Cargar()
{
    std::cout << "Id Rol: ";
    std::cin >> _idRol;
    std::cout << "Nombre Rol: ";
    cargarCadena(_nombreRol, 30);
    setEstado(true);
}

void Rol::Mostrar()
{
    if (_estado == true)
    {
      std::cout << "---------------------" << std::endl;
      std::cout << "Id Rol: " << _idRol << std::endl;
      std::cout << "Nombre Rol: " << _nombreRol << std::endl;
      std::cout << "---------------------" << std::endl;
    }
}

std::string Rol::MostrarNombre(int num)
{
      Rol rol;
      ArchivoManager<Rol> archivoRol("roles.dat");


      int cant = archivoRol.cantidadRegistros();

      for(int i=0;i<cant;i++){
         rol = archivoRol.leerRegistro(rol, i);
         if(num == rol.getId() && rol.getEstado()){
            return rol.getNombreRol();

         }



    }
}
