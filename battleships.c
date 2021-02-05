#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    printf("BATTLESHIPS\n\n");

    char board [5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
        board [i][k] = 'O';
        }
    }

    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            printf("%c", board [j][k]);
        }
        printf("\n");
    }

    //generate a random number (between 0 and 5)
    srand((unsigned)time(NULL));
    int hidden_row = (rand() / ((double) RAND_MAX + 1)) * 5;
    //printf("%i\n", hidden_row);
    int hidden_col = (rand() / ((double) RAND_MAX + 1)) * 5;
    //printf("%i\n", hidden_col);

    for (int z = 10; z > 0; z--)
    {
        if (z > 1)
        {
            printf("\n%i guesses remaining\n\n", z);
        }

        if (z == 1)
        {
            printf("\n%i guess remaining\n\n", z);
        }

        int guess_row;
        int guess_col;
        int num_ok;
        char c;

        printf("Enter a row (between 1 and 5): ");
        num_ok = scanf("%d", &guess_row);
        if (num_ok != 1) 
        {
            scanf("%c", &c);
            printf("%c isn't a number, hambrain.\n\n", c);
            z++;
        } 
        else 
        {
            printf("Enter a column (between 1 and 5): ");
            num_ok = scanf("%d", &guess_col);
            if (num_ok != 1) 
            {
                scanf("%c", &c);
                printf("%c isn't a number, hambrain.\n\n", c);
                z++;
            } 
            else
            {
                if (guess_row > 5 || guess_col > 5 || guess_row < 1 || guess_col < 1)
                {
                    printf("\nRead the instructions, dickhead.\n\n");
                    z++;
                }
                else
                {
                    if (guess_row - 1 == hidden_row && guess_col - 1 == hidden_col)
                    {
                    printf("\nYou sunk my battleship!\n\n");
                    board[guess_row - 1][guess_col - 1] = 'X';
                    for (int j = 0; j < 5; j++)
                    {
                        for (int k = 0; k < 5; k++)
                        {
                            printf("%c", board [j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    break;
                    }
                    if (guess_row - 1 != hidden_row || guess_col -1 != hidden_col)
                    {
                        printf("\nMissed!\n\n");
                        board[guess_row - 1][guess_col - 1] = ' ';
                        for (int j = 0; j < 5; j++)
                        {
                            for (int k = 0; k < 5; k++)
                            {
                                printf("%c", board [j][k]);
                            }
                        printf("\n");
                        }
                        printf("\n");
                        if (z == 1)
                        {
                            printf("You lost!\n");
                        }
                    }
                }
            }
        }
    }
}