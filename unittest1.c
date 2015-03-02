#include "dominion.h" 
#include "dominion_helpers.h" 
#include "rngs.h" 
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

void testGameOver();



int main()
{

/*For isGameOver(), For fullDeckCount()
For updateCoins(), For gainCard() 

For Smithy, For Adventurer
For Steward, For Village */

	printf("---TEST: isGameOver()---\n"); 
	
	testGameOver(); 


return 0; 

}

void testGameOver()
{
	
	
	struct gameState *test_game = malloc(sizeof(struct gameState)); 
	
	int ret_val; 
	int i; 
	
	ret_val - isGameOver(test_game); 
	
	printf("Return Value = %d when no supplies are initialized (should be arbitrary)\n", ret_val); 
	
	
	/*provences are 0, no other state assigned*/
	test_game->supplyCount[province] = 0; 
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 1) 
		printf("SUCCESS - GAME OVER if provences are at 0\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when provences are at 0\n", ret_val); 
		
	
	/*provinces == 10, all other cards uninitialized*/
	
	test_game->supplyCount[province] = 10; 
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 1) 
		printf("SUCCESS - GAME OVER if no supplies are available\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when no supplies are available\n", ret_val); 
		
	
	/*provences == 10, all other cards == 10*/ 
	
	for(i = 0; i< 25; i++) 
	{
		test_game->supplyCount[i] = 10; 
	}
	
	
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 0) 
		printf("SUCCESS - PLAY ON if no supplies are empty\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when no supplies are empty\n", ret_val); 
		
	
	/*provinces == 10, two piles are empty*/
	
	test_game->supplyCount[5] = 0;
	test_game->supplyCount[21] = 0;  
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 0) 
		printf("SUCCESS - PLAY ON if less than three supplies are empty\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when less than three supplies are empty\n", ret_val); 
		
	
	
	/*provinces == 10, three piles are empty */ 	
 
	test_game->supplyCount[12] = 0; 
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 1) 
		printf("SUCCESS - GAME OVER if three supplies are empty\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when three supplies are empty\n", ret_val); 
		
		
	/*provinces == 10, five piles are empty */ 	   
 
	test_game->supplyCount[7] = 0; 
	test_game->supplyCount[3] = 0;
	
	ret_val = isGameOver(test_game); 
	
	if(ret_val == 1) 
		printf("SUCCESS - GAME OVER if more than three supplies are empty\n"); 
	
	else 
		printf("FAULURE. Ret_val = %d when more than three supplies are empty\n", ret_val); 
		

}


