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

void Estacion::setNumTransferencias(int num) {
    this->numTransferencias = num;
}

void Estacion::setNombre(string nombre) {
    this->nombre = nombre;
}

string Estacion::getNombre() {
    return nombre;
}

void Estacion::setLineasTransferencia(Estacion* lineasTransferencia) {
    this->lineasTransferencia = lineasTransferencia;
}

Estacion* Estacion::getLineasTransferencia() {  //Es un arreglo
    return lineasTransferencia;
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

