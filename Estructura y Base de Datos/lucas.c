

#include "utils.h"
#define PATH "Pilas.dat"

 

typedef struct {
  long int cod;
  string desc;
  int cant;
  float pre;
} Registro;

 

typedef struct elemento {
  Registro datos;
  struct elemento *sig;
} Nodo;

 

void cargaPila(Nodo **, Registro [], int);
void mostrar(FILE *);
char menu(void);
Nodo* extraerDato(int, Registro []);
void apilar(Nodo **, Nodo *);
void listarPila(Nodo *);
void mostrarRegistro(Nodo*);

 

 

int main(){
    Registro info[] = {
    {100235, "Nebulizador", 50, 145.20},
    {100312, "Tensiometro", 120, 159.35},
    {200045, "Caloventor", 35, 46.00},
    {200511, "Estufa halogena", 15, 72.58},
    {400805, "Afeitadora", 100, 215.40},
    {400322, "Cortadora de Cabello", 210, 29.45}
    };

 

    Registro infocom[] = {
    {500100, "Reproductor de DVD", 24, 200.53},
    {100312, "Tensiometro", 50, 159.35},
    {500235, "Televisor 21", 30, 565.60},
    {200511, "Estufa halogena", 30, 72.58}
    };

 

    Nodo *pilaInfo, *pilaInfocom;
    int opc, cantElementos;
    FILE* pArch = abrirArchivoBinario(PATH, "w+b");
    pilaInfo = NULL;
    pilaInfocom = NULL;
    do{
        CLEAN();
        opc = menu();
        CLEAN();
        switch (opc){
        case '1':
            cargaPila(pilaInfo, info, 6);
            cargaPila(pilaInfocom, infocom, 4);
            cargar();
            break;
        case '2':
            break;
        case '3':
            listarPila(pilaInfo);
            listarPila(pilaInfocom);
            tecla();
            break;
        case '4':
            cargaArchivo(pArch, pilaInfo);
            break;
        case '5':
            break;
        case '6':
            mostrar(pArch);
            tecla();
            break;
        }
    } while(opc != '7');

 

 

    return 0;
}

 

 

 

char menu(void){
    char opc;
    do{
        //system("cls");
        printf("\n\t\t\t\t MENU DE OPCIONES (PILAS)\n\n");
        printf("\n\t\t\t\t - CARGAR DATOS INICIALES     <1>\n");
        printf("\n\t\t\t\t - AGREGAR DATOS AL STOCK     <2>\n");
        printf("\n\t\t\t\t - LISTAR DATOS               <3>\n");
        printf("\n\t\t\t\t - CARGAR EN ARCHIVO          <4>\n");
        printf("\n\t\t\t\t - BORRAR Y SALIR             <5>\n");
        printf("\n\t\t\t\t - MOSTRAR ARCHIVO            <6>\n");
        printf("\n\t\t\t\t - INGRESE OPCION  [1-6]:  ");
        opc = getch();
        CLEAN();
    } while (opc != '1' && opc != '2' && opc != '3' && opc != '4' && opc != '5' && opc != '6' && opc != '7');
    return opc;
}

 

void cargaPila(Nodo** p, Registro r[], int cant){
    Nodo *q;
    for(int i = 0; i < cant; i++)
    {
        q = extraerDato(i, r);
        mostrarRegistro(q);
        apilar(&(*p), q);
        printf("\n");
        mostrarRegistro(p);
     }
}

 

void mostrar(FILE* x){
    Registro r;
    printf("\n\t\t CONTENIDO DE LOS REGISTROS EN EL ARCHIVO\n\n");
    printf("\n\n Codigo\t\tNombre\t\t\tCantidad\t\tPrecio\n\n");
    rewind(x);
    fread(&r,sizeof(r),1,x);
    while(!feof(x))
    {
        printf("\n\n%3d\t\t%-20s\t%6d\t\t\t%6.2f",r.cod,r.desc,r.cant,r.pre);
        fread(&r,sizeof(r),1,x);
    }
}

 

Nodo* extraerDato(int num, Registro r[]){
    Nodo *q;
    q = (Nodo*) malloc(sizeof(Nodo));
    //q->datos = r[num];
    q->sig = NULL;
    return q;
}

 

void apilar(Nodo** p, Nodo* q){
    q->sig = *p;
    *p = q;
}

 

void listarPila(Nodo *p){
    while(p){
        printf("Direccion: %x Dato: %s sig: %x\n", p, p->datos.desc, p->sig);
        p = p->sig;
    }
}

 

void mostrarRegistro(Nodo *r){
    printf("Dato extraido: ");
    printf("\n\n%3d\t\t%-20s\t%6d\t\t\t%6.2f",r->datos.cod,r->datos.desc,r->datos.cant,r->datos.pre);
    tecla();
}

 

void insertarRegistro(FILE* pArch, Registro dato){
    fseek(pArch, 0L, SEEK_END);
    fwrite(&dato, sizeof(dato), 1, pArch);
}

 

void cargaArchivo(FILE* pArch, Nodo *p){
    while(p){
        insertarRegistro(pArch, p->datos);
        p = p->sig;
    }
}