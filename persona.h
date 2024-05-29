#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona
{
private:
    int _id;
    int _dni;
    string _nombre;
    string _apellido;
    int _edad;
    string _sexo;
    string _direccion;
    string _telefono;

public:
    Persona();

    void setId(int id);
    int getId();

    void setDni(int dni);
    int getDni();

    void setNombre(string nombre);
    string getNombre();

    void setApellido(string apellido);
    string getApellido();

    void setEdad(int edad);
    int getEdad();

    void setSexo(string sexo);
    string getSexo();

    void setDireccion(string direccion);
    string getDireccion();

    void setTelefono(string telefono);
    string getTelefono();
};

#endif // PERSONA_H_INCLUDED
