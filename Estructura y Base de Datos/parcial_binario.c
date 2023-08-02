#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#define p printf
#define s scanf

typedef struct
{
    int cod_art;
    char nom_art[20];
    float pre_art;
    int sto_art;
    float fact_art;
} regarti;
typedef struct
{
    int cod_cli;
    char nom_cli[20];
    float cuenta;
} regcli;

void inicio(FILE *, FILE *);
void ingresar(FILE *, FILE *);
void mostrar(FILE *, FILE *);
int error(char *);
void tecla(void);
void linea(int);
main()
{
    FILE *cli, *art;
    char nomarchcli[] = "clientes.dat";
    char nomarchart[] = "articulos.dat";
    system("cls");
    srand(time(NULL));
    system("color 9f");
    if ((cli = fopen(nomarchcli, "wb+")) == NULL)
        exit(error(nomarchcli));
    p("\nEl archivo %s ha sido cargado!!", nomarchcli);

    if ((art = fopen(nomarchart, "wb+")) == NULL)
        exit(error(nomarchart));
    p("\nEl archivo %s ha sido cargado!!", nomarchart);

    tecla();
    fflush(stdin);
    inicio(cli, art);
    system("cls");
    ingresar(cli, art);
    mostrar(cli, art);
    linea(80);
    tecla(); // lo muestro
    system("cls");
    fclose(cli);
    fclose(art);
    return (0);
}
void linea(int x)
{
    int i;
    // p("");
    for (i = 1; i < x; i++)
        p("*");
    // p("\n");
}

void inicio(FILE *x, FILE *y)
{
    regcli c;
    regarti a;
    char nomcli[][20] = {"LOPEZ", "RODRIGUEZ", "GARCIA", "MARTINEZ", "RAMIREZ"};
    char nomart[][20] = {"COCA COLA", "AGUA TONICA", "N.FANTA", "SPRITE", "POMELO", "MANDARINA"};
    float pre[] = {200.70, 300.75, 300.66, 200.80, 200.90, 300.10};
    int sto[] = {73, 120, 76, 34, 77, 98};
    int i;
    for (i = 0; i < 5; i++)
    {
        c.cod_cli = i + 1;
        strcpy(c.nom_cli, nomcli[i]);
        c.cuenta = 0.;
        fseek(x, 0L, SEEK_END);
        fwrite(&c, sizeof(c), 1, x); // registro clientes
    }

    for (i = 0; i < 6; i++)
    {
        a.cod_art = i + 1;
        strcpy(a.nom_art, nomart[i]);
        a.pre_art = pre[i];
        a.sto_art = sto[i];
        a.fact_art = 0.;
        fseek(y, 0L, SEEK_END);
        fwrite(&a, sizeof(a), 1, y); // registro articulos
    }
}

void mostrar(FILE *x, FILE *y)
{
    regcli c;
    regarti a;
    rewind(x);
    system("cls");
    p("\n\n\t\t\tN%cMINA DE CLIENTES\n\n", 224);
    linea(80);
    p("\nC%cDIGO\tNOMBRE\t\t\t\t\t\tSALDO\n", 224);
    fread(&c, sizeof(c), 1, x);
    while (!feof(x))
    {
        p("\n%3d\t%-20s\t\t\t\t%6.2f\n", c.cod_cli, c.nom_cli, c.cuenta);
        fread(&c, sizeof(c), 1, x);
    }
    p("\n");
    rewind(y);
    linea(80);
    p("\n\n\t\t\t N%cMINA DE ART%cCULOS\n\n", 224, 214);
    linea(80);
    p("\nC%cDIGO\tART%cCULO\t\t\tSTOCK\t\tFACTURACI%cn\n", 224, 214, 224);
    fread(&a, sizeof(a), 1, y);
    while (!feof(y))
    {
        p("\n%3d\t%-20s\t\t%3d\t\t%8.2f\n", a.cod_art, a.nom_art, a.sto_art, a.fact_art);
        fread(&a, sizeof(a), 1, y);
    }
}

void ingresar(FILE *cl, FILE *ar)
{
    int numfac, art, cant, clie, b = 0;
    regarti a;
    regcli c;
    p("\nINGRESE N%cMERO DE FACTURA O CERO PARA FINALIZAR: ", 233);
    s("%d", &numfac);
    while (numfac)
    {
        do
        {
            p("\nINGRESE N%cUMERO CLIENTE[1-5]:", 233);
            s("%d", &clie);
        } while (clie < 1 || clie > 5);
        clie--;
        fseek(cl, sizeof(c) * (clie), SEEK_SET);
        fread(&c, sizeof(c), 1, cl);
        do
        {
            p("\nINGRESE EL C%cDIGO ARTICULO[1-6]:", 224);
            s("%d", &art);
        } while (art < 0 || art > 6);
        b = 0;
        while (art)
        {
            --art;
            fseek(ar, sizeof(a) * (art), SEEK_SET); // posiciona el articulo 
            fread(&a, sizeof(a), 1, ar);// lo lee
            p("\nINGRESE LA CANTIDAD DE %s:", a.nom_art);
            s("%d", &cant);
            if (cant > a.sto_art)
                b = 1;
            if (b == 0)
            {
                a.fact_art += a.pre_art * cant;
                a.sto_art = (a.sto_art - cant);
                fseek(ar, sizeof(a) * (art), SEEK_SET);
                fwrite(&a, sizeof(a), 1, ar);
            }
            else
                p("\nLa cantidad es mayor al stock");
            system("cls");
            do
            {
                p("\nINGRESE EL C%cDIGO ARTICULO[1-6]:", 224);
                s("%d", &art);
            } while (art < 0 || art > 6);

            // fseek(cl,sizeof(c)*(clie),SEEK_SET);  Desde el Principio
            fseek(cl, sizeof(c) * (-1L), SEEK_CUR); // Posicionado en el Registro del cliente
            c.cuenta += a.pre_art * cant; // actualiza la cuenta del cliente
            fwrite(&c, sizeof(c), 1, cl); // graba el registro del cliente
        }
        p("\nINGRESE N%cMERO DE FACTURA O CERO PARA FINALIZAR: ", 233);
        s("%d", &numfac);
    }
}

int error(char *x)
{
    fprintf(stderr, "no se puede abrir el archivo %s", x);
    return (1);
}
void tecla(void)
{
    p("\nPRESIONE CUALQUIER TECLA PARA CONTINUAR!!!");
    getch();
}
