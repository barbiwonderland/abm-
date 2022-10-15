#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAM_LOC 8
#include "persona.h"
#include "mockUp.h"
#include "localidad.h"
#include "validaciones.h"
#include "outputs.h"
#include "informes.h"
#include "menu.h"


int main()
{
    int nextID=20000;
    char confirmaSalida='n';
    ePersona listaPersonas[TAM];
    eLocalidad localidades[TAM_LOC]= {{100,"Bernal"},{101,"Lanus"},{102,"Banfield"},{103,"Adrogue"},{104,"Escalada"},{105,"Gerli"},{106,"Quilmes"},{107,"Avellaneda"}};


        if(!inicializarPersonas(listaPersonas,TAM))
        {
            printf("Problema al inicializar...\n");
        }
        harcodearPersonas(listaPersonas,TAM,4,&nextID);
        do
        {
            switch(menu())
            {
            case 1:
                if(!altaPersona(listaPersonas, TAM,&nextID))
                {
                    printf("Error, no se pudo dar de alta.../n");
                }
                else
                {
                    printf("Alta exitosa\n");
                }
                outputGoaback();
                break;
            case 2:
                bajaPersona(listaPersonas,TAM,localidades,TAM_LOC);
                outputGoaback();
                break;
            case 3:
                ModificarPersona(listaPersonas,TAM,localidades,TAM_LOC);
                outputGoaback();
                break;
            case 4:
                system("cls");
                mostrarPersonas(listaPersonas,TAM,localidades,TAM_LOC);
                outputGoaback();
                break;
            case 5:
                if(ordenarPersonas(listaPersonas,TAM))
                {
                    char confirma;
                    system("cls");
                    printf("Lista ordenada exitosamente...\n\n");
                    validaciones_confirma(&confirma,"Desea ver la nueva lista?\nEscriba 's' para confirmar o 'n' para regresar al menu...\n",'s','n');
                    if(confirma == 's')
                    {
                        mostrarPersonas(listaPersonas,TAM,localidades,TAM_LOC);
                    }
                }
                else
                {
                    printf("Hubo un problema al ordenar...\n");
                }
                outputGoaback();
                break;
            case 6:
                informes(listaPersonas,TAM,localidades,TAM_LOC);
                break;
            case 7:
                validaciones_confirma(&confirmaSalida,"Esta seguro que quiere salir del programa?\nIngrese 's' para si, 'n' para cancelar\n",'s','n');
            }
        }
        while(confirmaSalida == 'n');

        return 0;
    }
