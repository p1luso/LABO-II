#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
#include "../utils/rlutil.h"
#include "../utils/utils.h"

int main()
{
    rlutil::cls();
    tests();
    rlutil::anykey();
    // rlutil::setBackgroundColor(rlutil::BLACK);
    // rlutil::setColor(rlutil::WHITE);
    // int opc;
    // rlutil::setConsoleTitle("Sistema de personas");
    // int screen_width = rlutil::tcols();
    // int screen_height = rlutil::trows();
    // int menuX = (screen_width - 20) / 2;
    // int menuY = screen_height / 2 - 5;
    // rlutil::locate(menuX, menuY);

    // while (true)
    // {
    //     rlutil::cls();

    //     rlutil::setBackgroundColor(rlutil::CYAN);
    //     rlutil::setColor(rlutil::BLACK);
    //     rlutil::locate(menuX, menuY + 1);
    //     cout << "Sistema de personas  " << endl;
    //     rlutil::locate(menuX, menuY + 2);
    //     cout << "  Menu de opciones   " << endl;

    //     rlutil::resetColor();
    //     rlutil::setBackgroundColor(rlutil::BLACK);
    //     rlutil::setColor(rlutil::WHITE);
    //     rlutil::locate(menuX, menuY + 4);
    //     cout << "1. Ingresar persona  " << endl;
    //     rlutil::locate(menuX, menuY + 5);
    //     cout << "2. Listar personas   " << endl;
    //     rlutil::locate(menuX, menuY + 6);
    //     cout << "3. Modificar persona " << endl;
    //     rlutil::locate(menuX, menuY + 7);
    //     cout << "0. Salir" << endl;
    //     rlutil::locate(menuX, menuY + 9);
    //     cout << "Ingrese una opcion:  ";
    //     cin >> opc;

    //     rlutil::cls();
    //     rlutil::setBackgroundColor(rlutil::BLACK);
    //     switch (opc)
    //     {
    //     case 1:

    //         cout << "Opción 1 seleccionada: Ingresar persona" << endl;
    //         mostrarDirector();
    //         cout << "Presione una tecla para continuar...";
    //         cin.ignore();
    //         cin.get();
    //         break;
    //     case 2:
    //         cout << "Opción 2 seleccionada: Listar personas" << endl;

    //         GuardarDirector();
    //         cout << "Presione una tecla para continuar...";
    //         cin.ignore();
    //         cin.get();
    //         break;
    //     case 3:
    //         cout << "Opción 3 seleccionada: Modificar persona" << endl;
    //         contarDirector();
    //         cout << "Presione una tecla para continuar...";
    //         cin.ignore();
    //         cin.get();
    //         break;
    //     case 0:
    //         return 0;
    //     default:
    //         cout << "Opción no válida" << endl;
    //         cout << "Presione una tecla para continuar...";
    //         cin.ignore();
    //         cin.get();
    //         break;
    //     }
    // }

    return 0;
}