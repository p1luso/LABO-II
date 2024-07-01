#pragma once

class Nota {
private:
   int _idTrimestre;
   int _idNivel;
   int _idCurso;
   int _idAsignatura;
   int _idDocente;
   int _idEstudiante;
public:
    std::string asignatura;
    float valor;

    Nota(std::string asignatura, float valor) : asignatura(asignatura), valor(valor) {}
};


///std::vector<Nota> _notas; // Nueva propiedad para almacenar notas

///void agregarNota(std::string asignatura, float valor); // Nuevo método para agregar notas
