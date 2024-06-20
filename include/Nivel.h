#include <string>
#pragma once

class Nivel
{
private:
   int _idNivel;
   char _nombreNivel[30];
   bool _estado;

public:
   Nivel(int idNivel, std::string nombreNivel);
   Nivel();

   void setId(int id);
   int getId();
   void setNombreNivel(std::string nombreNivel);
   std::string getNombreNivel();
   void setEstado(bool estado);
   bool getEstado();

   void Cargar();

   void Mostrar();

   void altaNivel();

   void listarNiveles();

   void bajaNivel();
};
