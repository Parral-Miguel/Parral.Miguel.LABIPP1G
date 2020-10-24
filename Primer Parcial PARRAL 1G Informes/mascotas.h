#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include "colores.h"
#include "tipos.h"
#include "cliente.h"

struct //estructura mascota
{
    int id;
    char nombre [20];
    eTipo idTipo;
    eColor idColor;
    int edad;
    eCliente idCliente;
    int isEmpty;
} typedef eMascota;

#endif // MASCOTAS_H_INCLUDED

int inicializarLista (eMascota* mascotas, int tam); //inicializa lista
int buscarEspacioLibre (eMascota* mascotas, int tam);   //busca un espacio libre
int altaMascota(eMascota* mascotas, eTipo* tipo, eColor* color, eCliente* clientes, int tam, int tam_a, int id);   //da de alta mascota
void mostrarUnaMascota(eMascota* mascotas, int tam, int indice);    //muestra una sola mascota
int listarMascotas(eMascota* mascotas, int tam); //lista todas las mascotas
void listarMascota(eMascota* mascotas, int tam, int indice);    //lista una mascota para la funcion listarMascotas
int ordenarMascotas (eMascota* mascotas, int tam);      //ordena mascotas
int bajaMascota (eMascota* mascotas, int tam);  //da de baja mascota
int buscarVacio(eMascota* mascotas, int tam);   //busca si el registro esta vacio
int buscarPorId (eMascota* mascotas, int tam, int id);  //busca mascota por id
int validarColor (eMascota* mascotas, eColor* colores, int tam, int indice);   //valida que el color ingresado exista
int validarTipo (eMascota* mascotas, eTipo* tipo, int tam, int indice); //valida que el tipo ingresado exista
int modificarMascotas (eMascota* mascotas, eTipo* tipo, int tam, int tam_a);
int validarCliente (eMascota* mascotas, eCliente* clientes, int tam, int indice);
void mascotasUnColor (eMascota* mascotas, eColor* colores, int tam, int eleccion);

