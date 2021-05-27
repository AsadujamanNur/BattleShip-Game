#include <stdio.h>
int main()
{
    //variables//
    int start_button;
    char start_button_mode_reply[]=" ______________________________________________________\n"
                                   "|           -------------------------------            |\n"
                                   "|          |                               |           |\n"
                                   "|          |          Select Mode          |           |\n"
                                   "|          |                               |           |\n"
                                   "|        --------------------------------------        |\n"
                                   "|       | Press '1' to Select Single PlyerMode |       |\n"
                                   "|       | Press '2' to Select MultiPlayerMode  |       |\n"
                                   "|        --------------------------------------        |\n"
                                   "|______________________________________________________|\n";

    char start_button_rules_reply[]=             " ______________________________________________________\n"
                                                 "|                                                      |\n"
                                                 "|               *************************              |\n"
                                                 "|               *      Rules Book       *              |\n"
                                                 "|               *************************              |\n"
                                                 "|                                                      |\n"
                                                 "|______________________________________________________|\n";


    char playerOne[120];





//beggining of the code//
                       //interface//
   puts("*************************************************");
   puts("*           Welcome to The warzone              *");
   puts("*                Ready your                     *");
   puts("*-----------------------------------------------*");
   puts("*                                               *");
   puts("*               BattleShip                      *");
   puts("*                                               *");
   puts("*                                               *");
   puts("*************************************************");

                      //MainMenu//

   puts(" _______________________________________________");
   puts("|                                               |");
   puts("|                                               |");
   puts("|                                               |");
   puts("|            'Press '1' to START'               |");
   puts("|         'Press '2' to See the Rules           |");
   puts("|                                               |");
   puts("|_______________________________________________|");


                   //taking Input from User//
   scanf("%d",&start_button);


                 //Making Decision based on Users input//
   if(start_button==1)
   {
       printf("Please Choose a Name for Player one Here:\n");
       scanf("%s",&playerOne);
       printf("Hallo '%s' Please choose your desired PlayingMode\n",playerOne);
       printf("%s",start_button_mode_reply);
   }
   else if(start_button==2)
   {
       printf("%s",start_button_rules_reply);
   }
   else
   {
       printf("you pushed the wrong button please follow the instructions\n");
   }

}
