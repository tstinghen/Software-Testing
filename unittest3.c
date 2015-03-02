#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/*gain card*/ 

void testGainCard(); 

int main()
{

	testGainCard(); 



return 0; 
}

void testGainCard()
{
	
	int curHandCount; 
	int curSupCount; 
	int funcSuccess; 
	
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
	
	
/*test case where supply count is < 1 */ 


/*test case where add to hand */ 


gainCard(3, state, 2, 1); 
gainCard(3, state, 2, 1); 

curHandCount = state->handCount[1]; 
curSupCount = state->supplyCount[3]; 


gainCard(3, state, 2, 1); 
 printf("TESTING---gainCard()---\n");
if(state->handCount[1] == (curHandCount + 1))
{
	printf("SUCCESS: Add card to hand\n"); 	   
}

else
	printf("ERROR: Add card to hand\n"); 
	
/*test that the supply is -1 */ 

if(state->supplyCount[3] == (curSupCount - 1))
{
	printf("SUCCESS: Remove card from supply\n"); 	  
}

else
	printf("ERROR: Remove card from supply\n"); 

/*test case where add to deck */ 

gainCard(3, state, 1, 1); 
gainCard(3, state, 1, 1); 
gainCard(3, state, 1, 1); 
gainCard(3, state, 1, 1); 
 

curHandCount = state->deckCount[1]; 

gainCard(3, state, 1, 1);

if(state->deckCount[1] == (curHandCount + 1))
{
	printf("SUCCESS: Add card to deck\n"); 	   
}

else
	printf("ERROR: Add card to deck\n"); 


/*test case where add to discard */ 

gainCard(3, state, 0, 1); 
gainCard(3, state, 0, 1); 
gainCard(3, state, 0, 1); 


curHandCount = state->discardCount[1]; 

gainCard(3, state, 0, 1);


if(state->discardCount[1] == (curHandCount + 1))
{
	printf("SUCCESS: Add card to discard\n"); 	  
}

else
	printf("ERROR: Add card to discard\n"); 

curSupCount = state->supplyCount[3]; 

funcSuccess = gainCard(3, state, 0, 1);

if(curSupCount == 0) 
{
	if(funcSuccess == -1)
	{
		printf("SUCCESS: Supply count empty, no card added\n");	  
	}
	
	else 
	{
		printf("ERROR: Supply count empty but card added\n");
	}

}
else 
	printf("NOTE: Did not test for case Supply Enpty"); 




}

