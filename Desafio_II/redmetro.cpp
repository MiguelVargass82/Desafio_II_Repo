#include "redmetro.h"

// Constructor
RedMetro::RedMetro(string nombre) {
    this->nombre = nombre;
    this->numLineas=0;
    this->lineas=nullptr;
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


void RedMetro::AgregarEstacion(){


}

void RedMetro::EliminarEstacion(){



}


void RedMetro::AgregarLinea(){
    if(numLineas==0){   //Es la primera linea
        this->lineas

    }



}

void RedMetro::EliminarLinea(){


}
