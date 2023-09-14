/*

Una empresa muy importante del rubro del deporte nos contrató
 porque quiere un sistema para ayudar a contabilizar datos
 en los partidos de básquet de la liga nacional.
 para ello se deberá realizar un programa al que se le puede
 ir ingresando los puntos (Equipo 1 o equipo 2)
 y el valor del punto.
  El partido y la carga de información finalizará
  cuando se ingrese que el jugador pertenece al equipo 0.
   Luego de cualquier carga de datos se deberá siempre
   ir actualizando el puntaje del partido e
   indicar que equipo va ganando.
   Cuando el programa finalice, deberá indicar.
   * Los puntos por cada equipo y que equipo es el ganador.
   * La cantidad de simples, dobles y triples que se realizaron.
   * *El promedio de tiros simples, dobles y triples
   * *El porcentaje de puntos que se representan los tiros simples,
   dobles y triples sobre el total.
*/
#include <stdio.h>
int main()
{
    int toc_equipo1 = 0, toc_equipo2 = 0, equipo, puntaje;
    int tsimples = 0, tdobles = 0, ttriples = 0;
    int ts = 0, td = 0, tt = 0;
    int puntaje_e1 = 0, puntaje_e2 = 0;
    int valor_punto;
    float porcentaje_simples, porcentaje_dobles, porcentaje_triples, tot;
    do
    {
        printf("ingrese el equipo <1 o 2> \ <0 cero> para finalizar ingreso:");
        scanf("%d", &equipo);
    } while ((equipo < 1 || equipo > 2) && equipo != 0);
    while (equipo != 0)
    {
        do
        {
            printf("ingrese el puntaje del equipo  <%d>: ", equipo);
            scanf("%d", &puntaje);
        } while (puntaje < 1 || puntaje > 3);

        if (equipo == 1)
        {
            toc_equipo1 += puntaje;
        }
        else
        {
            toc_equipo2 += puntaje;
        }

        switch (puntaje)
        {
        case 1:
            tsimples += puntaje;
            ts += 1;
            break;
        case 2:
            tdobles += puntaje;
            td += 1;
            break;
        case 3:
            ttriples += puntaje;
            tt += 1;
        }
        printf("el puntaje del equipo 1 es : %d\n ", toc_equipo1);
        printf("el puntaje del equipo 2 es : %d\n ", toc_equipo2);
        printf("----------------------------------\n");
        do
        {
            printf("ingrese el equipo <1 o 2> \ <0 cero> para finalizar ingreso:");
            scanf("%d", &equipo);
        } while ((equipo < 1 || equipo > 2) && equipo != 0);
    }
    printf("total de puntos del equipo 1 : %d\n", toc_equipo1);
    printf("total de puntos del equipo 2 : %d\n\n", toc_equipo2);

    printf("total de tiros simples:%d\n", ts);
    printf("total de tiros dobles :%d\n", td);
    printf("total de tiros triples :%d \n\n", tt);

    printf("promedio de tiros simples:%d\n", tsimples / ts);
    printf("promedio de tiros dobles :%d\n", tdobles / td);
    printf("promedio de tiros triples :%d \n\n", ttriples / tt);
    tot = ts + td + tt;
    porcentaje_simples = (float)(ts / (tot)) * 100.0;
    porcentaje_dobles = (float)(td / (tot)) * 100.0;
    porcentaje_triples = (float)(tt / (tot)) * 100.0;
    printf("Porcentaje de tiros simples :%3.2f\n", porcentaje_simples);
    printf("Porcentaje de tiros dobles  :%3.2f\n", porcentaje_dobles);
    printf("Porcentaje de tiros triples :%3.2f\n", porcentaje_triples);
    return 0;
}