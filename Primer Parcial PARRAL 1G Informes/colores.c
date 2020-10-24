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

/** \brief inicializa el struct colores
 *
 * \param colores eColor*
 * \param tam int
 * \return int
 *
 */
int inicializarColor(eColor* colores, int tam)
{

    int error = 1;
    if (colores!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            colores[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/** \brief busca siguiente espacio libre en colores
 *
 * \param colores eColor*
 * \param tam int
 * \return int
 *
 */
int buscarEspacioLibreColor(eColor* colores, int tam) //busca el primer espacio libre de la lista
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(colores[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief lista un color
 *
 * \param colores eColor*
 * \param tam int
 * \param indice int
 * \return void
 *
 */
void listarColor(eColor* colores, int tam, int indice)
{

    printf(" %d    %s  \n", colores[indice].id, colores[indice].nombreColor);

}

/** \brief lista todos los colores
 *
 * \param colores eColor*
 * \param tam int
 * \return int
 *
 */
int listarColores(eColor* colores, int tam)
{

    int error = 1;

    if( colores != NULL && tam > 0)
    {
        printf(" ID   Color\n");
        printf("-------------\n");

        for(int i=0; i<tam; i++)
        {
            if(colores[i].isEmpty == 0)
            {
                listarColor(colores, tam, i);
            }
        }
    }
    printf("\n\n");

    error = 0;


    return error;

}

/** \brief da de alta un color
 *
 * \param colores eColor*
 * \param tam int
 * \param id int
 * \return int
 *
 */
int altaColor(eColor* colores, int tam, int id)
{
    int error = 1;
    int indice;
    indice = buscarEspacioLibreColor(colores, tam);
    if (indice != -1)
    {
        colores[indice].id = id;
        printf("Ingrese el nuevo color: \n");       //pido datos y los pongo
        gets(colores[indice].nombreColor);
        colores[indice].isEmpty = 0;
        listarColor(colores, tam, indice);
        error = 0;
    }
     return error;
}



/** \brief busca un color por id
 *
 * \param colores eColor*
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarPorIdColor(eColor* colores, int tam, int id)
{

    int indice = -1;

    for(int i = 0; i < tam; i++)
    {

        if(colores[i].id == id && colores[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief baja logica de color
 *
 * \param colores eColor*
 * \param tam int
 * \return int
 *
 */
int bajaColor(eColor* colores, int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirmar;

    if(colores != NULL && tam > 0)
    {
        system("cls");
        printf("  --- BAJA DE COLOR ---\n");
        listarColores(colores, tam);
        printf("Ingrese el id: ");
        id = ingresarInt();
        indice = buscarPorIdColor(colores, tam, id);

        if( indice == -1)
        {
            printf("Id invalido.\n");
        }
        else
        {
            listarColor(colores, tam, indice);
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
                colores[indice].isEmpty = 1;
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

/** \brief busca si color esta vacio
 *
 * \param colores eColor*
 * \param tam int
 * \return int
 *
 */
int buscarVacioColor(eColor* colores, int tam)
{
    int error = 1;

    for (int i = 0; i < tam; i++)
    {
        if (colores[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}

