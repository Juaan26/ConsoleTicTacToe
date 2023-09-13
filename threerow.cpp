#include <stdio.h>

//para que el compilador pueda llamar a estas funciones en main
void loop(char c[3][3]);
void enter_first(char c[3][3]);
void board(char c[3][3]);

int main()
{

    char c[3][3];

    loop(c); // llama a todas las funciones fundamentales y hace un refresco de pantalla

    return 0;
}

void loop(char c[3][3])
{
    enter_first(c);
     board(c);
}

void enter_first(char c[3][3])// esta funcion contiene al bucle genera la matriz ( 1 2 3)
                                                                            //   ( 4 5 6)
                                                                            //   ( 7 8 9) 
{

    int i, j;
    char aux;

    aux = '1';
    /*incia el primer bucle en posicion 0 y el segundo pasa por 0,1 y 2 hasta que
    la condición no se cunmple y vuelve al primero donde i está en 1 y repite el proceso*/
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
             c[i][j] = aux++;
        }
    }
}

void board(char c[3][3]) // el bucle de esta función se encarga de iterar la matriz para imprimir sus valores
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c |", c[i][j]);
        }
        printf("\n------------\n");
    }
}