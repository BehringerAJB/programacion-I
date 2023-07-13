#include <stdio.h>
unsigned int ingresarDocumento(void);
int validarDocumento(unsigned int);
void imprimirError(void);

int main() 
{
    unsigned int numeroDocumento;
    numeroDocumento = ingresarDocumento();
    printf("El número de documento ingresado es: %u\n", numeroDocumento);
    return 0;
}

unsigned int ingresarDocumento() 
{
    unsigned int documento;
    int valido = 0;
     while (!valido) 
    {
        printf("Ingrese el numero de documento: ");
        scanf("%u", &documento);
         valido = validarDocumento(documento);
         if (!valido) 
        {
            imprimirError();
        }
    }
     return documento;
}
 int validarDocumento(unsigned int documento) 
{
    if ((int)documento <= 0) 
    {
        return 0;
    }
     return 1;
}
 void imprimirError() 
{
    printf("\n\nError: el numero de documento debe ser mayor que cero.\n");
}