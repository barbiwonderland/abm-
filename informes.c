#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "localidad.h"
#include "inputs.h"
#include "validaciones.h"
#include "outputs.h"
#include <ctype.h>
#include "informes.h"
#include "menu.h"

void informes(ePersona listaPersonas[],int tam,eLocalidad localidades[],int tamLoc)
{

    switch(menuInformes())
    {
    case 1:
        filtrarPersonaPorSexo(listaPersonas,tam,localidades,tamLoc);
        outputGoaback();
        break;
    case 2:
        filtrarPersonaPorEdad(listaPersonas,tam,localidades,tamLoc);
        outputGoaback();
        break;
    case 3:
        filtrarPorNombre(listaPersonas,tam,localidades,tamLoc);
        outputGoaback();
        break;
    case 4:
        filtrarPersonasPorLocalidad(listaPersonas,tam,localidades,tamLoc);
        break;
    case 5:
        outputGoaback();
        break;

    }
}



int filtrarPersonaPorSexo(ePersona listaPersonas[],int tam,eLocalidad localidades[], int tamLoc)
{
    int flagPersonas=0;
    int todoOk=0;
    char sexoAFiltrar;
    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 )
    {
        system("cls");
        sexoAFiltrar=tolower(getChar("Ingrese sexo a filtrar, 'f' para femenino o 'm' para masculino\n"));
        printf("                           ***Listado de personas***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     IdLocalidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!listaPersonas[i].isEmpty && listaPersonas[i].sexo == sexoAFiltrar)
            {
                mostrarPersona(listaPersonas[i],localidades,tamLoc);
                flagPersonas=1;
            }

        }
        if(!flagPersonas)
        {
            printf("No hay personas para mostrar...\n");
        }
        todoOk=1;
    }

    return todoOk;


}
int filtrarPersonaPorEdadRango(ePersona listaPersonas[],int tam,int rangoMin,int rangoMax, eLocalidad localidades[], int tamLoc)
{
    int flagPersonas=0;
    int todoOk=0;
    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 )
    {
        // system("cls");
        printf("                           ***Listado de personas***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     IdLocalidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!listaPersonas[i].isEmpty && listaPersonas[i].edad>=rangoMin && listaPersonas[i].edad <=rangoMax)
            {
                mostrarPersona(listaPersonas[i],localidades,tamLoc);
                flagPersonas=1;
            }

        }
        if(!flagPersonas)
        {
            printf("No hay personas para mostrar...\n");
        }
        todoOk=1;
    }

    return todoOk;


}
int filtrarPersonaPorEdad(ePersona listaPersonas[],int tam, eLocalidad localidades[], int tamLoc)
{
    int flagPersonas=0;
    int todoOk=0;
    int rangoMin;
    int rangoMax;
    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 )
    {
        system("cls");
        getInt(&rangoMin,"Ingrese edad minima a filtrar..\n","Error, ingrese una edad valida");
        getInt(&rangoMax,"Ingrese edad maxima a filtrar..\n","Error, ingrese una edad valida");


        printf("                           ***Listado de personas***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     IdLocalidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!listaPersonas[i].isEmpty && listaPersonas[i].edad>=rangoMin && listaPersonas[i].edad <=rangoMax)
            {
                mostrarPersona(listaPersonas[i],localidades,tamLoc);
                flagPersonas=1;
            }

        }
        if(!flagPersonas)
        {
            printf("No hay personas para mostrar...\n");
        }
        todoOk=1;
    }

    return todoOk;


}


int filtrarPorNombre(ePersona listaPersonas[],int tam, eLocalidad localidades[], int tamLoc)
{
    int flagPersonas=0;
    int todoOk=0;
    char nombreaBuscar[20];
    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 )
    {
        system("cls");
        getString("Ingrese nombre a buscar..\n",nombreaBuscar,15);
        printf("\n");
        printf("                 ***Listado de personas por nombre x ***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     IdLocalidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            // aca me gustaria agregar que no sea case sensitive la busqueda.
            if(!listaPersonas[i].isEmpty &&  strcmp(listaPersonas[i].nombre, nombreaBuscar)==0)
            {
                mostrarPersona(listaPersonas[i],localidades,tamLoc);
                flagPersonas=1;
            }

        }
        if(!flagPersonas)
        {
            system("cls");
            printf("\nNo hay personas para mostrar...\n");
        }
        todoOk=1;
    }

    return todoOk;
}
int filtrarPersonasPorLocalidad(ePersona listaPersonas[],int tam, eLocalidad localidades[],int tamLoc)
{
    int todoOk=0;
    int id;
    int flagPersonas=0;
    char localidadAMostrar[20];

    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 && tamLoc>0 && localidades!= NULL && tamLoc>0)
    {
        system("cls");
        printf("***Personas de una localidad***\n");
        mostrarLocalidades(localidades,tamLoc);
        getInt(&id,"Ingrese id de localidad\n","Ingrese id valido\n");
        while(!validarIdLocalidad(localidades,id,tamLoc))
        {
            system("cls");
            mostrarLocalidades(localidades,tamLoc);
            getInt(&id,"Localidad invalida, ingrese otro id...\n","Localidad invalida, ingrese otro id...\n");

        }
        printf("\n");
        printf("                 ***Listado de personas por localidad x ***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     IdLocalidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!listaPersonas[i].isEmpty && listaPersonas[i].idLocalidad == id)
            {
                mostrarPersona(listaPersonas[i],localidades,tamLoc);
                flagPersonas=1;
            }

        }
        outputGoaback();
        if(!flagPersonas)
        {
            cargarDescripcionLocalidad(localidades,tamLoc,id,localidadAMostrar);
            printf("No hay personas de esa localidad para mostrar...\n");
        }
        todoOk=1;
    }

    return todoOk;

}
