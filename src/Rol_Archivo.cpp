#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Rol.h"

void Rol::alta()
{
    Rol rol;
    ArchivoManager<Rol> archivoRol("Roles.dat");
    rol.Cargar();

    if(!archivoRol.guardarRegistro(rol)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;
        system("pause");

}

void Rol::listar()
{
    Rol rol;
    ArchivoManager<Rol> archivoRol("roles.dat");
    int posY = 1; // Inicializar posY para la posición vertical de inicio
    archivoRol.listarRegistro(rol);
        system("pause");

}



void Rol::baja()
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
        int posY = 2; // Definir la posición inicial Y

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
        system("pause");

}
