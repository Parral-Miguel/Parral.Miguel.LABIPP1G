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

/** \brief pone un 1 en los isEmpty
 *
 * \param mascotas eMascota*
 * \param tam int
 * \return int
 *
 */
int inicializarLista(eMascota* mascotas, int tam)
{

    int error = 1;
    if (mascotas!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/** \brief busca isEmpty = 1
 *
 * \param
 * \param
 * \return
 *
 */
int buscarEspacioLibre (eMascota* mascotas, int tam) //busca el primer espacio libre de la lista
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief da de alta una mascota, devuelve estado de error o no
 *
 * \param mascotas eMascota*
 * \param tipos eTipo*
 * \param colores eColor*
 * \param tam int
 * \param id int
 * \return int
 *
 */
int altaMascota(eMascota* mascotas, eTipo* tipos, eColor* colores, int tam, int id)
{
    int error = 1;
    int valido = 1;
    int indice;
    indice = buscarEspacioLibre(mascotas, tam);
    if (indice != -1)
    {
        mascotas[indice].id = id;
        printf("Ingrese el nombre de la mascota: \n");       //pido datos y los pongo
        gets(mascotas[indice].nombre);
        system("cls");
        listarTipos(tipos, 5);
        printf("\n\n");
        printf("Ingrese la ID del tipo: \n");
        mascotas[indice].idTipo = ingresarInt();
        valido = validarTipo(mascotas[indice], tipos, 5);
        while (valido)
        {
            printf("No existe ese tipo (ID de tipo comienzan desde 1000): \n");
            printf("Ingrese la ID de tipo: \n");
            mascotas[indice].idTipo = ingresarInt();
            valido = validarTipo(mascotas[indice], tipos, 5);
        }
        system("cls");
        listarColores(colores, 5);
        printf("\n\n");
        printf("Ingrese la ID de color: \n");
        mascotas[indice].idColor = ingresarInt();
        valido = validarColor(mascotas[indice], colores, 5);
        while (valido)
        {
            printf("No existe ese color (ID de color comienzan desde 5000): \n");
            printf("Ingrese la ID de color: \n");
            mascotas[indice].idColor = ingresarInt();
            valido = validarColor(mascotas[indice], colores, 5);
        }
        system("cls");
        printf("Ingrese la edad: \n");
        mascotas[indice].edad = ingresarInt();
        mascotas[indice].isEmpty = 0;
        mostrarUnaMascota(mascotas[indice]);
        error = 0;
    }
     return error;
}

/** \brief muestra una sola mascota
 *
 * \param unaMascota eMascota
 * \return void
 *
 */
void mostrarUnaMascota(eMascota unaMascota)
{
    system("cls");
    printf(" ID   Nombre   Tipo    Color     Edad \n");
    printf("----------------------------------------------\n");
    printf(" %d    %s       %d       %d        %d\n", unaMascota.id, unaMascota.nombre, unaMascota.idTipo, unaMascota.idColor, unaMascota.edad);
}

int buscarVacio(eMascota* mascotas, int tam)
{
    int error = 1;

    for (int i = 0; i < tam; i++)
    {
        if (mascotas[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}

void listarMascota(eMascota unaMascota)
{
    printf(" %d    %s       %d       %d        %d\n", unaMascota.id, unaMascota.nombre, unaMascota.idTipo, unaMascota.idColor, unaMascota.edad);

}

/** \brief lista todas las mascotas
 *
 * \param mascotas eMascota*
 * \param tam int
 * \return int
 *
 */
int listarMascotas(eMascota* mascotas, int tam)
{

    int error = 1;
    int flag = 0;

    if( mascotas != NULL && tam > 0)
    {
        printf(" ID   Nombre   Tipo    Color     Edad \n");
        printf("----------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                listarMascota(mascotas[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}

/** \brief busca mascota por id
 *
 * \param
 * \param
 * \return
 *
 */
int buscarPorId (eMascota* mascotas, int tam, int id)
{

    int indice = -1;

    for(int i = 0; i < tam; i++)
    {

        if(mascotas[i].id == id && mascotas[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/** \brief ordena por tipo y nombre
 *
 * \param
 * \param
 * \return
 *
 */
int ordenarMascotas (eMascota* mascotas, int tam)
{

    int error = 1;
    eMascota auxMascota;

    if(mascotas != NULL && tam > 0)
    {

        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                if (mascotas[i].idTipo > mascotas[j].idTipo)
                {

                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;

                }

                else if(mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }

            }
        }
        error = 0;
    }

    return error;
}

/** \brief da de baja mascota poniendo isEmpty en 1
 *
 * \param mascotas eMascota*
 * \param tam int
 * \return int
 *
 */
int bajaMascota(eMascota* mascotas, int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirmar;

    if(mascotas != NULL && tam > 0)
    {
        system("cls");
        printf("  --- BAJA DE MASCOTA ---\n");
        listarMascotas(mascotas, tam);
        printf("Ingrese el id: ");
        id = ingresarInt();
        indice = buscarPorId(mascotas, tam, id);

        if( indice == -1)
        {
            printf("No existe una mascota con ese id.\n");
        }
        else
        {
            mostrarUnaMascota(mascotas[indice]);
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
                mascotas[indice].isEmpty = 1;
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

/** \brief valida que exista valor de color
 *
 * \param
 * \param
 * \return
 *
 */
int validarColor (eMascota unaMascota, eColor* colores, int tam)
{

    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(colores[i].id == unaMascota.idColor)
        {
            error = 0;
        }
    }
    return error;
}

/** \brief valida que exista valor de tipo
 *
 * \param
 * \param
 * \return
 *
 */
int validarTipo (eMascota unaMascota, eTipo* tipo, int tam)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(tipo[i].id == unaMascota.idTipo)
        {
            error = 0;
        }
    }
    return error;
}

