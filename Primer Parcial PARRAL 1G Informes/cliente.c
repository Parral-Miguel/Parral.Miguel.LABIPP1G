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


/** \brief inicializa cliente
 *
 * \param clientes eCliente*
 * \param tam int
 * \return int
 *
 */
int inicializarCliente(eCliente* clientes, int tam)
{

    int error = 1;
    if (clientes!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            clientes[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/** \brief lista cliente para la funcion listarClientes
 *
 * \param clientes eCliente*
 * \param tam int
 * \param indice int
 * \return void
 *
 */
void listarCliente(eCliente* clientes, int tam, int indice)
{

    printf(" %4d    %8s   %c\n", clientes[indice].id, clientes[indice].nombre, clientes[indice].sexo);

}


/** \brief listar todos los clientes
 *
 * \param clientes eCliente*
 * \param tam int
 * \return int
 *
 */

int listarClientes(eCliente* clientes, int tam)
{

    int error = 1;

    if( clientes != NULL && tam > 0)
    {
        printf(" ID    Nombre     Sexo \n");
        printf("-----------------------\n");

        for(int i=0; i<5; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                listarCliente(clientes, tam, i);
            }

        }

        printf("\n\n");

        error = 0;

    }
    return error;

}
