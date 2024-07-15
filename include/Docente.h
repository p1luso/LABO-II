#pragma once
#include "persona.h"
#include <string>
#include "../utils/IRegistros.h"
#include "../utils/funciones.h"
#include "Asignatura.h"

class Docente : public Persona, public IRegistro
{
private:
    int _id;
    char _nombreRol[10] = "Docente";
    int _idNivel;
    int _idCurso;
    int _idAsignatura;
    char _turno[10];
public:
    Docente();
    ~Docente();
    int getId();
    std::string getNombreRol();

    int getIdNivel();
    int getIdCurso();
    int getIdAsignatura();
    std::string getTurno();
    void setId(int idDocente);

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
