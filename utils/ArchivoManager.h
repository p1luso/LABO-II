#pragma once

#include <cstring> // para strcpy
#include <cstdio>  // para FILE, fopen, fclose, etc.
#include <stdexcept>
#include <string>
#include <iostream>
#include "../include/Docente.h"
#include "../include/Asignatura.h"
#include "../include/Estudiante.h"


using namespace std;

template <class T>
class ArchivoManager
{
public:
    char nombreArchivo[256];
    ArchivoManager(const char *nombreArchivo);

    bool guardarRegistro(T obj);
   void listarRegistro(T obj);
    int buscarRegistro(T obj, int id);
    T leerRegistro(T obj, int pos);
    bool modificarRegistro(T obj, int pos);
    int cantidadRegistros();
    bool registroExiste(int pos);
    void listarDocentesPorCriterio(const std::string &criterio, const std::string &valor);
    void listarEstudiantesPorCriterio(const std::string &criterio, const std::string &valor);
    void listarNotasPorAsignatura(const std::string &asignatura);
    std::string obtenerAsignaturaPorId(int id); // Nueva función para obtener la asignatura por ID

};

template <class T>
ArchivoManager<T>::ArchivoManager(const char *nombreArchivo)
{
    strcpy(this->nombreArchivo, nombreArchivo);
}

template <class T>
bool ArchivoManager<T>::guardarRegistro(T obj)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "ab");
    if (f == NULL)
    {
        return false;
    }
    bool escrito = fwrite(&obj, sizeof(T), 1, f) == 1;
    fclose(f);
    return escrito;
}

template <class T>
void ArchivoManager<T>::listarRegistro(T obj)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    while (fread(&obj, sizeof(T), 1, f) == 1)
    {
        if (obj.getEstado())
        {
            obj.Mostrar();
        }
    }
    fclose(f);
}

template <class T>
int ArchivoManager<T>::buscarRegistro(T obj, int id)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    int pos = 0;

    if (f == NULL)
    {
        cout << "Error: No se pudo acceder al archivo" << endl;
        fclose(f);
        exit(-1);
    }

    while (fread(&obj, sizeof obj, 1, f) == 1)
    {
        if (obj.getId() == id)
        {
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -2;
}

template <class T>
T ArchivoManager<T>::leerRegistro(T obj, int pos)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        return obj;
    }

    fseek(f, pos * sizeof obj, SEEK_SET);
    fread(&obj, sizeof obj, 1, f);
    fclose(f);
    return obj;
}

template <class T>
bool ArchivoManager<T>::modificarRegistro(T obj, int pos)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "r+b");
    if (f == NULL)
    {
        return false;
    }
    fseek(f, pos * sizeof(T), SEEK_SET);
    bool escrito = fwrite(&obj, sizeof(T), 1, f) == 1;
    fclose(f);
    return escrito;
}

template <class T>
int ArchivoManager<T>::cantidadRegistros()
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        return 0;
    }
    fseek(f, 0, SEEK_END);
    int cant = ftell(f) / sizeof(T);
    fclose(f);
    return cant;
}

template <class T>
bool ArchivoManager<T>::registroExiste(int pos)
{
    return pos >= 0 && pos < cantidadRegistros();
}

template <class T>
void ArchivoManager<T>::listarDocentesPorCriterio(const std::string &criterio, const std::string &valor)
{
    ArchivoManager<Docente> archivoDocente("docentes.dat");
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    Docente docente;
    Asignatura asignatura;
    std::string nombreAsig;

    int archiAsigTam = archivoAsignatura.cantidadRegistros();

    for(int i = 0; i< archiAsigTam; i++)
    {
        if(docente.getIdAsignatura().getId() == asignatura.getId())
        {
            nombreAsig = asignatura.getNombreAsignatura();
        }
    }

    std::string ruta = "files/docentes.dat";
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo 'docentes.dat'" << std::endl;
        return;
    }



    std::cout << "Buscar Docente en: " << valor << std::endl;
    while (fread(&docente, sizeof(Docente), 1, f) == 1)
    {
        if ((criterio == "asignatura" && nombreAsig == valor) ||
            (criterio == "curso" && docente.getCurso() == valor) || // Asumiendo que hay un método getCurso
            (criterio == "nivel" && docente.getNivel() == valor) ||  // Asumiendo que hay un método getNivel
            (criterio == "turno" && docente.getTurno() == valor))   // Asumiendo que hay un método getNivel
        {
            docente.Mostrar();
            std::cout << std::endl;
        }
    }
    fclose(f);
}

template <class T>
void ArchivoManager<T>::listarEstudiantesPorCriterio(const std::string &criterio, const std::string &valor)
{
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
    Estudiante estudiante;

    std::string ruta = "files/estudiantes.dat";
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo 'estudiantes.dat'" << std::endl;
        return;
    }

    std::cout << "Buscar Estudiantes en: " << valor<< std::endl;
    while (fread(&estudiante, sizeof(Estudiante), 1, f) == 1)
    {
        if ((criterio == "asignatura" && estudiante.getAsignatura() == valor) ||
            (criterio == "curso" && estudiante.getCurso() == valor) ||
            (criterio == "nivel" && estudiante.getNivel() == valor) ||
            (criterio == "turno" && estudiante.getTurno() == valor))

        {
            estudiante.Mostrar();
        }
    }

    fclose(f);
}

template <class T>
void ArchivoManager<T>::listarNotasPorAsignatura(const std::string &asignatura) {
    std::string ruta = "files/estudiantes.dat";
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo 'estudiantes.dat'" << std::endl;
        return;
    }

    Estudiante estudiante;
    while (fread(&estudiante, sizeof(Estudiante), 1, f) == 1)
    {
        if (estudiante.getEstado() && estudiante.getAsignatura() == asignatura)
        {
            estudiante.Mostrar();
            std::cout << std::endl;
        }
    }

    fclose(f);
}
template <class T>
std::string ArchivoManager<T>::obtenerAsignaturaPorId(int id)
{
    std::string asignatura;

    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return asignatura; // Devuelve una cadena vacía si no se puede abrir el archivo
    }

    T obj;
    bool encontrado = false;
    while (fread(&obj, sizeof(T), 1, f) == 1)
    {
        if (obj.getId() == id) // Suponiendo que T tiene un método getId() que devuelve el ID del docente
        {
            asignatura = obj.getAsignatura(); // Suponiendo que T tiene un método getAsignatura() que devuelve la asignatura del docente
            encontrado = true;
            break;
        }
    }

    fclose(f);

    if (!encontrado)
    {
        std::cerr << "No se encontró el docente con ID: " << id << std::endl;
    }

    return asignatura;
}
