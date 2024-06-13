// En Menus.h
#ifndef MENUS_H
#define MENUS_H
#include "ArchivoManager.h"
#include "../include/Director.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "rlutil.h"
#include "funciones.h"
#include <functional>
#include <vector>

struct MenuItem {
    const char* texto;
    std::function<void()> accion;
};

class Menus {
public:
    static void Login();
    static void menuAdmin();
    static void menuDirector();
    static void menuDocente();
    static void menuEstudiante();
    static void menuAdmPers();
    static void menuAdmColeg();
    static void menuDirDoce();
    static void menuDirEstu();
    static void subMenuDoc();
    static void menuVarios();
    static void setLoginCode(int login);
    static int getLoginCode();

private:
    static int login_code;

    static void mostrarMenu(const std::vector<MenuItem>& items);

    template<class T>
    static void realizarAccion(ArchivoManager<T>& manager, int tipo);

     template <class T>
    static void altaRegistro(ArchivoManager<T>& manager);

    template <class T>
    static void bajaRegistro(ArchivoManager<T>& manager);

    template <class T>
    static void modificarRegistro(ArchivoManager<T>& manager);
};

#endif // MENUS_H
