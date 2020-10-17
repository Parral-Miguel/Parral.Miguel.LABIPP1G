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



int altaTipo(eTipo* tipos, int tam, int id, int indice)
{
    int error = 1;
    if (indice < tam)
    {
        tipos[indice].id = id;
        printf("Ingrese el nuevo tipo: \n");       //pido datos y los pongo
        gets(tipos[indice].descripcion);
        error = 0;
    }
     return error;
}


void listarTipo(eTipo unTipo)
{

    printf(" %d    %s   \n", unTipo.id, unTipo.descripcion);

}


int listarTipos(eTipo* tipos, int tam)
{

    int error = 1;

    if( tipos != NULL && tam > 0)
    {
        printf(" ID    Tipo \n");
        printf("-------------\n");

        for(int i=0; i<tam; i++)
        {

            listarTipo(tipos[i]);

        }

        printf("\n\n");

        error = 0;

    }
    return error;

}
