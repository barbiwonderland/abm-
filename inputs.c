#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt( int *pVariableAInt, char mensaje[], char mensajeError[])
{
    int validado=0;
    int resultado;
    int auxResultado;
    if(pVariableAInt != NULL)
    {
        printf(mensaje);
        resultado=scanf("%d",&auxResultado);
        while(resultado !=1)
        {
            fflush(stdin);
            printf(mensajeError);
            resultado= scanf("%d",&auxResultado);
        }
        *pVariableAInt=auxResultado;
        validado=1;
    }

    return validado;
}

int getFloat(char mensaje[], char mensajeError[], float *pVariableAFloat)
{
    int validado=0;
    int resultado;
    float auxResultado;
    if(pVariableAFloat != NULL)
    {
        printf(mensaje);
        resultado=scanf("%f",&auxResultado);
        while(resultado !=1)
        {
            fflush(stdin);
            printf(mensajeError);
            resultado= scanf("%f",&auxResultado);
        }
        *pVariableAFloat=auxResultado;
        validado=1;
    }

    return validado;
}
int getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
void getString(char mensaje[],char input[],int sizeString)
{
    printf(mensaje);
    fflush(stdin);
    fgets(input,sizeString,stdin);

}
