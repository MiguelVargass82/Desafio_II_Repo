#ifndef REDMETRO_H
#define REDMETRO_H
#include <string>
#include "linea.h"
using namespace std;

class RedMetro
{


private:
    string nombre;
    Linea* lineas;  //Arreglo de las lineas
    int numLineas;  //Numero de lineas (ayuda al control del arreglo)
public:

    RedMetro(string nombre);
    void setNombre(string nombre);
   string getNombre() ;
    void setLineas(Linea* lineas);
    Linea* getLineas() const;
    void setNumLineas(int num);
    int getNumLineas();


    //Metodos
    void AgregarEstacion();
    void EliminarEstacion();
    void AgregarLinea();
    void EliminarLinea();
};

#endif // REDMETRO_H
