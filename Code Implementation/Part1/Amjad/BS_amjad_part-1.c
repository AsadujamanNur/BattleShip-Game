#include <stdio.h>
void starting();
void enterName1();
void enterName2();
void selectMode();
void selectDiff();


int main()
{
    starting();
    enterName1();
    selectMode();

    return 0;
}


void starting()

{
    printf ("WE WELCOME YOU TO OUR\n\n");
    printf ("XXXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX  XX  XX XX XXXXXX\n");
	printf ("XX  XX  XX  XX   XX     XX   XX     XX      XX     XX  XX XX XX  XX\n");
	printf ("XXXXXX  XX  XX   XX     XX   XX     XXXXXX  XXXXX  XXXXXX XX XXXXXX\n");
	printf ("XX  XX  XXXXXX   XX     XX   XX     XX         XX  XX  XX XX XX\n");
	printf ("XXXXXX  XX  XX   XX     XX   XXXXXX XXXXXX  XXXXX  XX  XX XX XX\n");
	printf ("\n");
	printf ("XXXXXX   XXXX    XXXXXXXXXXXX     XXXXXX   XX\n");
	printf ("XX      XX  XX   XX   XX   XX     XX       XX\n");
	printf ("XX  XX  XX  XX   XX   XX   XX     XXXXXX   XX\n");
	printf ("XX   X  XXXXXX   XX   XX   XX     XX\n");
	printf ("XXXXXX  XX  XX   XX   XX   XX     XXXXXX   XX\n");


	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.However each players uses his own computer and his own instance of this programme\n");
	printf ("2. Player will be prompted to select the initial formation of his ships\n");
	printf ("    for the game board \n");
	printf ("3. There are 6 types of formations to be placed \n");
	printf ("4. The ship grid is printed and user should select which goes first: himself or the opponent \n");
	printf ("5. The computer randomly selects where the next player's shot will hit(coordinates in GREEK)\n");
	printf ("6. When the enemy hits the player, user has to enter incoming shot coordinates(using GREEK letters)\n");
	printf ("7. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [*] hit and [X] miss\n");
	printf ("8. First player to guess the location of all ships wins\n\n");


}

void enterName1()
{
    printf ("\nPlease enter your name:");
    char name1 [100];
    scanf("%s", name1);
    printf("Hello %s! Welcome to the Battleship game! To defeat or to be defeated? That is your decision to choose!", name1);
}

void selectMode()
{
   int x;
   printf("\n\nDo you want to play as a single player or as multiple players?");
   printf("\nEnter the number \"1\" if you want to play as a single player and \"2\" as a multiple player");
   printf("\nPlease enter either \"1\" or \"2\" only!");
   printf("\nPlease enter your choice:");

   scanf("%d", &x);

   switch (x)
		{
    			case 1:
      			         selectDiff();
      			break;

	                case 2:
	                         enterName2();

                        break;


    			default:
    			        printf("\nThe number you enter in invalid");
    			        printf("\nPlease enter the right input");
    			        selectMode();

		}

}

 void enterName2()
{
    printf ("\nPlayer 2, please enter your name:");
    char name1 [100];
    scanf("%s", name1);
    printf("Hello %s! Welcome to the Battleship game! To defeat or to be defeated? That is your decision to choose!", name1);
}

void selectDiff()
{
    int y;

     printf("\nPlease choose your desired difficulty");
     printf("Enter the number \"1\" if you want to choose EASY mode and \"2\" for HARD mode");
     printf("Please enter either \"1\" or \"2\" only");
     printf("Please enter your desired difficulty level:");
     scanf("%d", &y);

     switch (y)
		{
    			case 1:
      			         printf("You're gonna play it easy");
      			break;

	                case 2:
	                          printf("You're gonna play it hard");

                        break;


    			default:
    			        printf("\nThe number you enter in invalid");
    			        printf("\nPlease enter the right input");
    			        selectDiff();

		}
}
