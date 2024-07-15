#pragma once


class UserId{
private:
   int _userId;
   int _userDni;
   char _nombreRol[20];
   bool _userEstado;

public:
   void setId(int id);
   int getIdUser();

   void setNombreRol(std::string nombre);
   std::string getNombreRol();

   void setDni(int dni);
   int getDni();

   void setEstado(bool estado);
   bool getEstado();


   void Guardar();
   void Mostrar();
   void Cargar(int id, int dni, std::string nombreRol, bool estado);

   UserId ObtenerUserConDni(int dni);
   int VerificadorUsuario(int code);


};
