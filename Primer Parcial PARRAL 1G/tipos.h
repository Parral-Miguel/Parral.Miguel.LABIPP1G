#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct //estructura tipo
{
    int id;
    char descripcion[20];
} typedef eTipo;


#endif // TIPOS_H_INCLUDED

void listarTipo(eTipo unTipo);
int listarTipos(eTipo* tipos, int tam);
int altaTipo(eTipo* tipos, int tam, int id, int indice);
