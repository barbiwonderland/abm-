#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
void informes(ePersona listaPersonas[],int tam,eLocalidad localidades[],int tamLoc);
int filtrarPersonaPorSexo(ePersona listaPersonas[],int tam, eLocalidad localidades[], int tamLoc);
int filtrarPersonaEdadRango(ePersona listaPersonas[],int tam,int rangoMin,int rangoMax, eLocalidad localidades[], int tamLoc);
int filtrarPersonaPorEdad(ePersona listaPersonas[],int tam, eLocalidad localidades[], int tamLoc);
int filtrarPorNombre(ePersona listaPersonas[],int tam, eLocalidad localidades[], int tamLoc);
int filtrarPersonasPorLocalidad(ePersona listaPersonas[],int tam, eLocalidad localidades[],int tamLoc);
