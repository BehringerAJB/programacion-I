#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define p printf
#define s scanf
typedef struct
{
    int cod_cli;
    char nom_cli[30];
    int venta;
} registro1;

typedef struct
{
    int cod_cli;
    char nom_cli[30];
    int venta;
    int mes;
} registro2;

typedef struct lista_mes_cod
{
    int cod_cli;
    int mes;
    int venta_total;
    struct lista_mes_cod *sig;
} nodo_mes_cod;

typedef struct lista
{
    int cod_cli;
    char nom_cli[30];
    int venta;
    struct lista *sig;
} nodo;

void cargar_lista(nodo **, FILE *);
void insertar(nodo **, int, char[], int);
nodo *nuevonodo(int, char[], int);
int sacapal(char[], int d, char[]);
void encontrar_maxima_venta(nodo *);
void CargarArchivoBinario(nodo *, FILE *);
void listar(nodo *);
void tecla(void);
void eliminar(nodo **);
void mostrar(FILE *);
void mostrar_lista_agrupada(nodo_mes_cod *);
nodo_mes_cod *buscar_o_insertar(nodo_mes_cod **, int, int, int);
void guardar_en_archivo(nodo_mes_cod *);

int main()
{

    FILE *archivo, *orden;
    char *nombre = "C:\\Users\\behri\\Documents\\test\\EyBD_2023\\texto.txt"; // nombre físico del archivo
    char *nomord = "C:\\Users\\behri\\Documents\\test\\EyBD_2023\\ordenar.dat";
    char cadena[80], pri[80], seg[80], ter[80], cua[80];
    int cod, ventas, mes, i;
    nodo *cabeza; 
    nodo_mes_cod *CabezaMesCod;
    system("color 9f");
    cabeza = NULL;
    CabezaMesCod = NULL;
    cadena[0] = '\0';
    pri[0] = '\0';
    seg[0] = '\0';
    ter[0] = '\0';
    cua[0] = '\0'; // vacío las cadenas
    if ((archivo = fopen(nombre, "r+")) == NULL)
        p("\n\n***El archivo %s no pudo abrirse ***\n", nombre);
    else
    {
        p("\n CONTENIDO DEL ARCHIVO DE TEXTO\n\n");
        while (fgets(cadena, 81, archivo)) //!=NULL)  hasta \n n-1 o salto de linea
            p("%s", cadena);
        rewind(archivo);
        tecla();
        p("\n\n CONTENIDO DE LOS CAMPOS EN MEMORIA");
        p("\n\n CODIGO\t\tNOMBRE\t\t\tventa\t Mes \n\n");
        while (fgets(cadena, 81, archivo)) // Recorro el Archivo de Texto
        {
            i = 0;
            while (cadena[i] != '\0')
            {
                i = sacapal(cadena, 0, pri); // Saco la primer palabra y la convierto a entero (COD)
                cod = atoi(pri);
                p("\n%3d", cod);
                i += 1;
                i = sacapal(cadena, i, seg); // Saco la segunda palabra y la guardo en una variable
                p("\t\t%-20s ", seg);        // que será el nombre del cliente
                i++;
                i = sacapal(cadena, i, ter); // Saco la tercer palabra y la convierto a entero (venta)
                ventas = atoi(ter);
                p("\t%6d", ventas);
                i++;
                i = sacapal(cadena, i, cua); // Saco la cuarta palabra y la convierto a entero (venta)
                mes = atoi(cua);
                p("\t%3d", mes);

            } // Salgo del renglón
            /// Inserto en orden en la lista sin repeticiones de registros
            /// este va ordenado por codigo y acumula ventas (cabeza)
            insertar(&cabeza, cod, seg, ventas);
            /// este acumula por agrupado de cod y mes las ventas
            nodo_mes_cod *nodo_actual = buscar_o_insertar(&CabezaMesCod, cod, mes, ventas);
            /*
            la función buscar_o_insertar se llama recursivamente hasta 
            que encuentra el nodo o llega al final de la lista (*x == NULL). 
            En cada llamada recursiva, la función pasa un puntero al siguiente nodo 
            (&(*x)->sig), para continuar buscando en la siguiente posición
             de la lista. Por lo tanto, para que esta recursión funcione adecuadamente,
             la función debe devolver el puntero al nodo encontrado 
             o al nuevo nodo insertado en cada nivel de recursión.
            
            */
        }  
        p("\n\n Se cargo la lista Por Ventas!!!!\n\n");
        listar(cabeza);
        tecla();

        p("\n\n Se cargo la lista Por Por Mes y Codigo de las ventas!!!!\n\n");
        mostrar_lista_agrupada(CabezaMesCod);
        tecla();
        orden = fopen(nomord, "wb+"); // Elimina el archivo anterior
        /// Cargo la lista en el archivo en orden
        CargarArchivoBinario(cabeza, orden);
        p("\n\n LA LISTA SE CARGO EN EL ARCHIVO %s !!!!\n", nomord);
        rewind(orden);
        mostrar(orden);
        tecla();
        p("\n\n Mostraremos El vendedor con su Maxima Venta\n");
        encontrar_maxima_venta(cabeza);
        tecla();
        guardar_en_archivo(CabezaMesCod);
        eliminar(&CabezaMesCod);
        eliminar(&cabeza);
        fclose(orden);
    } // else de la apertura de Archivo
    tecla();
    system("cls");

    free(cabeza);
    fclose(archivo);
    return (0);
}

