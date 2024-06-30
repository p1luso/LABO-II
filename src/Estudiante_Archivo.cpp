#include <iostream>
#include "../utils/ArchivoManager.h"
#include "../include/persona.h"
#include "../include/Estudiante.h"
#include "../include/UserId.h"

void Estudiante::alta()
{
    Estudiante estudiante;

    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

    estudiante.Cargar();

    archivoEstudiante.guardarRegistro(estudiante);

    UserId user;
    ArchivoManager<UserId> archivoUser("users.dat");

    int cant = archivoEstudiante.cantidadRegistros();
    archivoEstudiante.leerRegistro(estudiante, cant);
    int id = estudiante.getIdUser();
    int dni = estudiante.getDni();
    int idRol = estudiante.getIdRol();
    bool estado = estudiante.getEstado();
    user.Cargar(id, dni, idRol, estado);

    archivoUser.guardarRegistro(user);
    system("pause");
}

void Estudiante::listar()
{
    Estudiante estudiante;
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");

    int posY = 1; // Inicializar posY para la posición vertical de inicio
    archivoEstudiante.listarRegistro(estudiante);
    system("pause");
}

void Estudiante::baja()
{
    Estudiante estudiante;
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
    int id;
    cout << "Ingrese el id del Estudiante a eliminar: ";
    cin >> id;

    int idPos = archivoEstudiante.buscarRegistro(estudiante, id);
    if (idPos == -1)
    {
        cout << "No se encontro el Estudiante" << endl;
        return;
    }

    estudiante = archivoEstudiante.leerRegistro(estudiante, idPos);

    if (estudiante.getEstado() == true)
    {
        int posY = 2; // Definir la posición inicial Y
        estudiante.Mostrar();
        cout << "Desea eliminar el Estudiante? (s/n): " << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            estudiante.setEstado(false);
            archivoEstudiante.modificarRegistro(estudiante, idPos);
            cout << "Estudiante eliminado " << endl;
        }
    }
    else
    {
        cout << "El Estudiante ya no existe o fue eliminado " << endl;
    }
    system("pause");
}


int Estudiante::getNuevoId(){
    Estudiante estudiante;
    ArchivoManager<Estudiante> archivoEstudiante("estudiantes.dat");
    int cant = archivoEstudiante.cantidadRegistros();
    if(cant > 0){
      estudiante = archivoEstudiante.leerRegistro(estudiante, cant-1);
      return estudiante.getId() + 1;
    }
    else{
      return 1;
    }
}
