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


#define TAM 20

/** \brief ingreso un int y valida que sea int
 *
 * \param
 * \param
 * \return
 *
 */
int ingresarInt ()
{
    int valido;
    int n;

    valido = scanf("%d", &n);
    fflush(stdin);

    while (!valido)
    {
        fflush(stdin);
        printf("Invalido. Ingrese un numero:");
        valido = scanf("%d", &n);
    }
    return n;
}

/** \brief menu principal
 *
 * \param
 * \param
 * \return
 *
 */
int menu ()
{
    char opcion;
    printf("Bienvenido. Ingrese una opcion:\n ");
    printf("A - ALTA MASCOTA:\n "); //Permite ingresar calculando el ID automaticamente. El resto es ingresado por usuario
    printf("B - MODIFICAR MASCOTA:\n "); // Permite cambiar informacion ID
    printf("C - BAJA MASCOTA:\n ");   //Dar de baja ingresando numero de ID
    printf("D - LISTAR MASCOTA\n ");  //listar
    printf("E - LISTAR TIPOS\n "); //listar
    printf("F - LISTAR COLORES\n "); //listar
    printf("G - LISTAR SERVICIOS\n "); //listar
    printf("H - ALTA TRABAJO\n ");  //Permite ingresar calculando el ID automaticamente. El resto es ingresado por usuario
    printf("I - LISTAR TRABAJOS\n ");    //listar
    printf("J - SALIR   :\n ");    //sale del menu
    scanf("%c", &opcion);
    system("cls");
    fflush(stdin);
    return opcion;
}

/** \brief menu para opcion modificar
 *
 * \param
 * \param
 * \return
 *
 */
int menuModificar ()
{
    char opcion;
    printf("Ingrese lo que desea cambiar: \n");
    printf("a - TIPO:\n ");
    printf("b - EDAD:\n ");
    scanf("%c", &opcion);
    system("cls");
    fflush(stdin);
    while (opcion !='a' && opcion != 'b' )
    {
        printf("ingrese una opcion valida:\n");
        scanf("%c", &opcion);
        fflush (stdin);
    }
    return opcion;
}



