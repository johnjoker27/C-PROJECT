#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));


    int number = (rand() % 100) +1;
    int guess = 0 ;
    do
    {
        printf("Enter a guess: \n");
        scanf("%d",&guess);

        if (guess == number)
            printf("You got it:\')\'");
        else if (guess < number)
            printf("guess higher");
        else
            printf("Guess lower");
    }
    while (guess != number);
    return 0;
}
