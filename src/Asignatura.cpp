#include <cstring>
#include <iostream>
#include "../include/Asignatura.h"
#include "../utils/utils.h"
#include "../utils/ArchivoManager.h"
#include "../include/Nivel.h"

Asignatura::Asignatura() {}

void Asignatura::setId(int id) { _idAsignatura = id; }

int Asignatura::getId() { return _idAsignatura; }

void Asignatura::setIdNivel(int id) { _idNivel = id; }


int Asignatura::getIdNivel() { return _idNivel; }


void Asignatura::setNombreAsignatura(std::string nombreAsignatura) { strcpy(_nombreAsignatura, nombreAsignatura.c_str()); }

std::string Asignatura::getNombreAsignatura() { return std::string(_nombreAsignatura); }

void Asignatura::setEstado(bool estado) { _estado = estado; }

bool Asignatura::getEstado() { return _estado; }

void Asignatura::Cargar()
{
    Nivel nivel;
    std::cout << "Id Asignatura: " << getNuevoId() << std::endl;
    setId(getNuevoId());
    std::cout << "Selecione el Nivel: " << std::endl;
    nivel.MostrarNombres();
    std::cin >> _idNivel;
    std::cout << "Nombre Asignatura: ";
    cargarCadena(_nombreAsignatura, 30);
    setEstado(true);

}

void Asignatura::Mostrar()
{
   Nivel nivel;
    if (getEstado() == true)
    {
        std::cout<< "ID: " << getId() << std::endl;
        std::cout<< "Nivel: ";
        nivel.MostrarNombre(getIdNivel());
        std::cout << "Nombre: " << getNombreAsignatura() << std::endl;
        std::cout << "*********************** " << std::endl;
    }
}
void Asignatura::MostrarNombre(int id){
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    int cant = archivoAsignatura.cantidadRegistros();

    for(int i=0; i<cant; i++){
      asignatura = archivoAsignatura.leerRegistro(asignatura, i);
      if(asignatura.getId() == id && asignatura.getEstado()){
         std::cout << asignatura.getNombreAsignatura() << std::endl;
      }
    }
}
void Asignatura::MostrarNombresPorNivel(int id){
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    int cant = archivoAsignatura.cantidadRegistros();

    for(int i=0; i<=cant; i++){
      asignatura = archivoAsignatura.leerRegistro(asignatura, i);
      if(asignatura.getIdNivel() == id){
         cout << asignatura.getId() << ": " << asignatura.getNombreAsignatura() << " | ";
      }
    }
    cout << ": ";

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
