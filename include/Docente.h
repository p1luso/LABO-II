#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"
#include "Asignatura.h"
#include "../include/Rol.h"
#include "Curso.h"
#include "Nivel.h"
class Docente : public Persona, public IRegistro
{
private:
    int _id;
    int _idRol = 3;
    char _turno[10];
    Asignatura _asignatura;
    Curso _curso;  //cambio
    Nivel _nivel; //cambio
public:
    Docente();
    ~Docente();
    Rol rol;
    int getId();
    int getIdRol();
    std::string getTurno();
    Asignatura getIdAsignatura();
    Curso getCurso(); //cambio
    Nivel getNivel(); //cambio
    void setId(int idDocente);
    void setTurno(std::string turno);
    void setIdAsignatura(Asignatura asignatura);
    void setCurso(Curso curso); //cambio
    void setNivel(Nivel nivel);
    void Cargar();
    void listarEstudiantesPorMateria();
    void Mostrar();
    int getNuevoId();
    void alta() override;
    void listar() override;
    void baja() override;

};
