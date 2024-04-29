#include "utilidades.h"


Estacion* Utilidades::agregarEstacion(Estacion estacion, Estacion* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Estacion* nuevoArreglo = new Estacion[longitud+1];
    for(int i=0; i<=longitud;i++){
        if(i<longitud){
            nuevoArreglo[i]=arreglo[i];
        }
        else{
            nuevoArreglo[i]=estacion;
        }
    }
    delete[] arreglo;
    return nuevoArreglo;
}
