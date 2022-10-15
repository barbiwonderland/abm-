#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void outputGoaback()
{
    printf("Pulse cualquier tecla para regresar al menu principal..\n");
    fflush(stdin);
    getchar();
}
int stringLower(char str[])
{
   int validado=0;
    if(str != NULL)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = tolower(str[i]);
        }
        validado=1;

    }
    return validado;
}

