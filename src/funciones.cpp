#include "../utils/funciones.h"

void clrscr(void)
{
    system("cls");
}

void pause(void)
{
    system("pause >nul");
}

void gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void textcolor(short colorTexto, short colorFondo)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo)
{
    for (int i = iniX; i <= iniX + ancho; ++i)
    {
        for (int j = iniY; j <= iniY + alto; ++j)
        {
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            if (i == iniX && j == iniY)
            {
                std::cout << static_cast<char>(201);
            }
            else if (i == iniX + ancho && j == iniY)
            {
                std::cout << static_cast<char>(187);
            }
            else if (i == iniX && j == iniY + alto)
            {
                std::cout << static_cast<char>(200);
            }
            else if (i == iniX + ancho && j == iniY + alto)
            {
                std::cout << static_cast<char>(188);
            }
            else if (j == iniY || j == iniY + alto)
            {
                std::cout << static_cast<char>(205);
            }
            else if (i == iniX || i == iniX + ancho)
            {
                std::cout << static_cast<char>(186);
            }
            else
            {
                std::cout << " ";
            }
        }
    }
}

///FUNCION PARA MENU ---> COLOREA EL SELECCIONADO
void showItem(const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTMAGENTA);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);
    }

    rlutil::locate(posx, posy);
    std::cout << text << std::endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void obtenerDimensionesConsola(int &ancho, int &alto)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columnas, filas;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    ancho = columnas;
    alto = filas;
}
