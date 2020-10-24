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

/** \brief valida que la eleccion exista
 *
 * \param colores eColor*
 * \param mascotas eMascota*
 * \param tam int
 * \param tam_a int
 * \param eleccion int
 * \return int
 *
 */
int validarEleccion(eColor* colores, eMascota* mascotas, int tam, int tam_a, int eleccion)
{
    int error = 1;
    for(int j = 0; j < tam_a; j++)
    {
        if (colores[j].id == eleccion)
        {
            error = 2;
        }
    }
    if (error == 2)
    {
        system("cls");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(mascotas[i].idColor.id == eleccion)
            {
                listarMascota(mascotas, tam, i);
                error = 0;
            }
        }
    }
    return error;
}

/** \brief valida que la eleccion exista
 *
 * \param tipos eTipo*
 * \param mascotas eMascota*
 * \param tam int
 * \param tam_a int
 * \param eleccion int
 * \return int
 *
 */
int validarEleccionTipo(eTipo* tipos, eMascota* mascotas,int tam, int tam_a, int eleccion)
{
    int error = 1;
    for(int j = 0; j < tam_a; j++)
    {
        if (tipos[j].id == eleccion)
        {
            error = 2;
        }
    }
    if (error == 2)
    {
        system("cls");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(mascotas[i].idTipo.id == eleccion)
            {
                listarMascota(mascotas, tam, i);
                error = 0;
            }
        }
    }
    return error;
}

/** \brief busca la mascota menor
 *
 * \param mascotas eMascota*
 * \param tam int
 * \return int
 *
 */
int buscarMascotaMenor(eMascota* mascotas, int tam)
{
    int error = 1;
    eMascota auxMascota;

    if(mascotas != NULL && tam > 0)
    {

        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                if (mascotas[i].edad > mascotas[j].edad)
                {

                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;

                }

            }
        }
        error = 0;
    }
    printf("----MASCOTAS DE ACUERDO A LA MAS JOVEN----\n\n");
    listarMascotas(mascotas, tam);
    return error;
}

/** \brief separa por tipo las mascotas
 *
 * \param tipos eTipo*
 * \param mascotas eMascota*
 * \param tam int
 * \param tam_a int
 * \return void
 *
 */
void SepararTipo(eTipo* tipos, eMascota* mascotas,int tam, int tam_a)
{
    int error;
    system("cls");

    for(int n = 0; n < 5; n++)
    {
        error = 1;
        printf("\n\n");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(mascotas[i].idTipo.id == tipos[n].id)
            {
                listarMascota(mascotas, tam, i);
                error = 0;
            }
        }
        if (error)
        {
            printf("No hay mascotas de ese tipo (%s)\n", tipos[n].descripcion);
        }
    }
}

/** \brief cuenta las instancias de un tipo y un color y ambos a la vez
 *
 * \param mascotas eMascota*
 * \param tipos eTipo*
 * \param colores eColor*
 * \param tam int
 * \param tam_a int
 * \param eleccionTipo int
 * \param eleccionColor int
 * \return int
 *
 */
int contarTipoColor(eMascota* mascotas, eTipo* tipos, eColor* colores, int tam, int tam_a, int eleccionTipo, int eleccionColor)
{
    int error = 1;
    int flag1 = 0;
    int flag2 = 0;
    int contadorTipo = 0;
    int contadorColor = 0;
    int contadorAmbos = 0;
    for(int j = 0; j < tam_a; j++)
    {
        if (tipos[j].id == eleccionTipo)
        {
            flag1 = 1;
        }
        if (colores[j].id == eleccionColor)
        {
            flag2 = 1;
        }
    }

    if (flag1 == 1 && flag2 == 1)
    {
        system("cls");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(mascotas[i].idTipo.id == eleccionTipo)
            {
                listarMascota(mascotas, tam, i);
                contadorTipo++;
                error = 0;
            }
        }
        printf("Hay %d mascotas de ese tipo\n\n", contadorTipo);
        system("pause");
        system("cls");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n\n");
        for(int n = 0; n < tam; n++)
        {
            if(mascotas[n].idColor.id == eleccionColor)
            {
                listarMascota(mascotas, tam, n);
                contadorColor++;
                error = 0;
            }
        }

        printf("Hay %d mascotas de ese color\n\n", contadorColor);
        system("pause");
        system("cls");
        printf(" ID   Nombre   Tipo    Color     Edad       Cliente\n");
        printf("---------------------------------------------------\n\n");
        for(int g = 0; g < tam; g++)
        {
            if(mascotas[g].idColor.id == eleccionColor && mascotas[g].idTipo.id == eleccionTipo)
            {
                listarMascota(mascotas, tam, g);
                contadorAmbos++;
                error = 0;
            }
        }
        printf("Hay %d mascotas de ese color y tipo\n\n", contadorAmbos);
    }
    return error;
}


/** \brief busca el color mas presente en la lista
 *
 * \param colores eColor*
 * \param mascotas eMascota*
 * \param tam int
 * \param tam_a int
 * \return int
 *
 */
void MasColor(eColor* colores, eMascota* mascotas, int tam, int tam_a)
{
    int contador[5] = {0,0,0,0,0};

    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].idColor.id == colores[0].id)
        {
            contador[0]++;
        }
        if(mascotas[i].idColor.id == colores[1].id)
        {
            contador[1]++;
        }
        if(mascotas[i].idColor.id == colores[2].id)
        {
            contador[2]++;
        }
        if(mascotas[i].idColor.id == colores[3].id)
        {
            contador[3]++;
        }
        if(mascotas[i].idColor.id == colores[4].id)
        {
            contador[4]++;
        }
    }
    if (contador[4] >= contador[3] && contador[4] >= contador[2] && contador[4] >= contador[1] && contador[4] >= contador[0])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[4].nombreColor, contador[4]);
    }
    if (contador[4] >= contador[3] && contador[4] >= contador[2] && contador[4] >= contador[1] && contador[4] >= contador[0])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[4].nombreColor, contador[4]);
    }
    if (contador[3] >= contador[4] && contador[3] >= contador[2] && contador[3] >= contador[1] && contador[3] >= contador[0])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[3].nombreColor, contador[3]);
    }
    if (contador[2] >= contador[3] && contador[2] >= contador[4] && contador[2] >= contador[1] && contador[2] >= contador[0])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[2].nombreColor, contador[2]);
    }
    if (contador[1] >= contador[3] && contador[1] >= contador[2] && contador[1] >= contador[4] && contador[1] >= contador[0])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[1].nombreColor, contador[1]);
    }
    if (contador[0] >= contador[3] && contador[0] >= contador[2] && contador[0] >= contador[1] && contador[0] >= contador[4])
    {

        printf("el color mas popular es %s. aparece %d veces\n", colores[0].nombreColor, contador[0]);
    }
}

int validarTrabajo (eMascota* mascotas, eTrabajo* trabajos, int tam, int mascotaId)
{
    int error = 1;
    int flag = 0;
    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].id == mascotaId)
        {
            error = 0;
        }
    }
    if (error == 0)
    {
        printf(" ID     Mascota        Servicio       Fecha\n");
        printf("------------------------------------------------\n");
        for (int n = 0; n < tam; n++)
        {
            if (trabajos[n].idMascota.id == mascotaId)
            {
                listarTrabajo(trabajos, tam, n);
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        printf("no se realizaron trabajos con esta mascota\n");
    }
    return error;
}

