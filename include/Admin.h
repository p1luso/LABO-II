#pragma once
#include "../include/persona.h"
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

class Admin : public Persona, public IRegistro
{
private:
   int _idAdmin;
   char _nombreRol[20] = "Administrador";
public:
   void setId(int idAdmin);
   int getId();
   std::string getNombreRol();

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

