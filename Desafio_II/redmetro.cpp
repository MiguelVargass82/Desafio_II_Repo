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


void RedMetro::AgregarLinea(){

        cout<<"Ingrese la linea a la cual pertenece la estacion de la cual va a iniciar la linea"<<endl;
        int eleccion;
        for(int i=0;i<numLineas;i++){
            cout<<i+1<<")"<<lineas[i].getNombre()<<endl;
        }
        cout<<"Seleccione una opcion"<<endl;
        cin>>eleccion;
        eleccion=eleccion-1;

        Linea lineaAux = lineas[eleccion]; //Linea auxiliar

        cout<<"Ingrese la estacion de la cual va a iniciar la linea"<<endl;
        for (int i=0;i<lineaAux.getNumEstaciones();i++){
            cout<<i+1<<")"<<lineaAux.getEstaciones()[i].getNombre()<<endl;
        }
        cout<<"Seleccione una opcion"<<endl;
        cin>>eleccion;
        eleccion=eleccion-1;
        Estacion estacionAux = lineaAux.getEstaciones()[eleccion];



        string nomPrimeraLinea;
        cout<<"Ingrese el nombre de la linea que quiere crear"<<endl;
        getline(std::cin, nomPrimeraLinea);

}

void RedMetro::EliminarLinea(){


}
