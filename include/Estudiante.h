#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include "../include/Rol.h"
#include "../include/Curso.h"
#include <vector>
#include <string>



class Estudiante : public Persona, public IRegistro {
private:
    int _idEstudiante;
    int _idRol = 4;
    int _idNivel;
    int _idCurso;
    char _turno[30];



public:
    Estudiante();
    ~Estudiante();

    Rol rol;
    Curso curso;
    int getId();
    int getIdRol();


    int getIdNivel();
    int getIdCurso();
    std::string getTurno();


    void setId(int idEstudiante);
    void setIdCurso(int curso);
    void setIdNivel(int nivel);
    void setTurno(std::string turno);


    void listarNotas(); // Nuevo método para listar notas

    int getNuevoId();
    void Cargar();
    void Mostrar();

    void alta() override;
    void baja() override;
    void listar() override;
};

#endif // ESTUDIANTE_H
