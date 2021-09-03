#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int RockPaperScissor(char you , char comp)
{

    if(you == comp)       //Draw condition
    {
	return 0;
    }
    else if((you == 'R' && comp == 'S') || (you == 'S' && comp == 'P') || (you == 'P' && comp == 'R')) //win condition
    {
	return 1;
    }
    else   //lose condition
    {
	return -1;
    }
}

int main(){
    int t,number1, guess, nguesses = 1;
    int number, result;
    char you, comp, repeat,str[20];;
    printf("\n\n\nENTER YOUR NAME :\n\n\n");
    gets(str);
    printf("Hello %s,Welcome to the\n****GAME MANIA****\n",str);
    printf("Enter 1:Rock Paper Scissor and 2:Guess the Number\n");
    scanf("%d",&t);
    if(t==1){
        clrscr();
     do{
       textcolor(7);
       srand(time(0));
       number = rand() % 100 + 1;
					//DENOTE:: R:ROCK ,S:SCISSOR ,P:PAPER
       if(number < 33){
	   comp = 'R';
        }
       else if(number > 33 && number < 66){
	   comp = 'P';
        }
       else{
	   comp = 'S';
       }
       printf("Enter 'R' for Rock ,'S' for Scissor and 'P' for Paper : \n");
       fflush(stdin);	scanf("%c",&you);
 
       if(!(you == 'R' || you == 'P' || you == 'S')){
	    printf("Invalid input...");
       }
       else{
	  result = RockPaperScissor(you,comp);
	  printf("You have selected %c and computer has selected %c.\n",you,comp);

	  if(result == 1){
	    textcolor(10);
	    cprintf("Congratulations , you won!!\n");
	  }
	  else if(result == 0){
	    textcolor(14);
	    cprintf("Draw!\n");
	  }
	  else{
	    textcolor(12);
	    cprintf("You lost! Better luck next time!\n\n");
	  }
       }

       printf("\nWould you like to try again?\n(Enter 'Y' for Yes and 'N' for No) : ");
       fflush(stdin);
       scanf("%c",&repeat);
       if(repeat == 'Y')
       textcolor(7);
       clrscr();
     }while(repeat == 'Y');

     delay(1500);

    }
    else{
     srand(time(0));
     number1 = rand() % 100 + 1; //GENERATES A NUMBER BETWEEN1 TO 100
     
     //KEEP RUNNING THE LOOP UNTIL THE NUMBER IS GUESSED
     do{
         printf("Guess the number between 1 to 100\n");
         scanf("%d", &guess);
         if (guess > number1)
         {
             printf("LOWER NUMBER PLEASE!\n");
         }    
     else if (guess < number1)
     {
         printf("HIGHER NUMBER PLEASE\n");
     }
     else
     {
         printf("CONGRATS %s YOU HAVE GUESSED THE NUMBER IN %d ATTEMPTS\n",str, nguesses);
     }
     nguesses++;}
     while (guess != number1); 
     return 0;
    }
}
    