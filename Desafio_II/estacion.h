#ifndef ESTACION_H
#define ESTACION_H
#include <string>
using namespace std;


class Estacion
{
private:
    string nombre;
    Estacion* lineasTransferencia;  //Arreglo que contendra sus estaciones variante de transferencia de transferencia que tiene la estacion
    float tiempoSiguiente;
    float tiempoAnterior;
    string linea;
    int numTransferencias;  //Numero de lineas alternas que tiene (nos sirve para tener control del arreglo dinamico)


public: //Solo tiene metodos de encapsulamiento

    Estacion(string nombre, string linea);

    Estacion();
    ~Estacion();
    void setNumTransferencias(int num);
    int getNumTransferencias();




    void setNombre(string nombre);
    string getNombre();

    void setLineasTransferencia(Estacion* lineasTransferencia);
    Estacion* getLineasTransferencia();

    void setTiempoSiguiente(float tiempoSiguiente);
    float getTiempoSiguiente();

    void setTiempoAnterior(float tiempoAnterior);
    float getTiempoAnterior();

    void setLinea(string linea);
    string getLinea();



};




#endif // ESTACION_H
