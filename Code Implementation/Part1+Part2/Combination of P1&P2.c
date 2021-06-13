#include <stdio.h>
#define HORIZONTAL 1
#define VERTICAL 2


//All the functions that are being used in the game//


//The function for first phase//
void starting();    //shows start menu
void rulebook();    //shows the rules for the game
void playerTwo();   //this function is being used to store the profile for player two
void selectMode();  //this is where player can choose their desired playing mode "single or multi"
void selectDiff();  //this function is being used to determine the level of difficulties in the game
//End of the first phase//



//Beginning of the 2nd phase//
void printMap(char board [11][11]);             //The function for printing The map AKA Battle Ground//
int getDirection();                             //This function determines which direction the ships will be placed//
void getPosition(int* posx, int* posy);         //This function is used to get the position of the ships in the map Ex. A0//
void ship_with_five_box(char board [11][11]);   //The function represent the ships with 5 boxes which can be used 1x//
void ship_with_four_box(char board [11][11]);   //The function represent the ships with 4 boxes which can be used 2x//
void ship_with_three_box(char board [11][11]);  //The function represent the ships with 3 boxes which can be used 3x//
void ship_with_two_box(char board[11][11]);     //The function represent the ships with 2 boxes which can be used 4x//
void ship_placement(char board [11][11]);       //This function is combined with other functions from above which will determine the ships location on the map based on the given condition//
void preparation_phase();                       //Kinda like main function of 2nd phase,since it contains all the function of 2nd phase and being recall in the main function as "Preparation Phase"//
//End of the 2nd Phase//

int main()
{
  //Phase 1//
  starting();               //Shows the first interface or welcome screen//
  selectMode();             //To select the playing mode either Single or Multi//

  //phase 2//
  preparation_phase();      //Basically in this phase Players has to Place their ships on the battleground//

  return 0;
}


void starting()

{
    int start_button;       //to choose weather to start the game or see rules//
    char playerOne[120];    // To store name of player one//


                                    //WELCOME SCREEN//
   puts("*******************************************************************************");
   puts("*                        Welcome to The warzone                               *");
   puts("*                              Ready your                                     *");
   puts("*-----------------------------------------------------------------------------*");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*         XXXXXX XXXXXX XXXXXX XXXXXX XX     XXXXXX XXXXXX  XX  XX XX XXXXXX  *");
   puts("*         XX  XX XX  XX   XX     XX   XX     XX     XX      XX  XX XX XX  XX  *");
   puts("*         XXXXXX XX  XX   XX     XX   XX     XXXXXX XXXXXX  XXXXXX XX XXXXXX  *");
   puts("*         XX  XX XXXXXX   XX     XX   XX     XX         XX  XX  XX XX XX      *");
   puts("*         XXXXXX XX  XX   XX     XX   XXXXXX XXXXXX XXXXXX  XX  XX XX XX      *");
   puts("*                                                                             *");
   puts("*         XXXXXX XXXXXX XXXXXXXXXX XXXXXX XX                                  *");
   puts("*         XX     XX  XX XX  XX  XX XX     XX                                  *");
   puts("*         XX XXX XX  XX XX  XX  XX XXXXXX XX                                  *");
   puts("*         XX  XX XXXXXX XX  XX  XX XX                                         *");
   puts("*         XXXXXX XX  XX XX  XX  XX XXXXXX XX                                  *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |            'Press '1' to START'               |                 *");
   puts("*           |       'Press '2' to opem the Rule Book'       |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");

    scanf("%d",&start_button);  //input from user to make decision for next action//


                 //Making Decision based on Users input//
   if(start_button==1)
   {
       puts(" ");
       puts(" ");
       printf("****************************************************************************\n");
       printf("*             Please Choose a Name for Player one Here:                    *\n");
       printf("****************************************************************************\n");
       scanf("%s",&playerOne);
         puts(" ____________________________________________________________________________");
         puts("|                                                                            |");
       printf("|                           Hallo '%s'                                       |\n",playerOne);
         puts("|                                                                            |");
         puts("|               'Please choose your desired Playing Mode'                    |");
         puts("|                                                                            |");
         puts("|              'Against the Computer OR Against your Mate?'                  |");
         puts("|                                                                            |");
         puts("|____________________________________________________________________________|");
   }
   else if(start_button==2) //if user enter "2" it will open up the rule books//
   {
       rulebook();      //contains the rules for the game//
       puts("");
       puts("");

   }
   else     //shows an error massage and take back to the strating screen if user put anything other than "1" or "2"//
   {
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");

       starting();  //after showing the error massage it takes back to the "starting phase" again so that the user can choose the right Option//

   }

}
//end of "void starting ()//


