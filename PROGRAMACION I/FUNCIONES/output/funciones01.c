#include <stdio.h>

void calcular_operaciones(float, float, int);
int menu(void);

int main()
{
    float num1, num2;
    int op;
    do
    {
        op = menu();
        if (op != 5)
        {

            printf("Ingrese el primer número: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo número: ");
            scanf("%f", &num2);
            calcular_operaciones(num1, num2, op); // llamando a la función/* code */
        }

    } while (op < 5);
    return 0;
}

int menu()
{
    int op;
    do
    {
        printf("Ingrese la operacion que desea realizar:\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("5. Salir\n");
        scanf("%d", &op); /* code */
    } while (op < 1 || op > 5);
    printf("opcion en funcion:%d\n", op);
    return op;
}

void calcular_operaciones(float x, float y, int opcion)
{
    float resultado;
    switch (opcion)
    {
    case 1:
        resultado = x + y;
        printf("La suma de %.2f y %3.2f es %.2f\n", x, y, resultado);
        break;
    case 2:
        resultado = x - y;
        printf("La resta de %.2f y %.2f es %.2f\n", x, y, resultado);
        break;
    case 3:
        resultado = x * y;
        printf("La multiplicación de %.2f y %.2f es %.2f\n", x, y, resultado);
        break;
    case 4:
        if (y == 0)
        {
            printf("Error: no se puede dividir entre cero\n");
        }
        else
        {
            resultado = x / y;
            printf("La división de %.2f y %.2f es %.2f\n", x, y, resultado);
        }
        break;
    default:
        printf("Opción inválida\n");
        break;
    }
}
