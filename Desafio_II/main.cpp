#include <iostream>
#include "redmetro.h"
#include"utilidades.h"
#include <string>
using namespace std;

int main()
{
    bool salir = false;
    RedMetro metro1(2); //Todo el programa se basara en esta instancia

    while(!salir){  //El programa se desenvolvera aca
        cout<<"Bienvenido a la red ("<<metro1.getNombre()<<") que te gustaria realizar: "<<endl;
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




        switch (eleccion1) {
        case 1:
            int eleccion2;
            cout<<"Seleccione la linea en la cual quiere ingresar la nueva estacion: "<<endl;
                for(int i=0; i<metro1.getNumLineas();i++){
                cout<<i+1<<") "<<metro1.getLineas()[i]->getNombre()<<endl;
            }
                cout<<"Seleccione: "<<endl;
            cin>>eleccion2;                 //FALTA VALIDACION
                eleccion2=eleccion2-1;

            Linea* lineaSel;
            lineaSel = metro1.getLineas()[eleccion2];

            cout<<"Quiere ingresar una estacion en: "<<endl;
            cout<<"1) Extremo superior "<<endl;
            cout<<"2) Extremo inferior "<<endl;
            cout<<"3) Posicion intermedia "<<endl;
            cout<<"Seleccione: "<<endl;

            int eleccion3;
            cin>>eleccion3; //FALTA VALIDACION


            switch (eleccion3) {
            case 1:

                break;
            case 2:

                break;

            default:    //Opcion de posicion intermedia
                cout<<"Despues de que estacion le gustaria crear la nueva estacion "<<endl;
                for (int i=0;i<lineaSel->getNumEstaciones()-1;i++){
                    cout<<i+1<<") "<<lineaSel->getEstaciones()[i]->getNombre();
                }

                int eleccion4;
                cin>>eleccion4;     //FALTA VALIDACION
                eleccion4=eleccion4-1;


                Estacion* estacionAnterior;
                estacionAnterior = lineaSel->getEstaciones()[eleccion4];
                Estacion* estacionSiguiente;
                estacionSiguiente = lineaSel->getEstaciones()[eleccion4+1];



                string nombreNuevaEstacion;
                cout<<"Cual va a ser el nombre de la nueva estacion: "<<endl;
                getline(cin,nombreNuevaEstacion);
                Estacion* estacionNueva = new Estacion(nombreNuevaEstacion,estacionAnterior->getNumEstacion(),lineaSel->getNombre());



                lineaSel->setEstaciones(Utilidades::agregarEstacionArreglo(estacionNueva,lineaSel->getEstaciones(),lineaSel->getNumEstaciones()));
                lineaSel->setNumEstaciones(lineaSel->getNumEstaciones()+1); //Agregamos el objeto al arreglo de estaciones

                cout<<"Cuanto tiempo se demora de la estacion "<<estacionAnterior->getNombre()<<" hasta la estacion "<<nombreNuevaEstacion<<" : "<<endl;
                float tiempoAnterior;
                cin>>tiempoAnterior;
                estacionNueva->setTiempoAnterior(tiempoAnterior);
                estacionAnterior->setTiempoSiguiente(tiempoAnterior);

                cout<<"Cuanto tiempo se demora de la estacion "<<estacionSiguiente->getNombre()<<" hasta la estacion "<<nombreNuevaEstacion<<" : "<<endl;
                float tiempoSiguiente;
                cin>>tiempoSiguiente;
                estacionNueva->setTiempoSiguiente(tiempoSiguiente);
                estacionSiguiente->setTiempoAnterior(tiempoSiguiente);

                break;      //Ahora toca ajustar la posicion de esta posicion en adelate para cada estacion
            }




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
