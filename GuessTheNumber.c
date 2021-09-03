#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int main()
{   char str[20];
    printf("\n\n\nENTER YOUR NAME :\n\n\n");
    gets(str);
    
    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1; //GENERATES A NUMBER BETWEEN1 TO 100
    
    //KEEP RUNNING THE LOOP UNTIL THE NUMBER IS GUESSED
    do{
        printf("Guess the number between 1 to 100\n");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("LOWER NUMBER PLEASE!\n");
        }    
    else if (guess < number)
    {
        printf("HIGHER NUMBER PLEASE\n");
    }
    else
    {
        printf("CONGRATS %s YOU HAVE GUESSED THE NUMBER IN %d ATTEMPTS\n",str, nguesses);
    }
    nguesses++;}
    while (guess != number); 
    getch();
    return 0;
}
