#include "localidad.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cargarDescripcionLocalidad(eLocalidad localidades[],int tamLoc, int idLocalidadPersona,char localidadAMostrar[])
{

    int todoOk=0;
    if(localidades != NULL && tamLoc > 0 && localidadAMostrar != NULL )
    {
        for(int i=0; i<tamLoc; i++)
        {
            if(localidades[i].id == idLocalidadPersona)
            {
                strcpy(localidadAMostrar,localidades[i].nombre);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
int mostrarLocalidades(eLocalidad localidades[],int tam)
{
    int todoOk=0;

    if(localidades != NULL && tam>0)
    {

        printf("Localidades:\n\n");
        printf("ID DESCRIPCION\n");
        for (int i=0; i<tam; i++)
        {
            printf("%d %s\n",localidades[i].id,localidades[i].nombre);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
int validarIdLocalidad(eLocalidad localidades[], int id, int tam)
{
    int esValido=0;
    if(localidades != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(localidades[i].id == id )
            {
                esValido=1;
                break;
            }
        }

    }
    return esValido;
}