void rulebook()     //shows the the rules and regulation for the game//
{

    int back_button;    //variable to store the reply input from user after showing him/her rules//


   puts(" __________________________________________________________________________________________________________________________________________________________");
   puts("|                                                                                                                                                          |");
   puts("|                                                           *************************                                                                      |");
   puts("|                                                           *      Rules Book       *                                                                      |");
   puts("|                                                           *************************                                                                      |");
   puts("|        1. This is a two player game. However, you can choose either to play it as a single player or as a multiple player                                |");
   puts("|           If the you choose to play as a single player, you will be playing against the computer itself                                                  |");
   puts("|           But if you choose to play as a multiple player, you will be playing against another player denoted as Player 2.                                |");
   puts("|        2. The battlefield is a 10x10 grid where you place your ships                                                                                     |");
   puts("|           The horizontal boxes are identified with numbers 1-10 and the vertical boxes are marked with letters a – j.                                    |");
   puts("|        3. You will be prompted to select the formation and position of your ships as you desired.                                                        |");
   puts("|        4. You can place your ships by entering its orientation, which are either horizontal or vertical                                                  |");
   puts("|           For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical.                                                      |");
   puts("|        5. There are 4 types of formations and a total of 10 ships to be placed by using  a coordinate system (x y)                                       |");
   puts("|           You need to place  4 ships over 2 boxes, 3 ships over 3 boxes, 2 ships over 4 boxes, 1 ship over 5 boxes.                                      |");
   puts("|        6. And its x y coordinates(both separated by a space) where x is the row number and y is the column number                                        |");
   puts("|        7. After placing your ships, the game begins as each player tries to guess the location of the enemy's ships and attack them                      |");
   puts("|           To attack a specific area, enter its x y coordinate(separated by a space).                                                                     |");
   puts("|        8. If your attack hits the enemy ship, it will be denoted by an 'H'. You also will get an extra turn. Same rules will be applied to your opponent |");
   puts("|        9. If your attack misses, it will be denoted by a '*' and your turn ends.                                                                         |");
   puts("|       10. First player to guess the location of all ships wins.                                                                                          |");
   puts("|                                                                                                                                                          |");
   puts("|__________________________________________________________________________________________________________________________________________________________|");


   puts("\n\nPlease press '1' to continue");
   scanf("%d",&back_button);
   if(back_button==1)
   {
   starting();      //after showing the rules user can go back to the starting phase again//
   }
   else             //if user choose anything rather than 1, this massage will show up and start from the begining//
   {
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser,press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");


       rulebook();      //after getting wrong input it takes back to the starting//
   }


}
//end of the Void rulebook()//


//beginning of the function SelectMode()//
void selectMode()
{
  int x;    //variable to store input from user which will be used to make decision whether to play single or multiplayer//

  // the interface stored in char which will guide the user to make selection//
  char start_button_mode_reply[]=  "\n****************************************************************************\n"
                                   "*                                                                          *\n"
                                   "*                     -------------------------------                      *\n"
                                   "*                    |                               |                     *\n"
                                   "*                    |          Select Mode          |                     *\n"
                                   "*                    |                               |                     *\n"
                                   "*                 ---------------------------------------                  *\n"
                                   "*                | Press '1' to Select Single PlayerMode |                 *\n"
                                   "*                | Press '2' to Select MultiPlayerMode   |                 *\n"
                                   "*                 ---------------------------------------                  *\n"
                                   "*                                                                          *\n"
                                   "*                                                                          *\n"
                                   "****************************************************************************\n";

  printf("%s",start_button_mode_reply);
  scanf("%d", &x);

  switch (x)    //making decision based on users input//

{
  case 1:       //if user choose "1" it will take him to the next stage, to select the difficulty level of the game//
      selectDiff();
  break;

  case 2:       //if user choose "2"(multiplayer) it will ask for player 2 name and continue with the game//
     playerTwo();
  break;


  default:      //if user put anything else other than what is mentioned in the menu, it will show the error massage and take back to the starting of this function//

       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser,press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");

       selectMode();    //takes back to the beginning of the function after showing the error massage//

}

}
//end of the function "selectMode"//

