#include "estacion.h"
#include <string>

Estacion::Estacion(string nombre, int num, string linea) {
    this->nombre=nombre;
    this->numEstacion=num;
    this->linea=linea;
}

void Estacion::setNumEstacion(int num) {
    numEstacion = num;
}

int Estacion::getNumEstacion() {
    return numEstacion;
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

Estacion* Estacion::getLineasTransferencia() {
    return lineasTransferencia;
}

void Estacion::setSiguiente(Estacion* siguiente) {
    this->siguiente = siguiente;
}

Estacion* Estacion::getSiguiente() {
    return siguiente;
}

void Estacion::setAnterior(Estacion* anterior) {
    this->anterior = anterior;
}

Estacion* Estacion::getAnterior() {
    return anterior;
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

