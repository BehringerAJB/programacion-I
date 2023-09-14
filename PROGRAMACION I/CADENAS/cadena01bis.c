#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int i;
    //int cont=0;
    char cad[81];
    printf("ingrese un Nombre:");
    scanf("%[^\n]", cad);
    //scanf("%s",cad);
    printf("%-10s\n", cad);
    printf("Largo de la cadena:%d\n", strlen(cad));
    for (i = 0;i < strlen(cad); i++)
// i < strlen(cad)
    {
         printf("-%c-", cad[i]);   
    }
    return 0;
}
