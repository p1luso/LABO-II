#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"
#include "../include/Nivel.h"
#pragma once

class Curso : public IRegistro
{
private:
   int _idNivel;
   int _idCurso;
   char _nombreCurso[50];
   bool _estado;

public:
   Curso(int idCurso, std::string nombrCurso);
   Curso();

   Nivel nivel;

   void setIdNivel(int id);
   int getIdNivel();
   void setId(int id);
   int getId();
   void setNombrCurso(std::string nombrCurso);
   std::string getNombrCurso();
   void setEstado(bool estado);
   bool getEstado();

   int getNuevoId();

   void Cargar();

   void Mostrar();
   void MostrarNombres();

   void alta();

   void listar();

   void baja();
};
