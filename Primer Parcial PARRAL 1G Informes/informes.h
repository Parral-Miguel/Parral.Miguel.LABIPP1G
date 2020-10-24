#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int validarEleccion(eColor* colores, eMascota* mascotas, int tam, int tam_a, int eleccion);
int validarEleccionTipo(eTipo* tipos, eMascota* mascotas,int tam, int tam_a, int eleccion);
int buscarMascotaMenor(eMascota* mascotas, int tam);
void SepararTipo(eTipo* tipos, eMascota* mascotas,int tam, int tam_a);
int contarTipoColor(eMascota* mascotas, eTipo* tipos, eColor* colores, int tam, int tam_a, int eleccionTipo, int eleccionColor);
void MasColor (eColor* colores, eMascota* mascotas, int tam, int tam_a);
int validarTrabajo (eMascota* mascotas, eTrabajo* trabajos, int tam, int mascotaId);
