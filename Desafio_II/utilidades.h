#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "linea.h"
#include "estacion.h"

class Utilidades
{
   Estacion** agregarEstacion(Estacion* estacion, Estacion** arreglo, int longitud);
   Estacion** EliminarEstacion(Estacion* estacion, Estacion** arreglo, int longitud);

   Linea** agregarLinea(Linea* linea, Linea** arreglo, int longitud);
   Linea** EliminarLinea(Linea* linea, Linea** arreglo, int longitud);




};

#endif // UTILIDADES_H
