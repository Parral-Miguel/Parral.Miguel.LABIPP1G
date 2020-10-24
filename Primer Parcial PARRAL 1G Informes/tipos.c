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

/** \brief inicializa el struct tipo
 *
 * \param tipos eTipo*
 * \param tam int
 * \return int
 *
 */
int inicializarTipo(eTipo* tipos, int tam)
{

    int error = 1;
    if (tipos!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            tipos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}
/** \brief busca siguiente espacio libre de tipo
 *
 * \param
 * \param
 * \return devuelve el indice
 *
 */
int buscarEspacioLibreTipo (eTipo* tipos, int tam) //busca el primer espacio libre de la lista
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(tipos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief da de alta un tipo nuevo
 *
 * \param tipos eTipo*
 * \param tam int
 * \param id int
 * \return int
 *
 */
int altaTipo(eTipo* tipos, int tam, int id)
{
    int error = 1;
    int indice;
    indice = buscarEspacioLibreTipo(tipos, tam);
    if (indice != -1)
    {
        tipos[indice].id = id;
        printf("Ingrese el nuevo tipo de mascota: \n");       //pido datos y los pongo
        gets(tipos[indice].descripcion);
        tipos[indice].isEmpty = 0;
        listarTipo(tipos, tam, indice);
        error = 0;
    }
     return error;
}


void listarTipo(eTipo* tipos, int tam, int indice)
{

    printf(" %d    %s   \n", tipos[indice].id, tipos[indice].descripcion);

}


/** \brief lista todos los tipos
 *
 * \param tipos eTipo*
 * \param tam int
 * \return int
 *
 */
int listarTipos(eTipo* tipos, int tam)
{

    int error = 1;

    if( tipos != NULL && tam > 0)
    {
        printf(" ID    Tipo \n");
        printf("-------------\n");

        for(int i=0; i<tam; i++)
        {

           if(tipos[i].isEmpty == 0)
            {
                listarTipo(tipos, tam, i);
            }

        }

        printf("\n\n");

        error = 0;

    }
    return error;

}


/** \brief busca un tipo por su id
 *
 * \param
 * \param
 * \return devuelve el numero de id
 *
 */
int buscarPorIdTipo (eTipo* tipos, int tam, int id)
{

    int indice = -1;

    for(int i = 0; i < tam; i++)
    {

        if(tipos[i].id == id && tipos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief baja logica de tipo
 *
 * \param tipos eTipo*
 * \param tam int
 * \return int
 *
 */
int bajaTipo(eTipo* tipos, int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirmar;

    if(tipos != NULL && tam > 0)
    {
        system("cls");
        printf("  --- BAJA DE TIPO ---\n");
        listarTipos(tipos, tam);
        printf("Ingrese el id: ");
        id = ingresarInt();
        indice = buscarPorIdTipo(tipos, tam, id);

        if( indice == -1)
        {
            printf("Id invalido.\n");
        }
        else
        {
            listarTipo(tipos, tam, indice);
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
                tipos[indice].isEmpty = 1;
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

/** \brief busca que tipo no este vacio
 *
 * \param tipos eTipo*
 * \param tam int
 * \return int
 *
 */
int buscarVacioTipo(eTipo* tipos, int tam)
{
    int error = 1;

    for (int i = 0; i < tam; i++)
    {
        if (tipos[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}


