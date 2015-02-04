#include <stdio.h>
#include <stdlib.h>

/* Hold user response */
char  response[256];

/* Deck of card in char array */
char deck[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,
                 2,3,4,5,6,7,8,9,10,10,10,10,11,
                 2,3,4,5,6,7,8,9,10,10,10,10,11,
                 2,3,4,5,6,7,8,9,10,10,10,10,11};

/* global variables for cards */
int player_1;
int player_2;
int dealer_1;
int dealer_2;
int player_total;
int dealer_total;

/* range of array deck */
int high = 51;
int low = 0;

/* function gets a random card value from the deck *
 * and sets the value to zero so it cannot be      *
 * selected again                                  */
int get_card()
{
  int rand_card = 0;
  int rand_index = 0;

  while (rand_card == 0)
  { 
   rand_index  = rand() % (high - low + 1) + low;
   rand_card = deck[rand_index];
  }

  deck[rand_index] = 0;
  return rand_card;
} 

/* stand function adds cards to dealer if *
 * total is not greater than 17. Then     *
 * reports result of the game             */
void stand(int p1, int p2, int d1, int d2)
{
  while((d1 + d2) < 17)
  {
   d1 = d1 + d2; 
   d2 = get_card();
    
   /* Ace handling statement sets the new  *
    * ace equal to one if the player would *
    * bust                                 */
    if (d2 == 11 && d1 > 10)
     {
       d2 = 1;
     }
    if ((d1 + d2) > 21)
     {
       printf("\nDealer now has: %d\n", (d1 + d2));
       printf("\nDealer Busts. You Win!\n");
       exit(1);
     }
   } // end while

  /* total the dealer and the players cards */
  int pt = p1 + p2;
  int dt = d1 + d2;
 
  if (pt > dt)
   {
     printf("\nDealer has:%d\nYou have:%d ", dt, pt);
     printf("You win!\n");
   } else if (dt > pt)
     {
       printf("\nDealer has:%d\nYou have:%d ", dt, pt);
       printf("\nDealer Wins!\n");
     } else 
        printf("\nDraw. That was close!\n");
        exit(1);

 }
int main()
{
 /* Seed the random number generator */
 srand((unsigned int)time(NULL));

 printf("\nWelcome to Dan Mahoney's illegal blackjack game\nWe are going to play some one-on-one blackjack today\nGood Luck Buddy\n");
 
 player_1 = get_card();
 dealer_1 = get_card();
 player_2 = get_card();
 dealer_2 = get_card();

 /* Print out player and dealer hands */
 printf("\nThe dealer:\n\? + %d\n", dealer_2);
 printf("\nYou:\n%d + %d = %d\n", player_1, player_2, (player_1 + player_2));


 /* total player and dealer cards */
 player_total = player_1 + player_2;
 dealer_total = dealer_1 + dealer_2;

 /* While loop to prompt the user to hit or stand */
 int k = 1;
 while (k == 1)
 {

   printf("\nWould you like to \"hit\" or \"stand\"\? ");
   scanf(" %s", &response);

    if (response[0] == 'h')
     {
       player_1 = player_1 + player_2;
       player_2 = get_card();
       
       /* Ace handling statement sets the new *
        * ace equal to one if the player would*
        * bust                                */
       if (player_2 == 11 && player_1 > 10)
        {
          player_2 = 1;
        }
       printf("\nThe dealer:\n\? + %d\n", dealer_2);
       printf("\n%d + %d = %d", player_1, player_2, (player_1 + player_2));
     } else
       {
       printf("\nThe dealer:\n\%d + %d\n", dealer_1, dealer_2);
       printf("\n%d + %d = %d\n", player_1, player_2, (player_1 + player_2));
       stand(player_1, player_2, dealer_1, dealer_2);
       }
   if ((player_1 + player_2) > 21)
    {  
       printf(" BUSTED!\nYou busted. Dealer wins.");  
       k = 0;
    }     
 }
  
 return 0;
}
 
