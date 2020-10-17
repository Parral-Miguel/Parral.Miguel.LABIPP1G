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


void listarServicio(eServicio unServicio)
{

    printf(" %d    %s   %d\n", unServicio.id, unServicio.servicio, unServicio.precio);

}


int listarServicios(eServicio* servicios, int tam)
{

    int error = 1;

    if( servicios != NULL && tam > 0)
    {
        printf(" ID    Servicio     Precio\n");
        printf("---------------------------\n");

        for(int i=0; i<tam; i++)
        {

        listarServicio(servicios[i]);

        }

        printf("\n\n");

        error = 0;

    }
    return error;

}

/** \brief alta de servicio
 *
 * \param servicios eServicio*
 * \param tam int
 * \param id int
 * \param indice int
 * \return int
 *
 */
int altaServicio(eServicio* servicios, int tam, int id, int indice)
{
    int error = 1;
    if (indice < tam)
    {
        servicios[indice].id = id;
        printf("Ingrese el nuevo servicio: \n");       //pido datos y los pongo
        gets(servicios[indice].servicio);
        system("cls");
        printf("Ingrese el precio: \n");
        servicios[indice].precio = ingresarInt();
        error = 0;
    }
     return error;
}
