#include<stdio.h>


int main()
{
    int simple=1, doble=2, triple=3;
    int equipo, puntos, simples1, dobles1, triples1, total1=0 , simples2, dobles2, triples2, total2=0;
    float promedioSimples, PromedioDobles, PromedioTriples, totalSimples, totalDobles, totalTriples, totalTiros;
    float porcentajeSimples, porcentajeDobles, porcentajeTriples;

    printf("Ingrese el equipo para calcular los puntos o 0 para salir: \n");
    scanf("%d", &equipo);
    if (equipo == 0)
    {
        printf("Gracias por utilizar el programa");
    }
    
    while (equipo !=0)
    {
   
        printf("ingrese el tipo de punto realizado: \n");
        printf("Simples: 1\n");
        printf("Dobles: 2\n");
        printf("Triples: 3\n");
        scanf("%d", &puntos);
        
        if (equipo == 1)
        {
            switch (puntos)
            {
            case 1:
                simples1 = simples1 + simple; 
                totalSimples++;
                break;
            case 2:
                dobles1  = dobles1 + doble;
                totalDobles++;
                break;
            case 3:
                triples1 = triples1 + triple;
                totalTriples++;         
            default:
                printf("Ingrese un tipo de tiro valido 1,2 o 3\n");
                break;
            totalTiros++;
            }
        }
        if (equipo == 2)
        {
            switch (puntos)
            {
            case 1:
                simples2 = simples2 + simple; 
                totalSimples++;
                break;
            case 2:
                dobles2  = dobles2 + doble;
                totalDobles++;
                break;
            case 3:
                triples2 = triples2 + triple;
                totalTriples++;         
            default:
                printf("Ingrese un tipo de tiro valido 1,2 o 3");
                break;
            totalTiros++;
            }
        }
            total1 = simples1 + simples1 + simples1;
            total2 = simples2 + simples2 + simples2;
            
            if (total1 > total2)
            {
                printf("Por el momento el equipo 1 va ganando\n");
            }
            if (total1 < total2)
            {
                printf("Por el momento el equipo 2 va ganando\n");
            }
            
                
        
        
        
        printf("Ingrese el equipo que realizo el siguiente tanto, o 0 para finalizar el partido\n");
        scanf("%d", &equipo);
        if (equipo == 0)
        {
            printf("El partido finalizo!, veamos las estadisticas\n\n");
        }
        
        
        }
        
    

        printf("El equipo 1 realizo %d puntos\n", total1);
        printf("El equipo 2 realizo %d puntos\n", total2);
         if (total1> total2)
         {
            printf("El ganador fue el equipo 1\n");
         }
         else
         {
            printf("el ganador fue el equipo 2\n");
         }
         
        promedioSimples = totalSimples/totalTiros;
        PromedioDobles = totalDobles/totalTiros;
        PromedioTriples = totalTriples/totalTiros;

        printf("Se tiraron un total de %1.f tiros simples, un promedio de %1.f tiros\n", totalSimples, promedioSimples);
        printf("se tiraron un total de %1.f tiros dobles, un promedio de %1.f tiros\n", totalDobles, PromedioDobles);
        printf("se tiraron un total de %1.f tiros triples, un promedio de %1.f tiros\n", totalTriples, PromedioTriples);

        porcentajeSimples = (totalTiros * totalSimples / 100);
        porcentajeDobles = (totalTiros * totalDobles / 100);
        porcentajeTriples = ( totalTiros* totalTriples / 100);

        printf("el porcentaje de tiros simples fue %1.f\nel porcentaje de tiros dobles fue %1.f\nel porcentaje de tiros triples fue %1.f", porcentajeSimples, porcentajeDobles, porcentajeTriples);
        printf("Se tiraron un total de %d", totalTiros);
    return 0;
}