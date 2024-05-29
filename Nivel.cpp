#include "Nivel.h"
#include <cstring>

Nivel::Nivel(int idNivel, std::string nombreNivel)
{
	_idNivel = 0;
	strcpy(_nombreNivel, "");
}

void Nivel::setIdNivel(int id)
{
	_idNivel = id;
}
int Nivel::getIdNivel()
{
	return _idNivel;
}
void Nivel::setNombreNivel(std::string nombreNivel)
{
	strcpy(_nombreNivel, nombreNivel.c_str());
}
std::string Nivel::getNombreNivel()
{
	return std::string(_nombreNivel);
}
