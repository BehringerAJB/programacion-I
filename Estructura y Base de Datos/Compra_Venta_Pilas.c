#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    char desc[25];
    int cant;
    float pre;
} registro;

typedef struct elemento
{
    registro datos;
    struct elemento *sig;
} nodo;

int menu(void);
nodo *ingresarDato(registro[], int);
void apilar(nodo **, nodo *);
nodo desapilar(nodo **);
void cargapila(nodo **, registro[], int);
void listarPila(nodo *);
void eliminarPila(nodo **);
int pilaVacia(nodo *);
void ActualizaStock(nodo **, nodo **);
nodo* Info(nodo);
// void mostrar(FILE *x);
int main()
{
    registro info[6] = {
        {1235, "Nebulizador", 50, 145.20},
        {1312, "Tensiometro", 120, 159.35},
        {2045, "Caloventor", 35, 46.00},
        {2511, "Estufa halogena", 15, 72.58},
        {4805, "Afeitadora", 100, 215.40},
        {4322, "Cortadora de Cabello", 210, 29.45}};

    registro infocom[4] = {
        {5100, "Reproductor de DVD", 24, 200.53},
        {1312, "Tensiometro", 50, 159.35},
        {5235, "Televisor 21", 30, 565.60},
        {2511, "Estufa halogena", 30, 72.58}};
    nodo *pila_info, *pila_infocom;
    int op, Cant_Elementos;
    pila_info = NULL;
    pila_infocom = NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1: // CARGAR DATOS INICIALES
            Cant_Elementos = 6;
            cargapila(&pila_info, info, Cant_Elementos);
            Cant_Elementos = 4;
            cargapila(&pila_infocom, infocom, Cant_Elementos);
            break;
        case 2: // AGREGAR DATOS AL STOCK
            if (pilaVacia(pila_info))
            {
                 ActualizaStock( &pila_info, &pila_infocom);
            }
            break;
        case 3: // LISTAR DATOS
            if (pilaVacia(pila_info))
            {
                printf("\nPila de Stock\n");
                listarPila(pila_info);
            }
            if (pilaVacia(pila_infocom))
            {
                printf("\nPila de Compras\n");
                listarPila(pila_infocom);
            }
            break;
        case 4: // CARGAR EN ARCHIVO
            if (pilaVacia(pila_info))
            {
            }
        }
    } while (op < 5);

    if (pila_info != NULL)
    {
        eliminarPila(&pila_info);
    }
    if (pila_infocom != NULL)
    {
        eliminarPila(&pila_infocom);
    }
   
    return 0;
};

int menu(void)
{
    int op;
    do
    {
        //system("cls");
        printf("\n\t\t\t\t MENU DE OPCIONES (PILAS)\n\n");
        printf("\n\t\t\t\t - CARGAR DATOS INICIALES     <1>\n");
        printf("\n\t\t\t\t - AGREGAR DATOS AL STOCK     <2>\n");
        printf("\n\t\t\t\t - LISTAR DATOS               <3>\n");
        printf("\n\t\t\t\t - CARGAR EN ARCHIVO          <4>\n");
        printf("\n\t\t\t\t - BORRAR Y SALIR             <5>\n");
        printf("\n\t\t\t\t - INGRESE OPCION  [1-5]:  ");
        scanf("%d", &op);
    } while (op < 1 || op > 5);
    return op;
}
// le paso el nodo, el registro y la cantidad de elementos a cargar en la pila
void cargapila(nodo **x, registro y[], int z)
{
    int i;
    nodo *q;
    for (i = 0; i < z; i++)
    {
        q = ingresarDato(y, i);
        apilar(&(*x), q);
    }
}
// tomo cada valor desapilado en la actualizacion 
// y genero un nuevo no para la pila auxiliar en la actualizacion
nodo *Info(nodo dato)
{
    nodo *s;
    s = (nodo *)malloc(sizeof(nodo));
    s->datos.cod = dato.datos.cod;
    strcpy(s->datos.desc, dato.datos.desc);
    s->datos.cant = dato.datos.cant;
    s->datos.pre = dato.datos.pre;
    s->sig=NULL;
    return s;
}
// toma el valor del vector de registro y lo pasa a la Pila
nodo *ingresarDato(registro y[], int i)
{
    nodo *q;
    q = (nodo *)malloc(sizeof(nodo));
    q->datos.cod = y[i].cod;
    strcpy(q->datos.desc, y[i].desc);
    q->datos.cant = y[i].cant;
    q->datos.pre = y[i].pre;
    q->sig=NULL;
    return q;
}
/*

void mostrar(FILE *x)
{
    registro r;
    printf("\n\t\t CONTENIDO DE LOS REGISTROS EN EL ARCHIVO\n\n");
    printf("\n\n Codigo\t\tNombre\t\t\tCantidad\t\tPrecio\n\n");
    rewind(x);
    fread(&r, sizeof(r), 1, x);
    while (!feof(x))
    {
        printf("\n\n%6d\t\t%-20s\t%6d\t\t\t%6.2f", r.cod, r.desc, r.cant, r.pre);
        fread(&r, sizeof(r), 1, x);
    }
}
*/
void apilar(nodo **p, nodo *q)
{
    q->sig = *p;
    *p = q;
}

