#ifndef ESTACION_H
#define ESTACION_H
#include <string>
using namespace std;


class Estacion
{
private:
    string nombre;
    Estacion* lineasTransferencia;  //Arreglo que contendra las lineas de transferencia que tiene la estacion
    Estacion* siguiente;
    Estacion* anterior;
    float tiempoSiguiente;
    float tiempoAnterior;
    string linea;
    int numEstacion;    //Numero que le corresponde en la linea
    int numTransferencias;  //Numero de lineas alternas que tiene (nos sirve para tener control del arreglo dinamico)
public:

    Estacion(string nombre, int num, string linea);
    Estacion();

    void setNumTransferencias(int num);
    int getNumTransferencias();


    void setNumEstacion(int num);
    int getNumEstacion();


    void setNombre(string nombre);
    string getNombre();

    void setLineasTransferencia(Estacion* lineasTransferencia);
    Estacion* getLineasTransferencia();

    void setSiguiente(Estacion* siguiente);
    Estacion* getSiguiente();

    void setAnterior(Estacion* anterior);
    Estacion* getAnterior();

    void setTiempoSiguiente(float tiempoSiguiente);
    float getTiempoSiguiente();

    void setTiempoAnterior(float tiempoAnterior);
    float getTiempoAnterior();

    void setLinea(string linea);
    string getLinea();



};

#endif // ESTACION_H
