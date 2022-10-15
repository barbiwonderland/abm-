#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "localidad.h"
#include "inputs.h"
#include "validaciones.h"
#include "outputs.h"
#include <ctype.h>
#include "menu.h"




int inicializarPersonas(ePersona listaPersonas[],int tam)
{
    int todoOk=0;
    if(listaPersonas != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            listaPersonas[i].isEmpty=1;
        }
        todoOk =1;
    }
    return todoOk;
}

int buscarLibre(ePersona listaPersonas[], int tam)
{
    int indice=-1;
    for (int i=0; i<tam; i++)
    {
        if(listaPersonas[i].isEmpty)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

void mostrarPersona(ePersona persona,eLocalidad localidades[], int tamLoc)
{
    char localidadAMostrar[40];
    cargarDescripcionLocalidad(localidades,tamLoc,persona.idLocalidad,localidadAMostrar);

   printf("%d      %7s     %7c      %7d      %7.2f        %s      \n\n"
          ,persona.id,persona.nombre,toupper(persona.sexo),persona.edad,persona.altura, localidadAMostrar);
}
int mostrarPersonas(ePersona listaPersonas[], int tam,eLocalidad localidades[], int tamLoc)
{
    int flagPersonas=0;
    int todoOk=0;
    // se verifica porque es un vector
    if(listaPersonas != NULL && tam >0 )
    {
        system("cls");
        printf("                           ***Listado de personas***          \n");
        printf("----------------------------------------------------------------------------\n");
        printf("Id:         Nombre:         Sexo:       Edad:       Altura:     Localidad \n");
        printf("----------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!listaPersonas[i].isEmpty)
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

int altaPersona(ePersona listaPersonas[],int tam, int *pNextID)
{
    int todoOk=0;
    int indice;
    ePersona auxPersona;
    if(listaPersonas != NULL &&tam >0)
    {
        system("cls");
        printf("            ALTA PERSONAS            \n");
        printf("Para cancelar presione la tecla 'ESC'\n'");
        printf("-------------------------------------\n");
        indice=buscarLibre(listaPersonas,tam);
        if(indice == -1)
        {
            printf("No hay lugar.../n");
        }
        else
        {
            validaciones_ingresoLetras(auxPersona.nombre,"Ingrese nombre\n","Error, ingrese un nombre valido\n");
            validaciones_ingresoChar(&auxPersona.sexo,"Ingrese Sexo\n","Error,ingrese 'm' o 'f'",'m','f');
            validaciones_ingresoRangoInt(&auxPersona.edad,"Ingrese Edad\n","Error ingrese edad entre 1 y 100",1,100);
            validaciones_ingresoRangoFloat(&auxPersona.altura,"Ingrese Altura\n","Error ingrese altura entre 0.5 y 2.80\n",0.5,2.80);
            auxPersona.isEmpty=0;
            auxPersona.id=*pNextID;
            (*pNextID)++;
            //asigno los datos cargados en el aux deltro del array con posicion en indice vacio encontrado en buscarindice
            listaPersonas[indice]=auxPersona;
            todoOk=1;
        }

    }
    return todoOk;
}

int buscarIndicePersonaId(ePersona listaPersonas[],int tam, int id)
{
    int indice = -1;
    for (int i=0; i<tam; i++)
    {
        if(!listaPersonas[i].isEmpty && listaPersonas[i].id == id )
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int bajaPersona(ePersona listaPersonas[],int tam,eLocalidad localidades[], int tamLoc)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;
    if(listaPersonas != NULL && tam>0)
    {

        do
        {
            system("cls");
            printf("BAJA PERSONA\n");
            mostrarPersonas(listaPersonas, tam,localidades,tamLoc);
            fflush(stdin);
            getInt(&id,"Ingrese el id de la persona a dar de baja : \n","Error,ingrese un numero valido\n");
            indice=buscarIndicePersonaId(listaPersonas,tam,id);
            if(indice == -1)
            {
                printf("Error,no se encuentra registrada ninguna persona con id %d..\n",id);
                validaciones_confirma(&confirma, "quiere volver a intentarlo?\n",'s','n');
            };

            if(indice != -1)
            {
                printf("\n");
                mostrarPersona(listaPersonas[indice],localidades,tamLoc);
                validaciones_confirma(&confirma,"Confirma baja? escriba si para confirmar... \n",'s','n');
                if(confirma == 's')
                {
                    listaPersonas[indice].isEmpty=1;
                    todoOk=1;
                    printf("Baja realizada exitosamente..\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario..\n");
                }
                validaciones_confirma(&confirma, "quiere realizar otra baja?",'s','n');

            }
        }
        while(confirma == 's');

    }
    return todoOk;
}

int ModificarPersona(ePersona listaPersonas[],int tam,eLocalidad localidades[], int tamLoc)
{

    int todoOk=0;
    int id;
    int indice;
    char confirma;
    char auxNombre[20];
    char auxSexo;
    int auxEdad;
    float auxAltura;

    if(listaPersonas != NULL && tam>0)
    {
        do
        {
            system("cls");
            printf("Modificacion PERSONA\n");
            mostrarPersonas(listaPersonas, tam,localidades,tamLoc);
            fflush(stdin);
            getInt(&id,"Ingrese el id de la persona a modificar : \n","Error, ingrese un id valido\n");
            indice=buscarIndicePersonaId(listaPersonas,tam,id);
            if(indice == -1)
            {
                printf("Error,no se encuentra registrada ninguna persona con id %d..\n",id);
                validaciones_confirma(&confirma, "Desea intentarlo nuevamente?",'s','n');
            }
            else
            {
                printf("\n");
                mostrarPersona(listaPersonas[indice],localidades,tamLoc);
                validaciones_confirma(&confirma,"Si es correcta la persona a modificar escriba si para continuar... \n", 's','n');
                while(confirma == 's')
                {
                    system("cls");
                    fflush(stdin);
                    switch(menuModificacion())
                    {
                    case 1:
                        validaciones_ingresoLetras(auxNombre,"Ingrese nuevo nombre..\n","Error, ingrese nombre valido..\n");
                        strcpy(listaPersonas[indice].nombre,auxNombre);

                        break;
                    case 2:
                        validaciones_ingresoChar(&auxSexo,"Ingrese nuevo sexo...\n","Ingrese un sexo valido, 'm' o 'f'",'f','m');
                        listaPersonas[indice].sexo=auxSexo;
                        break;
                    case 3:
                        validaciones_ingresoRangoInt(&auxEdad,"Ingrese nueva edad..\n","Ingrese edad entre 1 y 100",1,100);
                        listaPersonas[indice].edad=auxEdad;


                        break;
                    case 4:
                        validaciones_ingresoRangoFloat(&auxAltura,"Ingrese nueva altura..\n","Ingrese altura valida",0.50,2.80);
                        listaPersonas[indice].altura=auxAltura;
                        break;
                    default:
                        printf("Opcion invalida...");
                        outputGoaback();
                    }


                    validaciones_confirma(&confirma,"Desea modificar otro dato?\n",'s','n');
                    todoOk=1;
                }

                validaciones_confirma(&confirma,"Desea modificar otro usuario?",'s','n');
            }


        }
        while(confirma == 's');


    }
    return todoOk;
}


int ordenarPersonas(ePersona listaPersonas[], int tam)
{
    int todoOk;
    ePersona auxPersona;
    if(listaPersonas != NULL && tam >0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((listaPersonas[i].sexo>listaPersonas[j].sexo)||
                        (listaPersonas[i].sexo == listaPersonas[j].sexo &&
                         strcmp(listaPersonas[i].nombre, listaPersonas[j].nombre)>0))
                {
                    auxPersona=listaPersonas[i];
                    listaPersonas[i]=listaPersonas[j];
                    listaPersonas[j]=auxPersona;

                }
            }
        }

        todoOk=1;
    }
    return todoOk;
}

