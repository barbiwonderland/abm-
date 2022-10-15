#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validaciones_confirma(char *pVariable,char *mensaje, char confirma,char noConfirma)
{
    int todoOk = 0;
    char rta;
    if (pVariable != NULL)
    {
        printf(mensaje);
        fflush(stdin);
        rta = getchar();
        if (rta == 's' )
        {
            *pVariable = confirma;
        }
        else
        {

            *pVariable = noConfirma;
        }
        todoOk = 1;

    }
    return todoOk;
}


int validaciones_ingresoRangoInt(int *pResultado, char *mensaje, char *mensajeError,
                                 int minimo, int maximo)
{

    int validado = 0;
    int num;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && minimo <= maximo)
    {
        fflush(stdin);
        getInt(&num,mensaje,mensajeError);
        while ( num < minimo || num > maximo)
        {
            fflush(stdin);
            getInt(&num,mensajeError,mensajeError);
        }
        validado = 1;
        *pResultado = num;

    }
    return validado;

}
int validaciones_ingresoRangoFloat(float *pResultado, char *mensaje, char *mensajeError,
                                   float minimo, float maximo)
{

    int validado = 0;
    float num;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && minimo <= maximo)
    {
        getFloat(mensaje,mensajeError,&num);
        while ( num < minimo || num > maximo)
        {
            fflush(stdin);
            getFloat(mensajeError,mensajeError,&num);
        }
        validado = 1;
        *pResultado = num;

    }
    return validado;

}

int validaciones_ingresoRangoChar(char *pResultado, char *mensaje, char *mensajeError,
                                  char minimo, char maximo)
{

    int validado = 0;
    char aux;
    int buffer;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && minimo <= maximo)
    {
        buffer=getChar(mensaje);
        while (buffer == 0 || aux < minimo || aux > maximo)
        {
            if (buffer == 0)
            {
                fflush(stdin);
                buffer=getChar("Error, ingrese un caracter...");
            }
            else
            {
                printf(mensajeError);
                buffer = scanf("%c", &aux);
            }
        }
        validado = 1;
        *pResultado = aux;

    }
    return validado;

}

int validaciones_ingresoChar(char *pResultado, char *mensaje, char *mensajeError,
                             char opcionUno, char opcionDos)
{

    int validado = 0;
    int buffer;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && opcionUno != opcionDos)
    {
        buffer=tolower(getChar(mensaje));
        while ((buffer == 0) || (buffer != opcionUno && buffer != opcionDos))
        {
            if (buffer == 0)
            {
                fflush(stdin);
                buffer=getChar("Error, ingrese una letra valida");
            }
            else
            {
                buffer= getChar(mensajeError);
            }
        }
        validado = 1;
        *pResultado = buffer;

    }
    return validado;

}
int validaciones_letras(char str[])
{
    int validado=1;
    int i=0;
    while(str[i]!= '\0')
    {
        if((str[i] != ' ') && ((str[i]<'a') || (str[i]>'z')) && ((str[i]<'A') || (str[i]>'Z' )))
        {
            validado= 0;
            break;
        }
    i++;
    }
    return validado;

}
int validaciones_ingresoLetras(char pResultado[], char *mensaje, char *mensajeError)
{

    int validado = 0;
    char strIngresada[20];
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL)
    {
        getString(mensaje,strIngresada,15);
        while(!validaciones_letras(strIngresada))
        {
            getString(mensajeError,strIngresada,15);
        }

        validado = 1;
        strcpy(pResultado,strIngresada);

    }

    return validado;

}
