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

        //Solicitamos los tiempos
        cout<<"Ingrese el tiempo que se va demorar en ir desde la estacion "<<estaciones[numEstaciones-1].getNombre()<<" hasta la estacion "<<estacion.getNombre()<<endl;
        float time ;
        cin>>time;
        estaciones[numEstaciones-1].setTiempoSiguiente(time);
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
        cout<<"Ingrese el tiempo que se va demorar en ir desde la estacion "<<estacion.getNombre()<<" hasta la estacion "<<estaciones[numEstaciones-1].getNombre()<<":"<<endl;

        float time;    //Este tiempo despues lo vamos a volver variable
        cin>>time;


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


        if(indice!=numEstaciones){
            cout<<"Ingrese el tiempo que se va a demorar de la estacion "<<estacion.getNombre()<<" hasta "<<estaciones[indice].getNombre()<<":"<<endl;

            float timeSig ;    //Este tiempo despues lo vamos a volver variable
            cin>>timeSig;


            estaciones[indice].setTiempoAnterior(timeSig);
            estacion.setTiempoSiguiente(timeSig);

        }


        cout<<"Ingrese el tiempo que se va a demorar de la estacion "<<estaciones[indice-1].getNombre()<<" hasta "<<estacion.getNombre()<<":"<<endl;

        float timeAnt;    //Este tiempo despues lo vamos a volver variable
        cin>>timeAnt;

        estaciones[indice-1].setTiempoSiguiente(timeAnt);
        estacion.setTiempoAnterior(timeAnt);

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

    if(estacion.getTransferencia()==true)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"La estacion "<<estacion.getNombre()<<"es una estacion de transferencia, no puedes eliminar una estacion de transferencia "<<endl;
    }else{

        //Modificacion de tiempos
        int cont=0;
        bool encontrado=false;
        for(int i=0;i<numEstaciones;i++){
            if(estacion.getNombre()==estaciones[i].getNombre()){
                encontrado=true;
            }
            if(!encontrado){
                cont++;
            }
        }
        if(cont==numEstaciones-1){
            estaciones[cont-1].setTiempoSiguiente(0);
        }else{
            float nuevoTiempo=estaciones[cont-1].getTiempoSiguiente()+estaciones[cont-1].getTiempoAnterior();
            estaciones[cont-1].setTiempoSiguiente(nuevoTiempo);
            estaciones[cont+1].setTiempoAnterior(nuevoTiempo);
        }

        this->setEstaciones(Utilidades::EliminarEstacion(estacion,this->estaciones,this->numEstaciones));
        this->numEstaciones=this->numEstaciones-1;
        cout<<"Estacion "<<estacion.getNombre()<<" eliminada con exito "<<endl;

    }

}

void Linea::EstacionPertenece(string nombreEstacion){
    bool pertenece=false;
    for(int i = 0; i<numEstaciones;i++){
        if(nombreEstacion==this->estaciones[i].getNombre()){
            pertenece=true;
        }
    }   
    if(pertenece){
        cout<<"La estacion "<<nombreEstacion<<" pertenece a la linea "<<this->nombre<<endl;
    }else{
        cout<<"La estacion "<<nombreEstacion<<" NO pertenece a linea  "<<this->nombre<<endl;
    }

}
