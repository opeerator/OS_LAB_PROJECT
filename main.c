// Ali Yamini - Multi-threaded coin flipping        
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Constants
const int CCOUNT = 20; // Number of coins
const double PROBABILITY = 50; // Probability
const char *STRATEGY[2] = {"global lock", "coin lock"}; // Stategies
char *CSIDES[2] = {"X", "0"}; // Coin Sides

int persons = 100, tries = 10000;
char *coins[CCOUNT];

void cprinter(char *s, char *t)
{
    printf("coins: ");
    for(int i=0; i<CCOUNT; i++)
        printf("%s", coins[i]);
    printf(" (%s - %s)\n", t, s);
}

void randomize(char *s)
{
    for(int i=0; i<CCOUNT; i++)
    {
        int random_index = rand() % 2;
        coins[i] = CSIDES[random_index];
    }
    cprinter(s, "start");
}

void toss(char *s)
{
    for(int i=0; i<CCOUNT; i++)
    {
        int rnd_num = rand() % 100 + 1;
        if(rnd_num <= PROBABILITY)
            coins[i] = CSIDES[0];
        else
            coins[i] = CSIDES[1];
    }
    cprinter(s, "end");
}

int main(int argc, char * argv[])
{    
    srand(time(NULL));
    // Command line input checks
    if(argc==2)
        persons = atoi(argv[1]);
    if(argc>=3)
    {
        persons = atoi(argv[1]);
        tries = atoi(argv[2]);
    }

    // Strategy #1 - Global Lock
    randomize(STRATEGY[0]);
    toss(STRATEGY[0]);

    return 0;
}