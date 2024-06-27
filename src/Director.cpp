#include <iostream>
#include <string>
#include <cstring>

#include "../include/Director.h"

// void cargarCadena(char *pal, int tam)
// {
//    int i;
//    fflush(stdin); /// limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
//    for (i = 0; i < tam; i++)
//    {
//       pal[i] = cin.get();
//       if (pal[i] == '\n')
//          break;
//    }
//    pal[i] = '\0';
//    fflush(stdin); /// vuelve a limpiar el buffer para eliminar los caracteres sobrantes
// }
Director::Director() {}

Director::~Director() {}

int Director::getId()
{
    return _idDirector;
}

void Director::setId(int idDirector)
{
    _idDirector = idDirector;
}

void Director::Cargar()
{
    std::cout << "IdDirector: ";
    std::cin >> _idDirector;
    Persona::Cargar();
    Persona::setEstado(true);
}

void Director::Mostrar()
{
    if (getEstado() == true)
    {
        std::cout << "UserId: " << getUserId() << std::endl;
        std::cout << "ID: " << getId() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;
    }
}