void listarPila(nodo *p)
{
    printf("CONTENIDO DE LA PILA\n\n");
    while (p)
    {
        printf("%6d \t %-20s %4d \t %8.2f\n", p->datos.cod, p->datos.desc, p->datos.cant, p->datos.pre);
        p = p->sig;
    }
    printf("\n\n");
    system("pause");
}
int pilaVacia(nodo *p)
{
    if (p == NULL)
    {
        printf("\n\nPILA VACIA\n\n");
        system("pause");

        return 0;
    }
    else
        return 1;
}
nodo desapilar(nodo **p)
{
    nodo dato, *aux;
    aux = *p;
    dato = **p;
    *p = (*p)->sig;
    free(aux);
    return dato;
}
void eliminarPila(nodo **p) 
{
    nodo *aux;
    while (*p) 
    {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }
}

void ActualizaStock(nodo **pila_info, nodo **pila_infocom) {
    nodo *pila_aux = NULL;
    nodo *stock;
    nodo *compra;
    int encontrado;

    while (*pila_infocom != NULL) 
    {
        // Desapilamos un elemento de pila_infocom que tiene lo comprado
        compra = Info(desapilar(pila_infocom)); // Aquí creamos un nodo con lo desapilado de compra
        encontrado = 0; // Bandera para verificar si está en el stock
        // Recorremos la pila_info para buscar el código en el stock
        printf("pila_infocom (Compra): %5d %-20s %4d %4.2f\n", compra->datos.cod, compra->datos.desc, compra->datos.cant, compra->datos.pre);
        while (*pila_info != NULL) 
        {
            stock = Info(desapilar(pila_info)); 
            //printf("\t\tpila_info (Stock): %5d %-20s %4d %4.2f\n", stock->datos.cod, stock->datos.desc, stock->datos.cant, stock->datos.pre);
            // Tomamos el primer valor de la pila en stock
            if (stock->datos.cod == compra->datos.cod) 
            {
                // Actualizamos el stock si encontramos el código
                
                stock->datos.cant += compra->datos.cant;
                encontrado = 1; // Indicamos que encontramos el código
            }
            apilar(&pila_aux, stock);
        }
        // Preguntamos si no lo encontró en el Stock
        if (encontrado == 0) 
        {
            // No encontramos el código en pila_info, agregamos el registro de compra
            apilar(&pila_aux, compra);
        }
         while (pila_aux != NULL) 
        {
            stock = Info(desapilar(&pila_aux));
            apilar(pila_info, stock);
        }
        // Liberamos la memoria del nodo compra (ya fue procesado)
    }

    // Copiamos los elementos restantes de pila_info (Stock que no fue chequeado) a la pila_aux
    while (*pila_info != NULL) 
    {
        stock = Info(desapilar(pila_info));
        apilar(&pila_aux, stock);
    }
    // Ahora pila_aux tiene la información actualizada
    // Copiamos los elementos de la pila_aux a pila_info (recomponemos la pila original del Stock)
    while (pila_aux != NULL) 
    {
        stock = Info(desapilar(&pila_aux)); // Aquí es necesario desapilar de pila_aux para mantener consistencia
        apilar(pila_info, stock);
    }
}
