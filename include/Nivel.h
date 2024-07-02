#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"

#pragma once

class Nivel : public IRegistro
{
private:
   int _idNivel;
   char _nombreNivel[30];
   bool _estado;

public:
    void alta() override;
    void listar() override;
    void baja() override;
   Nivel(int idNivel, std::string nombreNivel);
   Nivel();

   void setId(int id);
   int getId();
   void setNombreNivel(std::string nombreNivel);
   std::string getNombreNivel();
   void setEstado(bool estado);
   bool getEstado();

   int getNuevoId();

   void Cargar();

   void Mostrar();
   void MostrarNombres();
};
