#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


/**
 * @brief confirma si el usuario quiere continuar ejecutando el programa o no
 *
 * @param p direccion de memoria de la variable donde se va a guardar la respuesta del usuario.
 * @param confirma el valor de confirmacion por ej 's'
 * @param Noconfirma el valor de confirmacion por ej 'n'
 * @return devuelve 0 para no, 1 para si
 */
int validaciones_confirma(char *pVariable,char *mensaje, char confirma,char noConfirma);
int validaciones_ingresoRangoInt(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo);
int validaciones_ingresoRangoFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo);
int validaciones_ingresoRangoChar(char *pResultado, char *mensaje, char *mensajeError,char minimo, char maximo);
int validaciones_ingresoChar(char *pResultado, char *mensaje, char *mensajeError,char opcionUno, char opcionDos);
int validaciones_letras(char str[]);
int validaciones_ingresoLetras(char pResultado[], char *mensaje, char *mensajeError);


#endif // VALIDACIONES_H_INCLUDED


