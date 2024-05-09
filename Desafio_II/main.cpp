#include <iostream>
#include "redmetro.h"
#include"utilidades.h"
#include <string>


using namespace std;

void mostrar(RedMetro metro1);
int main()
{
    //Variables predefinidas
 string nombreEstacion;
    Linea lineaSel;
 Estacion estacionSel;
    Linea nuevaLinea;
 int acum;
    string* estacionesTotales;
 int cont;
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
        cout<<"9) Consultar tiempo de una estacion a otra de la misma linea "<<endl;
        cout<<"Seleccione: "<<endl;

        int eleccion1;  //FALTA VALIDACION
        cin>>eleccion1;



        Linea lineaSel;
        switch (eleccion1) {
        case 1: //Agregar estacion

            if(metro1.getNumLineas()<1){
                cout<<"No existen lineas por ende no se pueden crear estaciones ";
                cout<<"-----------------------------------------------------"<<endl;

            }else{
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
                    metro1.getLineas()[eleccion2]=lineaSel;


                    break;  //Fin de agregar estacion el entremo arriba


                case 2: //Agregar estacion extremo abajo
                    cout<<"Ingrese el nombre de la nueva estacion: "<<endl;
                    cin>>nombreEstacion;
                    lineaSel.AgregarEstacionAtras(Estacion(nombreEstacion,lineaSel.getNombre()));
                    metro1.getLineas()[eleccion2]=lineaSel;

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
                        metro1.getLineas()[eleccion2]=lineaSel;
                    }
                }

                break;
            }//Fin case pequeño


            break;//Fin Agregar estacion
        case 2://Eliminar Estacion
            cout<<"Seleccine la linea de la estacion que desea eliminar: "<<endl;
            for(int i=0;i<metro1.getNumLineas();i++){
                cout<<i+1<<") "<<metro1.getLineas()[i].getNombre()<<endl;
            }
            cout<<"Seleccione: "<<endl;
            int eleccion4;
            cin>>eleccion4;

            eleccion4=eleccion4-1;
            lineaSel=metro1.getLineas()[eleccion4];
            cout<<"Seleccione la estacion que desea eliminar: "<<endl;
            for(int i =0 ; i<lineaSel.getNumEstaciones();i++){
                cout<<i+1<<")"<<lineaSel.getEstaciones()[i].getNombre()<<endl;
            }
            cout<<"Seleccione: "<<endl;
            int eleccion5;
            cin>>eleccion5;
            eleccion5=eleccion5-1;
            lineaSel.EliminarEstacion(lineaSel.getEstaciones()[eleccion5]);
            metro1.getLineas()[eleccion4]=lineaSel;



            break;//Fin eliminar Estacion

        case 3: //Consutar numero de lineas de la red
            cout<<"--------------------------------------------------"<<endl;
            cout<<"El numero de lineas de la red "<<metro1.getNombre()<<" es "<<metro1.getNumLineas()<<endl;
            cout<<"-------------------------------------------------"<<endl;

            break;//fin consultar numero de lineas

        case 4: //Consutar numero de estaciones en linea
            if(metro1.getNumLineas()<1){
                cout<<"-------------------------------------------------"<<endl;
                cout<<"No hay lineas para visualizar"<<endl;
                cout<<"-------------------------------------------------"<<endl;
            }else{

                cout<<"Seleccione la linea la cual quiere consultar el numero de estaciones: "<<endl;
                for(int i =0; i<metro1.getNumLineas();i++){
                    cout<<i+1<<") "<<metro1.getLineas()[i].getNombre()<<endl;
                }
                int eleccion4;
                cin>>eleccion4;
                eleccion4= eleccion4-1;
                cout<<"-------------------------------------------------"<<endl;
                cout<<"El numero de estaciones de la linea "<<metro1.getLineas()[eleccion4].getNombre()<<"  es "<<metro1.getLineas()[eleccion4].getNumEstaciones()<<endl;
                cout<<"-------------------------------------------------"<<endl;

            }
            break;// Fin consultar numeros de estacione en linea

        case 5: //Consultar si una estacion pertenece a una linea


            acum=0;
            for(int i=0;i<metro1.getNumLineas();i++){
                acum=acum+metro1.getLineas()[i].getNumEstaciones();
            }
            estacionesTotales = new string[acum];   //Creamos un arreglo donde vamos a almacenar las estaciones
            cont=0;
            for(int i=0;i<metro1.getNumLineas();i++){
                for(int j=0; j< metro1.getLineas()[i].getNumEstaciones(); j++){
                    estacionesTotales[cont] = metro1.getLineas()[i].getEstaciones()[j].getNombre();
                    cont++;
                }
            }

            cout<<endl;
            cout<<"Cual estacion desea consultar: "<<endl;

            for(int i=0;i<acum;i++){
                cout<<i+1<<") "<<estacionesTotales[i]<<endl;
            }


            int eleccion6;
            cin>>eleccion6;     //Falta validacion
            eleccion6=eleccion6-1;


            cout<<"Seleccione: "<<endl;

            nombreEstacion=estacionesTotales[eleccion6];

            cout<<"A que linea le gustaria consultar a la que pertence: "<<endl;
            for(int i=0;i<metro1.getNumLineas();i++){
                cout<<i+1<<")"<<metro1.getLineas()[i].getNombre()<<endl;
            }
            int eleccion7;
            cout<<"Seleccione: ";
             cin>>eleccion7;
            eleccion7=eleccion7-1;
            lineaSel=metro1.getLineas()[eleccion7];
             lineaSel.EstacionPertenece(nombreEstacion);

            break;//Fin consutar si una estacion pertenece a una linea

        case 6: //Agregar linea


            if(metro1.getNumLineas()<1){    //En dado caso que hallamos eliminado la primera y unica linea
                metro1.getLineas()[0]= Linea(1);
                metro1.setNumLineas(1);

            }else{
                cout<<endl<<"----------------------------------"<<endl;
                cout<<"Ingrese la linea de la estacion de la cual va a partir la nueva linea: "<<endl;
                for(int i=0; i<metro1.getNumLineas();i++){
                    cout<<i+1<<") "<<metro1.getLineas()[i].getNombre()<<endl;
                }
                int eleccion4;

                cout<<"Seleccione: ";
                cin>>eleccion4;
                eleccion4=eleccion4-1;  //Falta validacion-------



                lineaSel = metro1.getLineas()[eleccion4];
                cout<<"Linea seleccionada: "<<lineaSel.getNombre()<<endl;

                if(lineaSel.getNumEstaciones()<1){
                    cout<<endl<<"----------------------------------"<<endl;
                    cout<<"Para agregar una linea tiene que existir almenos una estacion de la linea de la cual vamos a partir "<<endl;
                    cout<<endl<<"----------------------------------"<<endl;


                }else{
                    cout<<"Seleccione la estacion de la cual va a partir la linea: "<<endl;
                    for(int i=0;i<lineaSel.getNumEstaciones();i++){
                        cout<<i+1<<")"<<lineaSel.getEstaciones()[i].getNombre()<<endl;
                    }
                    cout<<"Seleccione: ";
                    int eleccion5;
                    cin>>eleccion5; //Falta validacion
                    eleccion5= eleccion5-1;

                    lineaSel.getEstaciones()[eleccion5].setTransferencia(true);
                    estacionSel = lineaSel.getEstaciones()[eleccion5];
                    metro1.AgregarLinea(Linea(1));
                    //En la siguiente linea estamos creando la primera estacion de la linea en la cual tambien vamos a asignarle su nombre que tiene que ir contactenado con la...
                    //..estacion de la que partimos
                    metro1.getLineas()[metro1.getNumLineas()-1].AgregarEstacion(Estacion( estacionSel.getNombre()+metro1.getLineas()[metro1.getNumLineas()-1].getNombre(),metro1.getLineas()[metro1.getNumLineas()-1].getNombre()));
                }
            }
            break;//Fin de agregar linea


        case 7: //Eliminar linea de la red
            if(metro1.getNumLineas()==1){


                metro1.EliminarLinea();

            }else{
                cout<<endl<<"----------------------------------"<<endl;
                cout<<"No se pueden eliminar lineas ya que todas las lineas ya contienen estaciones de transferencia "<<endl;
                cout<<endl<<"----------------------------------"<<endl;
            }


            break;//Fin eliminar linea de la red


        case 8: //Consultar cuantas estaciones tiene la red
            cout<<"-----------------------------------------------------------"<<endl;
            if(metro1.getNumLineas()==1){
                cout<<"La red tiene "<<metro1.getLineas()->getNumEstaciones()<<" estaciones "<<endl;
            }else{

                acum=0;
                for(int i=0;i<metro1.getNumLineas();i++){
                    acum=acum+metro1.getLineas()[i].getNumEstaciones();
                }

                cout<<"La red tiene "<<acum-metro1.getNumLineas()+1<<" estaciones "<<endl;
                cout<<"-----------------------------------------------------------"<<endl;

            }


            break;

        case 9: //Tiempo de una estacion a otra de la misma linea

            int eleccion2;
            cout<<"Seleccione la linea en la cual quiere hacer la consulta: "<<endl;
            for(int i=0; i<metro1.getNumLineas();i++){
                cout<<i+1<<") "<<metro1.getLineas()[i].getNombre()<<endl;
            }
            cout<<"Seleccione: "<<endl;
            cin>>eleccion2;                 //FALTA VALIDACION
            eleccion2=eleccion2-1;
            lineaSel = metro1.getLineas()[eleccion2];




            for (int i=0;i<lineaSel.getNumEstaciones();i++){ //Le restamos uno para que no cuente el extremo mayor
                cout<<i+1<<") "<<lineaSel.getEstaciones()[i].getNombre()<<endl;
            }
            cout<<"Seleccione: "<<endl;


            int eleccion10;
            cin>>eleccion10;     //FALTA VALIDACION
            eleccion10=eleccion10-1;
            cout<<"Seleccione la segunda estacion: "<<endl;

            int eleccion11;
            cin>>eleccion11;     //FALTA VALIDACION
            eleccion11=eleccion11-1;
            if(eleccion10 == eleccion11){
                cout<<"---------------------------------------------------------"<<endl;
                cout<<"No puedes consultar el tiemp de una linea a la misma linea "<<endl;
                cout<<"---------------------------------------------------------"<<endl;

            }else{  // Si se puede encontrar el tiempo
                 float acum=0;
                if(eleccion10<eleccion11){

                    for(int i=eleccion10;i<eleccion11;i++){
                        cout<<"Acum es: "<<acum<<endl;
                        cout<<"El tiempo siguiente de la estacio "<<lineaSel.getEstaciones()[i].getNombre()<<" es "<<lineaSel.getEstaciones()[i].getTiempoSiguiente()<<endl;
                        acum=lineaSel.getEstaciones()[i].getTiempoSiguiente()+acum;
                        cout<<"Acum es: "<<acum<<endl;

                    }
                }else{

                    for(int i=eleccion11;i<eleccion10;i++){
                        cout<<"Acum es: "<<acum<<endl;
                        cout<<"El tiempo siguiente de la estacio "<<lineaSel.getEstaciones()[i].getNombre()<<" es "<<lineaSel.getEstaciones()[i].getTiempoSiguiente()<<endl;
                        acum=lineaSel.getEstaciones()[i].getTiempoSiguiente()+acum;
                        cout<<"Acum es: "<<acum<<endl;
                    }
                }
                cout<<"El tiempo que se tarda de la estacion "<<lineaSel.getEstaciones()[eleccion10].getNombre()<<" hasta la estacion "<<lineaSel.getEstaciones()[eleccion11].getNombre()<<" es "<<acum<<endl;
            }


            break;  // Fin tiempo de una estacion a otra de la misma linea



        default:
            cout<<"---------------------------------------------"<<endl;
            cout<<"Selecciona porfavor una opcion valida "<<endl;
            cout<<"---------------------------------------------"<<endl;
            break;
        }

        //Para tener mas control de lo que esta pasando
        mostrar(metro1);

    }
    cout<<"Seleccione la primera estacion "<<endl;







    return 0;
}

void mostrar(RedMetro metro1){
    for(int i=0;i<metro1.getNumLineas();i++){
        cout<<endl<<metro1.getLineas()[i].getNombre()<<"=>";
        for(int j=0;j< metro1.getLineas()[i].getNumEstaciones();j++){

            cout<<metro1.getLineas()[i].getEstaciones()[j].getNombre();
            if(j!=metro1.getLineas()[i].getNumEstaciones()-1){
                cout<<"_";
            }
        }
        metro1.getLineas()[i];
    }
    cout<<endl;
}
