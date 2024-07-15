#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Admin.h"
#include "../include/Estudiante.h"
#include "../include/Asignatura.h"
#include "../include/UserId.h"



void Admin::alta()
{
    Admin admin;

    ArchivoManager<Admin> archivoAdmin("admin.dat");

    admin.Cargar();

    if(!archivoAdmin.guardarRegistro(admin)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;

    UserId user;
    ArchivoManager<UserId> archivoUser("users.dat");

    int cant = archivoAdmin.cantidadRegistros();
    archivoAdmin.leerRegistro(admin, cant);
    int id = admin.getIdUser();
    int dni = admin.getDni();
    std::string nombreRol = admin.getNombreRol();
    bool estado = admin.getEstado();
    user.Cargar(id, dni, nombreRol, estado);

    archivoUser.guardarRegistro(user);
    system("pause");
}

void Admin::listar()
{
    Admin admin;
    ArchivoManager<Admin> archivoAdmin("admin.dat");
    archivoAdmin.listarRegistro(admin);
    system("pause");

}

void Admin::baja()
{
    Admin admin;
    ArchivoManager<Admin> archivoAdmin("admin.dat");
    int id;
    cout << "Ingrese el id del Administrador a eliminar: ";
    cin >> id;

    int idPos = archivoAdmin.buscarRegistro(admin, id);
    if (idPos == -1)
    {
        cout << "No se encontro el Administrador" << endl;
        return;
    }

    admin = archivoAdmin.leerRegistro(admin, idPos);

    if (admin.getEstado() == true)
    {
        int posY = 2; // Definir la posición inicial Y
        admin.Mostrar();
        cout << "Desea eliminar el Administrador? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            admin.setEstado(false);
            archivoAdmin.modificarRegistro(admin, idPos);
            cout << "Administrador eliminado " << endl;
        }
    }
    else
    {
        cout << "El Administrador ya no existe o fue eliminado " << endl;
    }
    system("pause");
}

int Admin::getNuevoId(){
    Admin admin;
    ArchivoManager<Admin> archivoAdmin("admin.dat");
    int cant = archivoAdmin.cantidadRegistros();
    if(cant > 0){
      admin = archivoAdmin.leerRegistro(admin, cant-1);
      return admin.getId() + 1;
    }
    else{
      return 1;
    }
}
