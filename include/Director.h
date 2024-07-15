#pragma once
#include "../include/persona.h"
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

class Director : public Persona, public IRegistro
{
private:
   int _idDirector;
   char _nombreRol[10] = "Director";
   int _idNivel;
public:
   Director();
   ~Director();

   void setId(int idDirector);
   void setIdNivel(int idNivel);
   int getId();
   std::string getNombreRol();
   int getIdNivel();

   void Cargar();
   void Mostrar();

   void docentePorCriterio(const std::string &criterio);
   void estudiantePorCriterio(const std::string &criterio);
   void listarNotasPorAsig();

   int getNuevoId();
   void guardarUser();
   void alta() override;

   void listar() override;

   void baja() override;
};

