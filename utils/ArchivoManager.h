#pragma once

#include <cstring> // para strcpy
#include <cstdio>  // para FILE, fopen, fclose, etc.
#include <stdexcept>
#include <string>
#include <iostream>

template <class T>
class ArchivoManager
{
public:
    char nombreArchivo[256];
    ArchivoManager(const char *nombreArchivo);

    bool guardarRegistro(T obj);
    bool listarRegistro(T obj);
    int buscarRegistro(T obj, int id);
    T leerRegistro(T obj, int pos);
    bool modificarRegistro(T obj, int pos);
    int cantidadRegistros();
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
bool ArchivoManager<T>::listarRegistro(T obj)
{
    std::string ruta = "files/";
    ruta.append(nombreArchivo);
    FILE *f = fopen(ruta.c_str(), "rb");
    if (f == NULL)
    {
        return false;
    }

    while (fread(&obj, sizeof obj, 1, f) == 1)
    {
        obj.Mostrar();
        std::cout << std::endl;
    }
    fclose(f);
    return true;
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
