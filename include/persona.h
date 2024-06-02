#pragma once
#include "../include/Fecha.h"
class Persona
{
private:
    int _id;
    int _dni;
    std::string _nombre;
    std::string _apellido;
    Fecha _fechaNacimiento;
    std::string _sexo;
    std::string _direccion;
    std::string _telefono;

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

    void setDireccion(std::string direccion);
    std::string getDireccion();

    void setTelefono(std::string telefono);
    std::string getTelefono();
};
