#ifndef LINEA_H
#define LINEA_H
#include <string>
#include "estacion.h"

using namespace std;

class Linea
{
private:
    string nombre;
    Estacion* estaciones;   //Arreglo de estaciones que posee
    int numEstaciones;  //Numero de estaciones que tiene la linea(nos ayuda a tener contro del arreglo)

public:
    //Encapsulamiento
    Linea(string nombre);
    void setEstaciones(Estacion* estaciones);
    Estacion* getEstaciones();
    void setNumEstaciones(int num);
    int getNumEstaciones();
};

#endif // LINEA_H
