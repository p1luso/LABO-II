#pragma once
#include "../include/Fecha.h"
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"


class Persona
{
private:
    int _idUser;
    int _dni;
    char _nombre[50];
    char _apellido[50];
    Fecha _fechaNacimiento;
    char _sexo[10];
    char _email[50];
    char _direccion[100];
    char _telefono[50];
    bool _estado;

public:
    Persona();

    void setIdUser(int id);
    int getIdUser();

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

    void setEstado(bool estado);
    bool getEstado();

    int getNuevoId();

    void Cargar();

    void Mostrar();






};