void playerTwo()
{
    char name2 [100];
    puts(" ");
       puts(" ");
       printf("****************************************************************************\n");
       printf("**********      Please Choose a Name for Player two Here:      *************\n");
       printf("****************************************************************************\n");

  scanf("%s", name2);
         puts(" ____________________________________________________________________________");
         puts("|                                                                            |");
         puts("|                                                                            |");
       printf("|                           Hallo '%s'                                      |\n",name2);
         puts("|                                                                            |");
         puts("|               'To Defeat or to be defeated is your choice                  |");
         puts("|                                                                            |");
         puts("|____________________________________________________________________________|");
}

void selectDiff()
{
    int y;

    puts("****************************************************************************");
    puts("*                                    *                                     *");
    puts("*    ____________________________    *     ____________________________    *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |            EASY            |   *    |            HARD            |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |         Press '1'          |   *    |         Press '2'          |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*                                    *                                     *");
    puts("*                                    *                                     *");
    puts("****************************************************************************");


    scanf("%d", &y);

switch (y)
{
case 1:
   puts("*******************************************************************************");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |        ('You're gonna play it easy')          |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");

break;

case 2:
   puts("*******************************************************************************");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |         ('You're gonna play it hard')         |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");

break;


default:
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

selectDiff();

}
}
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

        if (userInput[0] >= 'A' && userInput[0] <= 'J')
        {
            *posx = userInput[0] - 'A';
            correctCount++;
        }
        else if (userInput[0] >= 'a' && userInput[0] <= 'j')
        {
            *posx = userInput[0] - 'a';
            correctCount++;
        }
        if (userInput[1] >= '0' && userInput[1] <= '9')
        {
            *posy = userInput[1] - '0';
            correctCount++;
        }
        if (correctCount == 2)
        {
            isCorrect = 1;
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
       printf("*                 'PLEASE CHOOSE YOUR DESIRED SHIP'                        *\n");
       printf("*__________________________________________________________________________*\n");
       printf("*                                                                          *\n");
       printf("*                                                                          *\n");
       printf("*        PLEASE REMEMBER TO ONLY INSERT THE RIGHT NUMBERS OF SHIPS         *\n");
       printf("*                                                                          *\n");
       printf("*               ---------------------------------------                    *\n");
       printf("*              |  > PLACE ONLY 4 SHIPS OVER 2 BOXES <  |                   *\n");
       printf("*              |  > PLACE ONLY 3 SHIPS OVER 3 BOXES <  |                   *\n");
       printf("*              |  > PLACE ONLY 2 SHIPS OVER 4 BOXES <  |                   *\n");
       printf("*              |  > PLACE ONLY 1 SHIP  OVER 5 BOXES <  |                   *\n");
       printf("*               ---------------------------------------                    *\n");
       printf("*                                                                          *\n");
       printf("****************************************************************************\n");
       puts("");
       puts("");






    puts("****************************************************************************");
    puts("* __________________________________ * __________________________________  *");
    puts("*|                                  |*|                                  | *");
    puts("*|         Ships with 2 boxes       |*|           Ships with 3 boxes     | *");
    puts("*|__________________________________|*|__________________________________| *");
    puts("*|                                  |*|                                  | *");
    puts("*|          PLEASE ENTER '2'        |*|           PLEASE ENTER '3'       | *");
    puts("*|__________________________________|*|__________________________________| *");
    puts("****************************************************************************");
    puts("* __________________________________ * __________________________________  *");
    puts("*|                                  |*|                                  | *");
    puts("*|        Ships with 4 boxes        |*|         Ships with 5 boxes       | *");
    puts("*|__________________________________|*|__________________________________| *");
    puts("*|                                  |*|                                  | *");
    puts("*|          PLEASE ENTER '4'        |*|          PLEASE ENTER '5'        | *");
    puts("*|__________________________________|*|__________________________________| *");
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

void preparation_phase()
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
    for(int i=0;i<4;i++)
    {
   ship_placement(board);
    printMap(board);
    }
}

