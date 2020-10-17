#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

struct //estructura servicio
{
    int id;
    char servicio[20];
    int precio;
} typedef eServicio;


#endif // SERVICIOS_H_INCLUDED

int listarServicios(eServicio* servicios, int tam); //lista todos
void listarServicio(eServicio unServicio);
int altaServicio(eServicio* servicios, int tam, int id, int indice);  //alta de servicio
