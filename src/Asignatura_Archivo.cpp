#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Asignatura.h"

void Asignatura::alta()
{
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    asignatura.Cargar();

    archivoAsignatura.guardarRegistro(asignatura);
        system("pause");

}

void Asignatura::listar()
{
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");

    archivoAsignatura.listarRegistro(asignatura);
        system("pause");

}

void Asignatura::baja()
{
    Asignatura asignatura;
    ArchivoManager<Asignatura> archivoAsignatura("asignaturas.dat");
    int id;
    cout << "Ingrese el id de la asignatura a eliminar: ";
    cin >> id;

    int idPos = archivoAsignatura.buscarRegistro(asignatura, id);
    if (idPos == -1)
    {
        cout << "No se encontro la asignatura" << endl;
        return;
    }

    asignatura = archivoAsignatura.leerRegistro(asignatura, idPos);

    if (asignatura.getEstado() == true)
    {
        asignatura.Mostrar();
        cout << "Desea eliminar la asignatura? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            asignatura.setEstado(false);
            archivoAsignatura.modificarRegistro(asignatura, idPos);
            cout << "Asignatura eliminada" << endl;
        }
    }
    else
    {
        cout << "La asignatura ya esta eliminada" << endl;
    }
        system("pause");

}
