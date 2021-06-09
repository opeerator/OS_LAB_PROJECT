// Ali Yamini - Multi-threaded coin flipping        
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

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

void tprinter(int nth, int nfl, double t)
{
    printf("%d threads x %d flips: %f\n", nth, nfl, t);
}

void initialize(char *s)
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
}

void operation(char *s)
{
    for(int j=0; j<tries; j++)
    {
        toss(STRATEGY[0]);
    }
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
    initialize(STRATEGY[0]);
    clock_t begin = clock();

    for(int i=0; i<persons; i++)
    {
        operation("g");
    }

    cprinter(STRATEGY[0], "end");
    clock_t end = clock();
    double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
    tprinter(persons, tries, time_spent);

    putchar('\n');
    fflush(stdout);

    // Strategy #2 - Global Lock

    return 0;
}