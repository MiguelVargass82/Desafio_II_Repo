#include "estacion.h"
#include <string>

//Solo tiene constructor y encapsulamiento

Estacion::Estacion(string nombre, string linea) {
    this->nombre=nombre;
    this->linea=linea;
}

Estacion::Estacion() {

}
Estacion::~Estacion(){

}


void Estacion::setNombre(string nombre) {
    this->nombre = nombre;
}

string Estacion::getNombre() {
    return nombre;
}

void Estacion::setTransferencia(bool tranferencias) {
    this->Transferencia = tranferencias;
}

bool Estacion::getTransferencia() {  //Es un arreglo
    return Transferencia;
}

void Estacion::setTiempoSiguiente(float tiempoSiguiente) {
    this->tiempoSiguiente = tiempoSiguiente;
}

float Estacion::getTiempoSiguiente() {
    return tiempoSiguiente;
}

void Estacion::setTiempoAnterior(float tiempoAnterior) {
    this->tiempoAnterior = tiempoAnterior;
}

float Estacion::getTiempoAnterior() {
    return tiempoAnterior;
}

void Estacion::setLinea(string linea) {
    this->linea = linea;
}

string Estacion::getLinea() {
    return linea;
}

