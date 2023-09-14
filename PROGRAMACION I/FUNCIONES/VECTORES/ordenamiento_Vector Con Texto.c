
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//#include <unistd.h>

#define n 5
void ordenar(char[][30],int );
void MostrarVector(char[][30],char *);
void pausa(void);

int main()
{
    char vecNombres[n][30]={"Luis","Pepe","Ale","Zulema","Victor"};
    MostrarVector(vecNombres, "Vector Desordenado");
    pausa();
    ordenar(vecNombres,n);
    MostrarVector(vecNombres, "Vector Ordenado");
    pausa();
return 0;
}

void ordenar(char vec[][30], int y)
{
    int i, j;
    char temp[30];
    
    for (i = 0; i < y - 1; i++)
    {
        for (j = 0; j < y - i - 1; j++)
        {
            if (strcmp(vec[j], vec[j + 1]) > 0)
            {
                strcpy(temp, vec[j]);
                strcpy(vec[j], vec[j + 1]);
                strcpy(vec[j + 1], temp);
            }
        }
    }
}
void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}
void MostrarVector(char x[][30], char *tit)
{
    int i;
    printf("\n%s\n",tit);
    for (i = 0; i < n; i++)
    {
        printf("%-30s\n",x[i]);
    }
}