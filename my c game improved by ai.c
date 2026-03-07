#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char username[50];
    int difficulty;
    int decision;

    srand(time(NULL));

    printf("=====================================\n");
    printf("WELCOME TO THE NUMBER GUESSING GAME\n");
    printf("=====================================\n");

    printf("Enter your username: ");
    scanf("%49s", username);

    printf("\nChoose a difficulty:\n");
    printf("1 - Easy\n");
    printf("2 - Intermediate\n");
    printf("3 - SUFFERING MODE 😈\n");
    scanf("%d", &difficulty);

    printf("\nHello %s\n", username);

    printf("Enter 1 to start or 2 to quit: ");
    
    scanf("%d", &decision);

    if(decision == 2)
    {
        printf("Closing program...\n");
        return 0;
    }

    switch(difficulty)
    {

    /* ---------------- EASY MODE ---------------- */

    case 1:
    {
        int number = rand()%100 + 1;
        int guess;
        int attempts = 0;

        printf("\nEASY MODE\n");
        printf("Guess the number between 1 and 100\n");

        do
        {
            printf("Enter guess: ");
            scanf("%d",&guess);

            attempts++;

            if(guess > number)
                printf("Too high!\n");

            else if(guess < number)
                printf("Too low!\n");

        }while(guess != number);

        printf("\nCorrect! You guessed it in %d attempts.\n", attempts);
        break;
    }

    /* ---------------- INTERMEDIATE MODE ---------------- */

    case 2:
    {
        int num1 = rand()%100 + 1;
        int num2 = rand()%100 + 1;

        int guess1, guess2;
        int attempts = 0;

        printf("\nINTERMEDIATE MODE\n");
        printf("Guess TWO numbers between 1 and 100\n");

        while(1)
        {
            printf("\nEnter two guesses: ");
            scanf("%d %d", &guess1, &guess2);

            attempts++;

            int correct = 0;

            if(guess1 == num1)
                correct++;

            if(guess2 == num2)
                correct++;

            if(correct == 2)
                break;

            printf("You got %d number(s) correct.\n", correct);

            if(guess1 != num1)
            {
                if(guess1 > num1)
                    printf("First number too high.\n");
                else
                    printf("First number too low.\n");
            }

            if(guess2 != num2)
            {
                if(guess2 > num2)
                    printf("Second number too high.\n");
                else
                    printf("Second number too low.\n");
            }
        }

        printf("\nYou guessed both numbers in %d attempts!\n", attempts);
        break;
    }

    /* ---------------- SUFFERING MODE ---------------- */

    case 3:
    {
        int num1 = rand()%1000 + 1;
        int num2 = rand()%1000 + 1;
        int num3 = rand()%1000 + 1;

        int guess1, guess2, guess3;
        int attempts = 5;

        char *insults[] =
        {
            "That guess hurt my processor.",
            "I've seen rocks guess better.",
            "You are embarrassing yourself.",
            "Try using your brain next time.",
            "The computer feels bad for you."
        };

        printf("\n=============================\n");
        printf("WELCOME TO SUFFERING MODE 😈\n");
        printf("=============================\n");
        printf("Guess THREE numbers between 1 and 1000\n");
        printf("You only have 5 attempts.\n");
        printf("Hints may lie. Numbers may change.\n");
        printf("Good luck.\n\n");

        while(attempts > 0)
        {
            printf("\nEnter three numbers: ");
            scanf("%d %d %d", &guess1, &guess2, &guess3);

            attempts--;

            int correct = 0;

            if(guess1 == num1) correct++;
            if(guess2 == num2) correct++;
            if(guess3 == num3) correct++;

            if(correct == 3)
            {
                printf("\nIMPOSSIBLE... YOU WON.\n");
                break;
            }

            printf("You got %d number(s) correct.\n", correct);

            /* Evil lying hints */

            if(rand()%3 == 0)
            {
                printf("Hint: Something was too high...\n");
            }
            else
            {
                if(guess1 > num1 || guess2 > num2 || guess3 > num3)
                    printf("Hint: One number might be too high.\n");
                else
                    printf("Hint: One number might be too low.\n");
            }

            /* Random insult */

            printf("%s\n", insults[rand()%5]);

            /* Random number shift */

            if(rand()%4 == 0)
            {
                int change = rand()%3;

                if(change == 0)
                    num1 = rand()%1000 + 1;

                else if(change == 1)
                    num2 = rand()%1000 + 1;

                else
                    num3 = rand()%1000 + 1;

                printf("⚠ Reality has shifted... one number changed.\n");
            }

            printf("Attempts remaining: %d\n", attempts);
        }

        if(attempts == 0)
        {
            printf("\nYou lost.\n");
            printf("The numbers were: %d %d %d\n", num1, num2, num3);
        }

        break;
    }

    default:
        printf("Invalid difficulty.\n");
    }

    printf("\nThanks for playing, %s!\n", username);

    return 0;
}