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

int main()
{
    int id = 0001;
    int error = 0;
    int vacio;
    int identificacion;
    int valido = 0;
    char confirmar = 'n';

    eTipo tipos[5] = {{1000, "Ave"}, {1001, "Perro"}, {1002, "Gato"}, {1003, "Roedor"}, {1004, "Pez"}};     //harcodeo
    eColor colores[5] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eServicio servicios[3] = {{20000, "Corte", 250}, {20001, "Desparasitado", 300}, {20002, "Castrado", 400}};
    eMascota mascotas [TAM];

    inicializarLista(mascotas, TAM);

    do
    {
        switch (menu())
        {
        case 'a':
            system("cls");
            fflush(stdin);
            printf("  --- ALTA DE MASCOTA ---\n\n");
            error = altaMascota(mascotas, tipos, colores, TAM, id);
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
            listarMascotas(mascotas, TAM);
            printf("Ingrese el id de la mascota: \n");
            identificacion = ingresarInt();
            identificacion = buscarPorId(mascotas, TAM, identificacion);
            while (identificacion == -1)
            {
                printf("No existe esa id. Ingrese nuevamente: \n");
                identificacion = ingresarInt();
                identificacion = buscarPorId(mascotas, TAM, identificacion);
            }

            switch (menuModificar())
            {
            case 'a':
                system("cls");
                listarTipos(tipos, 5);
                printf("\n\n");
                printf("Ingrese la ID del tipo: \n");
                mascotas[identificacion].idTipo = ingresarInt();
                valido = validarTipo(mascotas[identificacion], tipos, 5);
                while (valido)
                {
                    printf("No existe ese tipo: \n");
                    printf("Ingrese la ID de tipo: \n");
                    mascotas[identificacion].idTipo = ingresarInt();
                    valido = validarTipo(mascotas[identificacion], tipos, 5);
                }
                system("cls");
                mostrarUnaMascota(mascotas[identificacion]);
                printf("  --- MODIFICADO CORRECTAMENTE ---\n\n");
                break;

            case 'b':
                system("cls");
                printf("Ingrese la edad de la mascota: \n");
                mascotas[identificacion].edad = ingresarInt();
                system("cls");
                mostrarUnaMascota (mascotas[identificacion]);
                printf("  --- MODIFICADO CORRECTAMENTE ---\n\n");
                break;

            }
            break;

        case 'c':
            valido = buscarVacio(mascotas, TAM);
            if (valido)
            {
                printf("Error. No hay mascotas en el registro.\n");
                system("pause");
                break;
            }
            error = bajaMascota (mascotas, TAM);     //con la id, la funcion busca el indice del empleado y pone isEmpty en 1
            if (error == 1)     //devuelve distintos errores por distintas circunstancias
            {
                printf ("No se realizo la baja \n");    //la id no existe
                system("pause");
            }
            else if (error == 2)
            {
                printf ("No se realizo la baja: cancelada por el usuario\n");   //el usuario cancelo
                system("pause");
            }
            else
            {
                printf ("Baja realizada con exito \n");
                system("pause");
            }

            break;
        case 'd':
            system("cls");
            fflush(stdin);
            ordenarMascotas (mascotas, TAM);
            listarMascotas(mascotas, TAM);
            system("pause");
            break;

        case 'e':
            system("cls");
            fflush(stdin);
            printf("  --- TIPOS DE MASCOTAS ---\n\n");
            listarTipos (tipos, 5);
            break;

        case 'f':
            system("cls");
            fflush(stdin);
            printf("  --- COLORES DE MASCOTAS ---\n\n");
            listarColores (colores, 5);;

            break;
        case 'g':
            system("cls");
            fflush(stdin);
            printf("  --- SERVICIOS ---\n\n");
            listarServicios (servicios, 3);

            break;
        case 'h':
            system("cls");
            fflush(stdin);

            break;
        case 'i':
            system("cls");
            fflush(stdin);

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
