 #include "../utils/Menus.h"
 #include "../include/Director.h"

 int Menus::login_code = 0;

 void Menus::setLoginCode(int login)
 {
     login_code = login;
 }

 int Menus::getLoginCode()
 {
     return login_code;
 }

 void Menus::mostrarMenu(const std::vector<MenuItem>& items) {
     int opy = 0, op = 1;

     int anchoConsola, altoConsola;
     obtenerDimensionesConsola(anchoConsola, altoConsola);

     const int anchoRecuadro = 70;
     const int altoRecuadro = 20;
     const int longitudTexto = 32;

     int recuadroX = (anchoConsola - anchoRecuadro) / 2;
     int recuadroY = (altoConsola - altoRecuadro) / 2;
     int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
     recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0); // Recuadro

     // Men�
     do {
         rlutil::hidecursor();
         rlutil::setColor(rlutil::COLOR::WHITE);
         for (size_t i = 0; i < items.size(); ++i) {
             showItem(items[i].texto, textoX, recuadroY + 7 + i * 2, opy == i * 2);
         }

         // Elegir opciones
         int key = rlutil::getkey();
         switch (key) {
         case 14: // Mueve la selecci�n en el men� hacia arriba
             if (opy > 0) {
                 opy -= 2;
             }
             break;
         case 15: // Mueve la selecci�n en el men� hacia abajo
             if (opy < (items.size() - 1) * 2) {
                 opy += 2;
             }
             break;
         case 1:
             items[opy / 2].accion();
             op = 0;
             break;
         default:
             break;
         }
     } while (op != 0);
 }

 void Menus::Login()
 {
     int anchoConsola, altoConsola;
     obtenerDimensionesConsola(anchoConsola, altoConsola);
     int code;
     const int anchoRecuadro = 70;
     const int altoRecuadro = 20;
     const int longitudTexto = 32;

     int recuadroX = (anchoConsola - anchoRecuadro) / 2;
     int recuadroY = (altoConsola - altoRecuadro) / 2;
     int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
     recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0); // Recuadro

     rlutil::locate(textoX,altoRecuadro/2);
     rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);
     rlutil::setColor(15);
     std::cout<<"Bienvenido, ingrese su usuario";
     rlutil::locate(textoX , altoRecuadro/2 + 2);
     std::cout<<"Usuario: ";
     rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);
     rlutil::setColor(15);
     std::cin>>code;
     Menus::setLoginCode(code);
     switch (Menus::getLoginCode())
     {
     case 1:
         Menus::menuAdmin();
         break;

     case 2:
         Menus::menuDirector();
         break;

     case 3:
         Menus::menuDocente();
         break;

     case 4:
         Menus::menuEstudiante();
         break;

     default:
         break;
     }

 }

 void Menus::menuAdmin() {
     std::vector<MenuItem> items = {
         {"1. CONFIGURACION PERSONAL    ", []() { Menus::menuAdmPers(); }},
         {"2. CONFIGURACION DE COLEGIO  ", []() { Menus::menuAdmColeg(); }},
     };
     mostrarMenu(items);
 }

 void Menus::menuDirector() {
     std::vector<MenuItem> items = {
         {"1. LISTA DOCENTES     ", []() { Menus::menuDirDoce(); }},
         {"2. LISTA ESTUDIANTES  ", []() { Menus::menuDirEstu(); }},
     };
     mostrarMenu(items);
 }

 void Menus::menuDocente() {
     std::vector<MenuItem> items = {
         {"1. LISTA ESTUDIANTES  ", []() { Menus::menuVarios(); }},
         {"2. NOTAS              ", []() { Menus::menuVarios(); }},
     };
     mostrarMenu(items);
 }

 void Menus::menuEstudiante() {
     std::vector<MenuItem> items = {
         {"1. VER NOTAS          ", []() { /* Acci�n para ver notas */ }},
         {"2. VER MATERIAS       ", []() { /* Acci�n para ver materias */ }},
     };
     mostrarMenu(items);
 }

 void Menus::menuAdmPers() {
     std::vector<MenuItem> items = {
         {"1. DIRECTIVO          ", []() { Menus::menuVarios(); }},
         {"2. DOCENTE            ", []() { Menus::menuVarios(); }},
         {"3. ESTUDIANTE         ", []() { Menus::menuVarios(); }},
         {"4. ATRAS              ", []() { Menus::menuAdmin(); }}
     };
     mostrarMenu(items);
 }

 void Menus::menuAdmColeg() {
     std::vector<MenuItem> items = {
         {"1. NIVEL              ", []() { Menus::menuVarios(); }},
         {"2. CURSO              ", []() { Menus::menuVarios(); }},
         {"3. ASIGNATURA         ", []() { Menus::menuVarios(); }},
         {"4. ATRAS              ", []() { Menus::menuAdmin(); }}
     };
     mostrarMenu(items);
 }
 void Menus::menuDirDoce() {
     std::vector<MenuItem> items = {
         {"1. DOCENTE POR CURSO      ", []() { Menus::menuVarios(); }},
         {"2. DOCENTE POR ASIGNATURA ", []() { Menus::menuVarios(); }},
         {"3. DOCENTE POR NIVEL      ", []() { Menus::menuVarios(); }},
         {"4. ATRAS                  ", []() { Menus::menuAdmin(); }}
     };
     mostrarMenu(items);
 }

 void Menus::menuDirEstu() {
     std::vector<MenuItem> items = {
         {"1. ESTUDIANTES POR CURSO      ", []() { Menus::menuVarios(); }},
         {"2. ESTUDIANTES POR ASIGNATURA ", []() { Menus::menuVarios(); }},
         {"3. ESTUDIANTES POR NIVEL      ", []() { Menus::menuVarios(); }},
         {"4. NOTAS DE ESTUDIANTES       ", []() { Menus::menuVarios(); }},
         {"6. ATRAS                      ", []() { Menus::menuAdmin(); }}
     };
     mostrarMenu(items);
 }

 void Menus::subMenuDoc(){
     std::vector<MenuItem> items = {
         {"1. ESTUDIANTES POR CURSO      ", []() { Menus::menuVarios(); }},
         {"2. ESTUDIANTES POR ASIGNATURA ", []() { Menus::menuVarios(); }},
         {"3. ESTUDIANTES POR NIVEL      ", []() { Menus::menuVarios(); }},
         {"4. NOTAS DE ESTUDIANTES       ", []() { Menus::menuVarios(); }},
         {"6. ATRAS                      ", []() { Menus::menuAdmin(); }}
     };
     mostrarMenu(items);
 }

 void Menus::menuVarios() {
     // Mostrar men� de acciones
     int opy = 0, op = 1;
     int anchoConsola, altoConsola;
     obtenerDimensionesConsola(anchoConsola, altoConsola);

     const int anchoRecuadro = 70;
     const int altoRecuadro = 20;
     const int longitudTexto = 23;

     int recuadroX = (anchoConsola - anchoRecuadro) / 2;
     int recuadroY = (altoConsola - altoRecuadro) / 2;
     int textoX = recuadroX + (anchoRecuadro - longitudTexto) / 2;
     recuadro(recuadroX, recuadroY, anchoRecuadro, altoRecuadro, 12, 0);

     do {
         rlutil::hidecursor();
         rlutil::setColor(rlutil::COLOR::WHITE);
         showItem("1. ALTA", textoX, recuadroY + 7, opy == 0);
         showItem("2. BAJA", textoX, recuadroY + 9, opy == 2);
         showItem("3. MODIFICACION", textoX, recuadroY + 11, opy == 4);
         showItem("4. ATRAS", textoX, recuadroY + 13, opy == 6);

         int key = rlutil::getkey();
         switch (key) {
         case 14:
             rlutil::locate(textoX - 2, recuadroY + 7 + opy);
             opy = (opy - 2 + 8) % 8;
             break;
         case 15:
             rlutil::locate(textoX - 2, recuadroY + 7 + opy);
             opy = (opy + 2) % 8;
             break;
         case 1:
             rlutil::cls();
             if (opy == 0) {
                 //realizarAccion(managerDirector, opy);
             } else if (opy == 2) {
                // realizarAccion(managerDocente, opy);
             } else if (opy == 4) {
              //   realizarAccion(managerEstudiante, opy);
             } else if (opy == 6) {
                 Login();
             }
             op = 0;
             break;
         default:
             break;
         }
     } while (op != 0);
 }


