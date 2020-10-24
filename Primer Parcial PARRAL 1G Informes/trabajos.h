#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "fecha.h"
#include "mascotas.h"
#include "servicios.h"
struct // estructura trabajo
{
    int id;
    eMascota idMascota;
    eServicio idServicio;
    eFecha fecha;
    int isEmpty;

} typedef eTrabajo;

int inicializarTrabajo (eTrabajo* trabajos, int tam); //inicializa lista
int buscarEspacioLibreTrabajo (eTrabajo* trabajos, int tam);
int listarTrabajos(eTrabajo* trabajos, int tam); //lista todos
void listarTrabajo(eTrabajo* trabajos, int tam, int indice);
void listarUnTrabajo(eTrabajo* trabajos, int tam, int indice);
int altaTrabajo(eTrabajo* trabajos, eMascota* mascota, eServicio* servicio, int tam, int tam_a, int id);  //alta de servicio
int bajaTrabajo(eTrabajo* trabajos, int tam);  //da de baja mascota
int buscarPorIdTrabajo (eTrabajo* trabajos, int tam, int id);
int buscarVacioTrabajo(eTrabajo* trabajos, int tam);
int validarMascota (eTrabajo* trabajos, eMascota* mascotas, int tam, int indice );
int validarServicio (eTrabajo* trabajos, eServicio* servicios, int tam, int indice);

#endif // TRABAJOS_H_INCLUDED
