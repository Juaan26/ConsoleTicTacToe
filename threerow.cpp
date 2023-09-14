#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// para que el compilador pueda llamar a estas funciones en main
void loop(char c[3][3]);
void enter_first(char c[3][3]);
void board(char c[3][3]);
void enter_my_values(char c[3][3]);
void enter_IA_values(char c[3][3]);
int winner(char c[3][3]);

int main()
{

    char c[3][3];

    loop(c); // llama a todas las funciones fundamentales y hace un refresco de pantalla

    return 0;
}

void loop(char c[3][3])
{
    int i,j;

    i = 0;
    enter_first(c);

    do
    {
        system("cls");
        board(c);
        if (i % 2 == 0)
        {
            enter_my_values(c);
        }
        else
        {
            enter_IA_values(c);
        }

        j = winner (c);
        i++;
    } while (i <= 9 && j == 2);

    if(j == 0){
        printf("\n\tits a Win!!!\n");
    }
    if(j == 1){
        printf("\n\tits a Lose!!!\n");
    }
    if(j == 2){
        printf("\n\tIts a tie!!!\n");
    }
}

void enter_first(char c[3][3]) // esta funcion contiene al bucle genera la matriz ( 1 2 3)
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
void enter_IA_values(char c[3][3])
{
    int i, j, k;

    srand(time(NULL));

    do
    {
        i = rand() % 3;
        j = rand() % 3;

    } while (c[i][j] == 'X' || c[i][j] == 'O');

    printf("\n\nturno de la IA :\n\n");
    c[i][j] = 'O';
}
void enter_my_values(char c[3][3])
{
    int i, j, k;
    char aux;
    do
    {
        do
        {
            printf("\ncoloca una ficha: ");
            fflush(stdin);
            scanf("%c", &aux);
        } while (aux < '1' || aux > '9');
        k = 0;
        switch (aux)
        {
        case '1':
        {
            i = 0;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }

        case '2':
        {
            i = 0;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '3':
        {
            i = 0;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '4':
        {
            i = 1;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '5':
        {
            i = 1;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '6':
        {
            i = 1;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '7':
        {
            i = 2;
            j = 0;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '8':
        {
            i = 2;
            j = 1;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        case '9':
        {
            i = 2;
            j = 2;
            if (c[i][j] == 'X' || c[i][j] == 'O')
            {
                k = 1;
                printf("La casilla está ocupada");
            }
            break;
        }
        }
    } while (k == 1);

    c[i][j] = 'X';
}
void board(char c[3][3]) // el bucle de esta función se encarga de iterar la matriz para imprimir sus valores
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j < 2)
            {
                printf(" %c |", c[i][j]);
            }
            else
            {
                printf(" %c ", c[i][j]);
            }
        }
        if (i < 2)
        {
            printf("\n-----------\n");
        }
    }
}
int winner(char c[3][3])
{
    if (c[0][0] == 'X' || c[0][0] == 'O')
    {
        if (c[0][0] == c[0][1] && c[0][0] == c[0][2])
        {
            if (c[0][0] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }

        if (c[0][0] == c[1][0] && c[0][0] == c[2][0])
        {
            if (c[0][0] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }
    }
    if (c[1][1] == 'X' || c[1][1] == 'O')
    {
        if (c[1][1] == c[0][1] && c[1][1] == c[2][1])
        {
            if (c[1][1] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }
        if (c[1][1] == c[1][0] && c[1][1] == c[1][2])
        {
            if (c[1][1] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }
        if (c[1][1] == c[0][0] && c[1][1] == c[2][2])
        {
            if (c[1][1] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }
        if (c[1][1] == c[0][2] && c[1][1] == c[2][0])
        {
            if (c[1][1] == 'X')
            {
                return 0; // he ganado
            }
            else
            {
                return 1;
            } // he perdido
        }
    }
    if (c[2][2] == 'X' || c[2][2] == 'O')
        {
            if (c[2][2] == c[0][2] && c[2][2] == c[1][2])
            {
                if (c[2][2] == 'X')
                {
                    return 0; // he ganado
                }
                else
                {
                    return 1;
                } // he perdido
            }
             if (c[2][2] == c[2][0] && c[2][2] == c[2][1])
            {
                if (c[2][2] == 'X')
                {
                    return 0; // he ganado
                }
                else
                {
                    return 1;
                } // he perdido
            }
        }
        return 2;
}
