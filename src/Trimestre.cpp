#include "../utils/ArchivoManager.h"
#include "../include/Trimestre.h"


void Trimestre::setFechaInicio(Fecha inicioFecha){ _inicioFecha = inicioFecha; }
Fecha Trimestre::getFechaInicio(){ return _inicioFecha;}

void Trimestre::setFechaFinal(Fecha finalFecha){ _finalFecha = finalFecha; }
Fecha Trimestre::getFechaFinal(){ return _finalFecha; }

void Trimestre::setTrimestre(int trimestre){ _trimestre = trimestre; }
int Trimestre::getTrimestre(){ return _trimestre; }

void Trimestre::setEstado(bool estado) { _estado = estado; }

bool Trimestre::getEstado() { return _estado; }


void Trimestre::Cargar(){
      Trimestre trimestre;
      ArchivoManager<Trimestre> archivoTrimestre("trimestres.dat");
      int cant = archivoTrimestre.cantidadRegistros();
      std::cout << "-Selecione el Trimestre 1, 2 , 3-"<< std::endl;
      std::cin >> _trimestre;
       if(cant > 0){
         for(int i=0;i<cant;i++){
            trimestre = archivoTrimestre.leerRegistro(trimestre, i);
            if(trimestre.getTrimestre() == _trimestre){
               cout << "Trimestre ya fue configurado con anterioridad! Es:" << endl;
               cout << endl;
               trimestre.Mostrar();
               cout << "Seleccione otro trimestre" << endl;
               cout << endl;
               system("pause");
               return;
            }
         }

       }
      std::cout << "Fecha de Inicio:" << std::endl;
      _inicioFecha.Cargar();
      std::cout << "Fecha de Final:" << std::endl;
      _finalFecha.Cargar();
      setEstado(true);
}

void Trimestre::Mostrar(){

      std::cout << "Trimestre "<< getTrimestre() << std::endl;
      std::cout << "Fecha de Inicio:" << getFechaInicio().toString() << std::endl;
      std::cout << "Fecha de Final:" << getFechaFinal().toString() << std::endl;
      std::cout << "------------------------------" << std::endl;

}

void Trimestre::alta()
{
    Trimestre trimestre;
    ArchivoManager<Trimestre> archivoTrimestre("trimestres.dat");

    trimestre.Cargar();

    if(!archivoTrimestre.guardarRegistro(trimestre)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;
}

void Trimestre::listar()
{
    Trimestre trimestre;
    ArchivoManager<Trimestre> archivoTrimestre("trimestres.dat");
    archivoTrimestre.listarRegistro(trimestre);
    system("pause");

}

void Trimestre::baja(){
}
