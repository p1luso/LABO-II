#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include <vector>
#include <string>

class Nota {
public:
    std::string asignatura;
    float valor;

    Nota(std::string asignatura, float valor) : asignatura(asignatura), valor(valor) {}
};

class Estudiante : public Persona, public IRegistro {
private:
    int _idEstudiante;
    char _asignatura[50];
    char _curso[50];
    char _turno[30];
    char _nivel[50];
    std::vector<Nota> _notas; // Nueva propiedad para almacenar notas

public:
    Estudiante();
    ~Estudiante();

    int getId();
    std::string getAsignatura();
    std::string getCurso();
    std::string getNivel();
    std::string getTurno();


    void setId(int idEstudiante);
    void setAsignatura(std::string asignatura);
    void setCurso(std::string curso);
    void setNivel(std::string nivel);
    void setTurno(std::string turno);

    void agregarNota(std::string asignatura, float valor); // Nuevo método para agregar notas
    void listarNotas(); // Nuevo método para listar notas

    void Cargar();
    void Mostrar();

    void alta() override;
    void baja() override;
    void listar() override;
};

#endif // ESTUDIANTE_H
