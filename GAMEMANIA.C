#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int RockPaperScissor(char you , char comp)
{
    if(you == comp)       //Draw condition
    {
	return 0;
    }
    else if((you == 'R' && comp == 'S') || (you == 'S' && comp == 'P') 
    || (you == 'P' && comp == 'R')) 
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
    int number, result, point=0, games=0;
    char you, comp, repeat,str[20];
    clrscr();
    gotoxy(32,1); printf("======GAME MANIA======");
    printf("\n\nEnter your name : ");
    gets(str);
    printf("\nHello %s, Welcome to Game Mania!",str);
    printf("\n\nGames available : "); textcolor(14); cprintf("1) Rock-Paper-Scissor");
    printf("\n\t\t");  textcolor(13); cprintf("  2) Witch of the wood's conundrum"); textcolor(7);
    printf("\n\nPlease enter your game of choice : ");
    scanf("%d",&t);

    if(t==1){
        clrscr();
     do{
       textcolor(7);
       srand(time(0));  //seeding an everchanging number to rand function , i.e the system time.
       number = rand() % 100 + 1;

       if(number < 33){         //Denotion:: R:Rock, S:Scissor, P:Paper
	   comp = 'R';
	}
       else if(number > 33 && number < 66){
	   comp = 'P';
	}
       else{
	   comp = 'S';
       }

       printf("Enter 'R' for Rock ,'S' for Scissor and 'P' for Paper : \n");
       fflush(stdin);
       scanf("%c",&you);

       if(!(you == 'R' || you == 'P' || you == 'S')){
	    printf("Invalid input...");
       }
       else{
	  result = RockPaperScissor(you,comp);
	  printf("You have selected "); textcolor(11); cprintf("%c",you); printf(" and computer has selected "); textcolor(13); cprintf("%c.",comp);

	  if(result == 1){
	    textcolor(10);	printf("\n");	cprintf("Congratulations , you won!!\n");
	    point++;
	  }
	  else if(result == 0){
	    textcolor(14);	printf("\n"); 	cprintf("Draw!\n");
	  }
	  else{
	    textcolor(12);	printf("\n");	cprintf("You lost! Better luck next time!");
	  }
       }

       printf("\nWould you like to try again?\n(Enter 'Y' for Yes and 'N' for No) : ");
       fflush(stdin);
       scanf("%c",&repeat);
       if(repeat == 'Y')
       {
	   textcolor(7);
	   clrscr();
       }
       games++;
     }while(repeat == 'Y');

     printf("\n%s, you won %d points in %d games!\n",str,point,games); //Final Result
     printf("Thank you for playing!\n");
     delay(3000);
    }
    else{
     clrscr();
     srand(time(0));
     number1 = rand() % 100 + 1; //Generates a number between 1 to 100 ( +1 is used to avoid 0)
     //Keep running the loop until the number is guessed
     printf("Witch : I see you've stumbled upon my humble abode in these woods...\n");
     printf("\tHumor me while you're here, guess what number do I think in my mind");
     textcolor(11); printf("\n\n"); cprintf("Game : Guess a number between 1 to 100 : ");

     do{
	 if(nguesses != 1)
	 printf("\n\nGuess a number between 1 to 100 : ");
	 scanf("%d", &guess);
	 if (guess > number1)
	 {
	     textcolor(12); printf("Witch : Not quite child, focus your sight on a number"); cprintf(" Lower ");
	 }
     else if (guess < number1)
     {
	 textcolor(14); printf("Witch : Not quite child, focus your sight on a number"); cprintf(" Higher ");
     }
     else
     {
	 textcolor(11); printf("\n"); cprintf("Witch : Oh? That was the number I was thinking of...");
	 printf("\n\nGame : Congratulations %s!, You guessed the number in",str); textcolor(13); cprintf(" %d ",nguesses); printf("attempts.\n\n");
     }
     nguesses++;
     }while (guess != number1);
     textcolor(11); cprintf("Thank you for playing!"); getch();//delay(5000);
    }
    return 0;
}