#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

struct //estructura color
{
    int id;
    char nombreColor[20];
} typedef eColor;


#endif // COLORES_H_INCLUDED

void listarColor(eColor unColor);
int listarColores(eColor* colores, int tam);
int altaColores(eColor* colores, int tam, int id, int indice);
