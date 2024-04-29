#include "linea.h"
#include <string>
using namespace std;

//Encapsulamiento
Linea::Linea(string nombre) {
    this->nombre=nombre;
}
void Linea::setEstaciones(Estacion* estaciones) {
    this->estaciones = estaciones;
}

Estacion* Linea::getEstaciones() {
    return estaciones;
}

void Linea::setNumEstaciones(int num) {
    numEstaciones = num;
}

int Linea::getNumEstaciones() {
    return numEstaciones;
}

