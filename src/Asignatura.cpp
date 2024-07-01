#include <cstring>
#include <iostream>
#include "../include/Asignatura.h"
#include "../utils/utils.h"
#include "../utils/ArchivoManager.h"

Asignatura::Asignatura() {}

void Asignatura::setId(int id) { _idAsignatura = id; }

int Asignatura::getId() { return _idAsignatura; }

void Asignatura::setNombreAsignatura(std::string nombreAsignatura) { strcpy(_nombreAsignatura, nombreAsignatura.c_str()); }

std::string Asignatura::getNombreAsignatura() { return std::string(_nombreAsignatura); }

void Asignatura::setEstado(bool estado) { _estado = estado; }

bool Asignatura::getEstado() { return _estado; }

void Asignatura::Cargar()
{
    std::cout << "Id Asignatura: " << getNuevoId() << std::endl;
    setId(getNuevoId());
    std::cout << "Nombre Asignatura: ";
    cargarCadena(_nombreAsignatura, 30);
    setEstado(true);

}

void Asignatura::Mostrar()
{
    if (getEstado() == true)
    {
        std::cout<< "ID: " << getId() << std::endl;
        std::cout << "Nombre: " << getNombreAsignatura() << std::endl;
    }
}
int Asignatura::getNuevoId(){
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    int cant = archivoAsignatura.cantidadRegistros();
    if(cant > 0){
      asignatura = archivoAsignatura.leerRegistro(asignatura, cant-1);
      return asignatura.getId() + 1;
    }
    else{
      return 1;
    }
}
