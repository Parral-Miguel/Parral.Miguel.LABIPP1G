#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "colores.h"
#include "tipos.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"
#include "fecha.h"

#endif // FUNCIONES_H_INCLUDED

int menu();     //menu
int menuModificar ();
int menuInformes();       //menu para opcion modificar
int ingresarInt ();     //ingresa un entero y valida que sea un numero
void hardcodeoMascotas (eMascota* mascotas, eTipo* tipos, eColor* colores, eCliente* clientes, int tam);
void hardcodeoTipos (eTipo* tipos, int tam_a);
void hardcodeoTrabajos (eTrabajo* trabajos, eMascota* mascotas, eServicio* servicios, int tam);
void hardcodeoColores (eColor* colores, int tam_a);
void hardcodeoServicios (eServicio* servicios, int tam_a);
void hardcodeoClientes (eCliente* clientes, int tam);








