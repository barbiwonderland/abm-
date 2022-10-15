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


int menuModificacion()
{
    int opcion;
    printf("Ingrese una opcion: \n");
    printf("1-Modificar Nombre \n");
    printf("2-Modificar Sexo \n");
    printf("3-Modificar Edad \n");
    printf("4-Modificar Altura \n");
    printf("5-Volver al menu principal \n");

    scanf("%d",&opcion);
    return opcion;

}
int menuR(int *pOpcionElegida,char opciones[][80], char tituloMenu[], int tamOpciones)
{
    int todoOk=0;
    int auxOpcion;
    if(tituloMenu != NULL && opciones != NULL && tamOpciones>0)
    {

        printf("%s", tituloMenu);
        for(int i=1; i<=tamOpciones; i++)
        {
            printf("%d)%s",i,opciones[i]);
        }
        printf("Ingrese una opcion..");
        scanf("%d",&auxOpcion);
        *pOpcionElegida=auxOpcion;
        todoOk=1;
    }
    return todoOk;
}


int menuInformes()
{
    system("cls");
    int opcion;
    validaciones_ingresoRangoInt(&opcion,
                                 "****Menu Informes****\n\n1)Filtrar por sexo\n2)Filtrar por edad\n3)Filtrar por nombre\n4)Filtrar por Localidad\n5)Volver\n","Error,ingrese un numero del 1 al 5",1,5);
    return opcion;

}
int menu()
{
    int opcion;
    system("cls");
    printf("                        ABM PERSONAS                      \n");
    printf("-----------------------------------------------------------\n");
    printf("1-ALTA PERSONA \n");
    printf("2-BAJA PERSONA \n");
    printf("3-MODIFICAR PERSONA \n");
    printf("4-LISTAR PERSONAS \n");
    printf("5-ORDENAR PERSONAS \n");
    printf("6-INFORMES \n");
    printf("7-SALIR \n");
    printf("Ingrese una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}
