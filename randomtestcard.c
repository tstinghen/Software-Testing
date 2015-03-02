#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void testSteward(); 

int main()
{
	
	
	testSteward(); 
	
	return 0; 


}

void testSteward()
{

	
	int j; 	   
	int i; 
	int run_times; 
	int rand_num; 
	int success = 0; 
	int error = 0;
	
	int hand_count; 
	int disc_count; 
	int deck_count; 
	int money;
	
	int hand_count2; 
	int disc_count2; 
	int deck_count2; 
	int money2; 
	
	int cur_card; 
	
	
	int deck; 
	int numPlayers = 3; 
	int player1 = 1;
	int player2 = 2; 
	int player3 = 3;  
	int random; 
	struct gameState *state = malloc(sizeof(struct gameState)); 
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			steward, tribute, smithy, council_room};

	char* cardName[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
			"steward", "tribute", "smithy", "council_room"};
	
	
	srand (time(NULL));
/*
int playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state) 



}

void zzzstewardplay(int currentPlayer, struct gameState *state, int choice1, int choice2, int choice3, int handPos)     
{	   
	if (choice1 == 1)
	{
	  //+2 cards
	  drawCard(currentPlayer, state);
	  drawCard(currentPlayer, state);
	}
    if (choice1 != 2)
	{
	  //+2 coins
	  state->coins = state->coins + 2;
	}
      else 
	{
	  //trash 2 cards in hand
	  discardCard(choice2, currentPlayer, state, 1);
	  discardCard(choice2, currentPlayer, state, 1);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
	  */
   
		
	initializeGame(numPlayers, k, random, state);
	
	
	gainCard(2, state, 1, 0); 	/*build starting decks for the players*/
	gainCard(3, state, 1, 0); 
	gainCard(4, state, 1, 0); 
	gainCard(5, state, 1, 0); 
	gainCard(6, state, 1, 0); 
	gainCard(2, state, 1, 0); 
	gainCard(3, state, 1, 0); 
	gainCard(4, state, 1, 0); 
	gainCard(5, state, 1, 0); 
	gainCard(6, state, 1, 0); 
	
	gainCard(2, state, 1, 1); 
	gainCard(3, state, 1, 1); 
	gainCard(4, state, 1, 1); 
	gainCard(5, state, 1, 1); 
	gainCard(6, state, 1, 1); 
	gainCard(2, state, 1, 1); 
	gainCard(3, state, 1, 1); 
	gainCard(4, state, 1, 1); 
	gainCard(5, state, 1, 1); 
	gainCard(6, state, 1, 1); 
	
	gainCard(2, state, 1, 2); 
	gainCard(3, state, 1, 2); 
	gainCard(4, state, 1, 2); 
	gainCard(5, state, 1, 2); 
	gainCard(6, state, 1, 2); 
	gainCard(2, state, 1, 2); 
	gainCard(3, state, 1, 2); 
	gainCard(4, state, 1, 2); 
	gainCard(5, state, 1, 2); 
	gainCard(6, state, 1, 2); 
	
	
	endTurn(state); 
	endTurn(state); 
	endTurn(state); 
	updateCoins(whoseTurn(state), state, 0); 
	printf("---TESTING: Play Steward - Option 1: Draw two Cards---\n"); 
	
	run_times = (rand() % 500) + 50;   
	
	
	for(j = 0; j < run_times; j++) 
	{
		printf("Test #%d\n", j);  
		
		rand_num = (rand() % 3) + 1; 
		
		hand_count = state->handCount[whoseTurn(state)]; 
		disc_count = state->discardCount[whoseTurn(state)]; 
		deck_count = state->deckCount[whoseTurn(state)]; 
	

		for(i = 0; i < state->handCount[whoseTurn(state)]; i++)
		{
			cur_card = state->hand[whoseTurn(state)][i]; 
			
			switch (cur_card) 
			{
				case copper: 
					money = money + 1; 
					break;
				case silver:
					money = money + 2; 
					break;
				case gold: 
					money = money + 3; 
					break;
					
				default: 
					break;
			}
		}
		
		zzzstewardplay(whoseTurn(state), state, rand_num, 1, 2, 3);
		
		
		hand_count2 = state->handCount[whoseTurn(state)]; 
		disc_count2 = state->discardCount[whoseTurn(state)]; 
		deck_count2 = state->deckCount[whoseTurn(state)]; 
		
		if(rand_num == 1) 
		{
			if(hand_count2 == (hand_count + 1))
			{
				printf("SUCCESS: Drew two cards, discarded used card \n"); 
				success++; 
			}
			if(hand_count2 != (hand_count + 1))
			{
				if(hand_count2 > (hand_count + 1))
				{
					printf("ERROR: Too many cards in hand \n"); 
				}
				if(hand_count2 < (hand_count + 1))
				{
					printf("ERROR: Too few cards in hand\n"); 
				}
				error++;
			}	   
		
		}
		
		if(rand_num == 2) 
		{
			if(money2 == (money + 2))
			{
				printf("SUCCESS: +2 coins \n"); 
				success++;
			}
			else 
			{
				printf("ERROR: Incorrect number of coins added \n");
				error++;  
			}
		}
		
		if(rand_num == 3) 
		{
			if(hand_count2 == (hand_count - 1))
			{
				printf("SUCCESS: Discarded card after use \n"); 
				success++;
			}
		
			if(hand_count2 != (hand_count - 1))
			{
				if(hand_count2 > (hand_count - 1))
				{
					printf("ERROR: Too many cards in hand \n"); 
				}
				if(hand_count2 < (hand_count - 1))
				{
					printf("ERROR: Too few cards in hand\n"); 
				}
				
				error++; 
			}
		
		
		}
		
		
		endTurn(state); 
	}
	
	printf("---SUMMARY---\n");
	printf("Out of %d card tests:\n", run_times);
	printf("Success: %d\nErrors: %d\n", success, error); 
	
	
	
}

