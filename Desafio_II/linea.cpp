#include "linea.h"
#include <string>
#include <iostream>
#include "utilidades.h"
using namespace std;

//Encapsulamiento
Linea::Linea() {    //Ojo con eso
    this->nombre = "";
    this->numEstaciones=NULL;
    this->estaciones= NULL;
}


Linea::Linea(int num) {   //Constructor que se invocara cuando se crea una nueva linea
    string nombre;
    cout<<"Ingrese el nombre de la nueva linea:"<<endl;
    cin>>nombre;
    this->nombre = nombre;
    this->numEstaciones=0;
    this->estaciones= new Estacion[1];
}

string Linea::getNombre(){
    return nombre;
}
void Linea::setNombre(string nombre){
    this->nombre=nombre;
}
void Linea::setEstaciones(Estacion* estaciones) {
    delete[] this->estaciones;
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

void Linea::AgregarEstacion(Estacion estacion){
    if(this->numEstaciones<=0){     //Agregamos la primera estacion
        this->numEstaciones=this->numEstaciones+1;
        this->estaciones[0]=estacion;
    }else{
        //No es la primera estacion


        float time = 30;    //Este tiempo despues lo vamos a volver variable


        estaciones[numEstaciones-1].setTiempoSiguiente(time);   //Modificamos directamente el objeto del arreglo no una copia
        estacion.setTiempoAnterior(time);
        this->setEstaciones(Utilidades::agregarEstacionArregloFinal(estacion,this->estaciones,this->getNumEstaciones()));
        this->numEstaciones= this->numEstaciones+1;
    }

    cout<<"Se agrego la estacion "<<estacion.getNombre()<<" con exito "<<endl;
}       //Fin agregar estacion adelante

void Linea::AgregarEstacionAtras(Estacion estacion){
    if(this->numEstaciones<=0){
        this->numEstaciones=this->numEstaciones+1;
        this->estaciones[0]=estacion;
    }else{

        float time = 30;    //Este tiempo despues lo vamos a volver variable

        estaciones[0].setTiempoAnterior(time);   //Modificamos directamente el objeto del arreglo no una copia
        estacion.setTiempoSiguiente(time);
        this->setEstaciones(Utilidades::agregarEstacionArregloInicio(estacion,this->estaciones,this->getNumEstaciones()));
        this->numEstaciones= this->numEstaciones+1;
    }
    cout<<"Se agrego la estacion "<<estacion.getNombre()<<" al inicio con exito "<<endl;
}   //Fin agregar estacion atras

void Linea::AgregarEstacionPosicion(Estacion estacion, int indice){
    if(this->numEstaciones<=0){     //Agregamos la primera estacion
        this->numEstaciones=this->numEstaciones+1;
        this->estaciones[0]=estacion;
    }else{
        //No es la primera estacion


        float timeAnt = 30;    //Este tiempo despues lo vamos a volver variable
        float timeSig = 20;    //Este tiempo despues lo vamos a volver variable



        estaciones[indice-1].setTiempoSiguiente(timeAnt);   //Modificamos directamente el objeto del arreglo no una copia
        estaciones[indice+1].setTiempoAnterior(timeSig);   //Modificamos directamente el objeto del arreglo no una copia

        estacion.setTiempoAnterior(timeAnt);
        estacion.setTiempoSiguiente(timeAnt);

        this->setEstaciones(Utilidades::agregarEstacionArregloMedio(estacion,this->estaciones,indice,this->getNumEstaciones()));
        this->numEstaciones= this->numEstaciones+1;

    }
}






void Linea::mostrarEstaciones(){
    for (int i=0;i<this->numEstaciones;i++){
        cout<<estaciones[i].getNombre();

        if(i!=this->numEstaciones-1)
            cout<<" -> ";
    }
    cout<<endl;
}   //Fin mostrarEstaciones

void Linea::EliminarEstacion(Estacion estacion){
    if(estacion.getTransferencia()==false)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"La estacion "<<estacion.getNombre()<<"es una estacion de transferencia, no puedes eliminar una estacion de transferencia "<<endl;
    }else{
        this->setEstaciones(Utilidades::EliminarEstacion(estacion,this->estaciones,this->numEstaciones));
        this->numEstaciones=this->numEstaciones-1;
        cout<<"Estacion "<<estacion.getNombre()<<" eliminada con exito "<<endl;

    }

}

void Linea::EstacionPertenece(Estacion estacion){
    bool pertenece=false;
    for(int i = 0; i<numEstaciones;i++){
        if(estacion.getNombre()==this->estaciones[i].getNombre()){
            pertenece=true;
        }

        if(pertenece){
            cout<<"La estacion "<<estacion.getNombre()<<" pertenece a  "<<this->nombre;
        }else{
            cout<<"La estacion "<<estacion.getNombre()<<" NO pertenece a  "<<this->nombre;
        }
    }



}
