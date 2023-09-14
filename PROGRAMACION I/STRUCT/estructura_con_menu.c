// directivas de Preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
// prototipos de funcion,
// recordar que en los parametrso solo van los tipos de datos
typedef struct
{
    int codigo;
    char producto[30]; /// aca te agrande el campo porque es muy chico de 30
    float precio;
} registro;
// con este tipo de definicion no tenes que poner struct adelante de nada mas solo
// solo invocas el nombre y listo
void pausa(void);
int menu(void);
void CambioDePrecio(registro[], int);
void CargaDeProducto(registro[], int *);
void MostrarListaProductos(registro[], int );
int main()
{
    registro r[10]; // registro de 10 datos como maximo
    int op;
    int numProductos = 0; // Contador de productos
    do
    {
        op = menu(); // llamada a al menu de opciones
        system("cls");
        switch (op)
        {
        case 1:
            CargaDeProducto(r, &numProductos); // Llama a la función para agregar un producto
            break;

        case 2:
            printf("este item fue desarrollado en el item 1\n");
            pausa();
            break;

        case 3:
            CambioDePrecio(r, numProductos);
            break;

        case 4:
            pausa();
            break;

        case 5:
            MostrarListaProductos(r, numProductos);
            break;
        }
    } while (op < 6);

    return (0);
}

int menu(void)
{
    int op;
    do
    {
        system("cls");
        printf("\n\t\t\t MENU DE OPCIONES DE ARTICULOS\n");
        printf("\n\n\t\t\t - Ingresar Datos             <1>\n");
        printf("\n\n\t\t\t - Agrega  Producto nuevo     <2>\n");
        printf("\n\n\t\t\t - Cambiar Precio             <3>\n");
        printf("\n\n\t\t\t - Promedio de Precios        <4>\n");
        printf("\n\n\t\t\t - Mostrar Lista de Productos <5>\n");
        printf("\n\n\t\t\t - Salir                      <6>\n");
        printf("\n\n\t\t\t   Ingrese Opcion [1-6]  :  ");
        scanf("%d", &op);
    } while (op < 1 || op > 6);
    return op;
}
void pausa(void)
{
    printf("\nPresione Enter para continuar...");
    fflush(stdin); // aqui si va porque puede quedar el /n
    getchar();
}
void CargaDeProducto(registro r[], int *numProductos)
{
    if (*numProductos >= 10)
    {
        printf("No se pueden agregar más productos. Limite alcanzado.\n");
    }
    else
    {
        system("cls");
        printf("\n\t\t\t CARGA DE PRODUCTO\n");

        printf("\nIngrese el código del producto: ");
        scanf("%d", &r[*numProductos].codigo);

        printf("Ingrese el nombre del producto: ");
        scanf("%[^\n]s", r[*numProductos].producto);
        // esto se llama acento circunflexo barra n
        // y sirve para poder poner un texto con espacios y no se corte apenas encuentra el espacio

        printf("Ingrese el precio del producto: ");
        scanf("%f", &r[*numProductos].precio);

        (*numProductos)++; // Incrementa el contador de productos

        printf("\nProducto agregado correctamente.\n");
    }
    pausa();
}

void CambioDePrecio(registro r[], int numProductos)
{
    int cod;
    int encontrado = 0; // este es una bandera para que me avisa si encontro el Producto
    system("cls");
    printf("\n\t\t\t CAMBIO DE PRECIO\n");

    if (numProductos == 0)
    {
        printf("No hay productos para cambiar el precio.\n");
    }

    printf("\nIngrese el c%cdigo del producto cuyo precio desea cambiar: ", 162);
    scanf("%d", &cod);

    for (int i = 0; i < numProductos && encontrado == 0; i++)
    {
        if (cod == r[i].codigo)
        {
            encontrado = 1;
            printf("Producto encontrado:\n");
            printf("Codigo: %d\n", r[i].codigo);
            printf("Nombre: %s\n", r[i].producto);
            printf("Precio actual: %3.2f\n", r[i].precio);

            printf("Ingrese el nuevo precio: ");
            scanf("%f", &r[i].precio);
            printf("Precio actualizado correctamente.\n");
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }

    pausa();
}
void MostrarListaProductos(registro r[], int numProductos)
{
    system("cls");
    printf("\n\t\t\t LISTA DE PRODUCTOS\n");

    if (numProductos == 0)
    {
        printf("No hay productos para mostrar.\n");
    }
    else
    {

        printf("%-10s %-30s %-10s\n", "Codigo", "Producto", "Precio"); // el -30s significa - (alineado a la izq, 30 reserva 30 lugares)
        printf("----------------------------------------------\n");

        for (int i = 0; i < numProductos; i++)
        {
            printf("%4d %-30s $%.2f\n", r[i].codigo, r[i].producto, r[i].precio);
        }
    }

    pausa();
}
