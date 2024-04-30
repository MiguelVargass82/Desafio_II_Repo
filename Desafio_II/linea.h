#ifndef LINEA_H
#define LINEA_H
#include <string>
#include "estacion.h"

using namespace std;

class Linea
{
private:
    string nombre;
    Estacion** estaciones;   //Arreglo de estaciones que posee (el orden del arreglo no es necesariamente el de las estaciones)
    int numEstaciones;  //Numero de estaciones que tiene la linea(nos ayuda a tener contro del arreglo)

public:
    //Encapsulamiento
    Linea();
    Linea(int num);
    string getNombre();
    void setNombre(string nombre);
    void setEstaciones(Estacion** estaciones);
    Estacion** getEstaciones();
    void setNumEstaciones(int num);
    int getNumEstaciones();


    //Metodos
    void AgregarEstacion();
    void EliminarEstacion();
};

#endif // LINEA_H
