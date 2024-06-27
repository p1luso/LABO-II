#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

#pragma once

class Curso : public IRegistro
{
private:
   int _idCurso;
   char _nombreCurso[100];
   bool _estado;

public:
   Curso(int idCurso, std::string nombrCurso);
   Curso();

   void setId(int id);
   int getId();
   void setNombrCurso(std::string nombrCurso);
   std::string getNombrCurso();
   void setEstado(bool estado);
   bool getEstado();

   void Cargar();

   void Mostrar();

   void alta();

   void listar();

   void baja();
};
