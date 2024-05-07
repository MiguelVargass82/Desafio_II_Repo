#ifndef ESTACION_H
#define ESTACION_H
#include <string>
using namespace std;


class Estacion
{
private:
    string nombre;
    bool Transferencia;  //Arreglo que contendra sus estaciones variante de transferencia de transferencia que tiene la estacion
    float tiempoSiguiente;
    float tiempoAnterior;
    string linea;


public: //Solo tiene metodos de encapsulamiento

    Estacion(string nombre, string linea);

    Estacion();
    ~Estacion();

    void setNombre(string nombre);
    string getNombre();

    void setTransferencia(bool transferencia);
    bool getTransferencia();

    void setTiempoSiguiente(float tiempoSiguiente);
    float getTiempoSiguiente();

    void setTiempoAnterior(float tiempoAnterior);
    float getTiempoAnterior();

    void setLinea(string linea);
    string getLinea();



};




#endif // ESTACION_H
