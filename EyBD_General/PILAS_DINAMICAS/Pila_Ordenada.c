#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define p printf
#define s scanf

typedef struct elemento
{
	int nro;
	struct elemento*sig;
} nodo;

void puntero(char[]);
nodo* ingresarDato(int);
int pilaVacia(nodo*);
void apilar(nodo**,nodo*);
nodo desapilar(nodo**);
void mostrarDato(nodo);
void listarPila(nodo*);
void eliminarPila(nodo**);

int main()
{
	nodo *pila_ori,*q,*pila_aux,*pila_ord,dato;
	 int i,n,maxi;
	 pila_ori=NULL;
	 pila_aux=NULL;
	 pila_ord=NULL;
	 srand(time(NULL));
	 system("color 9f");
	 p("\nINGRESE CANTIDAD DE NROS PARA APILAR:"); s("%d",&n);
	 for(i=0;i<n;i++)
      {
      	  // p("\n Ingrese Nro %d :",i+1);scanf("%d",&m);
      	  // q=ingresarDato(m);
      	   q=ingresarDato(rand()%80+1);
		   apilar(&pila_ori,q);
       }
    p("\n PILA ORIGINAL COMPLETA\n\n ");
    ///P es la pila original
    if(pilaVacia(pila_ori))listarPila(pila_ori);
    puntero("ORIGINAL");

    p("\n\nPRESIONE UNA TECLA PARA ORDENAR LA PILA !!\n\n  "); getch();
    for(i=0;i<n;i++)
     {
       maxi=0;
       while(pila_ori)
        {
          dato=desapilar(&pila_ori);
          q=ingresarDato(dato.nro);
          if(dato.nro>maxi)
            maxi=dato.nro;
          apilar(&pila_aux,q);

        }
       if(pila_aux==NULL)  
        p("\n PILA AUXILIAR VACIA!!!\n\n");
        while(pila_aux)  ///Pila auxiliar
       {
          dato=desapilar(&pila_aux);
          q=ingresarDato(dato.nro);
          if(dato.nro==maxi) 
            apilar(&pila_ord,q);
          else 
           apilar(&pila_ori,q);
       }
       p("\n CONTENIDO DE LA PILA ORDENADA EN LA %d%c PASADA:",i+1,167);
       listarPila(pila_ord);
       puntero("ORDENADA");
       if(pilaVacia(pila_ori))
        {
          p("\n CONTENIDO DE LA PILA ORIGINAL EN LA %d%c PASADA:",i+1,167);
          listarPila(pila_ori);
          puntero("ORIGINAL");
        } else
         {   
            p("\n");
             puntero("ORIGINAL ->NULL");
         }
        getch();
        p("\n\n");
     }
    /// pila_ord es la pila ordenada
    p("\n\nPILA ORDENADA COMPLETA\n\n ");
    if(pilaVacia(pila_ord))
        listarPila(pila_ord);
    puntero("ORDENADA");

    p("\n\n PRESIONE UNA TECLA PARA DESAPILAR LA PILA ORDENADA\n\n"); getch();
    i=1;
    while(pila_ord)
        {
          dato=desapilar(&pila_ord);
          mostrarDato(dato)  ;
        }
     if(pila_ori!=NULL) eliminarPila(&pila_ori);
     p("\n PILA ORIGINAL VAC%cA !!!\n\n",214);
     if(pila_aux!=NULL) eliminarPila(&pila_aux);
     p("\n PILA SECUNDARIA VAC%cA !!!\n\n",214);
     if(pila_ord!=NULL) eliminarPila(&pila_ord);
     p("\n PILA ORDENADA VAC%cA !!!\n\n",214);
     getch(); system("cls");
 	 return 0;
}

void puntero(char x[])
{
    p(" PUNTERO A LA PILA %s",x);
}

nodo* ingresarDato(int x)
{
  nodo *q;
	 q=(nodo*)malloc(sizeof(nodo));
	 q->nro=x;
     q->sig=NULL;
	 return q;
}

int pilaVacia(nodo*x)
{
	return((x==NULL)?0:1);
}

void apilar(nodo**x,nodo*q)
{
	 q->sig=*x;
	*x=q;
}

nodo desapilar(nodo**x)
{
	nodo dato,*aux;
	 aux=*x;
	 dato=**x;
	 *x=(*x)->sig;
	 free(aux);
	 return dato;
}

void mostrarDato(nodo dato)
{
	p("\n DATO DESAPILADO: %d\t",dato.nro);
	system("pause");
}

void listarPila(nodo*x)
{
    if(x)
	 {
		p("%3d <-",x->nro);
		listarPila(x->sig);
	 }
}

void eliminarPila(nodo**x)
{
	nodo *aux;
	 if(*x)
	 {
		aux=*x;
		*x=aux->sig;
		free(aux);
		eliminarPila(x);
	 }
}
