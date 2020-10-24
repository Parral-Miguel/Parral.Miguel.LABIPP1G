#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

struct //estructura color
{
    int id;
    char nombreColor[20];
    int isEmpty;
} typedef eColor;


#endif // COLORES_H_INCLUDED

int inicializarColor (eColor* colores, int tam); //inicializa lista
int buscarEspacioLibreColor (eColor* colores, int tam);
int listarColores(eColor* colores, int tam); //lista todos
void listarColor(eColor* colores, int tam, int indice);
int altaColor(eColor* colores, int tam, int id);  //alta de servicio
int bajaColor(eColor* colores, int tam);  //da de baja mascota
int buscarPorIdColor (eColor* colores, int tam, int id); //busca colores por id
int buscarVacioColor(eColor* colores, int tam); //busca si colores esta vacio
