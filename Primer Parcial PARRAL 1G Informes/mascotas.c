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
int altaMascota(eMascota* mascotas, eTipo* tipos, eColor* colores, eCliente* clientes, int tam, int tam_a, int id)
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
        listarTipos(tipos, tam_a);
        printf("\n\n");
        printf("Ingrese la ID del tipo: \n");
        mascotas[indice].idTipo.id = ingresarInt();
        valido = validarTipo(mascotas, tipos, tam, indice);
        while (valido)
        {
            printf("No existe ese tipo (ID de tipo comienzan desde 1000): \n");
            printf("Ingrese la ID de tipo: \n");
            mascotas[indice].idTipo.id = ingresarInt();
            valido = validarTipo(mascotas, tipos, tam, indice);
        }
        system("cls");
        listarColores(colores, tam_a);
        printf("\n\n");
        printf("Ingrese la ID de color: \n");
        mascotas[indice].idColor.id = ingresarInt();
        valido = validarColor(mascotas, colores, tam, indice);
        while (valido)
        {
            printf("No existe ese color (ID de color comienzan desde 5000): \n");
            printf("Ingrese la ID de color: \n");
            mascotas[indice].idColor.id = ingresarInt();
            valido = validarColor(mascotas, colores, tam, indice);
        }
        system("cls");
        printf("Ingrese la edad: \n");
        mascotas[indice].edad = ingresarInt();
        system("cls");
        listarClientes(clientes, tam);
        printf("\n\n");
        printf("Ingrese la ID del cliente: \n");
        mascotas[indice].idCliente.id = ingresarInt();
        valido = validarCliente(mascotas, clientes, tam, indice);
        while (valido)
        {
            printf("No existe ese cliente (ID de cliente comienzan desde 100): \n");
            printf("Ingrese la ID de cliente: \n");
            mascotas[indice].idCliente.id = ingresarInt();
            valido = validarCliente(mascotas, clientes, tam, indice);
        }
        system("cls");
        mascotas[indice].isEmpty = 0;
        mostrarUnaMascota(mascotas, tam, indice);
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
void mostrarUnaMascota(eMascota* mascotas, int tam, int indice)
{
    system("cls");
    printf(" ID   Nombre   Tipo    Color    Edad    Cliente \n");
    printf("-------------------------------------------------\n");
    printf(" %4d", mascotas[indice].id);
    printf(" %8s",mascotas[indice].nombre);
    printf(" %8s",mascotas[indice].idTipo.descripcion);
    printf(" %8s",mascotas[indice].idColor.nombreColor);
    printf(" %2d   ",mascotas[indice].edad);
    printf(" %8s\n",mascotas[indice].idCliente.nombre);
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

void listarMascota(eMascota* mascotas, int tam, int indice)
{
    printf(" %4d", mascotas[indice].id);
    printf(" %8s",mascotas[indice].nombre);
    printf(" %8s",mascotas[indice].idTipo.descripcion);
    printf(" %8s",mascotas[indice].idColor.nombreColor);
    printf(" %2d   ",mascotas[indice].edad);
    printf(" %8s\n",mascotas[indice].idCliente.nombre);


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

    if( mascotas != NULL && tam > 0)
    {
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                listarMascota(mascotas, tam, i);
            }
        }

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

                if (mascotas[i].idTipo.id > mascotas[j].idTipo.id)
                {

                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;

                }

                else if(mascotas[i].idTipo.id == mascotas[j].idTipo.id && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0)
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
            mostrarUnaMascota(mascotas, tam, indice);
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
int validarColor (eMascota* mascotas, eColor* colores, int tam, int indice)
{

    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(colores[i].id == mascotas[indice].idColor.id)
        {
            strcpy(mascotas[indice].idColor.nombreColor,colores[i].nombreColor);
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
int validarTipo (eMascota* mascotas, eTipo* tipo, int tam, int indice)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(tipo[i].id == mascotas[indice].idTipo.id)
        {
            strcpy(mascotas[indice].idTipo.descripcion,tipo[i].descripcion);
            error = 0;
        }
    }
    return error;
}

int modificarMascotas(eMascota* mascotas, eTipo* tipos, int tam, int tam_a)
{
    int error = 1;
    int identificacion;
    int valido;

    listarMascotas(mascotas, tam);
    printf("\nIngrese el id de la mascota: \n");
    identificacion = ingresarInt();
    identificacion = buscarPorId(mascotas, tam, identificacion);
    while (identificacion == -1)
    {
        printf("No existe esa id. Ingrese nuevamente: \n");
        identificacion = ingresarInt();
        identificacion = buscarPorId(mascotas, tam, identificacion);
    }
    system("cls");
    switch (menuModificar())
    {
    case 'a':
        listarTipos(tipos, tam_a);
        printf("\n\n");
        printf("Ingrese la ID del tipo: \n");
        mascotas[identificacion].idTipo.id = ingresarInt();
        valido = validarTipo(mascotas, tipos, tam, identificacion);
        while (valido)
        {
            printf("No existe ese tipo: \n");
            printf("Ingrese la ID de tipo: \n");
            mascotas[identificacion].idTipo.id = ingresarInt();
            valido = validarTipo(mascotas, tipos, tam, identificacion);
        }
        system("cls");
        mostrarUnaMascota(mascotas, tam, identificacion);
        printf("  --- MODIFICADO CORRECTAMENTE ---\n\n");
        break;

    case 'b':
        system("cls");
        printf("Ingrese la edad de la mascota: \n");
        mascotas[identificacion].edad = ingresarInt();
        system("cls");
        mostrarUnaMascota (mascotas, tam, identificacion);
        printf("  --- MODIFICADO CORRECTAMENTE ---\n\n");
        break;

    }
    return error;
}

int validarCliente (eMascota* mascotas, eCliente* clientes, int tam, int indice)
{
    int error = 1;
    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].id == mascotas[indice].idCliente.id)
        {
            strcpy(mascotas[indice].idCliente.nombre,clientes[i].nombre);
            error = 0;
        }
    }
    return error;
}
