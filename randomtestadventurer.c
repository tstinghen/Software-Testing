#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

void testAdventurer(); 

int main()
{
	testAdventurer(); 
	
	return 0; 


}

void testAdventurer()
{
	int i;
	int j; 
	int new_turn;
	int turn_count = 0;
	int play_times;  
	int money; 
	int money2;
	int hand; 
	int hand2; 
	int card;
	int cur_card; 
	int temp[MAX_HAND];
	int success = 0; 
	int error = 0; 
	
	int deck; 
	int deck2; 
	
	int numPlayers = 3; 
	int player1 = 1;
	int player2 = 2; 
	int player3 = 3;  
	int random; 
	struct gameState *state = malloc(sizeof(struct gameState)); 
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	char* cardName[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
			"sea_hag", "tribute", "smithy", "council_room"};
			
	
	initializeGame(numPlayers, k, random, state);	
	
	
	
gainCard(2, state, 1, 0); 	  /*build starting decks for the players*/
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
	

/*check when deck is empty*/ 
/*check number of coins*/ 
/*use update coins */
/*add silvers, golds to test, for coverage ... ? maybe*/ 

srand(time(NULL)); 

printf("---TESTING: Play Adventurer - draw cards until two treasures are drawn---\n"); 

play_times = (rand() % 300) + 50; 


for(j = 0; j < play_times; j++)
{
	hand = state->handCount[whoseTurn(state)]; 
	deck = state->deckCount[whoseTurn(state)]; 
	
	money = 0; 
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
	
	printf("Before Adventurer: $%d, cards: %d, deck: %d\n", money, hand, deck); 
	
	zzzadventurercardplay(0, whoseTurn(state), 0, temp, 0, state); 
	
	money2 = 0;
	
	for(i = 0; i < state->handCount[whoseTurn(state)]; i++)
	{
		cur_card = state->hand[whoseTurn(state)][i]; 
		
		switch (cur_card) 
		{
			case copper: 
				money2 = money2 + 1; 
				break;
			case silver:
				money2 = money2 + 2; 
				break;
			case gold: 
				money2 = money2 + 3; 
				break;
				
			default: 
				break;
		}
	}
			
	hand2 = state->handCount[whoseTurn(state)]; 
	deck2 = state->deckCount[whoseTurn(state)];
	
	printf("After Adventurer:$%d, cards: %d, deck: %d\n", money2, hand2, deck2); 
	
	if(money2 > money)
	{
		printf("SUCCESS: $%d worth of coins gained from card.\n", (money2 - money)); 
		success++;	  
	}	 	 
		
	else 
	{
		printf("ERROR:No coins gained from card.\n"); 
		error++;
	}	
		
	
	new_turn = rand() % 3; 
	
	if(new_turn == 1 )
	{
		printf("\n---NEW TURN---\n\n"); 
		endTurn(state); 
		turn_count++; 
	}

}

	printf("---SUMMARY---\n");
	printf("Turns played: %d\n", turn_count); 
	printf("Adventurer played %d times:\n", play_times);
	printf("Success: %d\nErrors: %d\n", success, error); 
	
}


