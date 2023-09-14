#include <stdio.h>
#include <string.h>

void mostrarVotos(FILE *);
void pausa(void);
void cargarVotos(FILE *);

typedef struct
{
    int cod_zona;
    int num_lista;
    int votos;
} registro;

int main()
{
    FILE *binario;
    char v[10] = "votos.dat";
    // if ((binario = fopen(v, "rb+")) == NULL) 
    // esto esta comentado para que cuando ejecuten no acumule y solo guarde lo ingresado en ese momento
    binario = fopen(v, "wb+");
    cargarVotos(binario);
    mostrarVotos(binario);
    fclose(binario);
    return 0;
}

void pausa(void)
{
    printf("\n\nPresione Enter para continuar...\n\n");
    fflush(stdin);
    getchar();
}

void cargarVotos(FILE *x)
{
    int numlista, codZona, flag; // numlista seria el numero de Lista y codZona el codigo de zona
    registro r; // este es el registro r donde se guardara lo cargado por teclado
    do
    {
        printf("\nIngrese numero de lista[1-3] o < -1 > para finalizar: ");
        scanf("%d", &numlista);
    } while ((numlista < 1 || numlista > 3) && (numlista!=-1));

    while (numlista!=-1)
    {
        flag = 0;
        do
        {
            printf("\nIngrese codigo de Zona[1-5]:");
            scanf("%d", &codZona);
        } while (codZona < 1 || codZona > 5);
        // aqui no confirmo si quiere votar o no por ese candidatos
        // por ser un parcial final, solo eso

        rewind(x);
        fread(&r, sizeof(r), 1, x);
        while (!feof(x) && flag == 0)
        {
            if (r.cod_zona == codZona && r.num_lista == numlista)
            {
                flag = 1;
            }
            if (flag == 0)
                fread(&r, sizeof(r), 1, x);
        }

        if (flag)
        {
            fseek(x, sizeof(r) * (-1l), SEEK_CUR); // posiciona el candidato y lista
            r.votos = r.votos + 1;                 // incremento 1 en el voto
            fwrite(&r, sizeof(r), 1, x);           // grabo el voto en la lista y candidato elegido
        }
        else
        {
            printf("ingresado por primera vez:\n\n");
            fseek(x, sizeof(r), SEEK_END); // Posicionado al final del archivo
            r.cod_zona = codZona;
            r.num_lista = numlista;
            r.votos = 1;
            fwrite(&r, sizeof(r), 1, x); // graba el registro del voto
        }

        do
        {
            printf("\nIngrese numero de lista[1-3] o < -1 > para finalizar: ");
            scanf("%d", &numlista);
        } while ((numlista < 1 || numlista > 3) && (numlista!=-1));
    }
}

void mostrarVotos(FILE *x)
{
    int totalVotos[3] = {0}; // acumula la cantidad de votos por lista
    int totalZonas[5] = {0}; // Acumula el total de votos por zona
    int votosTotales = 0; // acumula el total de votos en general
    char nom_lista[][40] = {"Juan Luis Manzur", "Beatriz Elias de Perez", "Ricardo Argentino Bussi"};
    char nom_zona[][40] = {"Aguilares", "Bella Vista", "Famailla", "Graneros", "La Cocha"};
    float porcentaje;
    registro r;

    rewind(x);
    fread(&r, sizeof(r), 1, x);
    while (!feof(x))
    {
        totalVotos[r.num_lista - 1] += r.votos;
        totalZonas[r.cod_zona - 1] += r.votos;
        votosTotales += r.votos;
        fread(&r, sizeof(r), 1, x);
    }

    printf("\nResultados parciales ingresados con exito.\n");
    printf("\n--- Informe de Votos ---\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s:\n", nom_zona[i]);
        for (int j = 0; j < 3; j++)
        {
            printf("%40s: %d votos.\n", nom_lista[j], totalVotos[j]);
        }
    }

    printf("\n--- Resultado Final ---\n");
    int listaGanadora = 1;
    int maxVotos = totalVotos[0];
    for (int i = 1; i < 3; i++)
    {
        if (totalVotos[i] > maxVotos)
        {
            maxVotos = totalVotos[i];
            listaGanadora = i + 1;
        }
    }
    printf("La lista ganadora es la %s, con un total de %d votos en todas las zonas.\n", nom_lista[listaGanadora - 1], maxVotos);

    printf("\n--- Porcentajes de Votos ---\n");
    for (int i = 0; i < 3; i++)
    {
        porcentaje = (float)totalVotos[i] / votosTotales * 100;
        printf("%30s: %.2f%%.\n", nom_lista[i], porcentaje);
    }
}