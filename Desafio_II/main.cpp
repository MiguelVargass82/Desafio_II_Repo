#include <iostream>
#include "redmetro.h"
#include"utilidades.h"
#include <string>
using namespace std;


int main()
{
    //Variables predefinidas
 string nombreEstacion;
 //Fin variables predefinidas



    bool salir = false;
    string nombre = "Metro de medellin";
    RedMetro metro1 (nombre);
    metro1.getLineas()[0]= Linea(1);
    metro1.setNumLineas(1);

    cout<<"Bienvenido a la red ("<<metro1.getNombre()<<") que te gustaria realizar: "<<endl;

    while(!salir){  //El programa se desenvolvera aca
        cout<<"1) Agregar una estacion  "<<endl;
        cout<<"2) Eliminar una estacion "<<endl;
        cout<<"3) Consultar numero de lineas de la red  "<<endl;
        cout<<"4) Consultar cuantas estaciones tiene una linea  "<<endl;
        cout<<"5) Consultar si una estacion pertenece a una linea  "<<endl;
        cout<<"6) Agregar una linea a la red  "<<endl;
        cout<<"7) Eliminar una linea de la red  "<<endl;
        cout<<"8) Consultar cuantas estaciones tiene la red  "<<endl;
        cout<<"Seleccione: "<<endl;

        int eleccion1;  //FALTA VALIDACION
        cin>>eleccion1;



        Linea lineaSel;
        switch (eleccion1) {
        case 1:



            int eleccion2;
            cout<<"Seleccione la linea en la cual quiere ingresar la nueva estacion: "<<endl;
            for(int i=0; i<metro1.getNumLineas();i++){
                cout<<i+1<<") "<<metro1.getLineas()[i].getNombre()<<endl;
            }
            cout<<"Seleccione: "<<endl;
            cin>>eleccion2;                 //FALTA VALIDACION
            eleccion2=eleccion2-1;
            lineaSel = metro1.getLineas()[eleccion2];
            cout<<"Quiere ingresar una estacion en: "<<endl;
            cout<<"1) Extremo superior "<<endl;
            cout<<"2) Extremo inferior "<<endl;
            cout<<"3) Posicion intermedia "<<endl;
            cout<<"Seleccione: "<<endl;


            int eleccion3;
            cin>>eleccion3; //FALTA VALIDACION



            switch (eleccion3) {
            case 1://Agregar estacion en extremo arriba(final)

                cout<<"Ingrese el nombre de la nueva estacion: "<<endl;
                cin>>nombreEstacion;
                lineaSel.AgregarEstacion(Estacion(nombreEstacion,lineaSel.getNombre()));
                metro1.getLineas()[0]=lineaSel;

                cout<<"Numero de estaciones de la linea "<<lineaSel.getNombre()<<" "<<lineaSel.getNumEstaciones()<<endl;
                cout<<"Numero de estaciones segun el arreglo de la red, de la linea "<<metro1.getLineas()[0].getNombre()<<": "<<metro1.getLineas()[0].getNumEstaciones()<<endl;
                cout<<"No hubo errores"<<endl;

                lineaSel.mostrarEstaciones();

                for(int i=0; i<lineaSel.getNumEstaciones();i++){
                    cout<<i+1<<"-"<<lineaSel.getEstaciones()[i].getNombre()<<endl;
                }
                cout<<endl<<"---------------------------------------------"<<endl;
                break;  //Fin de agregar estacion el entremo arriba


            case 2: //Agregar estacion extremo abajo
                cout<<"Ingrese el nombre de la nueva estacion: "<<endl;
                cin>>nombreEstacion;
                lineaSel.AgregarEstacionAtras(Estacion(nombreEstacion,lineaSel.getNombre()));
                metro1.getLineas()[0]=lineaSel;

                cout<<"Numero de estaciones de la linea "<<lineaSel.getNombre()<<" "<<lineaSel.getNumEstaciones()<<endl;
                cout<<"Numero de estaciones segun el arreglo de la red, de la linea "<<metro1.getLineas()[0].getNombre()<<": "<<metro1.getLineas()[0].getNumEstaciones()<<endl;
                cout<<"No hubo errores"<<endl;

                lineaSel.mostrarEstaciones();
             cout<<endl<<"---------------------------------------------"<<endl;


                break;  //Fin agregar estacion extremo abajo

            default:    //Opcion de posicion intermedia

                if(lineaSel.getNumEstaciones()<2){
                    cout<<"No puedes ingresar estaciones intermedias si solo tienes una estacion, debes crear una un extremo primero "<<endl;
                    cout<<"----------------------------------------------------"<<endl;
                     }
                else{

                    cout<<"Despues de que estacion le gustaria crear la nueva estacion "<<endl;
                    for (int i=0;i<lineaSel.getNumEstaciones();i++){ //Le restamos uno para que no cuente el extremo mayor
                        cout<<i+1<<") "<<lineaSel.getEstaciones()[i].getNombre()<<endl;
                    }
                    cout<<"Seleccione: ";
                    int eleccion4;
                    cin>>eleccion4;     //FALTA VALIDACION

                    cout<<"Ingrese el nombre de la nueva estacion: "<<endl;
                    cin>>nombreEstacion;

                    lineaSel.AgregarEstacionPosicion(Estacion(nombreEstacion, lineaSel.getNombre()),eleccion4);
                    metro1.getLineas()[0]=lineaSel;









                }

                break;      //Ahora toca ajustar la posicion de esta posicion en adelate para cada estacion
            }//Fin case pequeño
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;

        default:        //Caso 8
            break;
        }







    }









    return 0;
}
