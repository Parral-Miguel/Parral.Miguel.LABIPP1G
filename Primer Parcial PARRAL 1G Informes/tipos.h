#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct //estructura tipo
{
    int id;
    char descripcion[20];
    int isEmpty;
} typedef eTipo;


#endif // TIPOS_H_INCLUDED

int inicializarTipo (eTipo* tipos, int tam); //inicializa lista
int buscarEspacioLibreTipo (eTipo* tipos, int tam);
int listarTipos(eTipo* tipos, int tam); //lista todos
void listarTipo(eTipo* tipos, int tam, int indice);
int altaTipo(eTipo* tipos, int tam, int id);  //alta de servicio
int bajaTipo (eTipo* tipos, int tam);  //da de baja mascota
int buscarPorIdTipo (eTipo* tipos, int tam, int id); //busca tipo por id
int buscarVacioTipo(eTipo* tipos, int tam); // busca si tipo esta vacio
