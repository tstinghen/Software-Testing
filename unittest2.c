#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


/*score for */ 

void testScoreFor(); 

int main()
{

	testScoreFor(); 

return 0; 
}

void testScoreFor()
{

	int testScore; 
	int actualScore;
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
	
	printf("---TEST: scoreFor()---\n");
	/*has 0 cards */ 
	printf("---TESTING CASE: P1 - No Cards---\n"); 
	testScore = scoreFor(player1, state); 
	
	if (testScore == 0) 
	printf("SUCCESS - Zero cards in hand, score = %d \n", testScore); 
	
	else 
	printf("ERROR - Zero cards in hand, score = %d \n", testScore); 
	
	
	/*has cards in hand only - no points*/ 
	
	printf("---TESTING CASE: P1 - Cards in Hand, No Points---\n"); 
	
	state->hand[player1][0] = minion; 
	state->hand[player1][1] = mine; 
	state->hand[player1][2] = council_room; 
	
	state->handCount[player1] = 3; 
	
	testScore = scoreFor(player1, state); 
	
	if (testScore == 0) 
	printf("SUCCESS - Zero points, score = %d \n", testScore); 
	
	else 
	printf("ERROR - Zero points, score = %d \n", testScore); 
	
	
	/*hand only - points*/
	printf("---TESTING CASE: P1 - Cards in Hand, With Points---\n"); 
	state->hand[player1][3] = province; 
	state->hand[player1][4] = duchy; 
	
	state->handCount[player1] = state->handCount[player1] + 2; 
	
	
	testScore = scoreFor(player1, state); 
	
	actualScore = 6 + 3; 

	
	if(testScore == actualScore) 
	printf("SUCCESS - %d points, score = %d \n", actualScore, testScore); 
	
	else 
	printf("ERROR - %d points, score = %d \n", actualScore, testScore); 
	
	
	/*has cards in hand and deck*/ 
	printf("---TESTING CASE: P1 - Cards in Hand and Deck---\n"); 
	
	state->deck[player1][0] = province; 
	state->deck[player1][1] = mine; 
	state->deck[player1][2] = council_room; 
	state->deck[player1][3] = minion; 
	state->deck[player1][4] = curse; 

	state->deckCount[player1] = 5;
	
	testScore = scoreFor(player1, state); 
	
	actualScore = actualScore + (6 - 1); 

	if(testScore == actualScore) 
	printf("SUCCESS - %d points, score = %d \n", actualScore, testScore); 
	
	else 
	printf("ERROR - %d points, score = %d \n", actualScore, testScore); 
	
	
	
	/*has cards in deck only - points, no points*/ 
	
	/*has cards in discard only - points, no points*/ 
	printf("---TESTING CASE: P3 - Cards in Discard, No Points---\n"); 
	testScore = 0; 
	actualScore = 0; 
	
	state->discard[player3][0] = minion; 
	state->discard[player3][1] = mine; 
	state->discard[player3][2] = council_room; 
	
	state->discardCount[player3] = 3; 
	
	testScore = scoreFor(player3, state); 
	
	if (testScore == 0) 
	printf("SUCCESS - %d points, score = %d \n", actualScore, testScore); 
	
	else 
	printf("ERROR - %d points, score = %d \n", actualScore, testScore); 
	
	
	/*discard only - points*/
	printf("---TESTING CASE: P3 - Cards in Discard, With Points---\n"); 
	
	state->discard[player3][3] = province; 
	state->discard[player3][4] = duchy; 
	
	state->discardCount[player3] = state->discardCount[player3] + 2; 
	
	
	testScore = scoreFor(player3, state); 
	
	actualScore = 6 + 3; 

	
	if(testScore == actualScore) 
	printf("SUCCESS - %d points, score = %d \n", actualScore, testScore); 
	
	else 
	printf("ERROR - %d points, score = %d \n", actualScore, testScore); 
	
	/*has cards in all three =points, no points*/ 
	
	
	initializeGame(numPlayers, k, rand, state); 
	
	



}

