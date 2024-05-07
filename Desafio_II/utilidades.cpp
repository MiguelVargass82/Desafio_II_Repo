#include "utilidades.h"
#include<iostream>
using namespace std;


//Estos metodos modifican los arreglos de sus respectivos tipos y agregan en la ultima posicion lo que nosotros necesitemos usar
 Estacion* Utilidades::agregarEstacionArregloFinal(Estacion estacion, Estacion* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
     cout<<"longitud vale: "<<longitud<<endl;

     //Se puede borrar de aqui para arriba
    Estacion* nuevoArreglo = new Estacion[longitud+1];
    for(int i=0; i<longitud;i++){
         nuevoArreglo[i]=arreglo[i];
    }

    nuevoArreglo[longitud]=estacion;
    cout<<"Se completo la funcion de agregar una estacion al arreglo sin errores"<<endl;

    return nuevoArreglo;
}

 Estacion* Utilidades::agregarEstacionArregloInicio(Estacion estacion, Estacion* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
     cout<<"entro a la funcion aggInicio"<<endl;
     Estacion* nuevoArreglo = new Estacion[longitud+1];
     for(int i=0; i<=longitud;i++){
         if(i>0){
           nuevoArreglo[i]=arreglo[i-1];
         }
         else{
             nuevoArreglo[i]=estacion;
         }
     }
     cout<<"Nuevo arreglo "<<endl;
     for (int i=0; i<=longitud;i++)
         cout<<nuevoArreglo[i].getNombre()<<" "<<endl;

     cout<<"Se completo la funcion de agregar una estacion al inicio"<<endl;

     return nuevoArreglo;
 }


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
     nuevoArreglo[longitud]=arreglo[longitud-1];
     nuevoArreglo[indice]=estacion;
     return nuevoArreglo;
 }


 //METODOS PARA LINEAS

Linea* Utilidades::agregarLineaArregloFinal(Linea linea, Linea* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Linea* nuevoArreglo = new Linea[longitud+1];
    cout<<"longitud: "<<longitud<<endl;
    for(int i=0; i<longitud;i++){
            nuevoArreglo[i]=arreglo[i];          
    }
    nuevoArreglo[longitud]=linea;
    return nuevoArreglo;
}

//Funciones para agregar datos al inicio




Linea* Utilidades::agregarLineaArregloInicio(Linea linea, Linea* arreglo, int longitud){   //Esta funcion va a alargar el arreglo una posicion y luego le va a agregar el dato que necesitamos
    Linea* nuevoArreglo = new Linea[longitud+1];
    bool corre1=false;
    for(int i=0; i<=longitud;i++){
        if(i>0){
            if(corre1){
                nuevoArreglo[i]=arreglo[i-1];

            }else{
                nuevoArreglo[i]=arreglo[i];
            }
        }
        else{
            nuevoArreglo[i]=linea;
            corre1=true;
        }
    }
    delete[] arreglo;
    return nuevoArreglo;
}





static Estacion* EliminarEstacion(Estacion estacion, Estacion* arreglo, int longitud){
    Estacion* nuevoArreglo = new Estacion[longitud-1];
    bool eliminado=false;
    for(int i =0;i<longitud;i++){
        if(arreglo[i].getNombre()==estacion.getNombre()){
            eliminado=true;
        }else{
            if(eliminado){  //Y nos saltamos esa posicion
                nuevoArreglo[i-1]=arreglo[i];
            }else{  //No hemos saltado la posicion
                nuevoArreglo[i]=arreglo[i];
            }
        }
    }
    return nuevoArreglo;
}















//Funcion inutil
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


Linea* EliminarLinea(Linea linea, Linea* arreglo, int longitud){
    Linea* nuevoArreglo = new Linea[longitud-1];
    bool eliminado=false;
    for(int i =0;i<longitud;i++){
        if(arreglo[i].getNombre()==linea.getNombre()){
            eliminado=true;
        }else{
            if(eliminado){  //Y nos saltamos esa posicion
                nuevoArreglo[i-1]=arreglo[i];
            }else{  //No hemos saltado la posicion
                nuevoArreglo[i]=arreglo[i];
            }
        }
    }
    return nuevoArreglo;
}

