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
        cout << "Sistema de personas  " << endl;
        rlutil::locate(menuX, menuY + 1);
        cout << "  Menu de opciones   " << endl;

        // Imprimir las opciones del menú
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(menuX, menuY + 3);
        cout << "1. Ingresar persona  " << endl;
        rlutil::locate(menuX, menuY + 4);
        cout << "2. Listar personas   " << endl;
        rlutil::locate(menuX, menuY + 5);
        cout << "3. Modificar persona " << endl;
        rlutil::locate(menuX, menuY + 6);
        cout << "0. Salir" << endl;
        rlutil::locate(menuX, menuY + 8);
        cout << "Ingrese una opcion:  ";
        cin >> opc;

        // Restaurar el color de fondo a negro
        rlutil::setBackgroundColor(rlutil::BLACK);

        switch (opc)
        {
        case 1:
            // Código para ingresar persona
            cout << "Opción 1 seleccionada: Ingresar persona" << endl;
            break;
        case 2:
            // Código para listar personas
            cout << "Opción 2 seleccionada: Listar personas" << endl;
            break;

        case 0:
            return 0; // Salir del programa
        default:
            cout << "Opción no válida" << endl;
        }
    }

    return 0;
}
