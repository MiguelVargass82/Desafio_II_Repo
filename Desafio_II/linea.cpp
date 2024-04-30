#include "linea.h"
#include <string>
using namespace std;

//Encapsulamiento
Linea::Linea() {
}
Linea::Linea(string nombre) {   //Constructor que se invocara cuando se crea un aanueva linea
    this->nombre = nombre;

}

string Linea::getNombre(){
    return nombre;
}
void Linea::setNombre(string nombre){
    this->nombre=nombre;
}
void Linea::setEstaciones(Estacion** estaciones) {
    this->estaciones = estaciones;
}
Estacion** Linea::getEstaciones() {
    return estaciones;
}
void Linea::setNumEstaciones(int num) {
    numEstaciones = num;
}
int Linea::getNumEstaciones() {
    return numEstaciones;
}







void Linea::AgregarEstacion(){



}

void Linea::EliminarEstacion(){



}

