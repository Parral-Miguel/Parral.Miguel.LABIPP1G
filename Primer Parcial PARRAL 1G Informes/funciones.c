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
    printf("K - LISTAR CLIENTES\n ");
    printf("L - INFORMES\n ");
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

/** \brief submenu de informes
 *
 * \return int
 *
 */
int menuInformes()
{
    int informe;
    printf("Ingrese el informe deseado:\n ");
    printf("1 - MASCOTAS DE UN COLOR:\n "); //
    printf("2 - MASCOTAS POR TIPO:\n "); //
    printf("3 - MASCOTA DE MENOR EDAD:\n ");   //
    printf("4 - MASCOTAS SEPARADAS POR TIPO\n ");  //
    printf("5 - CONTAR TIPO Y COLOR\n "); //
    printf("6 - COLOR MAS FRECUENTE\n ");
    printf("7 - TRABAJOS EN MASCOTA\n "); //
    scanf("%d", &informe);
    system("cls");
    fflush(stdin);
    return informe;
}


/** \brief
 *
 * \param mascotas eMascota*
 * \param tam
 * \return void
 *
 */
void hardcodeoMascotas(eMascota* mascotas, eTipo* tipos, eColor* colores, eCliente* clientes,  int tam)
{
        int auxId [5] = {500, 501, 502, 503, 504};
        char nombres [5] [20] = {"Lolo", "Marcelo", "Gonzalo", "Pepe", "Micho"};
        int auxIdTipo [5] = {1003, 1002, 1002, 1001, 1004};
        int auxIdColor [5] = {5000, 5002, 5000, 5003, 5001};
        int auxEdad [5] = {5, 2, 10, 3, 1};
        int auxIdCliente [5] = {100, 102, 101, 103, 100};

    for(int i=0; i<5; i++)
        {
            mascotas[i].id = auxId[i];
            strcpy(mascotas[i].nombre, nombres[i]);
            mascotas[i].idTipo.id = auxIdTipo[i];
            validarTipo(mascotas, tipos, tam, i);
            mascotas[i].idColor.id = auxIdColor[i];
            validarColor(mascotas, colores, tam, i);
            mascotas[i].edad = auxEdad[i];
            mascotas[i].idCliente.id = auxIdCliente[i];
            validarCliente(mascotas, clientes, tam, i);
            mascotas[i].isEmpty = 0;
        }

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void hardcodeoTipos(eTipo* tipos, int tam_a)
{
    eTipo auxTipo[5] =
    {
        {1000, "Ave", 0},
        {1001, "Perro", 0},
        {1002, "Gato", 0},
        {1003, "Roedor", 0},
        {1004, "Pez", 0},
    };

    tipos[0] = auxTipo[0];
    tipos[1] = auxTipo[1];
    tipos[2] = auxTipo[2];
    tipos[3] = auxTipo[3];
    tipos[4] = auxTipo[4];
}
/** \brief
 *
 * \param trabajos eTrabajo*
 * \param tam
 * \return void
 *
 */
void hardcodeoTrabajos(eTrabajo* trabajos, eMascota* mascotas, eServicio* servicios, int tam)
{
        int auxId [5] = {8000, 8001, 8002, 8003, 8004};
        int auxIdMascota [5] = {500, 500, 502, 503, 504};
        int auxIdServicio [5] = {20002, 20001, 20001, 20000, 20001};
        int auxIdDia [5] = {10, 02, 05, 23, 01};
        int auxIdMes [5] = {5, 2, 10, 3, 1};
        int auxIdAnio [5] = {2000, 2000, 2010, 2003, 2001};

    for(int i=0; i<5; i++)
        {
            trabajos[i].id = auxId[i];
            trabajos[i].idMascota.id = auxIdMascota[i];
            validarMascota(trabajos, mascotas, tam, i);
            trabajos[i].idServicio.id = auxIdServicio[i];
            validarServicio(trabajos, servicios, tam, i);
            trabajos[i].fecha.dia = auxIdDia[i];
            trabajos[i].fecha.mes = auxIdMes[i];
            trabajos[i].fecha.anio = auxIdAnio[i];
            trabajos[i].isEmpty = 0;
        }

}
/** \brief
 *
 * \param colores eColor*
 * \param tam_a
 * \return void
 *
 */
void hardcodeoColores(eColor* colores, int tam_a)
{
    eColor auxColores[5] =
    {
        {5000, "Negro", 0},
        {5001, "Blanco", 0},
        {5002, "Gris", 0},
        {5003, "Rojo", 0},
        {5004, "Azul", 0},
    };

    colores[0] = auxColores[0];
    colores[1] = auxColores[1];
    colores[2] = auxColores[2];
    colores[3] = auxColores[3];
    colores[4] = auxColores[4];
}
/** \brief
 *
 * \param servicios eServicio*
 * \param tam_a
 * \return void
 *
 */
void hardcodeoServicios(eServicio* servicios, int tam_a)
{
    eServicio auxServi[5] = {{20000, "Corte", 250, 0}, {20001, "Desparasitado", 300, 0}, {20002, "Castrado", 400, 0}, };
    servicios[0] = auxServi[0];
    servicios[1] = auxServi[1];
    servicios[2] = auxServi[2];
}

void hardcodeoClientes (eCliente* clientes, int tam) {

eCliente auxClientes[5] =
    {
        {100, "Jose", 'm', 0},
        {101, "Pedro", 'm', 0},
        {102, "Carla", 'f', 0},
        {103, "Adrian", 'm', 0},
        {104, "Adriana", 'f', 0},
    };

    clientes[0] = auxClientes[0];
    clientes[1] = auxClientes[1];
    clientes[2] = auxClientes[2];
    clientes[3] = auxClientes[3];
    clientes[4] = auxClientes[4];
}
