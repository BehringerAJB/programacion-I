#include <stdio.h>
int main()
{
    int vec[10];
    int i;
    char l[4];
    system("cls");
    gets(l);
    for ( i = 0; i < 10; i++)
    {
        vec[i]=i;
        printf("vec[%d]=%d y vive en la direccion 0x%x\n",i,vec[i],&vec[i]);
    }
    printf("\n arranca la cadena\n");
     for ( i = 0; l[i]; i++)
    {
        printf("vec[%d]=%c y vive en la direccion %x\n",i,l[i],&l[i]);
    }
    return 0;
}
