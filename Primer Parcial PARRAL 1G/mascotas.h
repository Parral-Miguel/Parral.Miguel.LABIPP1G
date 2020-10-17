#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

struct //estructura mascota
{
    int id;
    char nombre [20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
} typedef eMascota;

#endif // MASCOTAS_H_INCLUDED

int inicializarLista (eMascota* mascotas, int tam); //inicializa lista
int buscarEspacioLibre (eMascota* mascotas, int tam);   //busca un espacio libre
int altaMascota(eMascota* mascotas, eTipo* tipo, eColor* color, int tam, int id);   //da de alta mascota
void mostrarUnaMascota(eMascota unaMascota);    //muestra una sola mascota
int listarMascotas(eMascota* mascotas, int tam);    //lista las mascotas
int ordenarMascotas (eMascota* mascotas, int tam);      //ordena mascotas
int bajaMascota (eMascota* mascotas, int tam);  //da de baja mascota
int buscarVacio(eMascota* mascotas, int tam);   //busca si el registro esta vacio
int buscarPorId (eMascota* mascotas, int tam, int id);  //busca mascota por id
int validarColor (eMascota unaMascota, eColor* colores, int tam);   //valida que el color ingresado exista
int validarTipo (eMascota unaMascota, eTipo* tipo, int tam); //valida que el tipo ingresado exista

