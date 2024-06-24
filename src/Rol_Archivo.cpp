#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Rol.h"

void Rol::altaRol()
{
    Rol rol;
    ArchivoManager<Rol> archivoRol("Roles.dat");
    rol.Cargar();

    archivoRol.guardarRegistro(rol);
}

void Rol::listarRoles()
{
    Rol rol;
    ArchivoManager<Rol> archivoRol("roles.dat");

    archivoRol.listarRegistro(rol);
}

void Rol::bajaRol()
{
    Rol rol;
    ArchivoManager<Rol> archivoRol("Roles.dat");
    int id;
    cout << "Ingrese el id del Rol a eliminar: ";
    cin >> id;

    int idPos = archivoRol.buscarRegistro(rol, id);
    if (idPos == -1)
    {
        cout << "No se encontro la Rol" << endl;
        return;
    }

    rol = archivoRol.leerRegistro(rol, idPos);

    if (rol.getEstado() == true)
    {
        rol.Mostrar();
        cout << "Desea eliminar el Rol? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            rol.setEstado(false);
            archivoRol.modificarRegistro(rol, idPos);
            cout << "Rol eliminado" << endl;
        }
    }
    else
    {
        cout << "El Rol no existe o fue eliminado" << endl;
    }
}