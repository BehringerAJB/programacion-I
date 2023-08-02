#include<stdio.h>   // con menú
#include<stdlib.h> //lista ordenada con repeticiones
#include<conio.h> // borra nodo determinado //
#include<time.h>
#define p printf
#define s scanf
typedef struct elemento
{
	int dato;
	struct elemento*sig;
} nodo;
int menu(void);
nodo*buscar(nodo*,int);
void insertar(nodo**,int);
nodo*nuevonodo(int);
void listar(nodo*);
void eliminar(nodo**);
void borranodo(nodo**,int);
main()
{
 int op,num;
 nodo*cabeza,*aux;
 cabeza=NULL;
 do
   {
    op=menu();
    system("cls");
    switch(op)
	{

	case 1:
		p("\n Ingrese Elemento:");
        s("%d",&num);
 	    insertar(&cabeza,num);
		break;
	 case 2:
		if(cabeza)
         {
           p("\n\n Lista Ordenada\n\n");
           listar(cabeza); getch();
          }
            else
             {
                 p("\n Lista vacía\n\n");
                 getch();
             }
		break;
	case 3:
        if(cabeza)
        {
          p("\n\n Ingrese el Nro a borrar:"); s("%d",&num);
          aux=buscar(cabeza,num);
          if(aux==NULL) {p("\n El nro no fue encontrado"); getch();}
           else
              {
                p("\n El nro fue encontrado\n\n");
                borranodo(&cabeza,num);
                p("\n Presione una tecla para ver la lista resultante!!\n"); getch();
                if(cabeza)  listar(cabeza);
              }
        } else p ("\n\nLista vacía!!!\n\n\n"); getch();
        break;
	case 4:
		if(cabeza)
		{
		   p("\n Presione una tecla y comenzar  a borrar nodos!!");getch();
           eliminar(&cabeza);
		}
		else  p("\n Lista vacía\n\n"); getch();
	}
            }while(op<5);

 getch();
 return(0);
 }
void borranodo(nodo**x,int y)
{
  nodo*aux;
  if(*x)
  {
	 aux=*x;
	 if((*x)->dato==y)
	 { p("\nNodo a eliminar:%3d",(*x)->dato);getch();
	  *x=aux->sig;
	   free(aux);
	  }  else	 borranodo(&(*x)->sig,y);
  }
}

 void eliminar(nodo**x)
 {
  nodo*aux;
  if(*x)
  {
	 aux=*x;
	 p("\nNodo a eliminar:%3d",(*x)->dato);getch();
	 *x=aux->sig;
	 free(aux);
	 eliminar(x);
  }
}
 /*void insertar(nodo** x,int y)// inserción iterativa
 {
	nodo *nuevo,*anterior,*p;
	nuevo=nuevonodo(y);
	if(*x==NULL) *x=nuevo;
		else if(y<(*x)->dato)
			{
			nuevo->sig=*x;
			*x=nuevo;
			} else
				{
				anterior=p=*x;
				while((p->sig!=NULL)&&(y>p->dato))
				{
				anterior=p;
				p=p->sig;
				}
				if(y>p->dato) // se inserta £ltimo
					anterior=p;
				nuevo->sig=anterior->sig;
				anterior->sig=nuevo;
				}

 }*/

 void insertar(nodo** x,int y) // inserción recursiva
 {
	nodo *nuevo,*anterior,*p;
	nuevo=nuevonodo(y);
	if(*x==NULL)    *x=nuevo;
		   else if((*x)->dato>y)
                {
                 nuevo->sig=*x;
                 *x=nuevo;
                }
                 else insertar(&(*x)->sig,y);


 }
nodo * nuevonodo(int x)
{
 nodo *a;
 a=(nodo*)malloc(sizeof(nodo));
 a->dato=x;
 a->sig=NULL;
 return a;
 }
nodo*buscar(nodo*x,int y)
{
	if(!x) return (NULL);
	 else if(y==x->dato) return(x);
		 else return(buscar(x->sig,y));
}

int menu(void)
{
	int op;
	 do
	 {
		system("cls");
		printf("\n\t\t\t MENU DE OPCIONES (LISTAS)\n\n");
		printf("\n\n\t\t\t - Ingresar Datos <1>\n");
		printf("\n\n\t\t\t - Listar Datos   <2>\n");
		printf("\n\n\t\t\t - Borrar Nodo    <3>\n");
		printf("\n\n\t\t\t - Borrar Lista   <4>\n");
		printf("\n\n\t\t\t - Salir          <5>\n");
		printf("\n\n\t\t\tIngrese Opcion:  ");
		scanf("%d",&op);
	 }while(op<1||op>5);
	 return op;
}

void listar(nodo*x)
{
	if(x)
	{	 p("%4d",x->dato);
	 listar(x->sig);
	 }
}
