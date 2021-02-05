#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool isabcd(char x);
int main(void)
{
    char guess[4];
    int hidden[5];
    char code[4];
    int right_letter;
    int right_position;

    //generate hidden code
    srand((unsigned)time(NULL));
    for (int j = 0; j < 5; j++)
    {
        hidden [j] = (rand() / ((double) RAND_MAX + 1)) * 4;
        //printf("%i\n", hidden[j]);
    }

    for (int k = 10; k > 0; k--)
    { 
        for (int j = 1; j < 5; j++)
        {
            if (hidden[j] == 0)
            {
                code[j - 1] = 'a';
            }
            else if (hidden[j] == 1)
            {
                code[j - 1] = 'b';
            }
            else if (hidden[j] == 2)
            {
                code[j - 1] = 'c';
            }
            else if (hidden[j] == 3)
            {
                code[j - 1] = 'd';
            }
           // printf("%c\n", code[j - 1]);
        }

        if (k > 1)
        {
            printf("\n%i guesses remaining\n\n", k);
        }

        if (k == 1)
        {
            printf("\n%i guess remaining\n\n", k);
        }
        
        printf("Guess: ");
        fgets(guess, 5, stdin);

        //check that guess is valid -- not finished
        if(isabcd(guess [0]) && isabcd(guess[1]) && isabcd(guess[2]) && isabcd(guess[3]))

        {
            right_letter = 0;
            right_position = 0;

            for (int l = 0; l < 4; l++)
            {
                if (guess[l] == code[l])
                {
                    right_position++;
                    guess[l] = 'e';
                    code[l] = 'f';
                }
            }

            for (int l = 0; l < 4; l++)
            {
                for (int q = 0; q < 4; q++)
                {
                    if (guess[l] == code[q])
                    {
                        right_letter++;
                        guess[l] = 'e';
                        code[q] = 'f';
                    }
                }
                
            }
        

        printf("\nRight letter, right position: %i\n", right_position);
        printf("Right letter, wrong position: %i\n\n", right_letter);

        if (right_position == 4)
        {
            printf("You win!\n");
            break;
            return 0;
        }

        else if (k == 1)
        {
            
            for (int j = 1; j < 5; j++)
            {
            if (hidden[j] == 0)
            {
                code[j - 1] = 'a';
            }
            else if (hidden[j] == 1)
            {
                code[j - 1] = 'b';
            }
            else if (hidden[j] == 2)
            {
                code[j - 1] = 'c';
            }
            else if (hidden[j] == 3)
            {
                code[j - 1] = 'd';
            }
            //printf("%c\n", code[j - 1]);    
            }

            printf("You lost!\n\n");
            printf("Answer: %c%c%c%c\n", code[0], code[1], code[2], code[3]);
        }

        }

        else
        {
                        
            printf("invalid guess\n\n");
            k++;
            
        }

        //gets rid of \n from fgets so doesn't skip the next turn
        fgetc(stdin);

    }

    
    return(0);
}

bool isabcd (char x)
{
    if (x == 'a' || x == 'b' || x == 'c' || x == 'd')
    {
        return true;
    }
    return false;
}