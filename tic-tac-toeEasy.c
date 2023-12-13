#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define size 3

void printFrame(char frame[size][size]);

int main(void)
{
    int l, c, line, column, player = 1, counter;
    char frame[size][size], stop = 'y';
    srand(time(NULL));

    printf("Instructions to play:\n"
    "choose a line and column to put on coordinates\n"
    "For exemplo >> PLAYER : Type a line and column to put a circle: 1 2\n"
    "Remember to put space between line and column\n"
    "Dont worry if you put a invalid value, the program will ask again\n");

    do
    {
        counter = 0;
        for(l = 0; l < 3; l++)
        {   
            for (c = 0; c < 3; c++)
            {
                frame[l][c] = ' ';
            }   
        }

        do
        {
            printFrame(frame);

            do
            {
                if (player == 1)
                {
                    printf("\nPLAYER : Type a line and column to put a circle: ");   
                    scanf("%d%d", &line, &column);
                }

                else if (frame[1][1] == ' ')
                {
                    line = 1;
                    column = 1;
                }
            
                else
                {   
                    line = rand() % 3;
                    column = rand() % 3;
                }
            
            }while (line < 0 || line > 2 || column < 0 || column > 2 || frame[line][column] != ' ');

            if (player == 1)
            {
                frame[line][column] = 'O';
                player ++;
            }

            else
            {
                printf("\nThe PC choosed >> line: %d | column: %d\n", line, column);
                frame[line][column] = 'X';
                player = 1;    
            }
        
            if ((frame[0][0] == 'O' && frame[0][1] == 'O' && frame[0][2] == 'O') || (frame[1][0] == 'O' && frame[1][1] == 'O' && frame[1][2] == 'O') || (frame[2][0] == 'O' && frame[2][1] == 'O' && frame[2][2] == 'O') || (frame[0][0] == 'O' && frame[1][1] == 'O' && frame[2][2] == 'O') || (frame[0][2] == 'O' && frame[1][1] == 'O' && frame[2][0]=='O') || (frame[0][0] == 'O' && frame[1][0] == 'O' && frame[2][0]=='O')|| (frame[0][1] == 'O' && frame[1][1] == 'O' && frame[2][1] == 'O') || (frame[0][2] == 'O' && frame[1][2] == 'O' && frame[2][2] == 'O'))
            {
                
                printf("\nThe player wins!");
                printFrame(frame);
                counter = 10;
            }

            if ((frame[0][0] == 'X' && frame[0][1] == 'X' && frame[0][2] == 'X') || (frame[1][0] == 'X' && frame[1][1] == 'X' && frame[1][2] == 'X') || (frame[2][0] == 'X' && frame[2][1] == 'X' && frame[2][2] == 'X') || (frame[0][0] == 'X' && frame[1][1] == 'X' && frame[2][2] == 'X') || (frame[0][2] == 'X' && frame[1][1] == 'X' && frame[2][0] == 'X') || (frame[0][0] == 'X' && frame[1][0] == 'X' && frame[2][0] == 'X') || (frame[0][1] == 'X' && frame[1][1] == 'X' && frame[2][1] == 'X') || (frame[0][2] == 'X' && frame[1][2] == 'X' && frame[2][2] == 'X'))
            {
                printf("\nThe PC wins!");
                printFrame(frame);
                counter = 10;
            }

            counter ++;

        }while(counter < 9 || counter == 10 );
        
        if (counter == 9)
        {
            printf("\nDRAW\n");
            printFrame(frame);
        }

        do
        {
            printf("\nDo you want try again? (y - continue | n - exit) ? ");
            scanf("%c", &stop);
            stop = tolower(stop);

        }while(stop != 'y' && stop != 'n');

    }while (stop == 'y');

    printf("THANKS FOR PLAYING");

    return EXIT_SUCCESS;
}


void printFrame(char frame[size][size])
{
    int c, l;

    printf("\n\t 0      1      2\n\n");
    for(l = 0; l < 3; l++)
    {   
        for (c = 0; c < 3; c++)
        {
            if (c == 0)
            {
                printf("\t");
            }
            printf("  %c  ", frame[l][c]);
            if (c < 2)
            {
                printf("|");
            }
            if (c == 2)
            {
                printf("  %d", l);
            }
            
        }
        if (l < 2)
        {  
            printf("\n\t-----------------");
        }
        printf("\n");

    }
}
