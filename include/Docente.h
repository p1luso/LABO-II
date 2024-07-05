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
    int _idNivel;
    int _idCurso;
    int _idAsignatura;
    char _turno[10];
public:
    Docente();
    ~Docente();
    Rol rol;
    int getId();
    int getIdRol();
    ///Asignatura getIdAsignatura();
    int getIdNivel();
    int getIdCurso();
    int getIdAsignatura();
    std::string getTurno();
    void setId(int idDocente);
    ///void setIdAsignatura(Asignatura asignatura);
    void setIdNivel(int idNivel);
    void setIdCurso(int idCurso);
    void setIdAsignatura(int idAsignatura);
    void setTurno(std::string turno);

    void listarEstudiantesPorMateria();

    void Cargar();
    void Mostrar();

    int getNuevoId();

    void alta() override;
    void listar() override;
    void baja() override;

};
