#include <iostream>
#include <string>
#include <cstring>
#include "../include/Estudiante.h"
#include "../utils/utils.h"
#include "../include/Nivel.h"
#include "../include/Curso.h"
#include "../include/Trimestre.h"
#include "../include/Notas.h"

Estudiante::Estudiante() {}

Estudiante::~Estudiante() {}

int Estudiante::getId() { return _idEstudiante; }

std::string Estudiante::getNombreRol(){ return _nombreRol; }

int Estudiante::getIdCurso() { return _idCurso; }
int Estudiante::getIdNivel() { return _idNivel; }
int Estudiante::getIdAsignatura(){ return _idAsignatura; }
std::string Estudiante::getTurno() { return std::string(_turno); }

void Estudiante::setId(int idEstudiante) { _idEstudiante = idEstudiante; }
void Estudiante::setIdCurso(int idCurso) { _idCurso = idCurso; }
void Estudiante::setIdNivel(int  idNivel) { _idNivel = idNivel; }
void Estudiante::setIdAsignatura(int idAsignatura){ _idAsignatura = idAsignatura; }
void Estudiante::setTurno(std::string turno) { strcpy(_turno, turno.c_str()); }

void Estudiante::Cargar() {
    Nivel nivel;
    Curso curso;
    _idEstudiante = getNuevoId();
    std::cout << "Rol: " << getNombreRol() << std::endl;
    Persona::Cargar();
    std::cout<<"Selecione el Nivel: " << std::endl;
    nivel.MostrarNombres();
    std::cin >> _idNivel;
    std::cout<< "Selecione Curso: " << std::endl;
    curso.MostrarNombresPorNivel(getIdNivel());
    std::cin >> _idCurso;
    std::cout <<"Turno M - Mañana | T - Tarde: ";
    cargarCadena(_turno, 30);
    setEstado(true);
}

void Estudiante::listarNotasEstudiantes(int id){
   system("cls");
   Menus menus;
   Curso curso;
   Asignatura asignatura;
   Trimestre trimestre;
   Notas notas;
   Estudiante estudiante;
   ArchivoManager<Notas> archivoNotas("notas.dat");
   ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

   estudiante = archivoEstudiante.buscarRegistroPorIdUser(estudiante, id);

   int cant = archivoNotas.cantidadRegistros();
   for(int i=0;i<cant;i++){
      notas = archivoNotas.leerRegistro(notas, i);
      if(estudiante.getId() == notas.getIdEstudiante()){
         for(int j=1;j<=3;j++){
            if(notas.getIdTrimestre() == j){
               std::cout<< "------------------------------"  << std::endl;
               std::cout<< "Trimestre:    " << notas.getIdTrimestre() << std::endl;
               std::cout<< "Curso:        " ;
               curso.MostrarNombre(notas.getIdCurso());
               std::cout<< "Asignatura:   ";
               asignatura.MostrarNombre(notas.getIdAsignatura());
               std::cout<< "Nota:         " << notas.getNota() << std::endl;
               std::cout<< "------------------------------"  << std::endl;

            }
         }
      }
   }
   system ("pause");
   system ("cls");
   menus.menuEstudiante();
}

void Estudiante::Mostrar() {

    Nivel nivel;
    Curso curso;
    if (getEstado()) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Id: " << getId() << std::endl;
        std::cout << "Id Usuario: " << getIdUser() << std::endl;
        std::cout << "DNI: " << getDni() << std::endl;
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Apellido: " << getApellido() << std::endl;
        std::cout << "Fecha de nacimiento: " << getFechaNacimiento().toString() << std::endl;
        std::cout << "Sexo: " << getSexo() << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Direccion: " << getDireccion() << std::endl;
        std::cout << "Telefono: " << getTelefono() << std::endl;
        std::cout << "Nivel: ";
        nivel.MostrarNombre(getIdNivel());
        std::cout << "Curso: ";
        curso.MostrarNombre(getIdCurso());
        std::cout << "Turno: "<<getTurno()<<std::endl;
        std::cout << "Estado: "<<getEstado()<<std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}






