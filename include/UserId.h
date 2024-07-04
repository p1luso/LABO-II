#pragma once


class UserId{
private:
   int _userId;
   int _userDni;
   int _userIdRol;
   bool _userEstado;

public:
   void setId(int id);
   int getIdUser();

   void setIdRol(int idRol);
   int getIdRol();

   void setDni(int dni);
   int getDni();

   void setEstado(bool estado);
   bool getEstado();


   void Guardar();
   void Mostrar();
   void Cargar(int id, int dni, int idRol, bool estado);

   UserId ObtenerUserConDni(int dni);
   int VerificadorUsuario(int code);


};