void eliminar(nodo **x)
{
    nodo *aux;
    if (*x)
    {
        aux = *x;
        *x = aux->sig;
        free(aux);
        eliminar(x);
    }
}

void tecla(void)
{
    printf("\nPresione Enter para continuar...\n");
    fflush(stdin);
    getchar();
}
int sacapal(char x[], int d, char y[])
{
    int i, j = 0;
    i = d;
    while (x[i] != ',' && x[i] != '\0')
        y[j++] = x[i++];
    y[j] = '\0';
    return (i);
}

void mostrar(FILE *x)
{
    registro1 r;
    p("\n CONTENIDO DE LOS REGISTROS EN EL ARCHIVO\n\n");
    p("\n\n C%cDIGO\t\tNOMBRE\t\t\tventa\n\n", 224);
    rewind(x);
    fread(&r, sizeof(r), 1, x);
    while (!feof(x))
    {
        p("\n\n%3d\t\t%-20s\t%6d", r.cod_cli, r.nom_cli, r.venta);
        fread(&r, sizeof(r), 1, x);
    }
}

nodo *nuevonodo(int x, char cli[], int venta)
{
    nodo *a;
    a = (nodo *)malloc(sizeof(nodo));
    a->cod_cli = x;
    strcpy(a->nom_cli, cli);
    a->venta = venta;
    a->sig = NULL;
    return a;
}

void insertar(nodo **x, int y, char nc[], int venta)
{
    nodo *nuevo;
    nuevo = nuevonodo(y, nc, venta);
    if (*x == NULL)
        *x = nuevo;
    else if ((*x)->cod_cli > y)
    {
        nuevo->sig = *x;
        *x = nuevo;
    }
    else if (y == (*x)->cod_cli)
        ((*x)->venta) += venta;
    else
        insertar(&(*x)->sig, y, nc, venta);
}

void listar(nodo *x)
{
    if (x)
    {
        p("\n%4d\t\t%-20s\t %6d", x->cod_cli, x->nom_cli, x->venta);
        listar(x->sig);
    }
}

void CargarArchivoBinario(nodo *lista, FILE *x) /// Carga de la lista al Archivo
{
    registro1 r;
    if (lista != NULL)
    {
        r.cod_cli = lista->cod_cli;
        strcpy(r.nom_cli, lista->nom_cli);
        r.venta = lista->venta;
        fwrite(&r, sizeof(r), 1, x);
        CargarArchivoBinario(lista->sig, x);
    }
}

void encontrar_maxima_venta(nodo *x)
{
    int max_venta = 0;
    char vendedor_max_venta[30];
    if (x != NULL)
    {
        max_venta = x->venta;
        strcpy(vendedor_max_venta, x->nom_cli);
    }
    while (x != NULL)
    {
        if (x->venta > max_venta)
        {
            max_venta = x->venta;
            strcpy(vendedor_max_venta, x->nom_cli);
        }

        x = x->sig;
    }

    printf("\nEl vendedor con la máxima venta es: %s", vendedor_max_venta);
    printf("\nLa venta máxima es: %d\n", max_venta);
}

/// ***************************************************************************************

nodo_mes_cod  *buscar_o_insertar(nodo_mes_cod **x, int cod, int mes, int venta)
{
    if (*x == NULL || ((*x)->cod_cli == cod && (*x)->mes == mes))
    {
        if (*x == NULL)
        {
            nodo_mes_cod *nuevo = (nodo_mes_cod *)malloc(sizeof(nodo_mes_cod));
            nuevo->cod_cli = cod;
            nuevo->mes = mes;
            nuevo->venta_total = 0;
            nuevo->sig = NULL;
            *x = nuevo;
        }
        (*x)->venta_total += venta;
        return *x;
    }
    return buscar_o_insertar(&(*x)->sig, cod, mes, venta);
   
}

void mostrar_lista_agrupada(nodo_mes_cod *x)
{
    while (x != NULL)
    {
        printf("\nCódigo: %d, Mes: %d, Ventas totales: %d\n", x->cod_cli, x->mes, x->venta_total);
        x = x->sig;
    }
}

/// **************************
/*
 ahora pasamos la lista a un archivo de texto
 Función para guardar los datos en el archivo de texto
*/
void guardar_en_archivo(nodo_mes_cod *x)
{
    FILE *archivo_resumen = fopen("resumen.csv", "w");
    p("\nTransformacion de lista Codigo-Mes a archivo resumen.csv\n");
    if (archivo_resumen == NULL)
    {
        printf("Error al abrir el archivo de resumen.\n");
        return;
    }
    while (x != NULL)
    {
        fprintf(archivo_resumen, "%d,%d,%d\n", x->cod_cli, x->mes, x->venta_total);
        p("\n%d,%d,%d", x->cod_cli, x->mes, x->venta_total);
        x = x->sig;
    }
    fclose(archivo_resumen);
}