CFLAGS = -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

#UNIT TESTS
unittest1: unittest1.c dominion.o rngs.o 
	gcc -o unittest1 -lm unittest1.c dominion.o rngs.o $(CFLAGS)	
	
unittest2: unittest2.c dominion.o rngs.o 
	gcc -o unittest2 -lm unittest2.c dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o 
	gcc -o unittest3 -lm unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o 
	gcc -o unittest4 -lm unittest4.c dominion.o rngs.o $(CFLAGS)

#CARD TESTS	
cardtest1: cardtest1.c dominion.o rngs.o 
	gcc -o cardtest1 -lm cardtest1.c dominion.o rngs.o $(CFLAGS)	
	
cardtest2: cardtest2.c dominion.o rngs.o 
	gcc -o cardtest2 -lm cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o 
	gcc -o cardtest3 -lm cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o 
	gcc -o cardtest4 -lm cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o 
	gcc -o randomtestadventurer -lm randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o 
	gcc -o randomtestcard -lm randomtestcard.c dominion.o rngs.o $(CFLAGS)	

runtests: unittest3 unittest1 unittest2 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard randomtestadventurer
	./unittest4 &> unittest4result.out
	gcov dominion.c >> unittest4result.out
	cat dominion.c.gcov >> unittest4result.out
	
	./unittest3 &> unittest3result.out
	gcov dominion.c >> unittest3result.out
	cat dominion.c.gcov >> unittest3result.out
	
	./unittest2 &> unittest2result.out
	gcov dominion.c >> unittest2result.out
	cat dominion.c.gcov >> unittest2result.out
	
	./unittest1 &> unittest1result.out
	gcov dominion.c >> unittest1result.out
	cat dominion.c.gcov >> unittest1result.out
	
	./cardtest1 &> cardtest1result.out
	gcov dominion.c >> cardtest1result.out
	cat dominion.c.gcov >> cardtest1result.out
	
	./cardtest2 &> cardtest2result.out
	gcov dominion.c >> cardtest2result.out
	cat dominion.c.gcov >> cardtest2result.out
	
	./cardtest3 &> cardtest3result.out
	gcov dominion.c >> cardtest3result.out
	cat dominion.c.gcov >> cardtest3result.out
	
	./cardtest4 &> cardtest4result.out
	gcov dominion.c >> cardtest4result.out
	cat dominion.c.gcov >> cardtest4result.out
	
	./randomtestadventurer &> randomtestadventurerresult.out
	gcov dominion.c >> randomtestadventurerresult.out
	cat dominion.c.gcov >> randomtestadventurerresult.out
	
	./randomtestcard &> randomtestcardresult.out
	gcov dominion.c >> randomtestcardresult.out
	cat dominion.c.gcov >> randomtestcardresult.out
	

	

all: unittest3 unittest1 unittest2 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard dominion.o rngs.o

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *# *~ unittest3 unittest1 unittest2 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard
