// Ali Yamini - Multi-threaded coin flipping        
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Constants
const int CCOUNT = 20; // Number of coins
const double PROBABILITY = 0.5; // Probability
const char *CSIDES[2] = {"X", "0"};

int persons = 100, tries = 10000;
char *coins[CCOUNT];

void randomize()
{
    printf("coins: ");
    srand(time(NULL));
    for(int i=0; i<CCOUNT; i++)
    {
        int random_index = rand() % 2;
        coins[i] = CSIDES[random_index];
        printf("%s", coins[i]);
    }
    printf(" (start - global lock)\n");
}

int main(int argc, char * argv[])
{    
    // Command line input checks
    if(argc==2)
        persons = atoi(argv[1]);
    if(argc>=3)
    {
        persons = atoi(argv[1]);
        tries = atoi(argv[2]);
    }

    // Strategy #1 - Global Lock
    // Randomly initialize coins array
    randomize();
    
    return 0;
}