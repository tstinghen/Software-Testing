#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void testSmithy(); 

int main()
{
	testSmithy(); 
	
	return 0; 


}

void testSmithy()
{
	int hand_count; 
	int disc_count; 
	int deck_count; 
	
	int hand_count2; 
	int disc_count2; 
	int deck_count2; 
	
	
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



/*void zzzsmithycardplay(int i, int currentPlayer, int handPos,
		struct gameState* state) { 
	//+3 Cards
	for (i = 0; i < 3; i++) {
		drawCard(currentPlayer, state);
	}
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);*/

/*int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{*/ 

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
printf("---TESTING: Play Smithy - Draw three cards, discard Smithy---\n"); 


hand_count = state->handCount[whoseTurn(state)]; 
disc_count = state->discardCount[whoseTurn(state)]; 
deck_count = state->deckCount[whoseTurn(state)]; 

printf("Beginning hand count %d \n", hand_count); 

printf("Beginning discard count %d \n", disc_count);

printf("Beginning deck count %d \n\n", deck_count); 

zzzsmithycardplay(0, whoseTurn(state), 3, state); 


hand_count2 = state->handCount[whoseTurn(state)]; 
disc_count2 = state->discardCount[whoseTurn(state)]; 
deck_count2 = state->deckCount[whoseTurn(state)]; 

printf("Deck count changed from %d to %d\n", deck_count, deck_count2);
if(hand_count2 == hand_count + 2)
{
	printf("SUCCESS hand count =  %d (increased by 2)\n", hand_count2); 
}
else
{
	printf("ERROR hand count changed from %d to %d\n", hand_count, hand_count2); 
}

if(disc_count2 == disc_count + 1) 
{
	printf("SUCCESS discard count = %d (incread by 1)\n", disc_count2);
}
else
{
	printf("ERROR discard count changed from %d to %d\n", disc_count, disc_count2); 
}

printf("\n---TESTING: Play Smithy again, same hand---\n"); 


hand_count = state->handCount[whoseTurn(state)]; 
disc_count = state->discardCount[whoseTurn(state)]; 
deck_count = state->deckCount[whoseTurn(state)]; 

printf("Beginning hand count %d \n", hand_count); 

printf("Beginning discard count %d \n", disc_count);

printf("Beginning deck count %d \n\n", deck_count); 

zzzsmithycardplay(0, whoseTurn(state), 3, state); 


hand_count2 = state->handCount[whoseTurn(state)]; 
disc_count2 = state->discardCount[whoseTurn(state)]; 
deck_count2 = state->deckCount[whoseTurn(state)]; 

printf("Deck count changed from %d to %d\n", deck_count, deck_count2);
if(hand_count2 == hand_count + 2)
{
	printf("SUCCESS hand count =  %d (increased by 2)\n", hand_count2); 
}
else
{
	printf("ERROR hand count changed from %d to %d\n", hand_count, hand_count2); 
}

if(disc_count2 == disc_count + 1) 
{
	printf("SUCCESS discard count = %d (incread by 1)\n", disc_count2);
}
else
{
	printf("ERROR discard count changed from %d to %d\n", disc_count, disc_count2); 
}

printf("\n---TESTING: Play Smithy again, new hand---\n"); 


endTurn(state); 
endTurn(state); 


hand_count = state->handCount[whoseTurn(state)]; 
disc_count = state->discardCount[whoseTurn(state)]; 
deck_count = state->deckCount[whoseTurn(state)]; 

printf("Beginning hand count %d \n", hand_count); 

printf("Beginning discard count %d \n", disc_count);

printf("Beginning deck count %d \n\n", deck_count); 

zzzsmithycardplay(0, whoseTurn(state), 3, state); 


hand_count2 = state->handCount[whoseTurn(state)]; 
disc_count2 = state->discardCount[whoseTurn(state)]; 
deck_count2 = state->deckCount[whoseTurn(state)]; 

printf("Deck count changed from %d to %d\n", deck_count, deck_count2);
if(hand_count2 == hand_count + 2)
{
	printf("SUCCESS hand count =  %d (increased by 2)\n", hand_count2); 
}
else
{
	printf("ERROR hand count changed from %d to %d\n", hand_count, hand_count2); 
}

if(disc_count2 == disc_count + 1) 
{
	printf("SUCCESS discard count = %d (incread by 1)\n", disc_count2);
}
else
{
	printf("ERROR discard count changed from %d to %d\n", disc_count, disc_count2); 
}



}

