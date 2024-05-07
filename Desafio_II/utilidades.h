
#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "linea.h"
#include "estacion.h"

class Utilidades
{
public:
   static Estacion* agregarEstacionArregloFinal(Estacion estacion, Estacion* arreglo, int longitud);
   static Linea* agregarLineaArregloFinal(Linea linea, Linea* arreglo, int longitud);
   static Estacion* agregarEstacionArregloInicio(Estacion estacion, Estacion* arreglo, int longitud);
   static Linea* agregarLineaArregloInicio(Linea linea, Linea* arreglo, int longitud);



   static Estacion* agregarEstacionArregloMedio(Estacion estacion, Estacion* arreglo, int indice, int longitud);
   static Linea* agregarLineaArregloMedio(Linea linea, Linea* arreglo, int indice, int longitud);



   Linea* EliminarLinea(Linea linea, Linea* arreglo, int longitud);
   Estacion* EliminarEstacion(Estacion* estacion, Estacion* arreglo, int longitud);



};

#endif // UTILIDADES_H
