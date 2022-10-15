#include "localidad.h"


#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    int idLocalidad;
    char nombre[20];
    char sexo;
    int edad;
    float altura;

    int isEmpty;
} ePersona;



#endif // PERSONA_H_INCLUDED

int inicializarPersonas( ePersona listaPersonas[],int tam);
int buscarLibre(ePersona listaPersonas[], int tam);
void mostrarPersona(ePersona persona,eLocalidad localidades[], int tamLoc);
int mostrarPersonas(ePersona listaPersonas[], int tam,eLocalidad localidades[], int tamLoc);
int altaPersona(ePersona listaPersonas[],int tam, int *pNextID);
int bajaPersona(ePersona listaPersonas[],int tam,eLocalidad localidades[], int tamLoc);
int ModificarPersona(ePersona listaPersonas[],int tam,eLocalidad localidades[], int tamLoc);
int buscarIndicePersonaId(ePersona listaPersonas[],int tam, int id);
int ordenarPersonas(ePersona listaPersonas[], int tam);

