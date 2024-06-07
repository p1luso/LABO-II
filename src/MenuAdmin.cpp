#include <iostream>
#include "../utils/MenuAdmin.h"
using namespace std;

void MenuAdmin::menu()
{
    int option;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- DIRECTIVO " << endl;
        cout << "2- DOCENTE" << endl;
        cout << "3- ESTUDIANTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            _dManager.menu();
            system("pause");
            break;

        case 2:

            system("pause");
            break;

        case 3:
            system("pause");
            break;
        }

    }
    while(option != 0);

}
