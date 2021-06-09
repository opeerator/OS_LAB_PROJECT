// Ali Yamini - Multi-threaded coin flipping        
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

// Constants
#define CCOUNT 20 // Number of coins
#define PROBABILITY 50 // Probability
const char *STRATEGY[2] = {"global lock", "coin lock"}; // Stategies

char *CSIDES[2] = {"X", "0"}; // Coin Sides
int persons = 100, tries = 10000;
char *coins[CCOUNT];

struct thr_args 
{
    char * strategy;
    pthread_t trd;
};

void cprinter(char *s, char *t)
{
    printf("coins: ");
    for(int i=0; i<CCOUNT; i++)
        printf("%s", coins[i]);
    printf(" (%s - %s)\n", t, s);
}

void tprinter(int nth, int nfl, double t)
{
    printf("%d threads x %d flips: %f ms\n", nth, nfl, t);
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

void toss(char *s, pthread_t trd)
{
    for(int i=0; i<CCOUNT; i++)
    {
        if(s == STRATEGY[1])
            pthread_join(trd, NULL);
        int rnd_num = rand() % 100 + 1;
        if(rnd_num <= PROBABILITY)
            coins[i] = CSIDES[0];
        else
            coins[i] = CSIDES[1];
    }
}

void operation(void *thr_args)
{
    struct thr_args *args = thr_args;
    for(int j=0; j<tries; j++)
        toss(args -> strategy, args -> trd);
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
    pthread_t thr_g[persons];
    initialize(STRATEGY[0]);
    clock_t begin_g = clock();

    for(int i=0; i<persons; i++)
    {
        struct thr_args args_g;
        args_g.strategy = STRATEGY[0];
        pthread_create(&thr_g[i], NULL, operation, (void *)&args_g);
        args_g.trd = thr_g[i];
        pthread_join(thr_g[i], NULL);
    }

    cprinter(STRATEGY[0], "end");
    clock_t end_g = clock();
    double time_spent_g = ((double)(end_g - begin_g) / CLOCKS_PER_SEC) * 1000;
    tprinter(persons, tries, time_spent_g);

    putchar('\n');
    fflush(stdout);

    // Strategy #2 - Coin Lock
    pthread_t thr_c[persons];
    initialize(STRATEGY[1]);
    clock_t begin_c = clock();

    for(int i=0; i<persons; i++)
    {
        struct thr_args args_c;
        args_c.strategy = STRATEGY[1];
        pthread_create(&thr_c[i], NULL, operation, (void *)&args_c);
        args_c.trd = thr_c[i];
    }

    cprinter(STRATEGY[1], "end");
    clock_t end_c = clock();
    double time_spent_c = ((double)(end_c - begin_c) / CLOCKS_PER_SEC) * 1000;
    tprinter(persons, tries, time_spent_c);

    return 0;
}