#pragma once
#include "../include/persona.h"
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"
#include "../include/Rol.h"

class Director : public Persona, public IRegistro
{
private:
   int _idDirector;
   int _idRol = 2;
public:
   Director();
   ~Director();

   Rol rol;

   void setId(int idDirector);
   int getId();
   int getIdRol();

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

