#include "../utils/Menus.h"
#include "../utils/funciones.h"

void Menus::App()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 14;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. ADMIN      ", textoX, recuadroY + 7, opy == 0);
        showItem("2. DIRECTIVO  ", textoX, recuadroY + 9, opy == 2);
        showItem("3. DOCENTE    ", textoX, recuadroY + 11, opy == 4);
        showItem("4. ESTUDIANTE ", textoX, recuadroY + 13, opy == 6);

        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuAdmin();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuDirector();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::menuDocente();
                op = 0;
            }
            else if (opy == 6)
            {
                rlutil::cls();
                Menus::menuEstudiante();
                op = 0;
            }

            break;
        default:
            break;
        }
    }
    while (op != 0);
}

void Menus::menuAdmin()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 32;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. CONFIGURACION PERSONAL    ", textoX, recuadroY + 7, opy == 0);
        showItem("2. CONFIGURACION DE COLEGIO  ", textoX, recuadroY + 9, opy == 2);
        showItem("2. ATRAS                     ", textoX, recuadroY + 11, opy == 4);


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuAdmPers();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuAdmColeg();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::App();
                op = 0;
            }
            break;
        default:
            break;
        }
    }
    while (op != 0);
}
void Menus::menuDirector()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 23;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. LISTA DOCENTES     ", textoX, recuadroY + 7, opy == 0);
        showItem("2. LISTA ESTUDIANTES  ", textoX, recuadroY + 9, opy == 2);
        showItem("2. ATRAS              ", textoX, recuadroY + 11, opy == 4);


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuDirDoce();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuDirEstu();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::App();
                op = 0;
            }
            break;
        default:
            break;
        }
    }
    while (op != 0);
}
void Menus::menuDocente()
{
    std::cout<<"Menu Docente";
}
void Menus::menuEstudiante()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 23;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. VER NOTAS          ", textoX, recuadroY + 7, opy == 0);
        showItem("2. VER MATERIAS       ", textoX, recuadroY + 9, opy == 2);
        showItem("2. ATRAS              ", textoX, recuadroY + 11, opy == 2);


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuDirDoce();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuDirEstu();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::App();
                op = 0;
            }
            break;
        default:
            break;
        }
    }
    while (op != 0);
}
void Menus::menuAdmPers()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 23;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. DIRECTIVO          ", textoX, recuadroY + 7, opy == 0);
        showItem("2. DOCENTE            ", textoX, recuadroY + 9, opy == 2);
        showItem("2. ESTUDIANTE         ", textoX, recuadroY + 11, opy == 4);
        showItem("2. ATRAS              ", textoX, recuadroY + 13, opy == 6);


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuVarios();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuVarios();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::menuVarios();
                op = 0;
            }
            else if (opy == 6)
            {
                rlutil::cls();
                Menus::menuAdmin();
                op = 0;
            }
            break;
        default:
            break;
        }
    }
    while (op != 0);
}
void Menus::menuAdmColeg()
{
    std::cout<<"Menu admin Colegio";
}
void Menus::menuDirDoce()
{
    std::cout<<"Menu Director Docente";
}
void Menus::menuDirEstu()
{
    std::cout<<"Menu Director Estudiantes";
}
void Menus::menuVarios()
{
    int opy = 0, op = 1;

    int anchoConsola, altoConsola;
    obtenerDimensionesConsola(anchoConsola, altoConsola);

    const int anchoRecuadro = 70;
    const int altoRecuadro = 20;
    const int longitudTexto = 23;

    int recuadroX = (anchoConsola - anchoRecuadro) / 2;
    int recuadroY = (altoConsola - altoRecuadro) / 2;
    int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
    recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        showItem("1. ALTA             ", textoX, recuadroY + 7, opy == 0);
        showItem("2. BAJA             ", textoX, recuadroY + 9, opy == 2);
        showItem("2. MODIFICACION     ", textoX, recuadroY + 11, opy == 4);
        showItem("2. ATRAS            ", textoX, recuadroY + 13, opy == 6);


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(textoX - 2, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            rlutil::locate(textoX + longitudTexto + 1, recuadroY + 7 + opy);
            if (opy > 6)
            {
                opy = 6;
            }
            opy = opy + 2;
            break;
        case 1:
            if (opy == 0)
            {
                rlutil::cls();
                Menus::menuDirDoce();
                op = 0;
            }
            else if (opy == 2)
            {
                rlutil::cls();
                Menus::menuVarios();
                op = 0;
            }
            else if (opy == 4)
            {
                rlutil::cls();
                Menus::menuVarios();
                op = 0;
            }
            else if (opy == 6)
            {
                rlutil::cls();
                Menus::menuAdmin();
                op = 0;
            }
            break;
        default:
            break;
        }
    }
    while (op != 0);

}
