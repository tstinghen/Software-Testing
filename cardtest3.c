#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void testVillage(); 

int main()
{
	testVillage(); 
	
	return 0; 


}

void testVillage()
{

	int hand_count; 
	int disc_count; 
	int deck_count; 
	int act_count; 
	
	int hand_count2; 
	int disc_count2; 
	int deck_count2; 
	int act_count2;
	
	
	int deck; 
	int numPlayers = 3; 
	int player1 = 1;
	int player2 = 2; 
	int player3 = 3;  
	int rand; 
	struct gameState *state = malloc(sizeof(struct gameState)); 
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	char* cardName[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
			"sea_hag", "tribute", "smithy", "council_room"};
	
	
		
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
	printf("---TESTING: Play Village - Draw one card, gain two actions, discard Village---\n"); 
	
	hand_count = state->handCount[whoseTurn(state)]; 
	disc_count = state->discardCount[whoseTurn(state)]; 
	deck_count = state->deckCount[whoseTurn(state)]; 
	act_count = state->numActions; 
	
	printf("Beginning hand count %d \n", hand_count); 
	
	printf("Beginning discard count %d \n", disc_count);
	
	printf("Beginning action count %d \n", act_count); 
	
	printf("Beginning deck count %d \n\n", deck_count); 
	
	zzzvilliagecardplay(whoseTurn(state), 3, state); 
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	act_count2 = state->numActions; 
	
	
	
	if(hand_count == hand_count2)
	{
		printf("SUCCESS: One card drawn\n", hand_count); 
	}
	else
	{
		printf("ERROR: Hand count is %d, supposed to be %d\n", hand_count2, hand_count); 	 
	}
	
	if(disc_count2 == disc_count + 1)
	{
		printf("SUCCESS: Village discarded\n", disc_count); 
	}
	else
	{
		printf("ERROR: Discard count is %d, supposed to be %d\n", disc_count2, (disc_count + 1)); 	  
	}
	
	if(act_count2 == act_count + 2)
	{
		printf("SUCCESS: Two actions gained\n", act_count); 
	}
	else
	{
		printf("ERROR: Action count is %d, supposed to be %d\n", act_count2, (act_count + 2)); 	   
	}
	
	if(deck_count2 == deck_count - 1)
	{
		printf("SUCCESS: One card drawn\n", deck_count); 
	}
	else
	{
		printf("ERROR: Deck count is %d, supposed to be %d\n", deck_count2, (deck_count - 1)); 	   
	}
	
	printf("---TESTING: Play Village again, same hand---\n"); 
	
	zzzvilliagecardplay(whoseTurn(state), 3, state); 
	hand_count = hand_count2;
	disc_count = disc_count2;
	deck_count = deck_count2;
	act_count = act_count2;
	
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	act_count2 = state->numActions; 
	
	
	if(hand_count == hand_count2)
	{
		printf("SUCCESS: One card drawn\n", hand_count); 
	}
	else
	{
		printf("ERROR: Hand count is %d, supposed to be %d\n", hand_count2, hand_count); 	 
	}
	
	if(disc_count2 == disc_count + 1)
	{
		printf("SUCCESS: Village discarded\n", disc_count); 
	}
	else
	{
		printf("ERROR: Discard count is %d, supposed to be %d\n", disc_count2, (disc_count + 1)); 	  
	}
	
	if(act_count2 == act_count + 2)
	{
		printf("SUCCESS: Two actions gained\n", act_count); 
	}
	else
	{
		printf("ERROR: Action count is %d, supposed to be %d\n", act_count2, (act_count + 2)); 	   
	}
	
	if(deck_count2 == deck_count - 1)
	{
		printf("SUCCESS: One card drawn\n", deck_count); 
	}
	else
	{
		printf("ERROR: Deck count is %d, supposed to be %d\n", deck_count2, (deck_count - 1)); 	    
	}
	
	printf("---TESTING: Play Village again, same hand---\n"); 
	
	zzzvilliagecardplay(whoseTurn(state), 3, state); 
	hand_count = hand_count2;
	disc_count = disc_count2;
	deck_count = deck_count2;
	act_count = act_count2;
	
	
	hand_count2 = state->handCount[whoseTurn(state)]; 
	disc_count2 = state->discardCount[whoseTurn(state)]; 
	deck_count2 = state->deckCount[whoseTurn(state)]; 
	act_count2 = state->numActions; 
	
	
	if(hand_count == hand_count2)
	{
		printf("SUCCESS: One card drawn\n", hand_count); 
	}
	else
	{
		printf("ERROR: Hand count is %d, supposed to be %d\n", hand_count2, hand_count); 	 
	}
	
	if(disc_count2 == disc_count + 1)
	{
		printf("SUCCESS: Village discarded\n", disc_count); 
	}
	else
	{
		printf("ERROR: Discard count is %d, supposed to be %d\n", disc_count2, (disc_count + 1)); 	  
	}
	
	if(act_count2 == act_count + 2)
	{
		printf("SUCCESS: Two actions gained\n", act_count); 
	}
	else
	{
		printf("ERROR: Action count is %d, supposed to be %d\n", act_count2, (act_count + 2)); 	   
	}
	
	if(deck_count2 == deck_count - 1)
	{
		printf("SUCCESS: One card drawn\n", deck_count); 
	}
	else
	{
		printf("ERROR: Deck count is %d, supposed to be %d\n", deck_count2, (deck_count - 1)); 	    
	}
	
	


}

