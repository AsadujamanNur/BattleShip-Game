#include <stdio.h>

#define HORIZONTAL 1
#define VERTICAL 2

void printMap(char board[11][11])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
}

int getDirection()
{
    int isCorrect = 0;
    int direction = -1;
    do
    {
    puts("****************************************************************************");
    puts("*                                    *                                     *");
    puts("*    ____________________________    *     ____________________________    *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |        HORIZONTAL          |   *    |         VERTICAL           |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |         Press '1'          |   *    |         Press '2'          |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*                                    *                                     *");
    puts("*                                    *                                     *");
    puts("****************************************************************************");

        //printf("\n1 .Horizontal   \n2. Vertical ");
        scanf("%d", &direction);
        if(direction == 1 || direction == 2)
            isCorrect = 1;
        else
            printf("\nYou suck looser, choose the right option. ");
    } while (!isCorrect);
    return direction;
}

void getPosition(int* posx, int* posy)
{
    char userInput[20];
    int isCorrect = 0;
    do
    {
        int correctCount = 0;
        printf("Enter position. ");
        scanf("%s", &userInput);
        if(userInput[0] >= 'A' && userInput[0] <= 'J')
        {
            *posx = userInput[0] - 'A';
            correctCount++;
        } else if (userInput[0] >= 'a' && userInput[0] <= 'j')
        {
            *posx = userInput[0] - 'a';
            correctCount++;
        }
        if (userInput[1] >= '0' && userInput[1] <= '9')
        {
            *posy = userInput[1] - '0';
            correctCount++;
        }
        if(correctCount == 2)
        {
            isCorrect = 1;
        } else
        {
            printf("\nYou suck looser, choose the right option. ");
        }

    } while (!isCorrect);

}
void ship_with_five_box(char board [11][11])
{
    int direction = getDirection();
    int posx, posy;
    getPosition(&posx, &posy);
    if(direction == HORIZONTAL)
    {
        for(int i = 0; i < 5; i++)
            board[posx + 1 ][posy + 1 + i] = '*';
    }
    if(direction == VERTICAL)
    {
        for(int i = 0; i < 5; i++)
            board[posx + 1 + i][posy + 1] = '*';
    }

}

void ship_with_four_box(char board [11][11])
{
        int direction = getDirection();
    int posx, posy;
    getPosition(&posx, &posy);
    if(direction == HORIZONTAL)
    {
        for(int i = 0; i < 4; i++)
            board[posx + 1 ][posy + 1 + i] = '*';
    }
    if(direction == VERTICAL)
    {
        for(int i = 0; i < 4; i++)
            board[posx + 1 + i][posy + 1] = '*';
    }

}

void ship_with_three_box(char board [11][11])
{
    int direction = getDirection();
    int posx, posy;
    getPosition(&posx, &posy);
    if(direction == HORIZONTAL)
    {
        for(int i = 0; i < 3; i++)
            board[posx + 1 ][posy + 1 + i] = '*';
    }
    if(direction == VERTICAL)
    {
        for(int i = 0; i < 3; i++)
            board[posx + 1 + i][posy + 1] = '*';
    }

}

void ship_with_two_box(char board[11][11])
{
    int direction = getDirection();
    int posx, posy;
    getPosition(&posx, &posy);
    if(direction == HORIZONTAL)
    {
        for(int i = 0; i < 2; i++)
            board[posx + 1 ][posy + 1 + i] = '*';
    }
    if(direction == VERTICAL)
    {
        for(int i = 0; i < 2; i++)
            board[posx + 1 + i][posy + 1] = '*';
    }

}



void ship_placement(char board [11][11])
{

int ship_number;

       puts("");
       puts("");
       printf("****************************************************************************\n");
       printf("*                   PLEASE CHOOSE YOUR DESIRED SHIP                        *\n");
       printf("*__________________________________________________________________________*\n");
       printf("*                                                                          *\n");
       printf("*        PLEASE REMEMBER TO ONLY INSERT THE RIGHT NUMBERS OF SHIPS         *\n");
       printf("*                                                                          *\n");
       printf("*        1. PLACE ONLY 4 SHIPS OVER 2 BOXES                                *\n");
       printf("*        2. PLACE ONLY 3 SHIPS OVER 3 BOXES                                *\n");
       printf("*        2. PLACE ONLY 2 SHIPS OVER 4 BOXES                                *\n");
       printf("*        2. PLACE ONLY 1 SHIP OVER 1 BOX                                   *\n");
       printf("*                                                                          *\n");
       printf("****************************************************************************\n");
       puts("");
       puts("");

    
       
       
       
       
    puts("****************************************************************************");
    puts("*                                    *                                     *");
    puts("* __________________________________ * __________________________________  *");
    puts("*                                    *                                     *");
    puts("*         Ships with 2 boxes         *           Ships with 3 boxes        *");
    puts("* __________________________________ * __________________________________  *");
    puts("*                                    *                                     *");
    puts("*          PLEASE ENTER '2'          *           PLEASE ENTER '3'          *");
    puts("*                                    *                                     *");
    puts("****************************************************************************");
    puts("*                                    *                                     *");
    puts("* __________________________________ *  __________________________________ *");
    puts("*                                    *                                     *");
    puts("*         Ships with 4 boxes         *          Ships with 5 boxes         *");
    puts("* __________________________________ *  __________________________________ *");
    puts("*                                    *                                     *");
    puts("*          PLEASE ENTER '4'          *           PLEASE ENTER '4'          *");
    puts("*                                    *                                     *");
    puts("****************************************************************************");



    scanf("%d",&ship_number);



    if(ship_number==2)
    {
        for(int i=0;i<4;i++)
        {
        ship_with_two_box(board);
        printMap(board);
        puts("Please choose your next ship position: ");
        }
    }
    else if(ship_number==3)
    {
        for(int i=0;i<3;i++)
        {
        ship_with_three_box(board);
        printMap(board);
        puts("Please choose your next ship position: ");
        }

    }
    else if(ship_number==4)
    {
        for(int i=0;i<2;i++)
        {
        ship_with_four_box(board);
        printMap(board);
        puts("Please choose your next ship position: ");
        }
    }
    else if (ship_number==5)
    {
        ship_with_five_box(board);
    }
    else
    {

       puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");

        ship_placement(board);
    }
}

int main()
{
    char board[11][11];
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            board[i][j] = ' ';
        }
    }
    board[0][0] = '&';

    for (int i = 1; i < 11; i++)
    {
        board[i][0] = 'A' + i - 1;
        board[0][i] = '0' + i - 1;
    }

       puts("");
       printf("****************************************************************************\n");
       printf("*                      HERE IS YOUR BATTLEGROUND                           *\n");
       printf("****************************************************************************\n");
       puts("");
       puts("");


    printMap(board);
    for(int i=0;i<9;i++)
    {
   ship_placement(board);
    printMap(board);
    }
}
