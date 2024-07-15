// En Menus.h
#ifndef MENUS_H
#define MENUS_H

#include "ArchivoManager.h"
#include "../include/Admin.h"
#include "../include/Director.h"
#include "../include/Docente.h"
#include "../include/Estudiante.h"
#include "../include/Nivel.h"
#include "../include/Curso.h"
#include "../include/Asignatura.h"
#include "../include/UserId.h"
#include "../include/Notas.h"
#include "rlutil.h"
#include "funciones.h"
#include <vector>
#include <functional>
#include "IRegistros.h"

struct MenuItem {
    const char* texto;
    std::function<void()> accion;
};

class Menus {
private:
    static int login_code;
    static int _idUser;
    static void mostrarMenu(const std::vector<MenuItem>& items);
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
    static void menuVarios(IRegistro& registro, void (*menuAnterior)());
    static void setLoginCode(int login);
    static int getLoginCode();
    static void setIdUser(int idUser);
    static int getIdUser();



};

#endif // MENUS_H
