#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>


void mostrar(FILE *);
int ConvierteLetra(char[]);
int error(char *);
void pausa(void);

int main()
{
    FILE *archivo;
    char nom1[80] = "F:\\UTN-INSPT\\Programacion 1\\ARCHIVOS\\ARCHIVOS DE TEXTO\\textoBinario.txt", cad[81]; // nombre físico del archivo
    int j;
    int letra;
    system("cls");
    if ((archivo = fopen(nom1, "r")) == NULL)
        exit(error(nom1)); // crea el archivo para escritura y lectura;
    printf("\n El archivo %s se ha abierto satisfactoriamente", nom1);
    printf("\n Presione una tecla para visualizar el contenido del archivo:%s\n\n", nom1);
    pausa();
    system("cls");
    rewind(archivo);
    printf("\n El contenido del archivo %s es:\n\n", nom1);
    mostrar(archivo);
    pausa();
    rewind(archivo);
    j = 0;
    printf("\nEstablecemos cada Letra\n\n");
    while (fgets(cad, 81, archivo) != NULL)
    {
        letra = ConvierteLetra(cad);
        printf("%c",letra);
    }
    printf("\n\n");
    pausa();
    fclose(archivo);

    return (0);
}


void mostrar(FILE *x)
{
    char cad[80];
    while (fgets(cad, 81, x) != NULL)
        printf("%s", cad);
}

int error(char *x)
{
    fprintf(stderr, "No se pudo abrir el archivo %s", x);
    return (1);
}

int ConvierteLetra(char x[])
{
    int cpal = 0, pos = 7, i = 0;
    char temp[2];
    while (x[i] != '\n')
    {
        temp[0] = x[i];
        temp[1] = '\0';
        cpal += atoi(temp) * pow(2, pos);
        pos--;
        i++;
    }
    return cpal;
}

void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}