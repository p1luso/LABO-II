#include <clocale>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
#include "../utils/rlutil.h"
#include "../utils/utils.h"
#include "../utils/funciones.h"
int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    tests();

    rlutil::locate(15,30);
    return 0;
}
