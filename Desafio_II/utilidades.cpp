#include "utilidades.h"



//Estos metodos modifican los arreglos de sus respectivos tipos y agregan en la ultima posicion lo que nosotros necesitemos usar
Estacion* Utilidades::agregarEstacionArregloFinal(Estacion estacion, Estacion* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos

    Estacion* nuevoArreglo = new Estacion[longitud+1];
    for(int i=0; i<longitud;i++){
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

Linea* Utilidades::agregarLineaArregloFinal(Linea linea, Linea* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Linea* nuevoArreglo = new Linea[longitud+1];
    for(int i=0; i<=longitud;i++){
        if(i<longitud){
            nuevoArreglo[i]=arreglo[i];
        }
        else{
            nuevoArreglo[i]=linea;
        }
    }
    delete[] arreglo;
    return nuevoArreglo;
}


//Con estas funciones puedo agregar un dato a los arreglos y este puede quedar en una posicion especifica





 //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
Estacion* Utilidades::agregarEstacionArregloMedio(Estacion estacion, Estacion* arreglo,int indice, int longitud){
    Estacion* nuevoArreglo = new Estacion[longitud+1];
    bool menos=false; //Boleano para restarle uno a las posiciones al saltarlos una posicion
    for(int i=0; i<longitud;i++){
        if(i!=indice){
            nuevoArreglo[i]=arreglo[i];
            if(menos){
                nuevoArreglo[i]=arreglo[i-1];
            }
        }
        else{
            menos = true;
        }
    }
    nuevoArreglo[indice]=estacion;
    delete[] arreglo;
    return nuevoArreglo;
}


Linea* Utilidades::agregarLineaArregloMedio(Linea linea, Linea* arreglo,int indice, int longitud){
    Linea* nuevoArreglo = new Linea[longitud+1];
    bool menos=false;   //Boleano para restarle uno a las posiciones al saltarlos una posicion
    for(int i=0; i<=longitud;i++){
        if(i!=indice){
            nuevoArreglo[i]=arreglo[i];
            if(menos){
                nuevoArreglo[i]=arreglo[i-1];
            }
        }
        else{
            menos=true;
        }
    }
    nuevoArreglo[indice]=linea;
    delete[] arreglo;
    return nuevoArreglo;
}

