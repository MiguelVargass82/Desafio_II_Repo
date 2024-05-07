#include "redmetro.h"
#include "utilidades.h"
#include <iostream>
#include <string>
using namespace std;

    RedMetro::RedMetro(string nombre) {
    this->nombre=nombre;
    this->lineas = new Linea[1];
    this->numLineas=0;
}

// Métodos de encapsulamiento para el atributo 'nombre'
void RedMetro::setNombre(string nombre) {
    this->nombre = nombre;
}

string RedMetro::getNombre() {
    return nombre;
}

// Métodos de encapsulamiento para el atributo 'lineas'
void RedMetro::setLineas(Linea* lineas) {
    delete[] this->lineas;

    this->lineas = lineas;
}

Linea* RedMetro::getLineas() const {
    return lineas;
}

void RedMetro::setNumLineas(int num){
    this->numLineas=num;
}

int RedMetro::getNumLineas(){
    return this->numLineas;
}


void RedMetro::AgregarLinea(Linea linea){
    this->setLineas(Utilidades::agregarLineaArregloFinal(linea,this->lineas,this->numLineas));
    this->numLineas=this->numLineas+1;
}



void RedMetro::EliminarLinea(){

    cout<<"Se elimino la linea "<<this->lineas[0].getNombre()<<endl;
    this->setLineas(new Linea[1]);
    this->numLineas=0;
    cout<<"-----------------------------------"<<endl;
}
