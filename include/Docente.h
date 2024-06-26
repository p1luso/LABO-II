#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"
#include "Asignatura.h"
#include "../include/Rol.h"
class Docente : public Persona, public IRegistro
{
private:
    int _id;
    int _idRol = 3;
    char _turno[10];
    Asignatura _asignatura;
    char _curso[50];
    char _nivel[15];
public:
    Docente();
    ~Docente();
    Rol rol;
    int getId();
    int getIdRol();
    std::string getTurno();
    Asignatura getIdAsignatura();
    std::string getCurso();
    std::string getNivel();
    void setId(int idDocente);
    void setTurno(std::string turno);
    void setIdAsignatura(Asignatura asignatura);
    void setCurso(std::string curso);
    void setNivel(std::string nivel);
    void Cargar();
    void listarEstudiantesPorMateria();
    void Mostrar();
    int getNuevoId();
    void alta() override;
    void listar() override;
    void baja() override;

};
