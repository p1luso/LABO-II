#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"


class Docente : public Persona, public IRegistro
{
private:
    int _id;
    char _turno[10];
    char _asignatura[50];
    char _curso[50];
    char _nivel[15];
public:
    Docente();
    ~Docente();
    int getId();
    std::string getTurno();
    std::string getAsignatura();
    std::string getCurso();
    std::string getNivel();
    void setId(int idDocente);
    void setTurno(std::string turno);
    void setAsignatura(std::string asignatura);
    void setCurso(std::string curso);
    void setNivel(std::string nivel);
    void Cargar();

    void Mostrar();

    void alta() override;

    void listar() override;

    void baja() override;

};
