#include <iostream>
#include <vector>
#include <string>
#include "rlutil.h"
using namespace std;

#include "persona.h"

int main()
{
    rlutil::setBackgroundColor(rlutil::BLACK);

    int opc;
    while (true)
    {
        rlutil::cls();

        // Obtener el tamaño de la pantalla
        int screenWidth = rlutil::tcols();
        int screenHeight = rlutil::trows();

        // Calcular la posición central del menú
        int menuX = (screenWidth - 20) / 2; // Ancho del menú es 20
        int menuY = screenHeight / 2 - 5;   // Altura del menú es 5

        // Imprimir el título del menú
        rlutil::locate(menuX, menuY);
        rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::setColor(rlutil::BLACK);
        std::cout << "Sistema de personas  " << std::endl;
        rlutil::locate(menuX, menuY + 1);
        std::cout << "  Menu de opciones   " << std::endl;

        // Imprimir las opciones del menú
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(menuX, menuY + 3);
        std::cout << "1. Ingresar persona  " << std::endl;
        rlutil::locate(menuX, menuY + 4);
        std::cout << "2. Listar personas   " << std::endl;
        rlutil::locate(menuX, menuY + 5);
        std::cout << "3. Modificar persona " << std::endl;
        rlutil::locate(menuX, menuY + 6);
        std::cout << "0. Salir" << std::endl;
        rlutil::locate(menuX, menuY + 8);
        std::cout << "Ingrese una opcion:  ";
        std::cin >> opc;

        // Restaurar el color de fondo a negro
        rlutil::setBackgroundColor(rlutil::BLACK);

        switch (opc)
        {
        case 1:
            // Código para ingresar persona
            std::cout << "Opción 1 seleccionada: Ingresar persona" << std::endl;
            break;
        case 2:
            // Código para listar personas
            std::cout << "Opción 2 seleccionada: Listar personas" << std::endl;
            break;
        case 3:
            // Código para modificar persona
            std::cout << "Opción 3 seleccionada: Modificar persona" << std::endl;
            break;
        case 0:
            return 0; // Salir del programa
        default:
            std::cout << "Opción no válida" << std::endl;
        }
    }

    return 0;
}
