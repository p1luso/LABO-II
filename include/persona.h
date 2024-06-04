#pragma once
#include "../include/Fecha.h"
class Persona
{
private:
    int _id;
    int _dni;
    char _nombre[50];
    char _apellido[50];
    Fecha _fechaNacimiento;
    char _sexo[10];
    char _email[50];
    char _direccion[100];
    char _telefono[50];

public:
    Persona();

    void setId(int id);
    int getId();

    void setDni(int dni);
    int getDni();

    void setNombre(std::string nombre);
    std::string getNombre();

    void setApellido(std::string apellido);
    std::string getApellido();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();

    void setSexo(std::string sexo);
    std::string getSexo();

    void setEmail(std::string email);
    std::string getEmail();

    void setDireccion(std::string direccion);
    std::string getDireccion();

    void setTelefono(std::string telefono);
    std::string getTelefono();

    void Cargar();
};
