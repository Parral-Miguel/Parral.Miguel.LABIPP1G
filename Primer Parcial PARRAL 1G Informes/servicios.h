#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

struct //estructura servicio
{
    int id;
    char servicio[20];
    int precio;
    int isEmpty;
} typedef eServicio;


#endif // SERVICIOS_H_INCLUDED

int inicializarServi (eServicio* servicios, int tam); //inicializa lista
int buscarEspacioLibreServi (eServicio* servicios, int tam);
int listarServicios(eServicio* servicios, int tam); //lista todos
void listarServicio(eServicio* servicios, int tam, int indice);
int altaServicio(eServicio* servicios, int tam, int id);  //alta de servicio
int bajaServicio (eServicio* servicios, int tam);  //da de baja mascota
int buscarPorIdServi (eServicio* servicios, int tam, int id); //busca servicio por id
int buscarVacioServi(eServicio* servicios, int tam); //busca si servicio esta vacio
