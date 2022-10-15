#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
int id;
char nombre[20];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED
int cargarDescripcionLocalidad(eLocalidad localidades[],int tam, int idLocalidadPersona,char localidadAMostrar[]);
int mostrarLocalidades(eLocalidad localidades[], int tam);
int validarIdLocalidad(eLocalidad localidades[], int id, int tam);
