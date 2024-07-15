#include <iostream>
#include "../include/Director.h"
#include "../include/persona.h"
#include "../include/Docente.h"
#include "../include/Asignatura.h"
#include "../utils/ArchivoManager.h"
#include "../include/UserId.h"
#include "../utils/Menus.h"

void Director::estudiantePorCriterio(const std::string &criterio)
{
    system("cls");

    int valor;
    std::cout << "Ingrese el " << criterio << ": ";
    std::cin >> valor;
    ///std::cin.ignore();
    //std::getline(std::cin, valor);

    ArchivoManager<Estudiante> archivoManager("estudiantes.dat");
    archivoManager.listarEstudiantesPorCriterio(criterio, valor);

    rlutil::anykey("Presione cualquier tecla para continuar...");
    system("cls");
    Menus::menuDirEstu();
}

void Director::listarNotasPorAsig()
{
    system("cls");

    int valor;
    std::cout << "Ingrese la asignatura para ver las notas: ";
    std::cin >> valor;
//    std::cin.ignore();
//    std::getline(std::cin, valor);

    ArchivoManager<Estudiante> archivoManager("estudiantes.dat");

    archivoManager.listarNotasPorAsignatura(valor); // Llama a la función para listar notas por asignatura

    rlutil::anykey("Presione cualquier tecla para continuar...");
    system("cls");
    Menus::menuDirEstu(); // Vuelve al menú de opciones para estudiantes del Director
}

void Director::docentePorCriterio(const std::string &criterio)
{
    system("cls");

    int valor;
    std::cout << "Ingrese el " << criterio << ": ";
    std::cin >> valor;
//    std::cin.ignore();
//    std::getline(std::cin, valor);

    ArchivoManager<Docente> archivoManager("docentes.dat");
    archivoManager.listarDocentesPorCriterio(criterio, valor);

    rlutil::anykey("Presione cualquier tecla para continuar...");
    system("cls");
    Menus::menuDirDoce();
}

void Director::alta()
{
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");

    director.Cargar();

    if(!archivoDirector.guardarRegistro(director)){
         cout << "No se pudo guardar!" << endl;
    }
    cout << "Se guardo con exito! " << endl;

    UserId user;
    ArchivoManager<UserId> archivoUser("users.dat");
    int cant = archivoDirector.cantidadRegistros();
    archivoDirector.leerRegistro(director, cant);
    int id = director.getIdUser();
    int dni = director.getDni();
    std::string nombreRol = director.getNombreRol();
    bool estado = director.getEstado();
    user.Cargar(id, dni, nombreRol, estado);

    archivoUser.guardarRegistro(user);
    system("pause");

}


void Director::listar()
{
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");
    archivoDirector.listarRegistro(director);
    system("pause");
//    std::cout << "------------------------------------ " << std::endl;
//    UserId user;
//    ArchivoManager<UserId> archivoUser("users.dat");
//    archivoUser.listarRegistro(user);
//    system("pause");
}

void Director::baja()
{
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");
    int id;
    std::cout << "Ingrese el id del Director a eliminar: ";
    std::cin >> id;

    int idPos = archivoDirector.buscarRegistro(director, id);
    if (idPos == -1)
    {
        std::cout << "No se encontro el Director" << std::endl;
        return;
    }

    director = archivoDirector.leerRegistro(director, idPos);

    if (director.getEstado() == true)
    {
        int posY = 2; // Definir la posición inicial Y
        director.Mostrar();
        std::cout << "Desea eliminar el Director? (s/n): " << std::endl;
        char opcion;
        std::cin >> opcion;
        if (opcion == 's' || opcion == 'S')
        {
            director.setEstado(false);
            archivoDirector.modificarRegistro(director, idPos);
            std::cout << "Director eliminado" << std::endl;
        }
    }
    else
    {
        std::cout << "El Director ya no existe o fue eliminado" << std::endl;
    }
    system("pause");
}

int Director::getNuevoId(){
    Director director;
    ArchivoManager<Director> archivoDirector("directores.dat");
    int cant = archivoDirector.cantidadRegistros();
    if(cant > 0){
      director = archivoDirector.leerRegistro(director, cant);
      return director.getId()+1;
    }
    else{
      return 1;
    }
}
