#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void testSteward(); 

int main()
{
	testSteward(); 
	
	return 0; 


}

void testSteward()
{

	int hand_count; 
	int disc_count; 
	int deck_count; 
	int coin_count;
	
	int hand_count2; 
	int disc_count2; 
	int deck_count2; 
	int coin_count2; 
	
	
	int deck; 
	int numPlayers = 3; 
	int player1 = 1;
	int player2 = 2; 
	int player3 = 3;  
	int rand; 
	struct gameState *state = malloc(sizeof(struct gameState)); 
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			steward, tribute, smithy, council_room};

	char* cardName[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
			"steward", "tribute", "smithy", "council_room"};
	
	
	
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
   
		
	initializeGame(numPlayers, k, rand, state);
	
	
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
	
	hand_count = state->handCount[whoseTurn(state)]; 
	disc_count = state->discardCount[whoseTurn(state)]; 
	deck_count = state->deckCount[whoseTurn(state)]; 
	coin_count = state->coins; 
	
	/*
	printf("Beginning hand count %d \n", hand_count); 
	
	printf("Beginning discard count %d \n", disc_count);
	
	printf("Beginning coins count %d \n", coin_count); 
	
	printf("Beginning deck count %d \n\n", deck_count); 
	*/
	
	zzzstewardplay(whoseTurn(state), state, 1, 1, 2, 3); 
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	coin_count2 = state->coins; 
	
	/*
	printf("Resultant hand count %d \n", hand_count2); 
	
	printf("Resultant discard count %d \n", disc_count2);
	
	printf("Resultant coins count %d \n", coin_count2); 
	
	printf("Resultant deck count %d \n\n", deck_count2); 
	*/
	
	if(coin_count2 != coin_count)
	{
		printf("ERROR: Coins changed by card inappropriately \n"); 
	}
	
	if(hand_count2 == (hand_count + 1))
	{
		printf("SUCCESS: Drew two cards, discarded used card \n"); 
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
	}
	
	if(disc_count2 == (disc_count - 1))
	{
		printf("SUCCESS: Card discarded after use\n"); 
	}
	if(disc_count2 != (disc_count - 1))
	{
		printf("ERROR: Incorrect discard behavior\n");
	}
	
	endTurn(state); 
	endTurn(state); 
	updateCoins(whoseTurn(state), state, 0); 
	printf("---TESTING: Play Steward - Option 2: Gain Two Coins---\n"); 
	
	hand_count = state->handCount[whoseTurn(state)]; 
	disc_count = state->discardCount[whoseTurn(state)]; 
	deck_count = state->deckCount[whoseTurn(state)]; 
	
	coin_count = state->coins; 
	/*
	printf("Beginning hand count %d \n", hand_count); 
	
	printf("Beginning discard count %d \n", disc_count);
	
	printf("Beginning coins count %d \n", coin_count); 
	
	printf("Beginning deck count %d \n\n", deck_count); 
	*/
	zzzstewardplay(whoseTurn(state), state, 2, 1, 2, 3); 
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	coin_count2 = state->coins; 
	
	/*
	printf("Resultant hand count %d \n", hand_count2); 
	
	printf("Resultant discard count %d \n", disc_count2);
	
	printf("Resultant coins count %d \n", coin_count2); 
	
	printf("Resultant deck count %d \n\n", deck_count2); 
	*/
	
	if(coin_count2 == (coin_count + 2))
	{
		printf("SUCCESS: +2 coins \n"); 
	}
	else 
		printf("ERROR: Incorrect number of coins added \n"); 
	
	if(hand_count2 == (hand_count - 3))
	{
		printf("SUCCESS: Discarded card after use and trashed two cards \n"); 
	}
	if(hand_count2 != (hand_count - 3))
	{
		if(hand_count2 > (hand_count - 3))
		{
			printf("ERROR: Too many cards in hand \n"); 
		}
		if(hand_count2 < (hand_count - 3))
		{
			printf("ERROR: Too few cards in hand\n"); 
		}
	}
	
	if(disc_count2 == (disc_count - 1))
	{
		printf("SUCCESS: Card discarded after use\n"); 
	}
	if(disc_count2 != (disc_count - 1))
	{
		printf("ERROR: Incorrect discard behavior\n");
	}
	
	
	endTurn(state); 
	updateCoins(whoseTurn(state), state, 0); 
	
	printf("---TESTING: Play Steward - Option 3: Trash Two Cards---\n"); 
	
	hand_count = state->handCount[whoseTurn(state)]; 
	disc_count = state->discardCount[whoseTurn(state)]; 
	deck_count = state->deckCount[whoseTurn(state)]; 
	updateCoins(whoseTurn(state), state, 0); 
	coin_count = state->coins; 
	/*
	printf("Beginning hand count %d \n", hand_count); 
	
	printf("Beginning discard count %d \n", disc_count);
	
	printf("Beginning coins count %d \n", coin_count); 
	
	printf("Beginning deck count %d \n\n", deck_count); 
	*/
	zzzstewardplay(whoseTurn(state), state, 3, 1, 2, 3); 
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	coin_count2 = state->coins; 
	
	/*
	printf("Resultant hand count %d \n", hand_count2); 
	
	printf("Resultant discard count %d \n", disc_count2);
	
	printf("Resultant coins count %d \n", coin_count2); 
	
	printf("Resultant deck count %d \n\n", deck_count2); 
	*/
	
	if(coin_count2 != coin_count)
	{
		printf("ERROR: Coins changed by card inappropriately \n"); 
	}
	
	if(hand_count2 == (hand_count - 1))
	{
		printf("SUCCESS: Discarded card after use \n"); 
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
	}
	
	if(disc_count2 == (disc_count - 1))
	{
		printf("SUCCESS: Card discarded after use\n"); 
	}
	if(disc_count2 != (disc_count - 1))
	{
		printf("ERROR: Incorrect discard behavior\n");
	}
	

}

