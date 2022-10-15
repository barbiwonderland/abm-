#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nombres[10][20]=
{
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};

int  idLocalidades[10]= {100,101,102,103,101,103,103,102,104,103};
                        char sexos[10]= {'m','m','f','m','f','f','f','m','m','f'};
int edades[10]= {23,10,12,50,80,43,63,58,4,16};
float alturas[10]= {1.80,1.30,1.20,1.80,1.95,1.70,1.60,1.55,1.90,2.00};


int harcodearPersonas(ePersona listaPersonas[],int tam, int cantidadDatos,int *personaId)
{
    int contador=-1;
    if(listaPersonas != NULL && tam >0 && cantidadDatos >=0 && 0 <=tam && personaId != NULL)
    {
        contador=0;
        for(int i=0; i<cantidadDatos; i++)
        {
            listaPersonas[i].id=*personaId;
            (*personaId)++;
            strcpy(listaPersonas[i].nombre,nombres[i]);
            listaPersonas[i].sexo=sexos[i];
            listaPersonas[i].edad=edades[i];
            listaPersonas[i].altura=alturas[i];
            listaPersonas[i].idLocalidad=idLocalidades[i];
            listaPersonas[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}
