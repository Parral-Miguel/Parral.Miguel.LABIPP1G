#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "colores.h"
#include "tipos.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"



void listarColor(eColor unColor)
{

    printf(" %d    %s  \n", unColor.id, unColor.nombreColor);

}

int listarColores(eColor* colores, int tam)
{

    int error = 1;

    if( colores != NULL && tam > 0)
    {
        printf(" ID   Color\n");
        printf("-------------\n");

        for(int i=0; i<tam; i++)
        {
            listarColor(colores[i]);
        }
    }
    printf("\n\n");

    error = 0;


    return error;

}

int altaColores(eColor* colores, int tam, int id, int indice)
{
    int error = 1;
    if (indice < tam)
    {
        colores[indice].id = id;
        printf("Ingrese el nuevo color: \n");       //pido datos y los pongo
        gets(colores[indice].nombreColor);
        error = 0;
    }
     return error;
}
