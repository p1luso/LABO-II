#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include "Asignatura.h"
#include "Curso.h"
#include "Nivel.h"
#include "../include/Rol.h"
#include <vector>
#include <string>

class Nota {
public:
    //cambiar!!
    std::string asignatura;
    float valor;
    //cambiar!!
    Nota(std::string asignatura, float valor) : asignatura(asignatura), valor(valor) {}
};

class Estudiante : public Persona, public IRegistro {
private:
    int _idEstudiante;
    int _idRol = 4;
    Asignatura _asignatura; //cambio
    Curso _curso; //cambio
    char _turno[30];
    Nivel _nivel; //cambio
    std::vector<Nota> _notas; // Nueva propiedad para almacenar notas

public:
    Estudiante();
    ~Estudiante();

    Rol rol;
    int getId();
    int getIdRol();

    Asignatura getAsignatura(); //cambio
    Curso getCurso(); //cambio
    Nivel getNivel(); //cambio
    std::string getTurno();


    void setId(int idEstudiante);
    void setAsignatura(Asignatura asignatura); //cambio
    void setCurso(Curso curso); //cambio
    void setNivel(Nivel nivel);//cambio
    void setTurno(std::string turno);

    //cambiar!!
    void agregarNota(std::string asignatura, float valor); // Nuevo método para agregar notas
    void listarNotas(); // Nuevo método para listar notas

    int getNuevoId();
    void Cargar();
    void Mostrar();

    void alta() override;
    void baja() override;
    void listar() override;
};

#endif // ESTUDIANTE_H
