#include <iostream>
#include "../include/Fecha.h"

using namespace std;

Fecha::Fecha()
{
   _dia = 0;
   _mes = 0;
   _anio = 0;
}

Fecha::Fecha(int dia = 0, int mes = 0, int anio = 0)
{
   _dia = dia;
   _mes = mes;
   _anio = anio;
}

int Fecha::getDia() { return _dia; }

int Fecha::getMes() { return _mes; }

int Fecha::getAnio() { return _anio; }

void Fecha::setDia(int dia) { _dia = dia; }

void Fecha::setMes(int mes) { _mes = mes; }

void Fecha::setAnio(int anio) { _anio = anio; }

void Fecha::Cargar()
{
   std::cout << "Dia: ";
   std::cin >> _dia;
   std::cout << "Mes: ";
   std::cin >> _mes;
   std::cout << "Anio: ";
   std::cin >> _anio;
}

std::string Fecha::toString()
{
   return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
