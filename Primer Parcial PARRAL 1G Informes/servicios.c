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
#include "fecha.h"
#include "cliente.h"
#include "informes.h"

/** \brief pone un 1 en los isEmpty
 *
 * \param servicios eServicio*
 * \param tam int
 * \return int
 *
 */
int inicializarServi (eServicio* servicios, int tam)
{

    int error = 1;
    if (servicios!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            servicios[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/** \brief Busca un espacio libre para el alta
 *
 * \param
 * \param
 * \return
 *
 */
int buscarEspacioLibreServi (eServicio* servicios, int tam) //busca el primer espacio libre de la lista
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(servicios[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/** \brief Listar un solo servicio
 *
 * \param unServicio eServicio
 * \return void
 *
 */
void listarServicio(eServicio* servicios, int tam, int indice)
{

    printf(" %d    %s   %d\n", servicios[indice].id, servicios[indice].servicio, servicios[indice].precio);

}


/** \brief listar todos los servicios
 *
 * \param servicios eServicio*
 * \param tam int
 * \return int
 *
 */
int listarServicios(eServicio* servicios, int tam)
{

    int error = 1;

    if( servicios != NULL && tam > 0)
    {
        printf(" ID    Servicio     Precio\n");
        printf("---------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(servicios[i].isEmpty == 0)
            {
                listarServicio(servicios, tam, i);
            }

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
int altaServicio(eServicio* servicios, int tam, int id)
{
    int error = 1;
    int indice;
    indice = buscarEspacioLibreServi(servicios, tam);
    if (indice != -1)
    {
        servicios[indice].id = id;
        printf("Ingrese el nuevo servicio: \n");       //pido datos y los pongo
        gets(servicios[indice].servicio);
        printf("Ingrese el precio del servicio: \n");
        servicios[indice].precio = ingresarInt();
        servicios[indice].isEmpty = 0;
        listarServicio(servicios, tam, indice);
        error = 0;
    }
    return error;
}

/** \brief Busca un servicio en particular por su ID
 *
 * \param
 * \param
 * \return
 *
 */
int buscarPorIdServi (eServicio* servicios, int tam, int id)
{

    int indice = -1;

    for(int i = 0; i < tam; i++)
    {

        if(servicios[i].id == id && servicios[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Baja logica de un servicio
 *
 * \param servicios eServicio*
 * \param tam int
 * \return int
 *
 */
int bajaServicio(eServicio* servicios, int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirmar;

    if(servicios != NULL && tam > 0)
    {
        system("cls");
        printf("  --- BAJA DE SERVICIO ---\n");
        listarServicios(servicios, tam);
        printf("Ingrese el id: ");
        id = ingresarInt();
        indice = buscarPorIdServi(servicios, tam, id);

        if( indice == -1)
        {
            printf("Id invalido.\n");
        }
        else
        {
            listarServicio(servicios, tam, indice);
            printf("Confirma baja: (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
            while (confirmar != 's' && confirmar != 'n')
            {
                printf("Invalido. Confirme baja: (s/n)\n");
                scanf("%c", &confirmar);
                fflush(stdin);
            }
            if(confirmar == 's')
            {
                servicios[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    return error;

}

/** \brief busca al menos un espacio lleno
 *
 * \param servicios eServicio*
 * \param tam int
 * \return int
 *
 */
int buscarVacioServi(eServicio* servicios, int tam)
{
    int error = 1;

    for (int i = 0; i < tam; i++)
    {
        if (servicios[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}
