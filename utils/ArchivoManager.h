#pragma once
#include <cstring>    // para strcpy
#include <cstdio>     // para FILE, fopen, fclose, etc.
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class ArchivoManager
{
public:
    char nombreArchivo[256];
    ArchivoManager(const char *nombreArchivo);

    bool guardarRegistro(T obj);
    bool listarRegistro(T obj);
    int buscarRegistro(int id);
    T leerRegistro(int pos);
    bool modificarRegistro(T obj, int pos);
    int cantidadRegistros(T obj);
    bool registroExiste(int pos);
};

template <class T>
ArchivoManager<T>::ArchivoManager(const char *nombreArchivo)
{
    strcpy(this->nombreArchivo, nombreArchivo);
}

template <class T>
bool ArchivoManager<T>::guardarRegistro(T obj)
{
    std::string ruta = "LABO-II/file/";
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
bool ArchivoManager<T>::listarRegistro(T obj)
{
    std::string ruta = "LABO-II/file/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        return false;
    }

    while (fread(&obj, sizeof(T), 1, f) == 1)
    {
        obj.Mostrar();

        cout << endl; // Asume que T tiene un método mostrar()
    }
    fclose(f);
    return true;
}

template <class T>
int ArchivoManager<T>::buscarRegistro(int id)
{
    std::string ruta = "LABO-II/file/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        return -1;
    }
    T obj;
    int pos = 0;
    while (fread(&obj, sizeof(T), 1, f) == 1)
    {
        if (obj.getId() == id)
        { // Asume que T tiene un método getId()
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

template <class T>
T ArchivoManager<T>::leerRegistro(int pos)
{
    std::string ruta = "LABO-II/file/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        throw std::runtime_error("Error al abrir el archivo");
    }
    T obj;
    fseek(f, pos * sizeof(T), SEEK_SET);
    if (fread(&obj, sizeof(T), 1, f) != 1)
    {
        fclose(f);
        throw std::runtime_error("Error al leer el registro");
    }
    fclose(f);
    return obj;
}

template <class T>
bool ArchivoManager<T>::modificarRegistro(T obj, int pos)
{
    std::string ruta = "LABO-II/file/";
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
int ArchivoManager<T>::cantidadRegistros(T obj)
{
    std::string ruta = "LABO-II/file/";
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
