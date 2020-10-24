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


#define TAM 20
#define TAM_A 10

int main()
{
    int id = 505;
    int idTrabajo = 8005;
    int mascotaId;

    int error = 0;
    int vacio;
    int eleccion;
    int eleccionTipo;
    int eleccionColor;
    int valido = 0;
    char confirmar = 'n';

    eTrabajo trabajos [TAM];
    eMascota mascotas [TAM];
    eTipo tipos[TAM_A];
    eColor colores[TAM_A];
    eCliente clientes[TAM_A];
    eServicio servicios[TAM_A];

    inicializarLista(mascotas, TAM);
    inicializarTrabajo(trabajos, TAM);
    inicializarColor(colores, TAM_A);
    inicializarTipo(tipos, TAM_A);
    inicializarServi(servicios, TAM_A);
    inicializarCliente(clientes, TAM);

    hardcodeoClientes(clientes, TAM);
    hardcodeoTipos(tipos, TAM_A);
    hardcodeoColores(colores, TAM_A);
    hardcodeoServicios(servicios, TAM_A);
    hardcodeoMascotas(mascotas, tipos, colores, clientes, TAM);
    hardcodeoTrabajos(trabajos, mascotas, servicios, TAM);


    do
    {
        switch (menu())
        {
        case 'a':
            system("cls");
            fflush(stdin);
            printf("  --- ALTA DE MASCOTA ---\n\n");
            error = altaMascota(mascotas, tipos, colores, clientes, TAM, TAM_A, id);
            if (error == 1)
            {
                printf("  --- Lista llena ---\n\n");
            }
            else
            {
                printf("  --- Alta realizada con exito ---\n\n");
                id++;
            }
            break;

        case 'b':
            vacio = buscarVacio(mascotas, TAM);    // checkea si hay almenos un empleado en registro antes de operar
            if (vacio)
            {
                printf("Error. No hay mascotas en el registro.\n");
                break;
            }
            printf("  --- MODIFICAR ---\n\n");
            error = modificarMascotas(mascotas, tipos, TAM, TAM_A);
            break;

        case 'c':
            valido = buscarVacio(mascotas, TAM);
            if (valido)
            {
                printf("Error. No hay mascotas en el registro.\n");
                break;
            }
            error = bajaMascota (mascotas, TAM);     //con la id, la funcion busca el indice del empleado y pone isEmpty en 1
            if (error == 1)     //devuelve distintos errores por distintas circunstancias
            {
                printf ("No se realizo la baja \n");    //la id no existe
            }
            else if (error == 2)
            {
                printf ("No se realizo la baja: cancelada por el usuario\n");   //el usuario cancelo
            }
            else
            {
                printf ("Baja realizada con exito \n");
            }

            break;
        case 'd':
            system("cls");
            fflush(stdin);
            printf("  --- LISTA DE MASCOTAS ---\n\n");
            ordenarMascotas (mascotas, TAM);
            listarMascotas(mascotas, TAM);
            break;

        case 'e':
            system("cls");
            fflush(stdin);
            printf("  --- TIPOS DE MASCOTAS ---\n\n");
            listarTipos (tipos, TAM_A);
            break;

        case 'f':
            system("cls");
            fflush(stdin);
            printf("  --- COLORES DE MASCOTAS ---\n\n");
            listarColores (colores, TAM_A);

            break;
        case 'g':
            system("cls");
            fflush(stdin);
            printf("  --- SERVICIOS ---\n\n");
            listarServicios (servicios, TAM_A);

            break;
        case 'h':
            system("cls");
            fflush(stdin);
            vacio = buscarVacio(mascotas, TAM);    // checkea si hay almenos un empleado en registro antes de operar
            if (vacio)
            {
                printf("Error. No hay mascotas en el registro.\n");
                break;
            }
            printf("  --- ALTA DE TRABAJO ---\n\n");
            error = altaTrabajo(trabajos, mascotas, servicios, TAM, TAM_A, idTrabajo);
            if (error == 1)
            {
                printf("  --- Lista llena ---\n\n");
            }
            else
            {
                printf("  --- Alta realizada con exito ---\n\n");
                idTrabajo++;
            }

            break;
        case 'i':
            system("cls");
            fflush(stdin);
            vacio = buscarVacioTrabajo(trabajos, TAM);    // checkea si hay almenos un empleado en registro antes de operar
            if (vacio)
            {
                printf("Error. No hay trabajos en el registro.\n");
                break;
            }
            listarTrabajos (trabajos, TAM_A);

            break;
        case 'j':
            printf ("esta seguro de salir?: (s/n)\n");  //confirmo si quiero salir y valido el dato ingresado
            scanf ("%c", &confirmar); // sobreescribo el valor de cornfirm, permitiendo salir del do while
            fflush (stdin);
            while (confirmar != 's' && confirmar != 'n')
            {
                printf ("opcion invalida, ingrese un caracter (s/n).\n");
                scanf ("%c", &confirmar);
                fflush (stdin);
            }
            break;

        case 'k':
            system("cls");
            fflush(stdin);
            printf("  --- LISTA DE CLIENTES ---\n\n");
            listarClientes(clientes, TAM_A);
            break;

        case 'l':
            vacio = buscarVacio(mascotas, TAM);    // checkea si hay almenos un empleado en registro antes de operar
            if (vacio)
            {
                printf("Error. No hay mascotas en el registro.\n");
                break;
            }
            system("cls");
            fflush(stdin);
            switch(menuInformes())
            {
            case 1:
                printf("  --- COLORES DE MASCOTAS ---\n\n");
                listarColores (colores, TAM_A);
                printf("Elegir un color para informar \n");
                eleccion = ingresarInt();
                valido = validarEleccion(colores, mascotas, TAM, TAM_A, eleccion);
                while (valido == 1)
                {
                    printf("No existe ese color (ID de color comienzan desde 5000): \n");
                    printf("Ingrese la ID de color: \n");
                    eleccion = ingresarInt();
                    valido = validarEleccion(colores, mascotas, TAM, TAM_A, eleccion);
                }
                if (valido == 2)
                {
                    printf("No hay una mascota con ese color en el sistema: \n");

                }

                break;

            case 2:
                printf("  --- TIPOS DE MASCOTAS ---\n\n");
                listarTipos (tipos, TAM_A);
                printf("Elegir un tipo para informar \n");
                eleccion = ingresarInt();
                valido = validarEleccionTipo(tipos, mascotas, TAM, TAM_A, eleccion);
                while (valido == 1)
                {
                    printf("No existe ese tipo (ID de tipo comienzan desde 1000): \n");
                    printf("Ingrese la ID de tipo: \n");
                    eleccion = ingresarInt();
                    valido = validarEleccionTipo(tipos, mascotas, TAM, TAM_A, eleccion);
                }
                if (valido == 2)
                {
                    printf("No hay una mascota de ese tipo en el sistema: \n");

                }
                break;
            case 3:
                buscarMascotaMenor(mascotas, TAM);
                break;
            case 4:
                printf("  --- MASCOTAS POR TIPO ---\n\n");
                SepararTipo(tipos, mascotas, TAM, TAM_A);
                break;

            case 5:
                printf("  --- CANTIDAD DE MASCOTAS POR TIPO Y COLOR ---\n\n");
                system("cls");
                listarTipos (tipos, TAM_A);
                printf("Elegir un tipo para informar \n");
                eleccionTipo = ingresarInt();
                system("cls");
                listarColores (colores, TAM_A);
                printf("Elegir un color para informar \n");
                eleccionColor = ingresarInt();
                valido = contarTipoColor(mascotas, tipos, colores, TAM, TAM_A, eleccionTipo, eleccionColor);
                while (valido == 1)
                {
                    printf("No existe ese tipo o color, ingresar nuevamente. \n");
                    system("pause");
                    system("cls");
                    listarTipos (tipos, TAM_A);
                    printf("Elegir un tipo para informar \n");
                    eleccionTipo = ingresarInt();
                    system("cls");
                    listarColores (colores, TAM_A);
                    printf("Elegir un color para informar \n");
                    eleccionColor = ingresarInt();
                    valido = contarTipoColor(mascotas, tipos, colores, TAM, TAM_A, eleccionTipo, eleccionColor);
                }
                system("pause");

                break;
            case 6:
                printf("  --- COLOR MAS FRECUENTE ---\n\n");
                MasColor(colores, mascotas, TAM, TAM_A);
                break;
            case 7:
                printf("  --- CHECKEO DE TRABAJOS ---\n\n");
                system("cls");
                listarMascotas(mascotas, TAM);
                printf("Ingrese la ID de la mascota: \n");
                mascotaId = ingresarInt();
                valido = validarTrabajo(mascotas, trabajos, TAM, mascotaId);
                while (valido)
                {
                    printf("No existe ese mascota: \n");
                    printf("Ingrese la ID de la mascota: \n");
                    mascotas[mascotaId].idTipo.id = ingresarInt();
                    valido = validarTrabajo(mascotas, trabajos, TAM, mascotaId);
                }
                break;

            default:
                printf ("Opcion invalida, ingrese nuevamente\n");
                break;
            }
            break;

        default:
            printf ("Opcion invalida, ingrese nuevamente\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");
    }
    while (confirmar == 'n');
    return 0;
}
