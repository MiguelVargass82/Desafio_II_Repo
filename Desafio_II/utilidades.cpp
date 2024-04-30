#include "utilidades.h"

void LiberarArrEstaciones(Estacion** arreglo, int num){
    for(int i =0;i<num;i++){
        delete arreglo[i];
    }
    delete[] arreglo;

}

void LiberarArrLineas(Estacion** arreglo, int num){
    for(int i =0;i<num;i++){
        delete arreglo[i];
    }
    delete[] arreglo;
}





Estacion** Utilidades::agregarEstacionArreglo(Estacion* estacion, Estacion** arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Estacion** nuevoArreglo = new Estacion*[longitud+1];
    for(int i=0; i<=longitud;i++){
        if(i<longitud){
            nuevoArreglo[i]=arreglo[i];
        }
        else{
            nuevoArreglo[i]=estacion;
        }
    }
    for(int i =0;i<longitud;i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    return nuevoArreglo;
}

Linea** Utilidades::agregarLineaArreglo(Linea* linea, Linea** arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Linea** nuevoArreglo = new Linea*[longitud+1];
    for(int i=0; i<=longitud;i++){
        if(i<longitud){
            nuevoArreglo[i]=arreglo[i];
        }
        else{
            nuevoArreglo[i]=linea;
        }
    }
    for(int i =0;i<longitud;i++){
        delete arreglo[i];
    }
    delete[] arreglo;

    return nuevoArreglo;
}


