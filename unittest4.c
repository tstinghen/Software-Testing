#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/*end turn*/

void testEndTurn(); 

int main()
{

	testEndTurn(); 



return 0; 
}

void testEndTurn()
{
	
	
	int whoTurn; 
	int cardsInHand; 
	int cardsInDiscard; 
	int moneyInHand; 
	int nextDiscard;
	int checkStates = 0;  
	
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




endTurn(state);
endTurn(state); 
endTurn(state); 

/*check that new hand is drawn*/ 

/*check that the current player advances */ 

/*check that the current player advances to 0, if max reached */ 
printf("---TETSTING: endTurn()---\n");
printf("---TESTING: Advance to Next Player and Draw Cards ---\n"); 

whoTurn = whoseTurn(state); 

if(state->handCount[whoseTurn(state)] == 5)
{
	printf("SUCCESS: Player %d drew cards\n", whoseTurn(state)); 
}

else 
{
	printf("ERROR: Player %d did not draw cards\n", whoseTurn(state)); 
}

endTurn(state);

if(whoTurn == whoseTurn(state) - 1)
{
	printf("SUCCESS: Advanced to player %d\n", whoseTurn(state)); 
}

else if(whoTurn == 2 && whoseTurn(state) == 0)
{
	printf("SUCCESS: Cycled back to player %d\n", whoseTurn(state)); 
}
else 
{
	printf("ERROR: Current player is player %d\n", whoseTurn(state)); 
}

whoTurn = whoseTurn(state); 



if(state->handCount[whoseTurn(state)] == 5)
{
	printf("SUCCESS: Player %d drew cards\n", whoseTurn(state)); 
}

else 
{
	printf("ERROR: Player %d did not draw cards\n", whoseTurn(state)); 
}

endTurn(state);


if(whoTurn == whoseTurn(state) - 1)
{
	printf("SUCCESS: Advanced to player %d\n", whoseTurn(state)); 
}

else if(whoTurn == 2 && whoseTurn(state) == 0)
{
	printf("SUCCESS: Cycled back to player %d\n", whoseTurn(state)); 
}
else 
{
	printf("ERROR: Current player is player %d\n", whoseTurn(state)); 
}

whoTurn = whoseTurn(state); 



if(state->handCount[whoseTurn(state)] == 5)
{
	printf("SUCCESS: Player %d drew cards\n", whoseTurn(state)); 
}

else 
{
	printf("ERROR: Player %d did not draw cards\n", whoseTurn(state)); 
}


endTurn(state);

if(whoTurn == whoseTurn(state) - 1)
{
	printf("SUCCESS: Advanced to player %d\n", whoseTurn(state)); 
}

else if(whoTurn == 2 && whoseTurn(state) == 0)
{
	printf("SUCCESS: Cycled back to player %d\n", whoseTurn(state)); 
}
else 
{
	printf("ERROR: Current player is player %d\n", whoseTurn(state)); 
}

whoTurn = whoseTurn(state); 



if(state->handCount[whoseTurn(state)] == 5)
{
	printf("SUCCESS: Player %d drew cards\n", whoseTurn(state)); 
}

else 
{
	printf("ERROR: Player %d did not draw cards\n", whoseTurn(state)); 
}


endTurn(state);

if(whoTurn == whoseTurn(state) - 1)
{
	printf("SUCCESS: Advanced to player %d\n", whoseTurn(state)); 
}

else if(whoTurn == 2 && whoseTurn(state) == 0)
{
	printf("SUCCESS: Cycled back to player %d\n", whoseTurn(state)); 
}
else 
{
	printf("ERROR: Current player is player %d\n", whoseTurn(state)); 
}

whoTurn = whoseTurn(state); 




/*check that states are correct */ 

printf("---TESTING: Confirm That Gamestate is Reset Properly ---\n"); 

endTurn(state);

if (state->outpostPlayed != 0)
{
	checkStates++; 
	
}

if (state->phase != 0)
{
	checkStates++; 
	printf("ERROR: Phase not returned to 0\n");
 
}

if (state->numActions != 1)
{
	checkStates++; 
	printf("ERROR: Actions not returned to 1\n");
 
}

if (state->coins != 0)
{
	checkStates++;
	printf("ERROR: Coins not returned to 0\n");
}

 if (state->numBuys != 1)
{
	checkStates++; 
	printf("ERROR: Buys not returned to 1\n");	
}
 
if (state->playedCardCount != 0)
{
	checkStates++; 
	printf("ERROR: Played cards not returned to 0\n");	
}

if (state->handCount[state->whoseTurn] != 0)
{
	checkStates++; 
	printf("ERROR: Hand count not returned to 0\n");	
}

printf("Check states: %d\n", checkStates); 

if(checkStates == 0) 
{
	printf("SUCCESS: %d gamestates showed incorrect values \n", checkStates); 
}






/*check that cards are in the discard */ 

printf("---TESTING: Check that Cards are Discarded ---\n"); 

whoTurn = whoseTurn(state);

switch (state->discardCount[whoTurn]) 
{
	case 0: 
		nextDiscard = 5; 
		break; 
		
	case 5: 
		nextDiscard = 10; 
		break; 
		
	case 10: 
		nextDiscard = 0; 
		break; 
}

endTurn(state);

if (state->discardCount[whoTurn] == nextDiscard) 
{
	printf("SUCCESS: Updated discard\n"); 

}

else
{
	printf("ERROR: Failed update discard\n"); 
}


whoTurn = whoseTurn(state);

switch (state->discardCount[whoTurn]) 
{
	case 0: 
		nextDiscard = 5; 
		break; 
		
	case 5: 
		nextDiscard = 10; 
		break; 
		
	case 10: 
		nextDiscard = 0; 
		break; 
}

endTurn(state);

if (state->discardCount[whoTurn] == nextDiscard) 
{
	printf("SUCCESS: Updated discard\n"); 

}

else
{
	printf("ERROR: Failed update discard\n"); 
}


whoTurn = whoseTurn(state);

switch (state->discardCount[whoTurn]) 
{
	case 0: 
		nextDiscard = 5; 
		break; 
		
	case 5: 
		nextDiscard = 10; 
		break; 
		
	case 10: 
		nextDiscard = 0; 
		break; 
}

endTurn(state);

if (state->discardCount[whoTurn] == nextDiscard) 
{
	printf("SUCCESS: Updated discard\n"); 

}

else
{
	printf("ERROR: Failed update discard\n"); 
}






}

