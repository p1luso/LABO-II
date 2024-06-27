#include <iostream>
using namespace std;

#include "../utils/ArchivoManager.h"
#include "../include/Nivel.h"

void Nivel::alta()
{
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    nivel.Cargar();

    archivoNivel.guardarRegistro(nivel);
        system("pause");

}

void Nivel::listar()
{
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    int posY = 1; // Inicializar posY para la posición vertical de inicio
    archivoNivel.listarRegistro(nivel);
        system("pause");

}

void Nivel::baja()
{
    Nivel nivel;
    ArchivoManager<Nivel> archivoNivel("niveles.dat");
    int id;
    cout << "Ingrese el id del Nivel a eliminar: ";
    cin >> id;

    int idPos = archivoNivel.buscarRegistro(nivel, id);
    if (idPos == -1)
    {
        cout << "No se encontro la Nivel" << endl;
        return;
    }

    nivel = archivoNivel.leerRegistro(nivel, idPos);

    if (nivel.getEstado() == true)
    {
        int posY = 2; // Inicializar posY para la posición vertical de inicio
        nivel.Mostrar();
        cout << "Desea eliminar la Nivel? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            nivel.setEstado(false);
            archivoNivel.modificarRegistro(nivel, idPos);
            cout << "Nivel eliminado" << endl;
        }
    }
    else
    {
        cout << "El Nivel no existe o fue eliminado" << endl;
    }
        system("pause");

}
