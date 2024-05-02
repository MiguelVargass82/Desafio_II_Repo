#include "redmetro.h"
#include "utilidades.h"
#include <iostream>
#include <string>
using namespace std;


// Constructor
    RedMetro::RedMetro(int num) {       //Este constructor especial se invoca cuando se crea la primera y unica isntancia de la red
    string nombre;
    cout<<"Ingrese el nombre de la nueva red de metro: "<<endl;
     getline(cin, nombre);
    this->nombre = nombre;
    this->lineas= new Linea[1];
    lineas[0] =  Linea(1);
    Linea lineaAux = lineas[0];
    lineaAux.setEstaciones(new Estacion[0]);
    cout<<"Ingrese el nombre de la estacion que iniciara la linea "<<lineaAux.getNombre()<<":"<<endl;
    string nomEstacion;


    cin>> nomEstacion;

    lineaAux.getEstaciones()[0]= Estacion(nomEstacion,lineaAux.getNombre());
    cout<<"hola";
    this->numLineas=1;
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
