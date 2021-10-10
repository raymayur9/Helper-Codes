#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int resUser = 0;
int resComp = 0;
void compare(char name[], int user, int comp)
{
    int a;
    if (comp == 0)
    {
        printf("Computer's turn : Rock\n");
        if (user == 0)
        {
            a = 0;
        }
        else if (user == 1)
        {
            a = 1;
        }
        else
        {
            a = -1;
        }
    }
    else if (comp == 1)
    {
        printf("Computer's turn : Paper\n");
        if (user == 0)
        {
            a = -1;
        }
        else if (user == 1)
        {
            a = 0;
        }
        else
        {
            a = 1;
        }
    }
    else
    {
        printf("Computer's turn : Scissor\n");
        if (user == 0)
        {
            a = 1;
        }
        else if (user == 1)
        {
            a = -1;
        }
        else
        {
            a = 0;
        }
    }
    if (a == 0)
    {
        printf("Result : Draw.\n");
    }
    else if (a == 1)
    {
        printf("Result : %s wins.\n", name);
        resUser++;
    }
    else
    {
        printf("Result : Computer wins.\n");
        resComp++;
    }
}
int main()
{
    printf("\nWelcome to Rock - Paper - Scissor game. \nPlease enter your name : ");
    char name[20];
    scanf("%s", name);
    printf("\nThere will be 3 rounds. Whoever gets the maximum points, wins the game.\nInput format :\nEnter 0 for ROCK.\nEnter 1 for PAPER.\nEnter 2 for SCISSOR.\n");
    resComp = 0;
    resUser = 0;
    for (int T = 0; T < 3; T++)
    {
        printf("\n%s's turn : ", name);
        int input;
        scanf("%d", &input);
        srand(time(NULL));
        int comp_turn = rand() % 3;
        compare(name, input, comp_turn);
    }
    printf("\nFinal result : \n%s : %d\nComputer : %d\n", name, resUser, resComp);
    if (resUser == resComp)
    {
        printf("It is draw.\n");
    }
    else if (resUser > resComp)
    {
        printf("%s wins the game.\n", name);
    }
    else
    {
        printf("Computer wins the game.\n");
    }
    printf("\nDo you want to play again?\nYES - Enter 1\nNO - Enter 0\n");
    int recurse;
    scanf("%d", &recurse);
    if (recurse == 1)
    {
        main();
    }
    else
    {
        printf("Will see you again next time.");
    }

    return 0;
}
