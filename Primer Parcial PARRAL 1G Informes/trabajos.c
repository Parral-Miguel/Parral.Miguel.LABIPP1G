#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fecha.h"
#include "funciones.h"
#include "colores.h"
#include "tipos.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"
#include "cliente.h"
#include "informes.h"


/** \brief pone un 1 en los isEmpty
 *
 * \param trabajos eTrabajo*
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajo (eTrabajo* trabajos, int tam)
{

    int error = 1;
    if (trabajos!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty = 1;
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
int buscarEspacioLibreTrabajo (eTrabajo* trabajos, int tam) //busca el primer espacio libre de la lista
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/** \brief Listar un solo servicio
 *
 * \param unTrabajo eTrabajo
 * \return void
 *
 */
void listarTrabajo(eTrabajo* trabajos, int tam, int indice)
{

    printf(" %4d     %8s      %8s      %2d/%2d/%4d\n", trabajos[indice].id, trabajos[indice].idMascota.nombre, trabajos[indice].idServicio.servicio, trabajos[indice].fecha.dia, trabajos[indice].fecha.mes, trabajos[indice].fecha.anio);

}


/** \brief listar todos los trabajos
 *
 * \param trabajos eTrabajo*
 * \param tam int
 * \return int
 *
 */
int listarTrabajos(eTrabajo* trabajos, int tam)
{

    int error = 1;

    if( trabajos != NULL && tam > 0)
    {
        printf(" ID     Mascota        Servicio       Fecha\n");
        printf("------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                listarTrabajo(trabajos, tam, i);
            }

        }

        printf("\n\n");

        error = 0;

    }
    return error;

}

/** \brief muestra un solo trabajo
 *
 * \param trabajos eTrabajo
 * \return void
 *
 */
void listarUnTrabajo(eTrabajo* trabajos, int tam, int indice)
{
    system("cls");
    printf(" ID      Mascota          Servicio        Fecha\n");
    printf("-------------------------------------------------\n");
    printf(" %4d     %8s        %8s        %2d/%2d/%4d\n", trabajos[indice].id, trabajos[indice].idMascota.nombre, trabajos[indice].idServicio.servicio, trabajos[indice].fecha.dia, trabajos[indice].fecha.mes, trabajos[indice].fecha.anio);
}

/** \brief alta de trabajo
 *
 * \param trabajos eTrabajo*
 * \param tam int
 * \param id int
 * \param indice int
 * \return int
 *
 */
int altaTrabajo(eTrabajo* trabajos, eMascota* mascota, eServicio* servicio, int tam, int tam_a, int id)
{
    int error = 1;
    int valido = 1;
    int indice;
    indice = buscarEspacioLibreTrabajo(trabajos, tam);
    if (indice != -1)
    {
        trabajos[indice].id = id;
        listarMascotas(mascota, tam);
        printf("Ingrese la ID de la mascota: \n");       //pido datos y los pongo
        trabajos[indice].idMascota.id = ingresarInt();
        valido = validarMascota(trabajos, mascota, tam, indice);
        while (valido)
        {
            printf("No existe esa Mascota (ID de mascota comienzan desde 0): \n");
            printf("Ingrese la ID de mascota: \n");
            trabajos[indice].idMascota.id = ingresarInt();
            valido = validarMascota(trabajos, mascota, tam, indice);
        }
        system("cls");
        listarServicios(servicio, tam_a);
        printf("\n\n");
        printf("Ingrese la ID del servicio: \n");
        trabajos[indice].idServicio.id = ingresarInt();
        valido = validarServicio(trabajos, servicio, tam, indice);
        while (valido)
        {
            printf("No existe ese servicio (ID de servicio comienzan desde 1000): \n");
            printf("Ingrese la ID de servicio: \n");
            trabajos[indice].idServicio.id = ingresarInt();
            valido = validarServicio (trabajos, servicio, tam, indice);
        }
        system("cls");
        printf("Ingrese la Fecha: (dd/mm/aaaa) \n");
        scanf("%d/%d/%d", &trabajos[indice].fecha.dia, &trabajos[indice].fecha.mes, &trabajos[indice].fecha.anio);
        trabajos[indice].isEmpty = 0;
        listarUnTrabajo(trabajos, tam, indice);
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
int buscarPorIdTrabajo (eTrabajo* trabajos, int tam, int id)
{

    int indice = -1;

    for(int i = 0; i < tam; i++)
    {

        if(trabajos[i].id == id && trabajos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Baja logica de un servicio
 *
 * \param trabajos eTrabajo*
 * \param tam int
 * \return int
 *
 */
int bajaTrabajo(eTrabajo* trabajos, int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirmar;

    if(trabajos != NULL && tam > 0)
    {
        system("cls");
        printf("  --- BAJA DE TRABAJO ---\n");
        listarTrabajos(trabajos, tam);
        printf("Ingrese el id: ");
        id = ingresarInt();
        indice = buscarPorIdTrabajo(trabajos, tam, id);

        if( indice == -1)
        {
            printf("Id invalido.\n");
        }
        else
        {
            listarTrabajo(trabajos, tam, indice);
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
                trabajos[indice].isEmpty = 1;
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
 * \param trabajos eTrabajo*
 * \param tam int
 * \return int
 *
 */
int buscarVacioTrabajo(eTrabajo* trabajos, int tam)
{
    int error = 1;

    for (int i = 0; i < tam; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}

/** \brief valida que la mascota exista y copia el nombre de mascota
 *
 * \param
 * \param
 * \return
 *
 */
int validarMascota (eTrabajo* trabajos, eMascota* mascotas, int tam, int indice)
{

    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].id == trabajos[indice].idMascota.id)
        {
            strcpy(trabajos[indice].idMascota.nombre ,mascotas[i].nombre);
            error = 0;
        }
    }
    return error;
}

/** \brief valida que el servicio exista y copia el nombre de servicio
 *
 * \param
 * \param
 * \return
 *
 */
int validarServicio (eTrabajo* trabajos, eServicio* servicios, int tam, int indice)
{

    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(servicios[i].id == trabajos[indice].idServicio.id)
        {
            strcpy(trabajos[indice].idServicio.servicio ,servicios[i].servicio);
            error = 0;
        }
    }
    return error;
}
