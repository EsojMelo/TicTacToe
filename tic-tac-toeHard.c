#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define size 3

void printFrame(char frame[size][size]);
int checkWinner(char frame[size][size], char simbol);
int checkFrame(char frame[size][size], char simbol);
void printFrame(char frame[size][size]);
void randComputer(char frame[size][size], int count);

int main(void)
{
    int l, c, line, column, player = rand() % 2, counter;
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

            if (player == 1)
            {
                do
                {

                    printf("\nPLAYER : Type a line and column to put a circle: ");   
                    scanf("%d%d", &line, &column);
            
                }while (line < 0 || line > 2 || column < 0 || column > 2 || frame[line][column] != ' ');

                frame[line][column] = 'O';
                player ++;
            }

            else
            {
                if (checkFrame(frame, 'X') != 1)
                    checkFrame(frame, 'X');
                else if (checkFrame(frame, 'O') != 1)
                    checkFrame(frame, 'O');
                else
                    randComputer(frame, counter);
                player = 1;             
            }

            if (checkWinner(frame,'O') == 1)
            {
                printf("\n\n           The player wins!");
                printFrame(frame);
                counter = 10;    
            }
            if (checkWinner(frame,'X') == 1)
            { 
                printf("\n\n           The PC wins!");
                printFrame(frame);
                counter = 10;
            }
            counter ++;

        }while(counter < 9 || counter == 10 );
        
        if (counter == 9)
        {
            printf("\n          DRAW\n");
            printFrame(frame);
        }

        do
        {
            printf("\nDo you want try again? (y - continue | n - exit) ? ");
            scanf("%c", &stop);
            stop = tolower(stop);

        }while(stop != 'y' && stop != 'n');

    }while (stop == 'y');

    printf("\n        THANKS FOR PLAYING");

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
                printf("     %d", l);
            }
            if (c == 0)
            {
                printf("\t");
            }
            printf("  %c  ", frame[l][c]);
            if (c < 2)
            {
                printf("|");
            }
            
        }
        if (l < 2)
        {  
            printf("\n\t-----------------");
        }
        printf("\n");

    }
}

void randComputer(char frame[size][size], int count)
{
    int c, l, choose = rand() % 2, choose2 = rand() % 4;

    if (count == 0)
    {
        if (choose == 0)
        {
            frame[1][1] = 'X';
        }
        else
        {
            if (choose2 == 0)
                frame[0][0] = 'X';
            if (choose2 == 1)
                frame[0][2] = 'X';
            if (choose2 == 2)
                frame[2][0] = 'X';
            if (choose2 == 3)
                frame[2][2] = 'X';
        } 
    }

    if (count == 1)
    {
        if (frame[1][1] == 'O')
        {
            if (choose2 == 0)
                frame[0][0] = 'X';
            if (choose2 == 1)
                frame[0][2] = 'X';
            if (choose2 == 2)
                frame[2][0] = 'X';
            if (choose2 == 3)
                frame[2][2] = 'X';
        }
        else
        {
            frame[1][1] = 'X';
        }
            
    }
    
    if (count > 1)
    {
        do
        {
            c = rand() % 3;
            l = rand() % 3;

        } while (frame[c][l] != ' ');
        frame[c][l] = 'X';
    }
}


int checkFrame(char frame[size][size], char simbol)
{   
    int stop = 0;

    for (int i = 0; i < 3; i++)
    {
        
        if (frame[i][0] == ' ' && frame[i][1] == simbol && frame[i][2] == simbol) //HORIZONTAL 1
        {
            frame[i][0] = 'X';
            break;
        }
        else if (frame[0][i] == ' ' && frame[1][i] == simbol && frame[2][i] == simbol) // VERTICAL 1
        {
            frame[0][i] = 'X';
            break;
        }
        

        else if (frame[i][0] == simbol && frame[i][1] == ' ' && frame[i][2] == simbol)//HORIZONTAL 2
        {
            frame[i][1] = 'X';
            break;   
        }
        else if (frame[0][i] == simbol && frame[1][i] == ' ' && frame[2][i] == simbol)// VERTICAL 2
        {
            frame[1][i] = 'X';
            break;
        }


        else if (frame[i][0] == simbol && frame[i][1] == simbol && frame[i][2] == ' ')//HORIZONTAL 3
        {
            frame[i][2] = 'X';
            break;
        }
        else if (frame[0][i] == simbol && frame[1][i] == simbol && frame[2][i] == ' ')// VERTICAL 3
        {
            frame[2][i] = 'X';
            break;
        }
        

        else if (frame[0][0] == ' ' && frame[1][1] == simbol && frame[2][2] == simbol) //DIAGONAL 1 - 1
        {
            frame[0][0] = 'X';
            break;
        }
        else if (frame[2][0] == ' ' && frame[1][1] == simbol && frame[0][2] == simbol) //DIAGONAL 2 - 1
        {
            frame[2][0] = 'X';
            break;
        }


        else if (frame[0][0] == simbol && frame[1][1] == ' ' && frame[2][2] == simbol) //DIAGONAL 1 - 2
        {
            frame[1][1] = 'X';
            break;
        }
        else if (frame[2][0] == simbol && frame[1][1] == ' ' && frame[0][2] == simbol) //DIAGONAL 2 - 2
        {
            frame[1][1] = 'X';
            break;
        }


        else if (frame[0][0] == simbol && frame[1][1] == simbol && frame[2][2] == ' ') //DIAGONAL 1 - 3
        {
            frame[2][2] = 'X';
            break;
        }
        else if (frame[2][0] == simbol && frame[1][1] == simbol && frame[0][2] == ' ') //DIAGONAL 2 - 3
        {
            frame[0][2] = 'X';
            break;
        }
        stop ++;   
    }

    if (stop > 2)
    {
        return 1;
    }
}



int checkWinner(char frame[size][size], char simbol)
{
    if((frame[0][0] == simbol && frame[0][1] == simbol && frame[0][2] == simbol) ||
    (frame[1][0] == simbol && frame[1][1] == simbol && frame[1][2] == simbol) ||
    (frame[2][0] == simbol && frame[2][1] == simbol && frame[2][2] == simbol) ||
    (frame[0][0] == simbol && frame[1][1] == simbol && frame[2][2] == simbol) ||
    (frame[0][2] == simbol && frame[1][1] == simbol && frame[2][0] == simbol) ||
    (frame[0][0] == simbol && frame[1][0] == simbol && frame[2][0] == simbol) ||
    (frame[0][1] == simbol && frame[1][1] == simbol && frame[2][1] == simbol) ||
    (frame[0][2] == simbol && frame[1][2] == simbol && frame[2][2] == simbol))
    {
        return 1;
    }
}


