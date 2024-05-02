#include "linea.h"
#include <string>
#include <iostream>
using namespace std;

//Encapsulamiento
Linea::Linea() {
}
Linea::Linea(int num) {   //Constructor que se invocara cuando se crea una nueva linea
    string nombre;
    cout<<"Ingrese el nombre de la nueva linea:"<<endl;
    getline(cin,nombre);
    this->nombre = nombre;
    this->numEstaciones=1;
}

string Linea::getNombre(){
    return nombre;
}
void Linea::setNombre(string nombre){
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







void Linea::AgregarEstacion(){



}

void Linea::EliminarEstacion(){



}

