
#include <cstring>
#include <iostream>
#include "../include/Nivel.h"
#include "../utils/utils.h"
#include "../utils/ArchivoManager.h"

Nivel::Nivel(int idNivel, std::string nombreNivel)
{
    _idNivel = idNivel;
    setNombreNivel(nombreNivel);
}

Nivel::Nivel() {}

void Nivel::setId(int id) { _idNivel = id; }

int Nivel::getId() { return _idNivel; }

void Nivel::setNombreNivel(std::string nombreNivel) { strcpy(_nombreNivel, nombreNivel.c_str()); }

std::string Nivel::getNombreNivel() { return _nombreNivel; }

void Nivel::setEstado(bool estado) { _estado = estado; }

bool Nivel::getEstado() { return _estado; }

void Nivel::Cargar()
{
    std::cout << "Id del nivel: " << getNuevoId() << std::endl;
    setId(getNuevoId());
    std::cout << "Ingrese el nombre del nivel: ";
    cargarCadena(_nombreNivel, 30);
    setEstado(true);
}

void Nivel::Mostrar()
{
    if (getEstado() == true)
    {

        std::cout << "Id Nivel: " << getId() << std::endl;
        std::cout << "Nombre Nivel: " << getNombreNivel() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void Nivel::MostrarNombres(){
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    int cant = archivoNivel.cantidadRegistros();

    for(int i=0; i<cant; i++){
      nivel = archivoNivel.leerRegistro(nivel, i);
      cout << nivel.getId() << ": " << nivel.getNombreNivel() << " | ";
    }
    cout << endl;

}

void Nivel::MostrarNombre(int id){
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    int cant = archivoNivel.cantidadRegistros();

    for(int i=0; i<cant; i++){
      nivel = archivoNivel.leerRegistro(nivel, i);
      if(nivel.getId() == id && nivel.getEstado()){
         std::cout << nivel.getNombreNivel() << std::endl;
      }
    }
}
/*
std::string Nivel::MostrarNombre(int num)
{
      Nivel nivel;
      ArchivoManager<Nivel> archivoNivel("niveles.dat");


      int cant = archivoNivel.cantidadRegistros();

      for(int i=0;i<cant;i++){
         nivel = archivoNivel.leerRegistro(rol, i);
         if(num == nivel.getId() && nivel.getEstado()){
            return nivel.getNombreNivel();
         }
    }
}
*/
int Nivel::getNuevoId(){
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    int cant = archivoNivel.cantidadRegistros();
    if(cant > 0){
      nivel = archivoNivel.leerRegistro(nivel, cant-1);
      return nivel.getId() + 1;
    }
    else{
      return 1;
    }
}
