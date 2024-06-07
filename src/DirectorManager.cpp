#include <iostream>

using namespace std;
#include "../include/DirectorManager.h"

void DirectorManager::menu()
{
    int option;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU PRODUCTOS ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR PRODUCTO " << endl;
        cout << "2- LISTAR TODOS LOS PRODUCTOS" << endl;
        cout << "3- MODIFICAR PRODUCTO" << endl;
        cout << "4- ELIMINAR PRODUCTO" << endl;
        cout << "5- LISTAR ORDENADOS POR PRECIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            //agregarProducto();
            system("pause");
            break;

        case 2:
            //listarProductos();
            system("pause");
            break;

        case 3:
            //modificarProducto();
            system("pause");
            break;

        case 4:
            //eliminarProducto();
            system("pause");
            break;

        case 5:
            //listarProductos(true);
            system("pause");
         break;
        }

    }
    while(option != 0);

}