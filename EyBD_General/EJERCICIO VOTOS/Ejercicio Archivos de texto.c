#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define s scanf
#define p printf
#define parar printf("\n"); system("pause");
int error(char *);//siempre escibir antes los prototipos
void mostrar(FILE*);
void cargar(FILE*);
void leelinea(FILE*);
int cont_pal(char *);
void contar_letras_espacios(FILE*); //cuenta letras y espacios

int main()
{
    FILE *origen;
    char nom1[80];   //defino una cadena de caracteres que es donde se va a guardar toda la linea
    int palabras;
    system("cls");             //limpia la consola

    p("\nIngrese el nombre del archivo a crear con la extension.txt: ");
    s("%[^\n]", nom1);
    fflush(stdin);

    if((origen=fopen(nom1, "w+"))==NULL) exit(error(nom1));
    cargar(origen);
    p("\nVisualizar el contenido de %s\n\n", nom1);
    rewind(origen);
    mostrar(origen);
    parar
    rewind(origen);
    leelinea(origen);
    rewind(origen);
    contar_letras_espacios(origen);
    rewind(origen);
    fclose(origen);
    parar

return(0);
}

int error(char *y)
{
fprintf(stderr, "No se puede abrir el archivo %s", y);//stderr es una secuencia estandar para la salida de error
return(1);
}

void cargar(FILE*archivo)
{
    char cad[81];

    p("\n\nIngrese caracteres hasta [enter]");
    p("\nPara finalizar Ctrl+Z\n\n");

    while(gets(cad)!=NULL)
    {
        fputs(cad,archivo);
        fputs("\n", archivo);
    }
}

void mostrar(FILE*archivo)
{
char cadena[81];
    while ((fgets(cadena,81,archivo))!=NULL) //almacena una cadena mientras sea diferente de EOF
            p("%s\n",cadena);
}
void leelinea(FILE*archivo)
{
 int cp=0;
 char cad[81];

 while(fgets(cad,81,archivo)!=NULL)
 {
    p("el string cad contiene lo siguiente: %s\n", cad);
    cp=cp+cont_pal(cad);
 }
 p("La cantidad de palabras es de %d\n", cp);
}
// funcion cuenta palabra

int cont_pal(char c[])
{
int cp=1, i=0;

    while (c[i] !='\0') //si la letra es distinta de fin de archivo
    {
      if((c[i]!=' ')||(c[i]=='\n'))
      {
         i++;
      }
      else
        if(c[i]==' ')
        {
          i++;
          cp++;
        }
        else
        {
          i++;
        }
    }

    return(cp);
}
void contar_letras_espacios(FILE*archivo)
{
 int cl=0, i=0, eb=0;
 char cad[81];
 //char c[];

 while(fgets(cad,81,archivo)!=NULL)
 {
    i=0;
    while (cad[i] !='\0') //si la letra es distinta de fin de archivo
    {
        if (cad[i]==' ')
        {
        //p ("paso x espacio en blanco.\n");
         eb++;
         i++;
        }

        else if (cad[i]!='\n')
            {
           // p("paso x letra\n");
            cl++;
            i++;
            }
       else
            {
            //p("paso x salto de pagina\n");
            eb++;
            i++;
            }
    }
 }
 p("La cantidad de letras es de %d\n", cl);
 p("La cantidad de espacios en blanco es de %d\n", eb); //me cuenta los espacios en blanco y salto de renglon.
}
