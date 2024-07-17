#pragma once
#include "../include/Fecha.h"
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"


class Trimestre : public IRegistro
{
private:
   Fecha _inicioFecha;
   Fecha _finalFecha;
   int _trimestre;
   bool _estado;
public:
   void setFechaInicio(Fecha inicioFecha);
   Fecha getFechaInicio();

   void setFechaFinal(Fecha finalFecha);
   Fecha getFechaFinal();

   void setTrimestre(int trimestre);
   int getTrimestre();

   void setEstado(bool estado);
   bool getEstado();

   void Cargar();
   void Mostrar();

   void alta() override;
   void listar() override;
   void baja() override;

};
